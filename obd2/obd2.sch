EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:CircuitHub
LIBS:kevin
LIBS:obd2-cache
EELAYER 27 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 1 1
Title ""
Date "26 nov 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R3
U 1 1 5277322F
P 9550 6400
F 0 "R3" V 9630 6400 40  0000 C CNN
F 1 "60 Ohm" V 9557 6401 40  0000 C CNN
F 2 "~" V 9480 6400 30  0000 C CNN
F 3 "~" H 9550 6400 30  0000 C CNN
	1    9550 6400
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5277323C
P 9550 6900
F 0 "R4" V 9630 6900 40  0000 C CNN
F 1 "60 Ohm" V 9557 6901 40  0000 C CNN
F 2 "~" V 9480 6900 30  0000 C CNN
F 3 "~" H 9550 6900 30  0000 C CNN
	1    9550 6900
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR01
U 1 1 52773301
P 7500 6400
F 0 "#PWR01" H 7500 6490 20  0001 C CNN
F 1 "+5V" H 7500 6490 30  0000 C CNN
F 2 "" H 7500 6400 60  0000 C CNN
F 3 "" H 7500 6400 60  0000 C CNN
	1    7500 6400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5277331D
P 7550 7000
F 0 "#PWR02" H 7550 7000 30  0001 C CNN
F 1 "GND" H 7550 6930 30  0001 C CNN
F 2 "" H 7550 7000 60  0000 C CNN
F 3 "" H 7550 7000 60  0000 C CNN
	1    7550 7000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 52773433
P 7700 3300
F 0 "#PWR03" H 7700 3300 30  0001 C CNN
F 1 "GND" H 7700 3230 30  0001 C CNN
F 2 "" H 7700 3300 60  0000 C CNN
F 3 "" H 7700 3300 60  0000 C CNN
	1    7700 3300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 52773439
P 3900 3200
F 0 "#PWR04" H 3900 3200 30  0001 C CNN
F 1 "GND" H 3900 3130 30  0001 C CNN
F 2 "" H 3900 3200 60  0000 C CNN
F 3 "" H 3900 3200 60  0000 C CNN
	1    3900 3200
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR05
U 1 1 5277343F
P 7700 2800
F 0 "#PWR05" H 7700 2760 30  0001 C CNN
F 1 "+3.3V" H 7700 2910 30  0000 C CNN
F 2 "" H 7700 2800 60  0000 C CNN
F 3 "" H 7700 2800 60  0000 C CNN
	1    7700 2800
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR06
U 1 1 52773445
P 3900 2750
F 0 "#PWR06" H 3900 2710 30  0001 C CNN
F 1 "+3.3V" H 3900 2860 30  0000 C CNN
F 2 "" H 3900 2750 60  0000 C CNN
F 3 "" H 3900 2750 60  0000 C CNN
	1    3900 2750
	1    0    0    -1  
$EndComp
Text GLabel 7750 4600 2    60   Input ~ 0
SPI_MISO
Text GLabel 7750 4450 2    60   Output ~ 0
SPI_MOSI
Text GLabel 7750 4000 2    60   Output ~ 0
SPI_SCK
Text GLabel 9950 6150 2    60   BiDi ~ 0
CAN_H
Text GLabel 9950 7150 2    60   BiDi ~ 0
CAN_L
$Comp
L C C11
U 1 1 527739DD
P 10100 6650
F 0 "C11" V 10100 6750 40  0000 L CNN
F 1 "C" V 10106 6565 40  0000 L CNN
F 2 "~" H 10138 6500 30  0000 C CNN
F 3 "~" H 10100 6650 60  0000 C CNN
	1    10100 6650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR07
U 1 1 52773A2C
P 10300 6800
F 0 "#PWR07" H 10300 6800 30  0001 C CNN
F 1 "GND" H 10300 6730 30  0001 C CNN
F 2 "" H 10300 6800 60  0000 C CNN
F 3 "" H 10300 6800 60  0000 C CNN
	1    10300 6800
	1    0    0    -1  
$EndComp
Text GLabel 8950 5950 2    60   Input ~ 0
CAN_XCVR_RS
$Comp
L R R2
U 1 1 52773D91
P 9300 6650
F 0 "R2" V 9380 6650 40  0000 C CNN
F 1 "R" V 9307 6651 40  0000 C CNN
F 2 "~" V 9230 6650 30  0000 C CNN
F 3 "~" H 9300 6650 30  0000 C CNN
	1    9300 6650
	0    -1   -1   0   
$EndComp
$Comp
L 1449-LPC11C14FBD48/301, U4
U 1 1 527C4C0F
P 4450 2300
F 0 "U4" H 4450 2330 60  0000 L CNN
F 1 "1449-LPC11C14FBD48/301," H 4450 -230 60  0000 L CNN
F 2 "melissa/dintu" H 4450 2600 60  0001 L CNN
F 3 "https://circuithub.com/parts/NXP/LPC11C14FBD48%2F301%2C/documents" H 4450 2700 60  0001 L CNN
F 4 "1449" H 4450 2800 60  0001 L CNN "CircuitHubID"
F 5 "kevink/b60mm" H 4450 2900 60  0001 L CNN "symbolURN"
F 6 "5c5a581cd8c9607056e83d31ff6539373c9a1d95" H 4450 3000 60  0001 L CNN "symbolRevision"
F 7 "80f05cb86d9e67aacf426a027030eab4869b28e1" H 4450 3100 60  0001 L CNN "footprintRevision"
	1    4450 2300
	1    0    0    -1  
