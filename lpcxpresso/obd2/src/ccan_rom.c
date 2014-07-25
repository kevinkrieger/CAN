/*
 * @brief CCAN on-chip driver example
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2012
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include "ccan_rom.h"
#include "string.h"
#include "ff.h"
/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/
extern char lcdBuffer[16];
extern FATFS Fatfs[_VOLUMES];	/* File system object for each logical drive */
extern FIL File[2];				/* File objects */
extern BYTE sdbuffer[1024] __attribute__ ((aligned (4))) ;	/* Working buffer,*/
UINT s1;
/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/
void baudrateCalculate(uint32_t baud_rate, uint32_t *can_api_timing_cfg)
{
	Board_LCD_WriteString("Calcing CAN baud");
	uint32_t pClk, div, quanta, segs, seg1, seg2, clk_per_bit, can_sjw;
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_CAN);
	pClk = Chip_Clock_GetMainClockRate();

	clk_per_bit = pClk / baud_rate;

	for (div = 0; div <= 15; div++) {
		for (quanta = 1; quanta <= 32; quanta++) {
			for (segs = 3; segs <= 17; segs++) {
				if (clk_per_bit == (segs * quanta * (div + 1))) {
					segs -= 3;
					seg1 = segs / 2;
					seg2 = segs - seg1;
					can_sjw = seg1 > 3 ? 3 : seg1;
					can_api_timing_cfg[0] = div;
					can_api_timing_cfg[1] =
						((quanta - 1) & 0x3F) | (can_sjw & 0x03) << 6 | (seg1 & 0x0F) << 8 | (seg2 & 0x07) << 12;
					Board_LCD_cmd(0x80);
					Board_LCD_WriteString("CAN baud calc'd");
					snprintf((char *)sdbuffer, 1024, "CAN baud calculated: %d\r\n",baud_rate);
					DEBUGSTR(sdbuffer);
					return;
				}
			}
		}
	}

}

/*	CAN receive callback */
/*	Function is executed by the Callback handler after
    a CAN message has been received */
void CAN_rx(uint8_t msg_obj_num) {
	Board_LCD_cmd(0x80);
	Board_LCD_WriteString("CAN RX:");
	/* Determine which CAN message has been received */
	msg_obj.msgobj = msg_obj_num;
	/* Now load up the msg_obj structure with the CAN message */
	LPC_CCAN_API->can_receive(&msg_obj);
	if (msg_obj_num == 1) {
		Board_LCD_WriteChar('1');
		Board_LCD_cmd(0xc0);
		//snprintf(lcdBuffer, 16, "RPM: %d ", ((msg_obj.data[0]*256)+msg_obj.data[1])/4);
		//snprintf(lcdBuffer, 16, "ID:%x,#:%x",msg_obj.mode_id,msg_obj.data[] )
	//	Board_LCD_WriteString(lcdBuffer);
		snprintf((char *)sdbuffer, 1024, "message 1: %x %x %x %x %x %x %x %x\r\n",msg_obj.data[0],msg_obj.data[1],msg_obj.data[2],msg_obj.data[3],msg_obj.data[4],msg_obj.data[5],msg_obj.data[6],msg_obj.data[7]);
		/*f_lseek(&File[1], f_size(&File[1]));
		f_write(&File[1], &sdbuffer, strlen((const char *)sdbuffer), &s1);
		f_sync(&File[1]);*/
		DEBUGSTR(sdbuffer);
		//Board_LCD_WriteString("0x")
		/* Simply transmit CAN frame (echo) with with ID +0x100 via buffer 2 */
		//msg_obj.msgobj = 2;
		//msg_obj.mode_id += 0x100;
		//msg_obj.msgobj  = 0;
		//	msg_obj.mode_id = 0x345;
		//msg_obj.mask    = 0x0;
		//msg_obj.dlc     = 4;
		//msg_obj.data[0] = 'b';	// 0x54
		//msg_obj.data[1] = 'E';	// 0x45
		//msg_obj.data[2] = 'S';	// 0x53
		//msg_obj.data[3] = 'T';	// 0x54
		//LPC_CCAN_API->can_transmit(&msg_obj);
	} else if(msg_obj_num == 2) { /* Configured for all 11 bit 7e8 messages.. */
		Board_LCD_WriteChar('2');
		/* SAE standard says that the 8 bytes should look like so for a query on 7DF:
		 * 0 = 2 for number of additional data bytes
		 * 1 = mode (1 for current data and 2 for freeze frame, meaning the last saved state when 'check engine' was lit up)
		 * 2 = PID code (0x0c should be engine rpm (again see http://en.wikipedia.org/wiki/OBD-II_PIDs#Mode_01 ) which returns
		 * two bytes that are interpreted as : rpm = ((A*256)+B)/4
		 */
		Board_LCD_cmd(0xc0);
		//snprintf(lcdBuffer, 16, "RPM: %d ", ((msg_obj.data[0]*256)+msg_obj.data[1])/4);
		//snprintf(lcdBuffer, 16, "ID:%x,#:%x",msg_obj.mode_id,msg_obj.data[] )
	//	Board_LCD_WriteString(lcdBuffer);
		snprintf((char *)sdbuffer, 1024, "message 2, ID: %x: %x %x %x %x %x %x %x %x\r\n",msg_obj.mode_id,msg_obj.data[0],msg_obj.data[1],msg_obj.data[2],msg_obj.data[3],msg_obj.data[4],msg_obj.data[5],msg_obj.data[6],msg_obj.data[7]);
		DEBUGSTR(sdbuffer);
		if(f_open(&File[1], "logfile.txt", FA_OPEN_ALWAYS | FA_WRITE) != FR_OK) {
				;
		} else {
			f_lseek(&File[1], f_size(&File[1]));
			f_write(&File[1], &sdbuffer, strlen((const char *)sdbuffer), &s1);
			f_sync(&File[1]);
			f_close(&File[1]);
		}

	} else {
		Board_LCD_WriteChar('?');
		snprintf((char *)sdbuffer, 1024, "message ?: %x %x %x %x %x %x %x %x\r\n",msg_obj.data[0],msg_obj.data[1],msg_obj.data[2],msg_obj.data[3],msg_obj.data[4],msg_obj.data[5],msg_obj.data[6],msg_obj.data[7]);
		DEBUGSTR(sdbuffer);
		if(f_open(&File[1], "logfile.txt", FA_OPEN_ALWAYS | FA_WRITE) != FR_OK) {
						;
		} else {
			f_lseek(&File[1], f_size(&File[1]));
			f_write(&File[1], &sdbuffer, strlen((const char *)sdbuffer), &s1);
			f_sync(&File[1]);
			f_close(&File[1]);
		}
	}
}

