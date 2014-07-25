/*
 * @brief CAN-obd2 11C14 board file
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
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
#include "retarget.h"
#include "systick.h"
#include "ff.h"
#include "rtc.h"
#include "ccan_rom.h"
#include <string.h>
#include "cmds.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/* SD card/filesystem stuff */
extern const char microSDTestData[1024];
extern const char microRestartedMsg[64];
extern const TCHAR *testfilename;
extern FATFS Fatfs[_VOLUMES];	/* File system object for each logical drive */
extern FIL File[2];				/* File objects */
extern BYTE sdbuffer[1024] __attribute__ ((aligned (4))) ;	/* Working buffer,
this will overflow your bss segment if it is too large. */
UINT s1;


const float adcVref = 3.3; // ADC reference voltage
uint16_t dataADC = 0; // Temporary adc storage
static ADC_CLOCK_SETUP_T ADCSetup;
char lcdBuffer[16];

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/* System oscillator rate and clock rate on the CLKIN pin */
const uint32_t OscRateIn = 20000000; // CAN-obd2 crystal is 20MHz
const uint32_t ExtRateIn = 0;

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/* Sends a character on the UART */
void Board_UARTPutChar(char ch)
{
#if defined(DEBUG_UART)
	Chip_UART_SendBlocking(DEBUG_UART, &ch, 1);
#endif
}

/* Gets a character from the UART, returns EOF if no character is ready */
int Board_UARTGetChar(void)
{
#if defined(DEBUG_UART)
	uint8_t data;

	if (Chip_UART_Read(DEBUG_UART, &data, 1) == 1) {
		return (int) data;
	}
#endif
	return EOF;
}

/* Outputs a string on the debug UART */
void Board_UARTPutSTR(char *str)
{
#if defined(DEBUG_UART)
	while (*str != '\0') {
		Board_UARTPutChar(*str++);
	}
#endif
}

/* Initialize debug output via UART for board */
void Board_Debug_Init(void)
{
#if defined(DEBUG_UART)
	Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_6, (IOCON_FUNC1 | IOCON_MODE_INACT)); /* RXD ** VERIFIED CORRECT on CAN-obd2 v1** */
	Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_7, (IOCON_FUNC1 | IOCON_MODE_INACT)); /* TXD ** VERIFIED CORRECT on CAN-obd2 v1** */

	/* Setup UART for 115.2K8N1 and receive RBR interrupt */
	Chip_UART_Init(LPC_USART);
	Chip_UART_SetBaud(LPC_USART, 9600);
	Chip_UART_ConfigData(LPC_USART, (UART_LCR_WLEN8 | UART_LCR_SBS_1BIT | UART_LCR_PARITY_DIS));
	Chip_UART_SetupFIFOS(LPC_USART, (UART_FCR_FIFO_EN | UART_FCR_RX_RS | UART_FCR_TX_RS | UART_FCR_TRG_LEV3));
	Chip_UART_IntEnable(LPC_USART,(UART_IER_RBRINT | UART_IER_RLSINT));
	Chip_UART_TXEnable(LPC_USART);

#endif
}

/* Initialize the us tick timer */
static void Board_us_Init(void) {
	/* Timer setup for 1us tickrate */
	Chip_TIMER_Init(LPC_TIMER32_1);
	Chip_TIMER_Reset(LPC_TIMER32_1);
	Chip_TIMER_PrescaleSet(LPC_TIMER32_1, (Chip_Clock_GetSystemClockRate()/1000000));
	Chip_TIMER_Enable(LPC_TIMER32_1);
}

/* Initializes board LED(s) */
static void Board_LED_Init(void)
{
	/* Set the PIO0_3 as output on CAN-obd2 v1. Also available are PIO0_4 and 5, and PIO1_9 */
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 0, 3);
	Chip_GPIO_SetPinState(LPC_GPIO, 0, 3, 0);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 0, 4);/* GPIO_0_4 is OPEN DRAIN */
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 0, 5);/* GPIO_0_5 is OPEN DRAIN */
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 1, 9);
}