$EndComp
Text GLabel 7700 7200 0    60   Output ~ 0
CAN_RXD
Text GLabel 7700 6150 0    60   Input ~ 0
CAN_TXD
Text GLabel 3850 4150 0    60   Input ~ 0
CAN_RXD
Text GLabel 3850 4300 0    60   Output ~ 0
CAN_TXD
$Comp
L C C3
U 1 1 527C55F2
P 2650 1000
F 0 "C3" H 2650 1100 40  0000 L CNN
F 1 "0.1uF" H 2656 915 40  0000 L CNN
F 2 "~" H 2688 850 30  0000 C CNN
F 3 "~" H 2650 1000 60  0000 C CNN
	1    2650 1000
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 527C5601
P 800 1100
F 0 "C1" H 800 1200 40  0000 L CNN
F 1 "0.33uF" H 806 1015 40  0000 L CNN
F 2 "~" H 838 950 30  0000 C CNN
F 3 "~" H 800 1100 60  0000 C CNN
	1    800  1100
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 527C560E
P 3450 1000
F 0 "C6" H 3450 1100 40  0000 L CNN
F 1 "10uF" H 3456 915 40  0000 L CNN
F 2 "~" H 3488 850 30  0000 C CNN
F 3 "~" H 3450 1000 60  0000 C CNN
	1    3450 1000
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 527C5616
P 3900 2950
F 0 "C8" H 3900 3050 40  0000 L CNN
F 1 "0.1u" H 3906 2865 40  0000 L CNN
F 2 "~" H 3938 2800 30  0000 C CNN
F 3 "~" H 3900 2950 60  0000 C CNN
	1    3900 2950
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 527C561C
P 7700 3000
F 0 "C10" H 7700 3100 40  0000 L CNN
F 1 "0.1u" H 7706 2915 40  0000 L CNN
F 2 "~" H 7738 2850 30  0000 C CNN
F 3 "~" H 7700 3000 60  0000 C CNN
	1    7700 3000
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 527C5622
P 7350 6650
F 0 "C9" H 7350 6750 40  0000 L CNN
F 1 "0.1u" H 7356 6565 40  0000 L CNN
F 2 "~" H 7388 6500 30  0000 C CNN
F 3 "~" H 7350 6650 60  0000 C CNN
	1    7350 6650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 527C564C
P 2650 1350
F 0 "#PWR08" H 2650 1350 30  0001 C CNN
F 1 "GND" H 2650 1280 30  0001 C CNN
F 2 "" H 2650 1350 60  0000 C CNN
F 3 "" H 2650 1350 60  0000 C CNN
	1    2650 1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 527C5652
P 3050 1400
F 0 "#PWR09" H 3050 1400 30  0001 C CNN
F 1 "GND" H 3050 1330 30  0001 C CNN
F 2 "" H 3050 1400 60  0000 C CNN
F 3 "" H 3050 1400 60  0000 C CNN
	1    3050 1400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 527C5658
P 3450 1350
F 0 "#PWR010" H 3450 1350 30  0001 C CNN
F 1 "GND" H 3450 1280 30  0001 C CNN
F 2 "" H 3450 1350 60  0000 C CNN
F 3 "" H 3450 1350 60  0000 C CNN
	1    3450 1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 527C565E
P 800 1400
F 0 "#PWR011" H 800 1400 30  0001 C CNN
F 1 "GND" H 800 1330 30  0001 C CNN
F 2 "" H 800 1400 60  0000 C CNN
F 3 "" H 800 1400 60  0000 C CNN
	1    800  1400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 527C5666
P 1400 1400
F 0 "#PWR012" H 1400 1400 30  0001 C CNN
F 1 "GND" H 1400 1330 30  0001 C CNN
F 2 "" H 1400 1400 60  0000 C CNN
F 3 "" H 1400 1400 60  0000 C CNN
	1    1400 1400
	1    0    0    -1  
$EndComp
Text GLabel 2050 800  2    60   UnSpc ~ 0
+5V
Text GLabel 3650 800  2    60   UnSpc ~ 0
+3.3V
Text GLabel 2500 800  0    60   UnSpc ~ 0
+5V
Text GLabel 750  800  0    60   UnSpc ~ 0
VBAT
$Comp
L CRYSTAL X1
U 1 1 527C5E35
P 3300 2950
F 0 "X1" H 3300 3100 60  0000 C CNN
F 1 "20MHz" H 3300 2800 60  0000 C CNN
F 2 "~" H 3300 2950 60  0000 C CNN
F 3 "~" H 3300 2950 60  0000 C CNN
	1    3300 2950
	0    1    1    0   
$EndComp
$Comp
L C C5
U 1 1 527C5EBA
P 3100 3300
F 0 "C5" H 3100 3400 40  0000 L CNN
F 1 "39pF" H 3106 3215 40  0000 L CNN
F 2 "~" H 3138 3150 30  0000 C CNN
F 3 "~" H 3100 3300 60  0000 C CNN
	1    3100 3300
	0    -1   -1   0   
$EndComp
$Comp
L C C4
U 1 1 527C5EC0
P 3100 2600
F 0 "C4" H 3100 2700 40  0000 L CNN
F 1 "39pF" H 3106 2515 40  0000 L CNN
F 2 "~" H 3138 2450 30  0000 C CNN
F 3 "~" H 3100 2600 60  0000 C CNN
	1    3100 2600
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR013
U 1 1 527C5EC6
P 2900 2700
F 0 "#PWR013" H 2900 2700 30  0001 C CNN
F 1 "GND" H 2900 2630 30  0001 C CNN
F 2 "" H 2900 2700 60  0000 C CNN
F 3 "" H 2900 2700 60  0000 C CNN
	1    2900 2700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 527C5ECC
