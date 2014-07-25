#include "cmds.h"
#include <stdio.h>
#include "ring_buffer.h"
#include "crc.h"

HDLC_OBJ_T hdlc_frame_struct;
uint16_t current_state;
uint8_t count;
HDLC_OBJ_T * hdlc_frame;

void hdlc_init(void) {
	/* Initialize the state machine to idle */
	current_state = STATE_IDLE;
	count = 0;
	crcInit();
	hdlc_frame = &hdlc_frame_struct;
}

/* hdlc frame parser monitors serial stream for sflag and parses frames.
 * Needs to be called by the receive interrupt. It takes in the ringbuffer
 * and keeps the state machine up to date. Once a valid message is received it passes
 * it to the command parser. */
void hdlc_frame_parser(RINGBUFF_T * ringbuffer) {
	/* check to see what we have received so far */
	uint8_t received;
	//printf("before while\r\n");
	while(RingBuffer_Pop(ringbuffer, &received)) {
		//printf("start of WHILE\r\n");
		switch(current_state) {
			/* States we can be in (8 bits) */
			case STATE_IDLE:
				printf("STATE_IDLE\r\n");
				count = 0;
				if(received == HDLC_SFLAG) {
					hdlc_frame->sflag = received;
					current_state = STATE_SFLAG_RECEIVED;
				} else {
					// Error
					printf("ERROR - RECEIVED VALUE NOT START FLAG: %x\r\n", received);
					current_state = STATE_IDLE;
				}
				break;
			case STATE_SFLAG_RECEIVED:
				printf("STATE_SFLAG_RECEIVED\r\n");
				if(getReceived(&received, ringbuffer) == STATE_IDLE) {
					current_state = STATE_IDLE;
				} else {
					//printf("cmd received 1\r\n");
					current_state = STATE_CMD_RECEIVED;
					hdlc_frame->cmd = received;
					//printf("cmd received2 \r\n");
				}

				//printf("cmd received...\r\n");
				break;
			case STATE_CMD_RECEIVED:
				printf("STATE_CMD_RECEIVED\r\n");
				if(getReceived(&received, ringbuffer) == STATE_IDLE) {
					current_state = STATE_IDLE;
				} else {
					hdlc_frame->len = received;
					if(hdlc_frame->len == 0) {
						current_state = STATE_RECEIVING_CRC;
					} else {
						current_state = STATE_RECEIVING_PAYLOAD;
					}
				}
				break;
			case STATE_RECEIVING_PAYLOAD:
				printf("STATE_RECEIVING_PAYLOAD: length: %d\r\n",hdlc_frame->len);
				//for(int i = 0; i<hdlc_frame->len; i++) {
				if(getReceived(&received, ringbuffer) == STATE_IDLE) {
					current_state = STATE_IDLE;
					break;
				} else {
					printf("received: %x count: %d\r\n",received,count);
					current_state = STATE_RECEIVING_PAYLOAD;
					hdlc_frame->payload[count++] = received;
					if(count == hdlc_frame->len) {
						printf("Count: %d, len: %d\r\n",count,hdlc_frame->len);
						current_state = STATE_RECEIVING_CRC;
						count = 0;
					}
				}
				//}
				break;
			case STATE_RECEIVING_CRC:
				printf("STATE_RECEIVING_CRC\r\n");
				/* Get first byte of crc */
				if(getReceived(&received, ringbuffer) == STATE_IDLE) {
					current_state = STATE_IDLE;
					printf("idle...\r\n");
				} else {
					if(count == 0) {
						printf("Receiving first byte of crc\r\n");
						hdlc_frame->crc = (received<<8);
						count++;
						current_state = STATE_RECEIVING_CRC;
						break;
					} else if (count == 1) {
						printf("receiving second byte of crc\r\n");
						hdlc_frame->crc |= received;
						count = 0;
						current_state = STATE_CRC_RECEIVED;
						break;
					} else {
						/* error, should never reach this code... */
						printf("ERROR - COUNT ERROR DURING CRC RECEPTION\r\n");
						current_state = STATE_IDLE;
						count = 0;
						break;
					}
				}
				break;
			case STATE_CRC_RECEIVED:
				printf("STATE_CRC_RECEIVED\r\n");
				if(getReceived(&received, ringbuffer) == STATE_IDLE) {
					current_state = STATE_IDLE;
				} else {
					hdlc_frame->eflag = received;
					current_state = STATE_EFLAG_RECEIVED;
				}
				break;
			case STATE_EFLAG_RECEIVED:
				printf("STATE_EFLAG_RECEIVED\r\n");
				break;
			case STATE_TIMEOUT:
				//printf("STATE_TIMEOUT\r\n");
				break;
			default:
				printf("STATE_DEFAULT\r\n");
				break;
		}//case
	}//while
//	//printf("End of WHILE\r\n");
	if(current_state == STATE_EFLAG_RECEIVED) {
		printf("Received entire frame\r\n");
		/* successfully received entire frame. Check that the CRC is right and send to
		 * command parser. */
		uint16_t length = 1+1+1+hdlc_frame->len;
		if(crcFast((uint8_t*)hdlc_frame, length) == hdlc_frame->crc) {
			current_state = STATE_IDLE;
			command_parser(hdlc_frame->cmd,hdlc_frame->len,hdlc_frame->payload);
		} else {
			/* CRC incorrect. Let the other side know */
			printf("CRC INCORRECT: %x\r\n",hdlc_frame->crc);
			printf("Calculated: %x\r\n",crcFast((uint8_t*)hdlc_frame, length));
			current_state = STATE_IDLE;
		}
	}
}