/* Initialize input pushbuttons */
static void Board_Pushbutton_Init(void) {
	/* Set input directions */
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, 2, 4);
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, 2, 5);
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, 2, 9);

	/* Enable Pullups */
	Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO2_4, (IOCON_FUNC0 | IOCON_MODE_PULLUP));
	Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO2_5, (IOCON_FUNC0 | IOCON_MODE_PULLUP));
	Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO2_9, (IOCON_FUNC0 | IOCON_MODE_PULLUP));

	/* Enable and configure interrupts on falling edge */
	Chip_GPIO_SetPinModeEdge(LPC_GPIO, 2, (0b1000110000));
	Chip_GPIO_SetEdgeModeSingle(LPC_GPIO, 2, (0b1000110000));
	Chip_GPIO_SetModeLow(LPC_GPIO, 2, (0b1000110000));
	Chip_GPIO_EnableInt(LPC_GPIO, 2, (0b1000110000));

	/* Enable interrupt in the NVIC */
	NVIC_ClearPendingIRQ(EINT2_IRQn);
	NVIC_EnableIRQ(EINT2_IRQn);
}

/* Initialize the onboard temperature sensor */
static void Board_Temperature_Init(void) {
	/* Initialize the adc channel */
	Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_11, (IOCON_FUNC1 | IOCON_ADMODE_EN));
	Chip_ADC_Init(LPC_ADC, &ADCSetup);
	Chip_ADC_EnableChannel(LPC_ADC, ADC_CH7, ENABLE);
}

/* Strobe the LCD EN line */
void Board_LCD_Strobe(void)
{
    Chip_GPIO_SetPinState(LPC_GPIO, 1, 2, 1);
    __delay_us(1);
    Chip_GPIO_SetPinState(LPC_GPIO, 1, 2, 0);
}

/**
 * @brief	Write to the LCD screen a character
 * @param	Character : a character to write to LCD screen
 * @return	None
 * */
void Board_LCD_WriteChar(char c) {
	Chip_GPIO_SetPinState(LPC_GPIO, 1, 0, 1);
    __delay_us(50);
    Chip_GPIO_SetPinState(LPC_GPIO, 1, 5, (c & 0x80));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 2, (c & 0x40));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 1, (c & 0x20));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 0, (c & 0x10));
    Board_LCD_Strobe();

    Chip_GPIO_SetPinState(LPC_GPIO, 1, 5, (c & 0x08));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 2, (c & 0x04));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 1, (c & 0x02));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 0, (c & 0x01));
    Board_LCD_Strobe();
}

/**
 * @brief	Write string to the LCD screen
 * @param	String : a string to write to the LCD screen
 * @return	None
 * 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
 * 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F
 * 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F
 */
void Board_LCD_WriteString(const char * lcdstring) {
	while (*lcdstring) {
		Board_LCD_WriteChar(*lcdstring++);
	}
}

/* Send a command to the LCD */
void Board_LCD_cmd(const char c)
{
	Chip_GPIO_SetPinState(LPC_GPIO, 1, 0, 0);
    __delay_us(50);
    Chip_GPIO_SetPinState(LPC_GPIO, 1, 5, (c & 0x80));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 2, (c & 0x40));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 1, (c & 0x20));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 0, (c & 0x10));
    Board_LCD_Strobe();

    Chip_GPIO_SetPinState(LPC_GPIO, 1, 5, (c & 0x08));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 2, (c & 0x04));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 1, (c & 0x02));
    Chip_GPIO_SetPinState(LPC_GPIO, 3, 0, (c & 0x01));
    Board_LCD_Strobe();
}

/* Clear the LCD */
void Board_LCD_Clear(void)
{
    Board_LCD_cmd(0x01);
    __delay_ms(2);
}

