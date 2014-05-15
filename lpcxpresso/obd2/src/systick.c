/*
 * systick.c
 *
 *  Created on: Apr 18, 2014
 *      Author: kevin
 */

#include "systick.h"


/* Set up the systick timer for 1ms interrupts */
void init_SysTickTimer(void) {

	msTicks = 0;
	secondTicks = 0;
    /* Setup SysTick Timer for 1 msec interrupts  */
    if (SysTick_Config(SystemCoreClock / 1000)) {
        while (1); /* Capture error */
    }

   // if (!(SysTick->CTRL & (1 << SysTick_CTRL_CLKSOURCE_Msk))) {
        /* When external reference clock is used(CLKSOURCE in
         Systick Control and register bit 2 is set to 0), the
         SYSTICKCLKDIV must be a non-zero value and 2.5 times
         faster than the reference clock.
         When core clock, or system AHB clock, is used(CLKSOURCE
         in Systick Control and register bit 2 is set to 1), the
         SYSTICKCLKDIV has no effect to the SYSTICK frequency. See
         more on Systick clock and status register in Cortex-M3
         technical Reference Manual. */
        //LPC_SYSCON->SYSTICKCLKDIV = 0x08; SYSTCKCAL?
  //  }
}

/* Delay milliseconds. Not very accurate */
void __delay_ms(uint32_t ms) {
	/*volatile uint32_t temp = msTicks;
	if(temp + ms < temp) {
		while(temp + ms <= msTicks);
	} else {
		while(temp + ms >= msTicks) ;
	}*/
	uint32_t i;
	for(i = 0; i < ms ; i++) {
		__delay_us(1000);
	}
}

/* Delay microseconds. not very accurate.*/
void __delay_us(uint32_t us) {
	volatile uint32_t temp = Chip_TIMER_ReadCount(LPC_TIMER32_1);
	if(temp + us < temp) {
		while(temp + us < Chip_TIMER_ReadCount(LPC_TIMER32_1));
	} else {
		while(temp + us > Chip_TIMER_ReadCount(LPC_TIMER32_1));
	}
}

/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
/*----------------------------------------------------------------------------
  SysTick_Handler - called every time the SysTick tick occurs
 *--------------------------------------------------------------------------*/

void SysTick_Handler(void) {
    msTicks++;  /* increment millisecond counter */
    disk_timerproc();   /* Disk timer process that needs to be called for the
    filesystem module to work properly */


    if(msTicks % 1000 == 0) {
    	secondTicks++;
    	 /* Re-enable gpio interrupts every second */
    	Chip_GPIO_ClearInts(LPC_GPIO,2, 0xFFFFFFFF);
    	NVIC_ClearPendingIRQ(EINT2_IRQn);
    	NVIC_EnableIRQ(EINT2_IRQn);
    }
}
