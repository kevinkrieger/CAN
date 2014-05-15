/* Written for the FATFS module
 * Author: Kevin Krieger
 * DATE: March 2012
 *
 * EP 495 BLADE instrument
 */

#ifndef _RTC_H
#define _RTC_H

#include "integer.h"

typedef struct {
	WORD	year;	/* 1..4095 */
	BYTE	month;	/* 1..12 */
	BYTE	mday;	/* 1.. 31 */
	BYTE	wday;	/* 1..7 */
	BYTE	hour;	/* 0..23 */
	BYTE	min;	/* 0..59 */
	BYTE	sec;	/* 0..59 */
} RTC;

DWORD get_fattime (void); /* User supplied gettime function for fat module */
int rtc_initialize (void);		/* Initialize RTC */
int rtc_gettime (RTC*);			/* Get time */
int rtc_settime (const RTC*);	/* Set time */

#endif