/* Initialize the LCD screen */
static void Board_LCD_Init(void) {
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 1, 5);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 3, 2);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 3, 1);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 3, 0);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 1, 2);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 1, 1);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 1, 0);
	__delay_ms(15);
	Board_LCD_cmd(0x38);
	__delay_ms(1);
	Board_LCD_cmd(0x38);
	__delay_us(100);
	Board_LCD_cmd(0x38);
	Board_LCD_cmd(0x28);            // Function set (4-bit interface, 2 lines, 5*7Pixels)
	Board_LCD_cmd(0x28);            // Function set (4-bit interface, 2 lines, 5*7Pixels)
	Board_LCD_cmd(0x0c);            // Make cursor invisible
	Board_LCD_Clear();            // Clear screen
	Board_LCD_cmd(0x6);            // Set entry Mode(auto increment of cursor)
}

/* Initialize the SD card */
static void Board_SD_Init(void) {
	/* Set input directions */
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, 2, 10);

	/* Enable Pullup */
	Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO2_10, (IOCON_FUNC0 | IOCON_MODE_PULLUP));

	/* Enable and configure interrupts on falling edge */
	Chip_GPIO_SetPinModeEdge(LPC_GPIO, 2, (1<<10));
	Chip_GPIO_SetEdgeModeSingle(LPC_GPIO, 2, (1<<10));
	Chip_GPIO_SetModeLow(LPC_GPIO, 2, (1<<10));
	Chip_GPIO_EnableInt(LPC_GPIO, 2, (1<<10));

	/* Mount SD card, open a test file, write some test data to it and close it */
	if(f_mount(0,&Fatfs[0]) != FR_OK) {
		;
	}else if(f_open(&File[0], testfilename, FA_OPEN_ALWAYS | FA_WRITE) != FR_OK) {
		;
	}
	else if (f_write(&File[0], &microSDTestData, strlen(microSDTestData), &s1) != FR_OK) {
		;
	}
	else {
		f_close(&File[0]);	/* Close the test file so the data is written */
	}

	/* Open another file for logging and write data to it after seeking to the end. Keep it open. */
	if(f_open(&File[1], "logfile.txt", FA_OPEN_ALWAYS | FA_WRITE) != FR_OK) {
		;
	}
	else {
		f_lseek(&File[1], f_size(&File[1]));
		f_write(&File[1], &microRestartedMsg, strlen(microRestartedMsg), &s1);
		f_sync(&File[1]);
		f_close(&File[1]);
	}
}

static void Board_CAN_Init() {
	/* set stdby pin low */
	//Chip_GPIO_SetPinDIROutput(LPC_GPIO, 3, 3);
	//Chip_GPIO_SetPinOutLow(LPC_GPIO, 3, 3);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 0, 1);
	Chip_GPIO_SetPinOutLow(LPC_GPIO, 0, 1);
}

/* Get temperature in millicelcius */
int32_t Board_Get_Temperature(void) {
	/* Start A/D conversion */
	Chip_ADC_SetStartMode(LPC_ADC, ADC_START_NOW, ADC_TRIGGERMODE_RISING);

	/* Waiting for A/D conversion complete */
	while (Chip_ADC_ReadStatus(LPC_ADC, ADC_CH7, ADC_DR_DONE_STAT) != SET) {}

	/* Read ADC value */
	Chip_ADC_ReadValue(LPC_ADC, ADC_CH7, &dataADC);

	return ((dataADC*adcVref/1024.0) - 2.7315)*100000;
}

/* Sets the state of a board LED to on or off */
void Board_LED_Set(uint8_t LEDNumber, bool On)
{
	if(LEDNumber == 0) {
		Chip_GPIO_SetPinState(LPC_GPIO, 0, 3, On);
	} else if (LEDNumber == 1) {
		Chip_GPIO_SetPinState(LPC_GPIO, 0, 4, On);/* GPIO_0_4 is OPEN DRAIN */
	} else if (LEDNumber == 2) {
		Chip_GPIO_SetPinState(LPC_GPIO, 0, 5, On);/* GPIO_0_5 is OPEN DRAIN */
	} else {
		Chip_GPIO_SetPinState(LPC_GPIO, 1, 9, On);
	}
}

