#include "cmds.h"
#include <stdio.h>
#include "ring_buffer.h"
#include "crc.h"

HDLC_OBJ_T hdlc_frame_struct;
HDLC_OBJ_T frame;
uint16_t current_state;
uint8_t count;
HDLC_OBJ_T * hdlc_frame;
int i;

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
	while(RingBuffer_Pop(ringbuffer, &received)) {
		//DEBUGSTR("start of WHILE\r\n");
		switch(current_state) {
			/* States we can be in (8 bits) */
			case STATE_IDLE:
				//DEBUGSTR("STATE_IDLE\r\n");
				count = 0;
				if(received == HDLC_SFLAG) {
					hdlc_frame->sflag = received;
					current_state = STATE_SFLAG_RECEIVED;
				} else {
					// Error
					//DEBUGSTR("ERROR - RECEIVED VALUE NOT START FLAG: ");
					//DEBUGSTR(received);
					//DEBUGSTR("\r\n");
					current_state = STATE_IDLE;
				}
				break;
			case STATE_SFLAG_RECEIVED:
				//DEBUGSTR("STATE_SFLAG_RECEIVED\r\n");
				if(getReceived(&received, ringbuffer) == STATE_IDLE) {
					current_state = STATE_IDLE;
				} else {
					//DEBUGSTR("cmd received 1\r\n");
					current_state = STATE_CMD_RECEIVED;
					hdlc_frame->cmd = received;
					//DEBUGSTR("cmd received2 \r\n");
				}

				//DEBUGSTR("cmd received...\r\n");
				break;
			case STATE_CMD_RECEIVED:
				//DEBUGSTR("STATE_CMD_RECEIVED\r\n");
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
				//DEBUGSTR("STATE_RECEIVING_PAYLOAD\r\n");
				//for(int i = 0; i<hdlc_frame->len; i++) {
				if(getReceived(&received, ringbuffer) == STATE_IDLE) {
					current_state = STATE_IDLE;
					break;
				} else {
					current_state = STATE_RECEIVING_PAYLOAD;
					hdlc_frame->payload[count++] = received;
					if(count == hdlc_frame->len) {
						current_state = STATE_RECEIVING_CRC;
						count = 0;
					}
				}
				//}
				current_state = STATE_RECEIVING_CRC;
				break;
			case STATE_RECEIVING_CRC:
				//DEBUGSTR("STATE_RECEIVING_CRC\r\n");
				/* Get first byte of crc */
				if(getReceived(&received, ringbuffer) == STATE_IDLE) {
					current_state = STATE_IDLE;
				} else {
					if(count == 0) {
						hdlc_frame->crc = (received<<8);
						count++;
						current_state = STATE_RECEIVING_CRC;
						break;
					} else if (count == 1) {
						hdlc_frame->crc |= received;
						count = 0;
						current_state = STATE_CRC_RECEIVED;
						break;
					} else {
						/* error, should never reach this code... */
						//DEBUGSTR("ERROR - COUNT ERROR DURING CRC RECEPTION\r\n");
						current_state = STATE_IDLE;
						count = 0;
						break;
					}
				}
				break;
			case STATE_CRC_RECEIVED:
				//DEBUGSTR("STATE_CRC_RECEIVED\r\n");
				if(getReceived(&received, ringbuffer) == STATE_IDLE) {
					current_state = STATE_IDLE;
				} else {
					hdlc_frame->eflag = received;
					current_state = STATE_EFLAG_RECEIVED;
				}
				break;
			case STATE_EFLAG_RECEIVED:
				//DEBUGSTR("STATE_EFLAG_RECEIVED\r\n");
				break;
			case STATE_TIMEOUT:
				//DEBUGSTR("STATE_TIMEOUT\r\n");
				break;
			default:
				//DEBUGSTR("STATE_DEFAULT\r\n");
				break;
		}//case
	}//while
//	//DEBUGSTR("End of WHILE\r\n");
	if(current_state == STATE_EFLAG_RECEIVED) {
		//DEBUGSTR("Received entire frame\r\n");
		/* successfully received entire frame. Check that the CRC is right and send to
		 * command parser. */
		uint16_t length = 1+1+1+hdlc_frame->len;
		if(crcFast((uint8_t*)hdlc_frame, length) == hdlc_frame->crc) {
			current_state = STATE_IDLE;
			command_parser(hdlc_frame->cmd,hdlc_frame->len,hdlc_frame->payload);
		} else {
			/* CRC incorrect. Let the other side know */
			//DEBUGSTR("CRC INCORRECT\r\n");
			current_state = STATE_IDLE;
		}
	}
}

/* Takes a command, length and payload and generates an hdlc frame, which it returns a pointer to. */
HDLC_OBJ_T* hdlc_frame_generator(uint8_t cmd, uint8_t len, uint8_t* payload) {

	frame.sflag = HDLC_SFLAG;
	frame.cmd = cmd;
	frame.len = len;
	for(i = 0; i< len; i++) {
		frame.payload[i] = payload[i];
	}
	frame.crc = crcFast((uint8_t*)&frame,3+frame.len);
	frame.eflag = HDLC_EFLAG;
	return &frame;
}

