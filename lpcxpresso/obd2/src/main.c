/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#include "board.h"
#endif
#include <stdio.h>
#include <cr_section_macros.h>
#include <string.h>
#include "systick.h"
#include "ccan_rom.h"
#include "ring_buffer.h"
#include "cmds.h"

#define TICKRATE_HZ1 10
int i = 0;
int j = 0;
int read_character = EOF;
uint8_t rb_itemSize = 1;
#define RB_LEN	256
uint8_t rb_data[RB_LEN];
static RINGBUFF_T ringbuffer;

/**
 * @brief	Handle interrupt from 32-bit timer
 * @return	Nothing
 */
void TIMER32_0_IRQHandler(void)
{

	if (Chip_TIMER_MatchPending(LPC_TIMER32_0, 1)) {
		i++;
		Chip_TIMER_ClearMatch(LPC_TIMER32_0, 1);
		if( Board_LED_Test(1)) {
			Board_LED_Set(1, 0);
		}
		else {
			Board_LED_Set(1, 1);
		}
	}
	if(i % 20 == 0) {
		j=j+1;
		//Board_UARTPutChar('t');
		//DEBUGSTR(" Test 0123456789.`~!@#$%^&*()-=_+[]{}\\|;:/?.>,<");
		//read_character = DEBUGIN();
		//while(read_character != EOF) {
		//	Board_UARTPutChar(read_character);
		//	read_character = DEBUGIN();
		//}
	//	while(RingBuffer_Pop(&ringbuffer, &read_character)) {
	//		Board_UARTPutChar(read_character);
		//}
		//read_character = DEBUGIN();
		//while(read_character != EOF) {
	//		Board_UARTPutChar(read_character);
		//	read_character = DEBUGIN();
	//	}
	//	DEBUGSTR("Temperature value: %d\r\n", Board_Get_Temperature());
		/* Send a message on CAN bus to query 7DF (see http://en.wikipedia.org/wiki/OBD-II_PIDs#CAN_.2811-bit.29_Bus_format)
			 * Message objects 1 and 2 should receive from 7E8 as an example, really they should have masks set to receive
			 * from 7E8 to 7EF. this is a TODO  */
			msg_obj.msgobj  = 3;
			msg_obj.mode_id = 0x7df | CAN_MSGOBJ_EXT;
			msg_obj.mask    = 0x0;
			msg_obj.dlc     = 8;
	/* SAE standard says that the 8 bytes should look like so for a query on 7DF:
	 * 0 = 2 for number of additional data bytes
	 * 1 = mode (1 for current data and 2 for freeze frame, meaning the last saved state when 'check engine' was lit up)
	 * 2 = PID code (0x0c should be engine rpm (again see http://en.wikipedia.org/wiki/OBD-II_PIDs#Mode_01 ) which returns
	 * two bytes that are interpreted as : rpm = ((A*256)+B)/4
	 */
			msg_obj.data[0] = 0x02; // 2 == 2 additional data bytes
			msg_obj.data[1] = 0x01; // 1 == current frame
			//msg_obj.data[2] = 0x0c; //engine rpm = (A*256 + B) / 4
			//msg_obj.data[2] = 0x0d; //speed km/hr
		//	msg_obj.data[2] = j%31; //increment
			msg_obj.data[2] = 0; //which pids are supported? 0x00 to 0x20?
			msg_obj.data[3] = 0x55;
			msg_obj.data[4] = 0x55;
			msg_obj.data[5] = 0x55;
			msg_obj.data[6] = 0x55;
			msg_obj.data[7] = 0x55;

			LPC_CCAN_API->can_transmit(&msg_obj);
	}
}

void UART_IRQHandler (void){
	//DEBUGSTR("Yep\r\n");
	if(LPC_USART->IIR & UART_IIR_INTID_RDA) {
		DEBUGSTR("RDA\r\n\x00");
		/* New data will be ignored if data not popped in time */
		while (Chip_UART_ReadLineStatus(LPC_USART) & UART_LSR_RDR) {
			uint8_t ch = Chip_UART_ReadByte(LPC_USART);
			RingBuffer_Insert(&ringbuffer, &ch);
			DEBUGSTR("inserted char into ringbuffer\r\n\x00");
			//Chip_UART_SendByte(LPC_USART, ch);
			//DEBUGSTR("\r\n"\x00);
		}
		hdlc_frame_parser(&ringbuffer);
	} else if(LPC_USART->IIR & UART_IIR_INTID_RLS) {
	//	DEBUGSTR("Yep");
		DEBUGSTR("RLS\r\n");
		Chip_UART_RXIntHandlerRB(LPC_USART, &ringbuffer);
	}
	else {
		DEBUGSTR("UNKNOWN\r\n");
		//DEBUGSTR("Unknown\r\n");
	}
}


