/*
 *  * Command and control scheme (data type, protocol, commands, etc) for this embedded system
 *   * The command parser should be located in whatever functional block receives commands
 *    * An example would be the UART receive functions.
 *     */

#ifndef __CMDS_H_
#define __CMDS_H_

#include "lpc_types.h"
#include "ring_buffer.h"

/* Data structure for modified HDLC that is described here:
 *  *  http://stackoverflow.com/questions/815758/simple-serial-point-to-point-communication-protocol */
#define MAX_HDLC_PAYLOAD 256
#define HDLC_SFLAG 		0x7E	/* Start flag */
#define HDLC_EFLAG 		0x7E	/* End flag */
#define HDLC_ESC 		0x7D	/* Escape sequence */
#define HDLC_SFLAG_TX	0x5E	/* This is how a data byte that is originally the SFLAG is transmitted */
#define HDLC_ESC_TX		0x5D	/* This is how a data byte that is originally the ESC sequence is transmitted */
#define HDLC_BIT_MASKED 0x20	/* The bit changed in SFLAG or ESC octets when transmitted. OR it with the received byte
								   to get the original back. */

typedef struct {
	uint8_t sflag;
	uint8_t cmd;
	uint8_t len;
	uint8_t payload[MAX_HDLC_PAYLOAD];
	uint16_t crc;
	uint8_t eflag;
} HDLC_OBJ_T;

/* States we can be in (16 bits) */
#define STATE_IDLE				0x00 // transition from IDLE to SFLAG only
#define	STATE_SFLAG_RECEIVED 	0x01 // transition from any others to the following one or timeout only
#define	STATE_CMD_RECEIVED		0x02
#define	STATE_LEN_RECEIVED		0x04
#define	STATE_RECEIVING_PAYLOAD	0x08
#define	STATE_PAYLOAD_RECEIVED	0x10
#define STATE_RECEIVING_CRC		0x20
#define	STATE_CRC_RECEIVED		0x40
#define	STATE_EFLAG_RECEIVED	0x80
#define	STATE_TIMEOUT			0x100 //timeout occurs when we have a timer interrupt twice while in the same state

/* Possible commands - 8 bits */
#define	NULL_COMMAND		0x00
#define CHANGE_CAN_SPEED	0x01
#define GET_CAN_SPEED		0x02
#define INIT_CAN_BUS		0x03
#define SET_CAN_RX_OBJ		0x04
#define	GET_CAN_RX_OBJ		0x05
#define SETUP_CAN_TX_OBJ	0x06
#define	GET_CAN_TX_OBJ		0x07
#define TRANSMIT_CAN_OBJ	0x08
#define GET_BOARD_TEMP		0x09
#define GET_BOARD_UPTIME	0x0A
#define	SET_BOARD_LED		0x0B
#define	GET_BOARD_LED		0x0C
#define	INIT_SD_CARD		0x0D
#define OPEN_FILE			0x0E
#define	CLOSE_FILE			0x0F
#define	WRITE_FILE			0x10
#define READ_FILE			0x11
#define WRITE_LCD_CMD		0x12
#define WRITE_LCD_STRING	0x13

/* Initialize state machine */
void hdlc_init(void) ;

/* hdlc frame parser monitors serial stream for sflag and parses frames */
void hdlc_frame_parser(RINGBUFF_T * ringbuffer);

/* Returns the current state after receiving appropriate character
 * returns STATE_IDLE if there was error */
uint8_t getReceived(uint8_t *received, RINGBUFF_T* ringbuffer);

/* Command parser - given a proper cmd, length and payload from the HDLC protocol and executes appropriate code */
void command_parser(uint8_t cmd, uint8_t len, uint8_t *payload);

#endif

