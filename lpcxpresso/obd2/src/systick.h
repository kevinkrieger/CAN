/*
 * systick.h
 *
 *  Created on: Apr 18, 2014
 *      Author: kevin
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "chip.h"

extern void disk_timerproc (void);
volatile uint32_t msTicks;
volatile uint32_t secondTicks;

/* Set up the systick timer for 1ms interrupts */
void init_SysTickTimer(void);

void __delay_ms(uint32_t ms);

void __delay_us(uint32_t us);

/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
/*----------------------------------------------------------------------------
  SysTick_Handler - called every time the SysTick tick occurs
 *--------------------------------------------------------------------------*/
void SysTick_Handler(void);


#endif /* SYSTICK_H_ */