/* Returns the current state after receiving appropriate character
 * returns STATE_IDLE if there was error */
uint8_t getReceived(uint8_t *received, RINGBUFF_T *ringbuffer) {
	//printf("getRecieved\r\n");
	if(*received == HDLC_SFLAG) {
		if(current_state == STATE_CRC_RECEIVED) {
			return STATE_EFLAG_RECEIVED;
		}
		// Error condition
		//printf("ERROR - RECEIVED ILLEGAL CHARACTER: %x\r\n",*received);
		return STATE_IDLE;
	} else if (*received == HDLC_ESC) {
		//printf("received HDLC_ESC\r\n");
		// We expect the next one to be either HDLC_ESC_TX or HDLC_SFLAG_TX
		if(RingBuffer_Pop(ringbuffer, received)) {
			if(*received == HDLC_ESC_TX || *received == HDLC_SFLAG_TX) {
				*received = *received | HDLC_BIT_MASKED;
				return current_state;
			} else {
				// error
				//printf("ERROR - RECEIVED ILLEGAL CHARACTER: %x\r\n",*received);
				return STATE_IDLE;
			}
		}
	}
	//printf("getRecieved done\r\n");
	return current_state;
}

/* Command parser - given a proper cmd, length and payload from the HDLC protocol and executes appropriate code */
void command_parser(uint8_t cmd, uint8_t len, uint8_t *payload) {

	//printf("Command parser\r\n");
	switch(cmd) {
	case NULL_COMMAND:
		printf("COMPUTER: NULL_COMMAND\r\n");
		printf("COMPUTER: %s\r\n",payload);
		break;
	case CHANGE_CAN_SPEED:
		printf("CHANGE_CAN_SPEED\r\n");
		break;
	case GET_CAN_SPEED:
		printf("GET_CAN_SPEED\r\n");
		break;
	case INIT_CAN_BUS:
		printf("INIT_CAN_BUS\r\n");
		break;
	case SET_CAN_RX_OBJ:
		printf("SET_CAN_RX_OBJ\r\n");
		break;
	case GET_CAN_RX_OBJ:
		printf("GET_CAN_RX_OBJ\r\n");
		break;
	case SETUP_CAN_TX_OBJ:
		printf("SETUP_CAN_TX_OBJ\r\n");
		break;
	case GET_CAN_TX_OBJ:
		printf("GET_CAN_TX_OBJ\r\n");
		break;
	case TRANSMIT_CAN_OBJ:
		printf("TRANSMIT_CAN_OBJ\r\n");
		break;
	case GET_BOARD_TEMP:
		printf("GET_BOARD_TEMP\r\n");
		break;
	case GET_BOARD_UPTIME:
		printf("GET_BOARD_UPTIME\r\n");
		break;
	case SET_BOARD_LED:
		printf("SET_BOARD_LED\r\n");
		break;
	case GET_BOARD_LED:
		printf("GET_BOARD_LED\r\n");
		break;
	case INIT_SD_CARD:
		printf("INIT_SD_CARD\r\n");
		break;
	case OPEN_FILE:
		printf("OPEN_FILE\r\n");
		break;
	case CLOSE_FILE:
		printf("CLOSE_FILE\r\n");
		break;
	case WRITE_FILE:
		printf("WRITE_FILE\r\n");
		break;
	case READ_FILE:
		printf("READ_FILE\r\n");
		break;
	case WRITE_LCD_CMD:
		printf("WRITE_LCD_CMD\r\n");
		break;
	case WRITE_LCD_STRING:
		printf("WRITE_LCD_STRING\r\n");
		break;
	default:
		printf("DEFAULT\r\n");
		break;
	}
}