/* Returns the current state of a board LED */
bool Board_LED_Test(uint8_t LEDNumber)
{
	if(LEDNumber == 0) {
		return Chip_GPIO_GetPinState(LPC_GPIO, 0, 3);
	} else if (LEDNumber == 1) {
		return Chip_GPIO_GetPinState(LPC_GPIO, 0, 4);/* GPIO_0_4 is OPEN DRAIN */
	} else if (LEDNumber == 2) {
		return Chip_GPIO_GetPinState(LPC_GPIO, 0, 5);/* GPIO_0_5 is OPEN DRAIN */
	} else {
		return Chip_GPIO_GetPinState(LPC_GPIO, 1, 9);
	}
}

void Board_LED_Toggle(uint8_t LEDNumber)
{
	if (LEDNumber == 0) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, 0, 3);
	} else if (LEDNumber == 1) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, 0, 4);/* GPIO_0_4 is OPEN DRAIN */
	} else if (LEDNumber == 2) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, 0, 5);/* GPIO_0_5 is OPEN DRAIN */
	} else {
		Chip_GPIO_SetPinToggle(LPC_GPIO, 1, 9);
	}
}

/**
 * @brief	Handle interrupt from input pushbuttons and card detect
 * @return	Nothing
 */
void PIOINT2_IRQHandler(void)
{
	/* Clear interrupt */
/* TODO: Should add delay in for button debounce */
	/* It was button 3 */
	if(LPC_GPIO[2].MIS & (1<<4)) {
		Chip_GPIO_ClearInts(LPC_GPIO, 2, (1<<4));
		Board_LED_Toggle(1);
		Board_LCD_cmd(0x80);
		snprintf(lcdBuffer, 16, "Temp %d\xdf\x43", Board_Get_Temperature()/1000);
		DEBUGSTR(lcdBuffer);
		Board_LCD_WriteString(lcdBuffer);
	}
	/* It was button 2 */
	if(LPC_GPIO[2].MIS &(1<<5)) {
		Chip_GPIO_ClearInts(LPC_GPIO, 2, (1<<5));
		Board_LED_Toggle(2);
		Board_LCD_cmd(0x80);
		snprintf(lcdBuffer, 16, "Temp to LCD %d\xdf\x43", Board_Get_Temperature()/1000);
		Board_LCD_WriteString(lcdBuffer);
		snprintf((char *)sdbuffer, 1024, "Temp: %d\xdf\x43, uptime: %d seconds\r\n", Board_Get_Temperature()/1000, secondTicks);
		DEBUGSTR(sdbuffer);
		if(f_open(&File[1], "logfile.txt", FA_OPEN_ALWAYS | FA_WRITE) != FR_OK) {
				;
		}else {
			f_lseek(&File[1], f_size(&File[1]));
			f_write(&File[1], &sdbuffer, strlen((const char *)sdbuffer), &s1);
			f_sync(&File[1]);
			f_close(&File[1]);
		}
	}
	/* It was button 1 */
	if(LPC_GPIO[2].MIS & (1<<9)) {
		Chip_GPIO_ClearInts(LPC_GPIO, 2, (1<<9));
		Board_LED_Toggle(3);
		/* Send a message on CAN bus to query 7DF (see http://en.wikipedia.org/wiki/OBD-II_PIDs#CAN_.2811-bit.29_Bus_format)
		 * Message objects 1 and 2 should receive from 7E8 as an example, really they should have masks set to receive
		 * from 7E8 to 7EF. this is a TODO  */
		msg_obj.msgobj  = 4;
		msg_obj.mode_id = 0x7df;
		msg_obj.mask    = 0x0;
		msg_obj.dlc     = 8;
/* SAE standard says that the 8 bytes should look like so for a query on 7DF:
 * 0 = 2 for number of additional data bytes
 * 1 = mode (1 for current data and 2 for freeze frame, meaning the last saved state when 'check engine' was lit up)
 * 2 = PID code (0x0c should be engine rpm (again see http://en.wikipedia.org/wiki/OBD-II_PIDs#Mode_01 ) which returns
 * two bytes that are interpreted as : rpm = ((A*256)+B)/4
 */
		msg_obj.data[0] = 0x02; // 2 == 2 additional data bytes
		msg_obj.data[1] = 0x09; // 1 == freeze frame, 9 == request vehicle information
		//msg_obj.data[2] = 0x0c; //engine rpm = (A*256 + B) / 4
		//msg_obj.data[2] = 0x0d; //speed km/hr
		msg_obj.data[2] = 0x02; // mode 9, 02 == VIN
		msg_obj.data[3] = 0x55;
		msg_obj.data[4] = 0x55;
		msg_obj.data[5] = 0x55;
		msg_obj.data[6] = 0x55;
		msg_obj.data[7] = 0x55;

		LPC_CCAN_API->can_transmit(&msg_obj);
		DEBUGSTR("BUTTON1 - VIN?\r\n");
	}

	/* Card detect */
	if(LPC_GPIO[2].MIS & (1<<10)) {
		Chip_GPIO_ClearInts(LPC_GPIO,2, (1<<10));
		Board_LCD_cmd(0xC0);
		Board_LCD_WriteString("SD Card: ");
		DEBUGSTR("SD Card: ");
		/* Might need delay here for debounce */
	//	__delay_ms(50);
		if(!(Chip_GPIO_GetPinState(LPC_GPIO, 2, 10))) {
			Board_LCD_WriteString("Inserted");
			DEBUGSTR("Inserted\r\n");
			__delay_ms(10);
			Board_SD_Init();
		}
		else Board_LCD_WriteString("Removed");
		DEBUGSTR("Removed\r\n");
	}

	/* clear and disable IRQ for the buttons, it is enabled in the systick interrupt routine every second */
	NVIC_ClearPendingIRQ(EINT2_IRQn);
	NVIC_DisableIRQ(EINT2_IRQn);
}