P 2900 3400
F 0 "#PWR014" H 2900 3400 30  0001 C CNN
F 1 "GND" H 2900 3330 30  0001 C CNN
F 2 "" H 2900 3400 60  0000 C CNN
F 3 "" H 2900 3400 60  0000 C CNN
	1    2900 3400
	1    0    0    -1  
$EndComp
Text Notes 3650 7950 0    60   ~ 0
XTAL required if C_CAN baud rates above 100kbit/s used
$Comp
L MICRO_SD J2
U 1 1 527C6FD2
P 4300 7000
F 0 "J2" H 4250 6500 60  0000 C CNN
F 1 "MICRO_SD" H 4300 7500 60  0000 C CNN
F 2 "" H 4300 7500 60  0000 C CNN
F 3 "" H 4300 7500 60  0000 C CNN
	1    4300 7000
	1    0    0    -1  
$EndComp
$Comp
L LCD16X2 LCD1
U 1 1 527C7949
P 10100 1850
F 0 "LCD1" H 10750 2150 60  0000 C CNN
F 1 "LCD16X2" H 9500 2150 60  0000 C CNN
F 2 "" H 9500 2150 60  0000 C CNN
F 3 "" H 9500 2150 60  0000 C CNN
	1    10100 1850
	0    1    1    0   
$EndComp
$Comp
L SCREW_4-40 MP1
U 1 1 52893DF5
P 700 7750
F 0 "MP1" H 709 7582 60  0000 C CNN
F 1 "SCREW_4-40" H 701 7911 60  0001 C CNN
F 2 "~" H 700 7750 60  0000 C CNN
F 3 "~" H 700 7750 60  0000 C CNN
	1    700  7750
	1    0    0    -1  
$EndComp
$Comp
L SCREW_4-40 MP2
U 1 1 52893E02
P 1000 7750
F 0 "MP2" H 1009 7582 60  0000 C CNN
F 1 "SCREW_4-40" H 1001 7911 60  0001 C CNN
F 2 "~" H 1000 7750 60  0000 C CNN
F 3 "~" H 1000 7750 60  0000 C CNN
	1    1000 7750
	1    0    0    -1  
$EndComp
$Comp
L SCREW_4-40 MP3
U 1 1 52893E08
P 1300 7750
F 0 "MP3" H 1309 7582 60  0000 C CNN
F 1 "SCREW_4-40" H 1301 7911 60  0001 C CNN
F 2 "~" H 1300 7750 60  0000 C CNN
F 3 "~" H 1300 7750 60  0000 C CNN
	1    1300 7750
	1    0    0    -1  
$EndComp
$Comp
L SCREW_4-40 MP4
U 1 1 52893E0E
P 1600 7750
F 0 "MP4" H 1609 7582 60  0000 C CNN
F 1 "SCREW_4-40" H 1601 7911 60  0001 C CNN
F 2 "~" H 1600 7750 60  0000 C CNN
F 3 "~" H 1600 7750 60  0000 C CNN
	1    1600 7750
	1    0    0    -1  
$EndComp
Text GLabel 7750 4300 2    60   Input ~ 0
SWCLK
Text GLabel 7750 3350 2    60   BiDi ~ 0
SWDIO
Text GLabel 3900 2300 0    60   Input ~ 0
~RESET
Text GLabel 3850 3450 0    60   Output ~ 0
SPI_SSEL
$Comp
L LED D1
U 1 1 52894BCC
P 4100 1350
F 0 "D1" H 4100 1450 50  0000 C CNN
F 1 "3V3_ON" H 4100 1250 50  0000 C CNN
F 2 "~" H 4100 1350 60  0000 C CNN
F 3 "~" H 4100 1350 60  0000 C CNN
	1    4100 1350
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 52894BFF
P 4100 900
F 0 "R1" V 4180 900 40  0000 C CNN
F 1 "330R" V 4107 901 40  0000 C CNN
F 2 "~" V 4030 900 30  0000 C CNN
F 3 "~" H 4100 900 30  0000 C CNN
	1    4100 900 
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR015
U 1 1 52894C16
P 4100 650
F 0 "#PWR015" H 4100 610 30  0001 C CNN
F 1 "+3.3V" H 4100 760 30  0000 C CNN
F 2 "" H 4100 650 60  0000 C CNN
F 3 "" H 4100 650 60  0000 C CNN
	1    4100 650 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 52894C6B
P 4100 1600
F 0 "#PWR016" H 4100 1600 30  0001 C CNN
F 1 "GND" H 4100 1530 30  0001 C CNN
F 2 "" H 4100 1600 60  0000 C CNN
F 3 "" H 4100 1600 60  0000 C CNN
	1    4100 1600
	1    0    0    -1  
$EndComp
Text GLabel 7600 2450 2    60   Output ~ 0
UART_TXD
Text GLabel 7600 2600 2    60   Input ~ 0
UART_RXD
Text Notes 600  7550 0    60   ~ 0
Mounting holes 4-40 hardware
NoConn ~ 3700 7350
NoConn ~ 3700 6650
Text GLabel 3300 6750 0    60   Output ~ 0
SPI_MISO
Text GLabel 3300 6950 0    60   Input ~ 0
SPI_SCK
$Comp
L +3.3V #PWR017
U 1 1 528955FF
P 3550 6250
F 0 "#PWR017" H 3550 6210 30  0001 C CNN
F 1 "+3.3V" H 3550 6360 30  0000 C CNN
F 2 "" H 3550 6250 60  0000 C CNN
F 3 "" H 3550 6250 60  0000 C CNN
	1    3550 6250
	1    0    0    -1  
