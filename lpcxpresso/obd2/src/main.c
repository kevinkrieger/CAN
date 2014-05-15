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

#define TICKRATE_HZ1 10
int i = 0;
int read_character = EOF;

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
		Board_UARTPutChar('t');
		DEBUGSTR(" Test 0123456789.`~!@#$%^&*()-=_+[]{}\\|;:/?.>,<");
		read_character = DEBUGIN();
		while(read_character != EOF) {
			Board_UARTPutChar(read_character);
			read_character = DEBUGIN();
		}

		printf("Temperature value: %d\r\n", Board_Get_Temperature());
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


	/* Configure message object 1 to receive all extended 7E8 messages  */
	msg_obj.msgobj = 1;
	msg_obj.mode_id = 0x7E8UL | CAN_MSGOBJ_EXT;
	msg_obj.mask = 0x0;
	LPC_CCAN_API->config_rxmsgobj(&msg_obj);

	/* Configure message object 2 to receive all 11 bit 7E8 messages  */
	msg_obj.msgobj = 2;
	msg_obj.mode_id = 0x7E8;
	msg_obj.mask = 0x0;
	LPC_CCAN_API->config_rxmsgobj(&msg_obj);

	//Board_LCD_WriteString("Testing!");
	//Board_LCD_cmd(0xC0); // Go to start of second line
	//Board_LCD_WriteString("Woop Woop!");
	while (1) {
		__WFI();
	}

	return 0;
}
