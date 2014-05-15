/*------------------------------------------------------------------------/
/  LPC1100 RTC control module
 * MODIFIED for EP 495 by Kevin Krieger - using LPC1343 - March 2012
 * Modified for CAN-obd2-v1 APril 2014.
/-------------------------------------------------------------------------/
/
/  Copyright (C) 2011, ChaN, all right reserved.
/
/ * This software is a free software and there is NO WARRANTY.
/ * No restriction on use. You can use, modify and redistribute it for
/   personal, non-profit or commercial products UNDER YOUR RESPONSIBILITY.
/ * Redistributions of source code must retain the above copyright notice.
/
/-------------------------------------------------------------------------*/

#include "chip.h"
#include "rtc.h"
#include "integer.h"

/*---------------------------------------------------------*/
/* User Provided RTC Function for FatFs module             */
/*---------------------------------------------------------*/
/* This is a real time clock service to be called from     */
/* FatFs module. Any valid time must be returned even if   */
/* the system does not support an RTC.                     */
/* This function is not required in read-only cfg.         */
DWORD get_fattime ()
{
	RTC rtc;

	/* Get local time */
	rtc_gettime(&rtc);

	/* Pack date and time into a DWORD variable */
	return	  ((DWORD)(rtc.year - 1980) << 25)
			| ((DWORD)rtc.month << 21)
			| ((DWORD)rtc.mday << 16)
			| ((DWORD)rtc.hour << 11)
			| ((DWORD)rtc.min << 5)
			| ((DWORD)rtc.sec >> 1);
}

int rtc_initialize (void)
{
	/*We have no hardware rtc, so just return 1
	 * This could be implemented later. A GPS module could
	 * provide the time, for example. */
	return 1;
}



int rtc_gettime (RTC *rtc)
{
	/* No RTC, so just put in a fun time :). This could be implemented
	 * later, by using a GPS module for example, or by purchasing a RTC
	 * and integrating it onto the BLADE electronics  */
	rtc->sec = 6;
	rtc->min = 9;
	rtc->hour = 9;
	rtc->wday = 0;
	rtc->mday = 29;
	rtc->month = 2;
	rtc->year = 2012;
	return 1;
	/*	DWORD d, t;*/
/*	do {
		t = CTIME0;
		d = CTIME1;
	} while (t != CTIME0 || d != CTIME1);

	if (RTC_AUX & _BV(4)) {
		rtc->sec = 0;
		rtc->min = 0;
		rtc->hour = 0;
		rtc->wday = 0;
		rtc->mday = 1;
		rtc->month = 1;
		rtc->year = 2011;
		return 0;
	}

	rtc->sec = t & 63;
	rtc->min = (t >> 8) & 63;
	rtc->hour = (t >> 16) & 31;
	rtc->wday = (t >> 24) & 7;
	rtc->mday = d & 31;
	rtc->month = (d >> 8) & 15;
	rtc->year = (d >> 16) & 4095;
	return 1;
*/
}




int rtc_settime (const RTC *rtc)
{
	/* Update RTC registers */
	/*SEC = rtc->sec;
	MIN = rtc->min;
	HOUR = rtc->hour;
	DOW = rtc->wday;
	DOM = rtc->mday;
	MONTH = rtc->month;
	YEAR = rtc->year;
*/
	/*RTC_AUX = _BV(4);	 Clear power fail flag */
	/*CCR = 0x11;			 Restart RTC, Disable calibration feature */

	return 1;
}