/* Sends hdlc frame properly out the serial port */
void hdlc_frame_send(HDLC_OBJ_T* frame) {
//	uint16_t length = 6+frame->len;
	uint8_t * ptr = frame;
//	Board_UARTPutChar(ptr[0]);
	Board_UARTPutChar(frame->sflag);
	for(i = 1; i < 3+frame->len ; i++) {
		if(ptr[i] == HDLC_SFLAG) {
			Board_UARTPutChar(HDLC_ESC);
			Board_UARTPutChar(HDLC_SFLAG_TX);
		} else if(ptr[i] == HDLC_ESC) {
			Board_UARTPutChar(HDLC_ESC);
			Board_UARTPutChar(HDLC_ESC_TX);
		} else {
			Board_UARTPutChar(ptr[i]);
		}
	}
	if( ((frame->crc & 0xFF00) >> 8) == HDLC_SFLAG) {
		Board_UARTPutChar(HDLC_ESC);
		Board_UARTPutChar(HDLC_SFLAG_TX);
	} else if( ((frame->crc & 0xFF00) >> 8) == HDLC_ESC) {
		Board_UARTPutChar(HDLC_ESC);
		Board_UARTPutChar(HDLC_ESC_TX);
	} else {
		Board_UARTPutChar( (frame->crc & 0xFF00) >> 8);
	}
	if( (frame->crc & 0xFF) == HDLC_SFLAG) {
		Board_UARTPutChar(HDLC_ESC);
		Board_UARTPutChar(HDLC_SFLAG_TX);
	} else if( (frame->crc & 0xFF) == HDLC_ESC) {
		Board_UARTPutChar(HDLC_ESC);
		Board_UARTPutChar(HDLC_ESC_TX);
	} else {
		Board_UARTPutChar(frame->crc & 0xFF);
	}
	Board_UARTPutChar(frame->eflag);
}

/* Returns the current state after receiving appropriate character
 * returns STATE_IDLE if there was error */
uint8_t getReceived(uint8_t *received, RINGBUFF_T *ringbuffer) {
	//DEBUGSTR("getRecieved\r\n");
	if(*received == HDLC_SFLAG) {
		if(current_state == STATE_CRC_RECEIVED) {
			return STATE_EFLAG_RECEIVED;
		}
		// Error condition
		//DEBUGSTR("ERROR - RECEIVED ILLEGAL CHARACTER: ");
		//DEBUGSTR(*received);
		//DEBUGSTR("\r\n");
		return STATE_IDLE;
	} else if (*received == HDLC_ESC) {
		//DEBUGSTR("received HDLC_ESC\r\n");
		// We expect the next one to be either HDLC_ESC_TX or HDLC_SFLAG_TX
		if(RingBuffer_Pop(ringbuffer, received)) {
			if(*received == HDLC_ESC_TX || *received == HDLC_SFLAG_TX) {
				*received = *received | HDLC_BIT_MASKED;
				return current_state;
			} else {
				// error
				//DEBUGSTR("ERROR - RECEIVED ILLEGAL CHARACTER: ");
				//DEBUGSTR(*received);
				//DEBUGSTR("\r\n");
				return STATE_IDLE;
			}
		}
	}
	//DEBUGSTR("getRecieved done\r\n");
	return current_state;
}

/* Command parser - given a proper cmd, length and payload from the HDLC protocol and executes appropriate code */
void command_parser(uint8_t cmd, uint8_t len, uint8_t *payload) {

	//DEBUGSTR("Command parser\r\n");
	switch(cmd) {
	case NULL_COMMAND:
		//DEBUGSTR("NULL_COMMAND\r\n");
		break;
	case CHANGE_CAN_SPEED:
		//DEBUGSTR("CHANGE_CAN_SPEED\r\n");
		break;
	case GET_CAN_SPEED:
		//DEBUGSTR("GET_CAN_SPEED\r\n");
		break;
	case INIT_CAN_BUS:
		//DEBUGSTR("INIT_CAN_BUS\r\n");
		break;
	case SET_CAN_RX_OBJ:
		//DEBUGSTR("SET_CAN_RX_OBJ\r\n");
		break;
	case GET_CAN_RX_OBJ:
		//DEBUGSTR("GET_CAN_RX_OBJ\r\n");
		break;
	case SETUP_CAN_TX_OBJ:
		//DEBUGSTR("SETUP_CAN_TX_OBJ\r\n");
		break;
	case GET_CAN_TX_OBJ:
		//DEBUGSTR("GET_CAN_TX_OBJ\r\n");
		break;
	case TRANSMIT_CAN_OBJ:
		//DEBUGSTR("TRANSMIT_CAN_OBJ\r\n");
		break;
	case GET_BOARD_TEMP:
		//DEBUGSTR("GET_BOARD_TEMP\r\n");
		break;
	case GET_BOARD_UPTIME:
		//DEBUGSTR("GET_BOARD_UPTIME\r\n");
		break;
	case SET_BOARD_LED:
		//DEBUGSTR("SET_BOARD_LED\r\n");
		break;
	case GET_BOARD_LED:
		//DEBUGSTR("GET_BOARD_LED\r\n");
		break;
	case INIT_SD_CARD:
		//DEBUGSTR("INIT_SD_CARD\r\n");
		break;
	case OPEN_FILE:
		//DEBUGSTR("OPEN_FILE\r\n");
		break;
	case CLOSE_FILE:
		//DEBUGSTR("CLOSE_FILE\r\n");
		break;
	case WRITE_FILE:
		//DEBUGSTR("WRITE_FILE\r\n");
		break;
	case READ_FILE:
		//DEBUGSTR("READ_FILE\r\n");
		break;
	case WRITE_LCD_CMD:
		//DEBUGSTR("WRITE_LCD_CMD\r\n");
		break;
	case WRITE_LCD_STRING:
		//DEBUGSTR("WRITE_LCD_STRING\r\n");
		break;
	default:
		//DEBUGSTR("DEFAULT\r\n");
		break;
	}
}