/* Set up and initialize all required blocks and functions related to the
   board hardware */
void Board_Init(void)
{
	/* Sets up DEBUG UART */
	DEBUGINIT();

	/* Initialize GPIO */
	Chip_GPIO_Init(LPC_GPIO);

	/* Initialize system tick timer at 1ms for the SD card library */
	init_SysTickTimer();

	/* Initialize microsecond tick */
	Board_us_Init();

	/* Initialize LEDs */
	Board_LED_Init();

	/* Initialize input pushbuttons */
	Board_Pushbutton_Init();

	/* Initialize Temperature */
	Board_Temperature_Init();

	/* Initialize LCD */
	Board_LCD_Init();

	/* Initialize SD card */
	Board_SD_Init();


	/* Change to AT mode if using HC-05 */
	Chip_GPIO_SetPinState(LPC_GPIO, 0, 3, 1);
	__delay_us(100);
	Board_UARTPutSTR("AT+UART=115200,0,0\r\n");
	Chip_UART_Read(LPC_USART, &sdbuffer , 32);
	//while()
	Board_LCD_cmd(0xC0);
	Board_LCD_WriteString(sdbuffer);
	Board_UARTPutSTR("AT+UART?\r\n");
	Chip_UART_Read(LPC_USART, &sdbuffer, 32);
	Board_LCD_cmd(0xC0);
	Board_LCD_WriteString(sdbuffer);
	Chip_GPIO_SetPinState(LPC_GPIO, 0, 3, 0);
	__delay_us(100);
	//Chip_UART_Init(LPC_USART);
	Chip_UART_SetBaud(LPC_USART, 115200);
//	Chip_UART_ConfigData(LPC_USART, (UART_LCR_WLEN8 | UART_LCR_SBS_1BIT));
	//	Chip_UART_SetupFIFOS(LPC_USART, (UART_FCR_FIFO_EN | UART_FCR_TRG_LEV2));

	//	Chip_UART_TXEnable(LPC_USART);

	__delay_ms(100);
	hdlc_init();

	DEBUGSTR("TESTING");



	Board_CAN_Init();
}