$EndComp
Text GLabel 3300 7150 0    60   Input ~ 0
SPI_MOSI
Text GLabel 3300 7300 0    60   Input ~ 0
SPI_SSEL
Text GLabel 5450 6950 2    60   Output ~ 0
CARD_DETECT
Text GLabel 7750 4750 2    60   Input ~ 0
CARD_DETECT
$Comp
L GND #PWR018
U 1 1 52897DF3
P 3550 6650
F 0 "#PWR018" H 3550 6650 30  0001 C CNN
F 1 "GND" H 3550 6580 30  0001 C CNN
F 2 "" H 3550 6650 60  0000 C CNN
F 3 "" H 3550 6650 60  0000 C CNN
	1    3550 6650
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 52897F9C
P 3550 6450
F 0 "C7" H 3550 6550 40  0000 L CNN
F 1 "0.1u" H 3556 6365 40  0000 L CNN
F 2 "~" H 3588 6300 30  0000 C CNN
F 3 "~" H 3550 6450 60  0000 C CNN
	1    3550 6450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 52898323
P 5250 7200
F 0 "#PWR019" H 5250 7200 30  0001 C CNN
F 1 "GND" H 5250 7130 30  0001 C CNN
F 2 "" H 5250 7200 60  0000 C CNN
F 3 "" H 5250 7200 60  0000 C CNN
	1    5250 7200
	1    0    0    -1  
$EndComp
$Comp
L LD1117 U3
U 1 1 528A9D75
P 3050 800
F 0 "U3" H 3100 550 60  0000 C CNN
F 1 "LD1117" H 3050 1000 60  0000 C CNN
F 2 "" H 3050 800 60  0000 C CNN
F 3 "" H 3050 800 60  0000 C CNN
	1    3050 800 
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 528A9D9B
P 2000 1150
F 0 "C2" H 2000 1250 40  0000 L CNN
F 1 "0.1uF" H 2006 1065 40  0000 L CNN
F 2 "~" H 2038 1000 30  0000 C CNN
F 3 "~" H 2000 1150 60  0000 C CNN
	1    2000 1150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 528A9DA1
P 2000 1450
F 0 "#PWR020" H 2000 1450 30  0001 C CNN
F 1 "GND" H 2000 1380 30  0001 C CNN
F 2 "" H 2000 1450 60  0000 C CNN
F 3 "" H 2000 1450 60  0000 C CNN
	1    2000 1450
	1    0    0    -1  
$EndComp
$Comp
L SP7805 U1
U 1 1 528AC0E9
P 1400 800
F 0 "U1" H 1600 550 60  0000 C CNN
F 1 "SP7805" H 1300 1000 60  0000 C CNN
F 2 "~" H 1400 750 60  0000 C CNN
F 3 "~" H 1400 750 60  0000 C CNN
	1    1400 800 
	1    0    0    -1  
$EndComp
$Comp
L MCP2561 U5
U 1 1 528C43C5
P 8200 6650
F 0 "U5" H 7900 6930 60  0000 L CNN
F 1 "MCP2561" H 8100 6350 60  0000 L CNN
F 2 "" H 7250 7200 60  0001 L CNN
F 3 "" H 7250 7300 60  0001 L CNN
	1    8200 6650
	1    0    0    -1  
$EndComp
$Comp
L CONN_5X2 P1
U 1 1 528C462E
P 9500 3150
F 0 "P1" H 9500 3450 60  0000 C CNN
F 1 "JTAG_PROG" V 9500 3150 50  0000 C CNN
F 2 "" H 9500 3150 60  0000 C CNN
F 3 "" H 9500 3150 60  0000 C CNN
	1    9500 3150
	-1   0    0    1   
$EndComp
$Comp
L SW_OFF_MOM SW1
U 1 1 528C4789
P 1100 2400
F 0 "SW1" H 1250 2510 50  0000 C CNN
F 1 "SW_OFF_MOM" H 1100 2320 50  0000 C CNN
F 2 "~" H 1100 2400 60  0000 C CNN
F 3 "~" H 1100 2400 60  0000 C CNN
	1    1100 2400
	1    0    0    -1  
$EndComp
$Comp
L SW_OFF_MOM SW2
U 1 1 528C4796
P 1100 3150
F 0 "SW2" H 1250 3260 50  0000 C CNN
F 1 "SW_OFF_MOM" H 1100 3070 50  0000 C CNN
F 2 "~" H 1100 3150 60  0000 C CNN
F 3 "~" H 1100 3150 60  0000 C CNN
	1    1100 3150
	1    0    0    -1  
$EndComp
$Comp
L SW_OFF_MOM SW3
U 1 1 528C479C
P 1100 3850
F 0 "SW3" H 1250 3960 50  0000 C CNN
F 1 "SW_OFF_MOM" H 1100 3770 50  0000 C CNN
F 2 "~" H 1100 3850 60  0000 C CNN
F 3 "~" H 1100 3850 60  0000 C CNN
	1    1100 3850
	1    0    0    -1  
$EndComp
$Comp
L RJ45_BASIC J1
U 1 1 528C4997
P 1200 4700
F 0 "J1" H 1400 5200 60  0000 C CNN
F 1 "RJ45_BASIC" H 1050 5200 60  0000 C CNN
F 2 "" H 1200 4700 60  0000 C CNN
F 3 "" H 1200 4700 60  0000 C CNN
	1    1200 4700
	0    -1   -1   0   