int main(void) {
#if defined (__USE_LPCOPEN)
#if !defined(NO_BOARD_LIB)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(1, true);
#endif
#endif

    uint32_t timerFreq;
    /* Initialize ring buffer */
    RingBuffer_Init(&ringbuffer, rb_data, rb_itemSize, RB_LEN);

	/* Enable timer 1 clock */
	Chip_TIMER_Init(LPC_TIMER32_0);

	/* Timer rate is system clock rate */
	timerFreq = Chip_Clock_GetSystemClockRate();



	/* Timer setup for match and interrupt at TICKRATE_HZ */
	Chip_TIMER_Reset(LPC_TIMER32_0);
	Chip_TIMER_MatchEnableInt(LPC_TIMER32_0, 1);
	Chip_TIMER_SetMatch(LPC_TIMER32_0, 1, (timerFreq / TICKRATE_HZ1));
	Chip_TIMER_ResetOnMatchEnable(LPC_TIMER32_0, 1);
	Chip_TIMER_Enable(LPC_TIMER32_0);

	/* Enable timer interrupt */
	NVIC_ClearPendingIRQ(TIMER_32_0_IRQn);
	NVIC_EnableIRQ(TIMER_32_0_IRQn);

	/* LEDs toggle in interrupt handlers */
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 2, 6);

    uint32_t CanApiClkInitTable[2];
	/* Publish CAN Callback Functions */
	CCAN_CALLBACKS_T callbacks = {
		CAN_rx,
		CAN_tx,
		CAN_error,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	};
	baudrateCalculate(TEST_CCAN_BAUD_RATE, CanApiClkInitTable);

	LPC_CCAN_API->init_can(&CanApiClkInitTable[0], TRUE);
	/* Configure the CAN callback functions */
	LPC_CCAN_API->config_calb(&callbacks);
	/* Enable the CAN Interrupt */
	NVIC_EnableIRQ(CAN_IRQn);
	NVIC_EnableIRQ(UART0_IRQn);
//LPC_CAN0->CANTEST |= 0b10000;

	/* Send a simple one time CAN message */
/*	msg_obj.msgobj  = 0;
	msg_obj.mode_id = 0x3FF | CAN_MSGOBJ_EXT;
	msg_obj.mask    = 0x0;
	msg_obj.dlc     =8;
	msg_obj.data[0] = 'b';	// 0x54
	msg_obj.data[1] = 'E';	// 0x45
	msg_obj.data[2] = 'S';	// 0x53
	msg_obj.data[3] = 'T';	// 0x54
	msg_obj.data[4] = 'b';	// 0x54
	msg_obj.data[5] = 'u';	// 0x45
	msg_obj.data[6] = 'd';	// 0x53
	msg_obj.data[7] = 's';	// 0x54

	LPC_CCAN_API->can_transmit(&msg_obj);
*/
/*	msg_obj.msgobj  = 0;
	msg_obj.mode_id = 0x7df;
	msg_obj.mask    = 0x0;
	msg_obj.dlc     = 8;
	msg_obj.data[0] = 0x02;
	msg_obj.data[1] = 0x01;
	msg_obj.data[2] = 0x0c;
	msg_obj.data[3] = 0x00;
	msg_obj.data[4] = 0x00;
	msg_obj.data[5] = 0x00;
	msg_obj.data[6] = 0x00;
	msg_obj.data[7] = 0x00;
*/
	//LPC_CCAN_API->can_transmit(&msg_obj);


	/* Configure message object 1 to receive all extended  messages  */
	msg_obj.msgobj = 1;
	msg_obj.mode_id = 0x7E8UL | CAN_MSGOBJ_EXT;
	msg_obj.mask = 0x0UL;
	LPC_CCAN_API->config_rxmsgobj(&msg_obj);

	/* Configure message object 2 to receive all 11 bit 7E0-7EF messages  */
	msg_obj.msgobj = 2;
	msg_obj.mode_id = 0x7E0;
	//msg_obj.mask = 0x7F0;
	msg_obj.mask = 0x0;//receive everything!
	LPC_CCAN_API->config_rxmsgobj(&msg_obj);


	//Board_LCD_WriteString("Testing!");
	//Board_LCD_cmd(0xC0); // Go to start of second line
	//Board_LCD_WriteString("Woop Woop!");
	while (1) {
		__WFI();
	}

	return 0;
}