/*	CAN transmit callback */
/*	Function is executed by the Callback handler after
    a CAN message has been transmitted */
void CAN_tx(uint8_t msg_obj_num) {
	//Board_LCD_cmd(0x80);
	//Board_LCD_WriteString("CAN TX!");
	snprintf(lcdBuffer, 16, "CAN TX: %x", msg_obj_num);
	DEBUGSTR(lcdBuffer);
}

/*	CAN error callback */
/*	Function is executed by the Callback handler after
    an error has occured on the CAN bus */
void CAN_error(uint32_t error_info) {
	Board_LCD_cmd(0xc0);
	snprintf(lcdBuffer, 16, "CAN ERR: %0.2X", error_info & 0xFF);
	DEBUGSTR(lcdBuffer);
	Board_LCD_WriteString(lcdBuffer);


//	switch(error_info) {
//	case CAN_ERROR_NONE: Board_LCD_WriteChar('0');
//			break;
//	case CAN_ERROR_PASS: Board_LCD_WriteChar('1');
//			break;
//	case CAN_ERROR_WARN: Board_LCD_WriteChar('2');
//			break;
//	case CAN_ERROR_BOFF: Board_LCD_WriteChar('3');
//			break;
//	case CAN_ERROR_STUF: Board_LCD_WriteChar('4');
//			break;
//	case CAN_ERROR_FORM: Board_LCD_WriteChar('5');
//			break;
//	case CAN_ERROR_ACK: Board_LCD_WriteChar('6');
//			break;
//	case CAN_ERROR_BIT1: Board_LCD_WriteChar('7');
//			break;
//	case CAN_ERROR_BIT0: Board_LCD_WriteChar('8');
//			break;
//	case CAN_ERROR_CRC: Board_LCD_WriteChar('9');
//			break;
//	}
	// error status bits
/*	#define CAN_ERROR_NONE 0x00000000UL
	#define CAN_ERROR_PASS 0x00000001UL
	#define CAN_ERROR_WARN 0x00000002UL
	#define CAN_ERROR_BOFF 0x00000004UL
	#define CAN_ERROR_STUF 0x00000008UL
	#define CAN_ERROR_FORM 0x00000010UL
	#define CAN_ERROR_ACK 0x00000020UL
	#define CAN_ERROR_BIT1 0x00000040UL
	#define CAN_ERROR_BIT0 0x00000080UL
	#define CAN_ERROR_CRC 0x00000100UL*/
	/* Error 0x0B means STUF, PASS and WARN - STUF is when more than 5 equal bits in a recieved message
	 * are observed where it is not allowed.
	 */
/* error 0x83 means bit0, pass and warn -> Bit0Error. During the transmission of a message (or acknowledge bit,
	or active error flag, or overload flag), the device wanted to send a
	LOW/dominant level (data or identifier bit logical value ‘0’), but the
	monitored Bus value was HIGH/recessive. During busoff recovery this
	status is set each time a sequence of 11 HIGH/recessive bits has been
	monitored. This enables the CPU to monitor the proceeding of the
	busoff recovery sequence (indicating the bus is ns not stuck at
			LOW/dominant or continuously disturbed).

			PASS means the device is in the passive error state
			WARN means that we have exceeded 96 errors in  a counter

			0x22 means ack, and warn -> the message transmitted was not acknowledged. (and we reached too many errors)*/
}

/**
 * @brief	CCAN Interrupt Handler
 * @return	Nothing
 * @note	The CCAN interrupt handler must be provided by the user application.
 *	It's function is to call the isr() API located in the ROM
 */
void CAN_IRQHandler(void) {
	//Board_LCD_cmd(0x80);
	//Board_LCD_WriteString("CAN ISR!");
	LPC_CCAN_API->isr();
}