$EndComp
$Comp
L R R6
U 1 1 5290395B
P 1400 2150
F 0 "R6" V 1480 2150 40  0000 C CNN
F 1 "10k" V 1407 2151 40  0000 C CNN
F 2 "~" V 1330 2150 30  0000 C CNN
F 3 "~" H 1400 2150 30  0000 C CNN
	1    1400 2150
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5290397B
P 1400 2900
F 0 "R7" V 1480 2900 40  0000 C CNN
F 1 "10k" V 1407 2901 40  0000 C CNN
F 2 "~" V 1330 2900 30  0000 C CNN
F 3 "~" H 1400 2900 30  0000 C CNN
	1    1400 2900
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 52903981
P 1400 3600
F 0 "R8" V 1480 3600 40  0000 C CNN
F 1 "10k" V 1407 3601 40  0000 C CNN
F 2 "~" V 1330 3600 30  0000 C CNN
F 3 "~" H 1400 3600 30  0000 C CNN
	1    1400 3600
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR021
U 1 1 529039A8
P 1400 3350
F 0 "#PWR021" H 1400 3310 30  0001 C CNN
F 1 "+3.3V" H 1400 3460 30  0000 C CNN
F 2 "" H 1400 3350 60  0000 C CNN
F 3 "" H 1400 3350 60  0000 C CNN
	1    1400 3350
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR022
U 1 1 529039AE
P 1400 2650
F 0 "#PWR022" H 1400 2610 30  0001 C CNN
F 1 "+3.3V" H 1400 2760 30  0000 C CNN
F 2 "" H 1400 2650 60  0000 C CNN
F 3 "" H 1400 2650 60  0000 C CNN
	1    1400 2650
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR023
U 1 1 529039B4
P 1400 1900
F 0 "#PWR023" H 1400 1860 30  0001 C CNN
F 1 "+3.3V" H 1400 2010 30  0000 C CNN
F 2 "" H 1400 1900 60  0000 C CNN
F 3 "" H 1400 1900 60  0000 C CNN
	1    1400 1900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 529039BA
P 800 3900
F 0 "#PWR024" H 800 3900 30  0001 C CNN
F 1 "GND" H 800 3830 30  0001 C CNN
F 2 "" H 800 3900 60  0000 C CNN
F 3 "" H 800 3900 60  0000 C CNN
	1    800  3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 529039C0
P 800 3200
F 0 "#PWR025" H 800 3200 30  0001 C CNN
F 1 "GND" H 800 3130 30  0001 C CNN
F 2 "" H 800 3200 60  0000 C CNN
F 3 "" H 800 3200 60  0000 C CNN
	1    800  3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR026
U 1 1 529039C6
P 800 2450
F 0 "#PWR026" H 800 2450 30  0001 C CNN
F 1 "GND" H 800 2380 30  0001 C CNN
F 2 "" H 800 2450 60  0000 C CNN
F 3 "" H 800 2450 60  0000 C CNN
	1    800  2450
	1    0    0    -1  
$EndComp
Text GLabel 1750 2400 2    60   Input ~ 0
Button1
Text GLabel 1750 3150 2    60   Input ~ 0
Button2
Text GLabel 1750 3850 2    60   Input ~ 0
Button3
$Comp
L +3.3V #PWR027
U 1 1 529041ED
P 4300 650
F 0 "#PWR027" H 4300 610 30  0001 C CNN
F 1 "+3.3V" H 4300 760 30  0000 C CNN
F 2 "" H 4300 650 60  0000 C CNN
F 3 "" H 4300 650 60  0000 C CNN
	1    4300 650 
	1    0    0    -1  
$EndComp
Text GLabel 4400 700  2    60   UnSpc ~ 0
+3.3V
$Comp
L +3.3V #PWR028
U 1 1 52904666
P 10050 3350
F 0 "#PWR028" H 10050 3310 30  0001 C CNN
F 1 "+3.3V" H 10050 3460 30  0000 C CNN
F 2 "" H 10050 3350 60  0000 C CNN
F 3 "" H 10050 3350 60  0000 C CNN
	1    10050 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR029
U 1 1 529046EA
P 10250 3350
F 0 "#PWR029" H 10250 3350 30  0001 C CNN
F 1 "GND" H 10250 3280 30  0001 C CNN
F 2 "" H 10250 3350 60  0000 C CNN
F 3 "" H 10250 3350 60  0000 C CNN
	1    10250 3350
	1    0    0    -1  
$EndComp
Text GLabel 9050 2950 0    60   Output ~ 0
~RESET
NoConn ~ 9900 3050
NoConn ~ 9100 3050
NoConn ~ 9100 3150
Text GLabel 9050 3250 0    60   Output ~ 0
SWCLK
Text GLabel 9050 3400 0    60   BiDi ~ 0
SWDIO
Text GLabel 1700 4300 2    60   BiDi ~ 0
CAN_H
Text GLabel 1700 4450 2    60   BiDi ~ 0
CAN_L
$Comp
L GND #PWR030
U 1 1 52904D09
P 1700 5100
F 0 "#PWR030" H 1700 5100 30  0001 C CNN
F 1 "GND" H 1700 5030 30  0001 C CNN
F 2 "" H 1700 5100 60  0000 C CNN
F 3 "" H 1700 5100 60  0000 C CNN
	1    1700 5100
	1    0    0    -1  
$EndComp
Text GLabel 1700 4950 2    60   UnSpc ~ 0
VBAT
Text GLabel 900  6250 2    60   UnSpc ~ 0
+5V
$Comp
L R R5
U 1 1 52905116
P 850 6550
F 0 "R5" V 930 6550 40  0000 C CNN
F 1 "4k7" V 857 6551 40  0000 C CNN
F 2 "~" V 780 6550 30  0000 C CNN
F 3 "~" H 850 6550 30  0000 C CNN
	1    850  6550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR031
