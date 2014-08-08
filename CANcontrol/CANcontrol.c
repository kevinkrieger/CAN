#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ring_buffer.h"
#include "cmds.h"
#include "crc.h"
#include <fcntl.h>
#include <stdgui.h>
#define BTSERIAL "/dev/rfcomm0"


char buffer[256];
int numread;
int input;
//FILE* can_board;
int can_board;
uint8_t written;
HDLC_OBJ_T* hdlc_frame;
RINGBUFF_T* ringbuffer;
uint8_t rb_itemSize = 1;
#define RB_LEN	256
uint8_t rb_data[RB_LEN];

CALLBACK(draw_hello,evt,param) {
	int ascent, descent;
	FONT fnt;
	fnt = get_appfont();
	get_font_info(fnt, &ascent, &descent, NULL);
	plot_str(evt->graphic, 5, 5+ascent+descent, "Hello World",fnt);

	return 0;
}

uint8_t inputAvailable()  
{
	struct timeval tv;
	fd_set fds;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return (FD_ISSET(0, &fds));
}

void sendCommand() {
//	while(1){
		printf("Send command: \r\n");
		printf("0 - NULL\r\n"
		   "1 - Change can speed\r\n"
		   "2 - Get can speed\r\n"
			"3 - Init can bus\r\n"
			"4 - Set can RX object\r\n"
			"5 - Get can RX object\r\n"
			"6 - Set can TX object\r\n"
			"7 - Get can TX object\r\n"
			"8 - Transmit CAN object\r\n"
			"9 - Get board temperature\r\n"
			"10 - Get board uptime\r\n"
			"11 - Set board LED\r\n"
			"12 - Get board LED\r\n"
			"13 - Init SD card\r\n"
			"14 - Open file\r\n"
			"15 - Close file\r\n"
			"16 - Write file\r\n"
			"17 - Write LCD command\r\n"
			"18 - Write LCD string\r\n");
	scanf("%d",&input);
	switch(input) {
	case NULL_COMMAND:
		printf("NULL_COMMAND\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case CHANGE_CAN_SPEED:
		printf("CHANGE_CAN_SPEED\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case GET_CAN_SPEED:
		printf("GET_CAN_SPEED\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case INIT_CAN_BUS:
		printf("INIT_CAN_BUS\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case SET_CAN_RX_OBJ:
		printf("SET_CAN_RX_OBJ\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case GET_CAN_RX_OBJ:
		printf("GET_CAN_RX_OBJ\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case SETUP_CAN_TX_OBJ:
		printf("SETUP_CAN_TX_OBJ\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case GET_CAN_TX_OBJ:
		printf("GET_CAN_TX_OBJ\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case TRANSMIT_CAN_OBJ:
		printf("TRANSMIT_CAN_OBJ\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case GET_BOARD_TEMP:
		printf("GET_BOARD_TEMP\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case GET_BOARD_UPTIME:
		printf("GET_BOARD_UPTIME\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case SET_BOARD_LED:
		printf("SET_BOARD_LED\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case GET_BOARD_LED:
		printf("GET_BOARD_LED\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case INIT_SD_CARD:
		printf("INIT_SD_CARD\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case OPEN_FILE:
		printf("OPEN_FILE\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case CLOSE_FILE:
		printf("CLOSE_FILE\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case WRITE_FILE:
		printf("WRITE_FILE\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case READ_FILE:
		printf("READ_FILE\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case WRITE_LCD_CMD:
		printf("WRITE_LCD_CMD\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	case WRITE_LCD_STRING:
		printf("WRITE_LCD_STRING\r\n");
		hdlc_frame->cmd = input;
		hdlc_frame->len = 0x00;
		break;
	default:
		printf("DEFAULT\r\n");
		return;
//	}
	}
	hdlc_frame->sflag = HDLC_SFLAG;
	hdlc_frame->eflag = HDLC_EFLAG;
	hdlc_frame->crc = crcSlow((uint8_t*)hdlc_frame,3+hdlc_frame->len);
	//written = fwrite(hdlc_frame,1,3+hdlc_frame->len,can_board);
	written = write(can_board,hdlc_frame,3+hdlc_frame->len);
	printf("Written bytes: %d\r\n",written); 

	return;
}

void main(int argc, int* argv) {
	int i;
	int rv;

	start_gui("hellO",args,arg,0,DEF_CB,"draw_hello",draw_hello,DONE);
	create_window("Hello",0,0,200,100,0,SET_PROP,"ON_REDRAW",1,"draw_hello",DONE);
	run_event_loop(&rv);

	printf("Opening %s... ",BTSERIAL);
	//can_board = fopen(BTSERIAL,"r+");
	can_board = open(BTSERIAL,O_RDWR|O_NONBLOCK);
	hdlc_frame = malloc(sizeof(HDLC_OBJ_T));
	ringbuffer = malloc(sizeof(RINGBUFF_T));
	RingBuffer_Init(ringbuffer, rb_data, rb_itemSize, RB_LEN);
	printf("Ringbuffer initialized\r\n");
	hdlc_init();

	if (can_board != 0) {
		printf("Success\r\n");
			printf("1 - Send command\r\n" 
					"2 - Listen only\r\n");
		while(1) {
			if(inputAvailable()) {
				printf("Input available\r\n");
				scanf("%d",&input);
				if(input == 1) {
					sendCommand();
				} else if (input == 2) {
					while(1) {
						//fscanf(can_board, "%s",(char *)buffer);
						numread = read(can_board,buffer,64);
						if(numread > 0) {
							printf("%s\r\n",(char *)buffer);
						}
					}
				}
			printf("1 - Send command\r\n" 
					"2 - Listen only\r\n");
			}
	//		else {
	//			printf("no input available");
	//		}
			//numread = fread(buffer,1,64,can_board);
			numread = read(can_board,buffer,64);
			if(numread > 0) {
				printf("Read something:");
				RingBuffer_InsertMult(ringbuffer, buffer,numread);
				for(i = 0; i< numread; i++){
					printf(" %x",buffer[i]);
				}
				printf("\r\n");
				hdlc_frame_parser(ringbuffer);
			} else {
				printf("Nothing read\r\n");
			}
			sleep(1);
		}
	//	fclose(can_board);
		close(can_board);
	}
	return;
}

