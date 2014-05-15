/*
 * @brief CAN-obd2 11C14 Sysinit file
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
 #include "string.h"

/* The System initialization code is called prior to the application and
   initializes the board for run-time operation. Board initialization
   includes clock setup and default pin muxing configuration. */

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/* IOCON pin definitions for pin muxing */
typedef struct {
	uint32_t pin:8;			/* Pin number */
	uint32_t modefunc:24;	/* Function and mode */
} PINMUX_GRP_T;

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/* Pin muxing table, only items that need changing from their default pin
   state are in this table. */
STATIC const PINMUX_GRP_T pinmuxing[] = {
	//{(uint32_t) IOCON_PIO0_1,  (IOCON_FUNC1 | IOCON_MODE_INACT)},	/* PIO0_1 used for CLKOUT ** ACTUALLY USED FOR GPIO/K_LINE on CAN-obd2 v1 ** */
	{(uint32_t) IOCON_PIO0_2,  (IOCON_FUNC1 | IOCON_MODE_INACT)},	/* PIO0_2 used for SSEL */
//	{(uint32_t) IOCON_PIO0_4,  (IOCON_FUNC1 | IOCON_SFI2C_EN)},	/* PIO0_4 used for SCL ** ACTUALLY USED FOR GPIO on CAN-obd2 v1 ** */
//	{(uint32_t) IOCON_PIO0_5,  (IOCON_FUNC1 | IOCON_SFI2C_EN)},	/* PIO0_5 used for SDA ** ACTUALLY USED FOR GPIO on CAN-obd2 v1 ** */
	{(uint32_t) IOCON_PIO0_4,  (IOCON_FUNC0)},	/* PIO0_4 used for GPIO on CAN-obd2 v1 ** OPEN_DRAIN */
	{(uint32_t) IOCON_PIO0_5,  (IOCON_FUNC0)},	/* PIO0_5 used for GPIO on CAN-obd2 v1 ** OPEN_DRAIN */
	{(uint32_t) IOCON_PIO1_9,  (IOCON_FUNC0)},	/* PIO1_9 used for GPIO on CAN-obd2 v1 ** */
	{(uint32_t) IOCON_PIO0_8,  (IOCON_FUNC1 | IOCON_MODE_INACT)},	/* PIO0_8 used for MISO */
	{(uint32_t) IOCON_PIO0_9,  (IOCON_FUNC1 | IOCON_MODE_INACT)},	/* PIO0_9 used for MOSI */
	{(uint32_t) IOCON_PIO0_11, (IOCON_FUNC1 | IOCON_ADMODE_EN)},	/* PIO0_11 used for AD0 ** NOT CONNECTED ON CAN-obd2 v1 ** */
	{(uint32_t) IOCON_PIO1_5,  (IOCON_FUNC0)}, /* PIO1_5 used for LCD_DB7 */
	{(uint32_t) IOCON_PIO3_2,  (IOCON_FUNC0)}, /* PIO3_2 used for LCD_DB6 */
	{(uint32_t) IOCON_PIO3_1,  (IOCON_FUNC0)}, /* PIO3_1 used for LCD_DB5 */
	{(uint32_t) IOCON_PIO3_0,  (IOCON_FUNC0)}, /* PIO3_0 used for LCD_DB4 */
	{(uint32_t) IOCON_PIO1_2,  (IOCON_FUNC1)}, /* PIO1_2 used for LCD_E */
	{(uint32_t) IOCON_PIO1_1,  (IOCON_FUNC1)}, /* PIO1_1 used for LCD_RW */
	{(uint32_t) IOCON_PIO1_0,  (IOCON_FUNC1)}, /* PIO1_0 used for LCD_RS */
	{(uint32_t) IOCON_PIO1_6,  (IOCON_FUNC1 | IOCON_MODE_INACT)},	/* PIO1_6 used for RXD */
	{(uint32_t) IOCON_PIO1_7,  (IOCON_FUNC1 | IOCON_MODE_INACT)},	/* PIO1_7 used for TXD */
	{(uint32_t) IOCON_PIO2_10, (IOCON_FUNC0 | IOCON_MODE_PULLUP)}, /* Card detect. Pulled up by internal and pulled low by card inserted */
	{(uint32_t) IOCON_PIO2_11, (IOCON_FUNC1 | IOCON_MODE_INACT)},	/* PIO2_11 used for SCK */
	{(uint32_t) IOCON_PIO1_11, (IOCON_FUNC1 | IOCON_ADMODE_EN)}, /* PIO1_11 used for the LM335 temperature sensor on CAN-obd2 v1*/
	{(uint32_t) IOCON_PIO3_3,  (IOCON_FUNC1 | IOCON_MODE_PULLDOWN)} /* CAN stby mode active high */
	/* TODO: Add other pins here */
};

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/* Setup system clocking */
STATIC void SystemSetupClocking(void)
{
	volatile int i;

	/* Powerup main oscillator */
	Chip_SYSCTL_PowerUp(SYSCTL_POWERDOWN_SYSOSC_PD);

	/* Wait 200us for OSC to be stablized, no status
	   indication, dummy wait. */
	for (i = 0; i < 0x100; i++) {}

	/* Set system PLL input to main oscillator */
	Chip_Clock_SetSystemPLLSource(SYSCTL_PLLCLKSRC_MAINOSC);

	/* Power down PLL to change the PLL divider ratio */
	Chip_SYSCTL_PowerDown(SYSCTL_POWERDOWN_SYSPLL_PD);

	/* Setup PLL for main oscillator rate (FCLKIN = 20MHz) * 5 = 100MHz
	   MSEL = 2 (this is pre-decremented), PSEL = 1 (for P = 2)
	   FCLKOUT = FCLKIN * (MSEL + 1) = 20MHz * 5 = 100MHz
	   FCCO = FCLKOUT * 2 * P = 100MHz * 2 * 1 = 200MHz (within FCCO range 156MHz to 320MHz) */
	Chip_Clock_SetupSystemPLL(2, 0);

	/* Powerup system PLL */
	Chip_SYSCTL_PowerUp(SYSCTL_POWERDOWN_SYSPLL_PD);

	/* Wait for PLL to lock */
	while (!Chip_Clock_IsSystemPLLLocked()) {}

	/* Set system clock divider to 2 to get 100MHz/2 = 50MHz */
	Chip_Clock_SetSysClockDiv(2);

	/* Setup FLASH access to 3 clocks */
	Chip_FMC_SetFLASHAccess(FLASHTIM_50MHZ_CPU);

	/* Set main clock source to the system PLL. This will drive 100MHz
	   for the main clock (FCLKOUT) and 50MHz for the system clock */
	Chip_Clock_SetMainClockSource(SYSCTL_MAINCLKSRC_PLLOUT);
}

/* Sets up system pin muxing */
STATIC void SystemSetupMuxing(void)
{
	int i;

	/* Enable IOCON clock */
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_IOCON);

	for (i = 0; i < (sizeof(pinmuxing) / sizeof(PINMUX_GRP_T)); i++) {
		Chip_IOCON_PinMuxSet(LPC_IOCON, (CHIP_IOCON_PIO_T) pinmuxing[i].pin,
			pinmuxing[i].modefunc);
	}
}

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/* Set up and initialize hardware prior to call to main */
void Board_SystemInit(void)
{
	/* Setup system clocking and muxing */
	SystemSetupClocking();
	SystemSetupMuxing();
}