U 1 1 529051C1
P 850 7250
F 0 "#PWR031" H 850 7250 30  0001 C CNN
F 1 "GND" H 850 7180 30  0001 C CNN
F 2 "" H 850 7250 60  0000 C CNN
F 3 "" H 850 7250 60  0000 C CNN
	1    850  7250
	1    0    0    -1  
$EndComp
$Comp
L LM335 U2
U 1 1 5290554D
P 850 6950
F 0 "U2" H 950 6750 60  0000 C CNN
F 1 "LM335" H 850 7100 60  0000 C CNN
F 2 "" H 850 6950 60  0000 C CNN
F 3 "" H 850 6950 60  0000 C CNN
	1    850  6950
	1    0    0    -1  
$EndComp
NoConn ~ 1000 7050
Text GLabel 1050 6850 2    60   Output ~ 0
TEMP
Text GLabel 7750 4150 2    60   Input ~ 0
TEMP
Text GLabel 3850 4900 0    60   Input ~ 0
Button3
Text GLabel 3850 4450 0    60   Input ~ 0
Button2
Text GLabel 3800 4000 0    60   Input ~ 0
Button1
$Comp
L TEST W1
U 1 1 52927B55
P 5250 650
F 0 "W1" H 5250 710 40  0000 C CNN
F 1 "VBAT_T" H 5250 580 40  0000 C CNN
F 2 "" H 5250 650 60  0000 C CNN
F 3 "" H 5250 650 60  0000 C CNN
	1    5250 650 
	1    0    0    -1  
$EndComp
$Comp
L TEST W2
U 1 1 52927C07
P 5250 850
F 0 "W2" H 5250 910 40  0000 C CNN
F 1 "5V_T" H 5250 780 40  0000 C CNN
F 2 "" H 5250 850 60  0000 C CNN
F 3 "" H 5250 850 60  0000 C CNN
	1    5250 850 
	1    0    0    -1  
$EndComp
$Comp
L TEST W3
U 1 1 52927C17
P 5250 1050
F 0 "W3" H 5250 1110 40  0000 C CNN
F 1 "3V3_T" H 5250 980 40  0000 C CNN
F 2 "" H 5250 1050 60  0000 C CNN
F 3 "" H 5250 1050 60  0000 C CNN
	1    5250 1050
	1    0    0    -1  
$EndComp
Text GLabel 9350 2050 0    60   Input ~ 0
LCD_DB4
Text GLabel 9350 2200 0    60   Input ~ 0
LCD_DB5
Text GLabel 9350 2350 0    60   Input ~ 0
LCD_DB6
Text GLabel 9350 2500 0    60   Input ~ 0
LCD_DB7
Text GLabel 9400 1550 0    60   Input ~ 0
LCD_RW
Text GLabel 9400 1700 0    60   Input ~ 0
LCD_E
Text GLabel 9400 1400 0    60   Input ~ 0
LCD_RS
NoConn ~ 9800 1700
NoConn ~ 9800 1800
NoConn ~ 9800 1900
NoConn ~ 9800 2000
$Comp
L JUMPER3 JP1
U 1 1 5294324A
P 9600 900
F 0 "JP1" H 9650 800 40  0000 L CNN
F 1 "LCD_V_SELECT" H 9600 1000 40  0000 C CNN
F 2 "~" H 9600 900 60  0000 C CNN
F 3 "~" H 9600 900 60  0000 C CNN
	1    9600 900 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR032
U 1 1 52943266
P 9700 1150
F 0 "#PWR032" H 9700 1150 30  0001 C CNN
F 1 "GND" H 9700 1080 30  0001 C CNN
F 2 "" H 9700 1150 60  0000 C CNN
F 3 "" H 9700 1150 60  0000 C CNN
	1    9700 1150
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR033
U 1 1 52943851
P 9250 900
F 0 "#PWR033" H 9250 860 30  0001 C CNN
F 1 "+3.3V" H 9250 1010 30  0000 C CNN
F 2 "" H 9250 900 60  0000 C CNN
F 3 "" H 9250 900 60  0000 C CNN
	1    9250 900 
	1    0    0    -1  
$EndComp
Text GLabel 9900 900  2    60   UnSpc ~ 0
+5V
$Comp
L +3.3V #PWR034
U 1 1 52943F22
P 5000 1050
F 0 "#PWR034" H 5000 1010 30  0001 C CNN
F 1 "+3.3V" H 5000 1160 30  0000 C CNN
F 2 "" H 5000 1050 60  0000 C CNN
F 3 "" H 5000 1050 60  0000 C CNN
	1    5000 1050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR035
U 1 1 52943FE7
P 5450 1100
F 0 "#PWR035" H 5450 1100 30  0001 C CNN
F 1 "GND" H 5450 1030 30  0001 C CNN
F 2 "" H 5450 1100 60  0000 C CNN
F 3 "" H 5450 1100 60  0000 C CNN
	1    5450 1100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR036
U 1 1 529440A3
P 5450 900
F 0 "#PWR036" H 5450 900 30  0001 C CNN
F 1 "GND" H 5450 830 30  0001 C CNN
F 2 "" H 5450 900 60  0000 C CNN
F 3 "" H 5450 900 60  0000 C CNN
	1    5450 900 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR037
U 1 1 52944160
P 5450 700
F 0 "#PWR037" H 5450 700 30  0001 C CNN
F 1 "GND" H 5450 630 30  0001 C CNN
F 2 "" H 5450 700 60  0000 C CNN
F 3 "" H 5450 700 60  0000 C CNN
	1    5450 700 
	1    0    0    -1  
$EndComp
Text GLabel 5000 850  0    60   UnSpc ~ 0
+5V
Text GLabel 5000 650  0    60   UnSpc ~ 0
VBAT
Text GLabel 7750 3650 2    60   Output ~ 0
LCD_DB4
Text GLabel 7750 3500 2    60   Output ~ 0
LCD_DB5
Text GLabel 7900 2900 2    60   Output ~ 0
LCD_DB6
Text GLabel 7600 2300 2    60   Output ~ 0
LCD_DB7
Text GLabel 8250 3700 2    60   Input ~ 0
LCD_E
Text GLabel 8250 3850 2    60   Input ~ 0
LCD_RW
Text GLabel 8250 4000 2    60   Input ~ 0
LCD_RS
Wire Wire Line
	8700 6700 9100 6700
Wire Wire Line
	9100 6700 9100 7150
Wire Wire Line
	9100 7150 9950 7150
Wire Wire Line
	8700 6600 9100 6600
Wire Wire Line
	9100 6600 9100 6150
Wire Wire Line
	7500 6400 7500 6700
Wire Wire Line
	7500 6700 7700 6700
Wire Wire Line
	7700 6600 7550 6600
Wire Wire Line
	7550 6600 7550 7000
Wire Wire Line
	7350 2800 7700 2800
Wire Wire Line
	7350 3100 7500 3100
Connection ~ 9550 7150
Wire Wire Line
	9550 6650 9900 6650
Wire Wire Line
	10300 6650 10300 6800
Wire Wire Line
	8700 6500 8700 5950
Wire Wire Line
	8700 5950 8950 5950
Wire Wire Line
	9100 6150 9950 6150
Connection ~ 9550 6150
Wire Wire Line
	9050 6650 8900 6650
Wire Wire Line
	8900 6650 8900 6800
Wire Wire Line
	8900 6800 8700 6800
Connection ~ 9550 6650
Wire Wire Line
	4050 2800 4250 2800
Wire Wire Line
	7700 7200 7700 6800
Wire Wire Line
	7700 6150 7700 6500
Wire Wire Line
	3850 4150 4150 4150
Wire Wire Line
	4150 4150 4150 4200
Wire Wire Line
	4150 4200 4250 4200
Wire Wire Line
	3850 4300 4250 4300
Wire Wire Line
	7350 6850 7550 6850
Connection ~ 7550 6850
Wire Wire Line
	7350 6450 7500 6450
Connection ~ 7500 6450
Wire Wire Line
	2650 1200 2650 1350
Wire Wire Line
	3050 1400 3050 1200
Wire Wire Line
	3450 1200 3450 1350
Wire Wire Line
	3650 800  3450 800 
Wire Wire Line
	2500 800  2650 800 
Wire Wire Line
	7500 3100 7500 3200
Wire Wire Line
	7500 3200 7700 3200
Wire Wire Line
	7700 3200 7700 3300
Wire Wire Line
	4250 3100 4100 3100
Wire Wire Line
	4100 3100 4100 2750
Wire Wire Line
	4100 2750 3900 2750
Wire Wire Line
	4050 2800 4050 3150
Wire Wire Line
	4050 3150 3900 3150
Wire Wire Line
	3900 3150 3900 3200
Wire Wire Line
	4250 2900 4150 2900
Wire Wire Line
	4150 2900 4150 2600
Wire Wire Line
	4150 2600 3300 2600
Wire Wire Line
	3300 2600 3300 2650
Wire Wire Line
	4250 3000 4150 3000
Wire Wire Line
	4150 3000 4150 3300
Wire Wire Line
	4150 3300 3300 3300
Wire Wire Line
	3300 3300 3300 3250
Wire Wire Line
	2900 3400 2900 3300
Wire Wire Line
	2900 2700 2900 2600
Wire Wire Line
	7750 3350 7600 3350
Wire Wire Line
	7600 3300 7350 3300
Wire Wire Line
	7750 4300 7350 4300
Wire Wire Line
	3900 2300 4200 2300
Wire Wire Line
	4200 2300 4200 2600
Wire Wire Line
	4200 2600 4250 2600
Wire Wire Line
	7350 4400 7700 4400
Wire Wire Line
	7700 4400 7700 4450
Wire Wire Line
	7700 4450 7750 4450
Wire Wire Line
	7750 4600 7650 4600
Wire Wire Line
	7650 4600 7650 4500
Wire Wire Line
	7650 4500 7350 4500
Wire Wire Line
	3850 3450 4200 3450
Wire Wire Line
	4200 3450 4200 3300
Wire Wire Line
	4200 3300 4250 3300
Wire Wire Line
	4100 1600 4100 1550
Wire Wire Line
	7600 2450 7500 2450
Wire Wire Line
	7500 2450 7500 2500
Wire Wire Line
	7500 2500 7350 2500
Wire Wire Line
	7600 2600 7350 2600
Wire Notes Line
	6900 5700 10450 5700
Wire Notes Line
	10450 7300 6900 7300
Wire Notes Line
	6900 7300 6900 5700
Wire Notes Line
	10450 5700 10450 7300
Wire Wire Line
	3650 6850 3700 6850
Wire Wire Line
	3400 7050 3700 7050
Wire Wire Line
	7750 4750 7350 4750
Wire Wire Line
	7350 4750 7350 4700
Wire Wire Line
	3700 6750 3300 6750
Wire Wire Line
	3300 6950 3700 6950
Wire Wire Line
	3700 7150 3300 7150
Wire Wire Line
	3300 7300 3650 7300
Wire Wire Line
	3650 7300 3650 7250
Wire Wire Line
	3650 7250 3700 7250
Wire Wire Line
	3650 6850 3650 6600
Wire Wire Line
	3650 6600 3550 6600
Wire Wire Line
	3550 6600 3550 6650
Wire Wire Line
	3400 7050 3400 6250
Wire Wire Line
	3400 6250 3550 6250
Wire Wire Line
	5250 7150 5100 7150
Wire Wire Line
	5250 6650 5250 7200
Wire Wire Line
	5100 7050 5250 7050
Connection ~ 5250 7150
Wire Wire Line
	5100 6650 5250 6650
Connection ~ 5250 7050
Wire Wire Line
	5100 6750 5250 6750
Connection ~ 5250 6750
Wire Wire Line
	5100 6950 5450 6950
Wire Wire Line
	5100 6850 5250 6850
Connection ~ 5250 6850
Wire Wire Line
	800  1400 800  1300
Wire Wire Line
	750  800  800  800 
Wire Wire Line
	800  800  800  900 
Connection ~ 800  800 
Wire Wire Line
	1400 1300 1400 1400
Wire Wire Line
	2000 800  2050 800 
Wire Wire Line
	2000 950  2000 800 
Wire Wire Line
	2000 1350 2000 1450
Wire Wire Line
	800  2450 800  2400
Wire Wire Line
	800  3200 800  3150
Wire Wire Line
	800  3900 800  3850
Wire Wire Line
	1750 2400 1400 2400
Wire Wire Line
	1750 3150 1400 3150
Wire Wire Line
	1750 3850 1400 3850
Wire Wire Line
	4300 650  4300 700 
Wire Wire Line
	4300 700  4400 700 
Wire Wire Line
	9900 3350 10050 3350
Wire Wire Line
	10250 3250 9900 3250
Wire Wire Line
	10250 2950 10250 3350
Wire Wire Line
	9900 3150 10250 3150
Connection ~ 10250 3250
Wire Wire Line
	9900 2950 10250 2950
Connection ~ 10250 3150
Wire Wire Line
	9100 2950 9050 2950
Wire Wire Line
	9100 3250 9050 3250
Wire Wire Line
	9050 3400 9100 3400
Wire Wire Line
	9100 3400 9100 3350
Wire Wire Line
	1650 4350 1700 4350
Wire Wire Line
	1700 4350 1700 4300
Wire Wire Line
	1650 4450 1700 4450
Wire Wire Line
	1650 5050 1700 5050
Wire Wire Line
	1700 5050 1700 5100
Wire Wire Line
	1650 4950 1700 4950
Wire Wire Line
	900  6250 850  6250
Wire Wire Line
	850  6250 850  6300
Wire Wire Line
	850  6850 850  6800
Wire Wire Line
	850  7250 850  7200
Wire Wire Line
	1050 6850 850  6850
Wire Wire Line
	7750 4150 7700 4150
Wire Wire Line
	7700 4150 7700 4200
Wire Wire Line
	7700 4200 7350 4200
Wire Wire Line
	3850 4450 4250 4450
Wire Wire Line
	4250 4450 4250 4400
Wire Wire Line
	3850 4900 4250 4900
Wire Wire Line
	4250 4900 4250 4700
Wire Wire Line
	7350 4100 7650 4100
Wire Wire Line
	7650 4100 7650 4000
Wire Wire Line
	7650 4000 7750 4000
Wire Wire Line
	3800 4000 4150 4000
Wire Wire Line
	4150 4000 4150 4100
Wire Wire Line
	4150 4100 4250 4100
Wire Wire Line
	9400 1400 9800 1400
Wire Wire Line
	9400 1500 9800 1500
Wire Wire Line
	9400 1700 9400 1600
Wire Wire Line
	9400 1600 9800 1600
Wire Wire Line
	9350 2050 9400 2050
Wire Wire Line
	9400 2050 9400 2100
Wire Wire Line
	9400 2100 9800 2100
Wire Wire Line
	9350 2200 9800 2200
Wire Wire Line
	9350 2350 9350 2300
Wire Wire Line
	9350 2300 9800 2300
Wire Wire Line
	9350 2500 9400 2500
Wire Wire Line
	9400 2500 9400 2400
Wire Wire Line
	9400 2400 9800 2400
Wire Wire Line
	9700 1150 9700 1100
Wire Wire Line
	9700 1100 9800 1100
Wire Wire Line
	9600 1000 9600 1250
Wire Wire Line
	9800 1200 9800 1250
Wire Wire Line
	9800 1250 9600 1250
Wire Wire Line
	9400 1550 9400 1500
Wire Wire Line
	9850 900  9900 900 
Wire Wire Line
	9250 900  9350 900 
Wire Wire Line
	5000 1050 5050 1050
Wire Wire Line
	5450 1100 5450 1050
Wire Wire Line
	5450 900  5450 850 
Wire Wire Line
	5450 700  5450 650 
Wire Wire Line
	5000 850  5050 850 
Wire Wire Line
	5000 650  5050 650 
Wire Wire Line
	7350 2400 7450 2400
Wire Wire Line
	7450 2400 7450 2300
Wire Wire Line
	7450 2300 7600 2300
Wire Wire Line
	7750 3650 7450 3650
Wire Wire Line
	7450 3600 7350 3600
Wire Wire Line
	7350 3500 7750 3500
Wire Wire Line
	7900 2900 7350 2900
Wire Wire Line
	7600 3350 7600 3300
Wire Wire Line
	7450 3650 7450 3600
Wire Wire Line
	7350 3700 7350 3750
Wire Wire Line
	7350 3750 8250 3750
Wire Wire Line
	8250 3750 8250 3700
Wire Wire Line
	7350 3800 8250 3800
Wire Wire Line
	8250 3800 8250 3850
Wire Wire Line
	7350 3900 8200 3900
Wire Wire Line
	8200 3900 8200 4000
Wire Wire Line
	8200 4000 8250 4000
$EndSCHEMATC
