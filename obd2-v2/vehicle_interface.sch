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
LIBS:kkrieger_logo
LIBS:obd2-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 7
Title ""
Date "11 aug 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L RJ45_BASIC J1
U 1 1 53E6EF49
P 1600 2750
F 0 "J1" H 1800 3250 60  0000 C CNN
F 1 "RJ45_BASIC" H 1450 3250 60  0000 C CNN
F 2 "RJ45" H 1600 2750 60  0000 C CNN
F 3 "" H 1600 2750 60  0000 C CNN
	1    1600 2750
	0    -1   -1   0   
$EndComp
Text GLabel 3050 3250 2    60   BiDi ~ 0
CAN_H
Text GLabel 3050 3050 2    60   BiDi ~ 0
CAN_L
Text Notes 1500 3950 0    60   ~ 0
OBD2 connection \nDLC - Diagnostic Link Connector in Honda Civic
Text Notes 1800 4150 0    60   ~ 0
1  2  3  4  5  6  7  8\n9 10 11 12 13 14 15 16
Text Notes 1500 4350 0    50   ~ 0
4 - Chassis Ground\n5 - Signal Ground\n6 - CAN high (J-2284)\n7 - K-LINE (ISO 9141-2 and ISO/DIS 14230-4)\n9 - SCS - (Service Check System - diagnostic codes)\n14 - CAN low\n15 - ISO 9141-2 L-Line (ISO 9141-2 and ISO/DIS 14230-4)\n16 - +12V unswitched
Text GLabel 3050 2650 2    60   BiDi ~ 0
K_LINE
Text GLabel 3050 2450 2    60   BiDi ~ 0
L_LINE
Text GLabel 3100 2850 2    60   BiDi ~ 0
SCS
Text GLabel 3100 2250 2    60   UnSpc ~ 0
VBAT
Wire Notes Line
	1550 4050 3200 4050
Wire Notes Line
	3200 4050 2950 4250
Wire Notes Line
	2950 4250 1800 4250
Wire Notes Line
	1800 4250 1550 4050
Wire Wire Line
	2050 2600 2850 2600
Wire Wire Line
	2050 2700 2900 2700
Wire Wire Line
	2050 2900 2200 2900
$Comp
L GND #PWR015
U 1 1 53E6EF8C
P 2200 3400
F 0 "#PWR015" H 2200 3400 30  0001 C CNN
F 1 "GND" H 2200 3330 30  0001 C CNN
F 2 "" H 2200 3400 60  0000 C CNN
F 3 "" H 2200 3400 60  0000 C CNN
	1    2200 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2400 2200 3400
$Comp
L R R4
U 1 1 53E6F1C8
P 8600 2200
F 0 "R4" V 8680 2200 40  0000 C CNN
F 1 "60R" V 8607 2201 40  0000 C CNN
F 2 "R3" V 8530 2200 30  0000 C CNN
F 3 "~" H 8600 2200 30  0000 C CNN
	1    8600 2200
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 53E6F1CE
P 8600 2700
F 0 "R5" V 8680 2700 40  0000 C CNN
F 1 "60R" V 8607 2701 40  0000 C CNN
F 2 "R3" V 8530 2700 30  0000 C CNN
F 3 "~" H 8600 2700 30  0000 C CNN
	1    8600 2700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR016
U 1 1 53E6F1D4
P 6550 2200
F 0 "#PWR016" H 6550 2290 20  0001 C CNN
F 1 "+5V" H 6550 2290 30  0000 C CNN
F 2 "" H 6550 2200 60  0000 C CNN
F 3 "" H 6550 2200 60  0000 C CNN
	1    6550 2200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 53E6F1DA
P 6600 2800
F 0 "#PWR017" H 6600 2800 30  0001 C CNN
F 1 "GND" H 6600 2730 30  0001 C CNN
F 2 "" H 6600 2800 60  0000 C CNN
F 3 "" H 6600 2800 60  0000 C CNN
	1    6600 2800
	1    0    0    -1  
$EndComp
Text GLabel 9000 1950 2    60   BiDi ~ 0
CAN_H
Text GLabel 9000 2950 2    60   BiDi ~ 0
CAN_L
$Comp
L C C6
U 1 1 53E6F1E2
P 9150 2450
F 0 "C6" V 9150 2550 40  0000 L CNN
F 1 "C" V 9156 2365 40  0000 L CNN
F 2 "c_0805" H 9188 2300 30  0000 C CNN
F 3 "~" H 9150 2450 60  0000 C CNN
	1    9150 2450
	0    1    1    0   
$EndComp
$Comp
L GND #PWR018
U 1 1 53E6F1E8
P 9350 2600
F 0 "#PWR018" H 9350 2600 30  0001 C CNN
F 1 "GND" H 9350 2530 30  0001 C CNN
F 2 "" H 9350 2600 60  0000 C CNN
F 3 "" H 9350 2600 60  0000 C CNN
	1    9350 2600
	1    0    0    -1  
$EndComp
Text GLabel 8000 1750 2    60   Input ~ 0
CAN_XCVR_RS
$Comp
L R R3
U 1 1 53E6F1EF
P 8350 2450
F 0 "R3" V 8430 2450 40  0000 C CNN
F 1 "R" V 8357 2451 40  0000 C CNN
F 2 "R3" V 8280 2450 30  0000 C CNN
F 3 "~" H 8350 2450 30  0000 C CNN
	1    8350 2450
	0    -1   -1   0   
$EndComp
Text GLabel 6750 3000 0    60   Output ~ 0
CAN_RXD
Text GLabel 6750 1950 0    60   Input ~ 0
CAN_TXD
$Comp
L C C5
U 1 1 53E6F1F7
P 6400 2450
F 0 "C5" H 6400 2550 40  0000 L CNN
F 1 "0.1u" H 6406 2365 40  0000 L CNN
F 2 "c_0805" H 6438 2300 30  0000 C CNN
F 3 "~" H 6400 2450 60  0000 C CNN
	1    6400 2450
	1    0    0    -1  
$EndComp
$Comp
L MCP2561 U3
U 1 1 53E6F1FD
P 7250 2450
F 0 "U3" H 6950 2730 60  0000 L CNN
F 1 "MCP2561" H 7150 2150 60  0000 L CNN
F 2 "SOIC-8-Narrow" H 6300 3000 60  0001 L CNN
F 3 "" H 6300 3100 60  0001 L CNN
	1    7250 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 2500 8150 2500
Wire Wire Line
	8150 2500 8150 2950
Wire Wire Line
	8150 2950 9000 2950
Wire Wire Line
	7750 2400 8150 2400
Wire Wire Line
	8150 2400 8150 1950
Wire Wire Line
	6550 2200 6550 2500
Wire Wire Line
	6550 2500 6750 2500
Wire Wire Line
	6750 2400 6600 2400
Wire Wire Line
	6600 2400 6600 2800
Connection ~ 8600 2950
Wire Wire Line
	8600 2450 8950 2450
Wire Wire Line
	9350 2450 9350 2600
Wire Wire Line
	7750 2300 7750 1750
Wire Wire Line
	7750 1750 8000 1750
Wire Wire Line
	8150 1950 9000 1950
Connection ~ 8600 1950
Wire Wire Line
	8100 2450 7950 2450
Wire Wire Line
	7950 2450 7950 2600
Wire Wire Line
	7950 2600 7750 2600
Connection ~ 8600 2450
Wire Wire Line
	6750 3000 6750 2600
Wire Wire Line
	6750 1950 6750 2300
Wire Wire Line
	6400 2650 6600 2650
Connection ~ 6600 2650
Wire Wire Line
	6400 2250 6550 2250
Connection ~ 6550 2250
Text Notes 6100 3250 0    60   ~ 0
60 Ohm termination resistors only populated if board is end of CAN bus
Wire Wire Line
	2050 2400 2200 2400
Connection ~ 2200 2900
Wire Wire Line
	2900 2700 2900 2650
Wire Wire Line
	2900 2650 3050 2650
Wire Wire Line
	2850 2600 2850 2450
Wire Wire Line
	2850 2450 3050 2450
Wire Wire Line
	2050 2500 2750 2500
Wire Wire Line
	2750 2500 2750 2250
Wire Wire Line
	2750 2250 3100 2250
Wire Wire Line
	3100 2850 3000 2850
Wire Wire Line
	3000 2850 3000 2800
Wire Wire Line
	3000 2800 2050 2800
Wire Wire Line
	2050 3000 2900 3000
Wire Wire Line
	2900 3000 2900 3050
Wire Wire Line
	2900 3050 3050 3050
Wire Wire Line
	2050 3100 2850 3100
Wire Wire Line
	2850 3100 2850 3250
Wire Wire Line
	2850 3250 3050 3250
$Comp
L MC33660 U4
U 1 1 53E78058
P 7500 4550
F 0 "U4" H 7450 4150 60  0000 C CNN
F 1 "MC33660" H 7350 4950 60  0000 C CNN
F 2 "" H 7500 4450 60  0000 C CNN
F 3 "" H 7500 4450 60  0000 C CNN
	1    7500 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 53E78065
P 6700 5050
F 0 "#PWR019" H 6700 5050 30  0001 C CNN
F 1 "GND" H 6700 4980 30  0001 C CNN
F 2 "" H 6700 5050 60  0000 C CNN
F 3 "" H 6700 5050 60  0000 C CNN
	1    6700 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 5050 6700 4650
Wire Wire Line
	6700 4650 6850 4650
Text GLabel 6050 4800 0    60   BiDi ~ 0
K_LINE
Wire Wire Line
	6050 4800 6850 4800
Text GLabel 6050 4350 0    60   UnSpc ~ 0
+12V
Wire Wire Line
	6050 4350 6850 4350
$Comp
L +5V #PWR020
U 1 1 53E7819B
P 8300 4100
F 0 "#PWR020" H 8300 4190 20  0001 C CNN
F 1 "+5V" H 8300 4190 30  0000 C CNN
F 2 "" H 8300 4100 60  0000 C CNN
F 3 "" H 8300 4100 60  0000 C CNN
	1    8300 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 4100 8300 4500
Wire Wire Line
	8300 4500 8150 4500
Text GLabel 9050 4650 2    60   Output ~ 0
K_LINE_RX
Text GLabel 9050 4800 2    60   Input ~ 0
K_LINE_TX
Wire Wire Line
	8150 4650 9050 4650
Wire Wire Line
	8150 4800 9050 4800
Text GLabel 9050 4350 2    60   Input ~ 0
K_LINE_EN
Wire Wire Line
	9050 4350 8150 4350
$Comp
L OPTO-TRANSISTOR4 U5
U 1 1 53E78B91
P 8100 6550
F 0 "U5" H 8300 6800 60  0000 C CNN
F 1 "LTV-816" H 8100 6300 60  0000 C CNN
F 2 "" H 8100 6550 60  0000 C CNN
F 3 "" H 8100 6550 60  0000 C CNN
	1    8100 6550
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 53E78BA0
P 7300 5950
F 0 "R2" V 7380 5950 40  0000 C CNN
F 1 "R" V 7307 5951 40  0000 C CNN
F 2 "~" V 7230 5950 30  0000 C CNN
F 3 "~" H 7300 5950 30  0000 C CNN
	1    7300 5950
	1    0    0    -1  
$EndComp
$Comp
L DIODE D3
U 1 1 53E78BAF
P 6800 6600
F 0 "D3" H 6800 6700 40  0000 C CNN
F 1 "1N4149" H 6800 6500 40  0000 C CNN
F 2 "~" H 6800 6600 60  0000 C CNN
F 3 "~" H 6800 6600 60  0000 C CNN
	1    6800 6600
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR021
U 1 1 53E78BBE
P 6800 6900
F 0 "#PWR021" H 6800 6900 30  0001 C CNN
F 1 "GND" H 6800 6830 30  0001 C CNN
F 2 "" H 6800 6900 60  0000 C CNN
F 3 "" H 6800 6900 60  0000 C CNN
	1    6800 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 6900 6800 6800
$Comp
L GND #PWR022
U 1 1 53E78C13
P 7300 6900
F 0 "#PWR022" H 7300 6900 30  0001 C CNN
F 1 "GND" H 7300 6830 30  0001 C CNN
F 2 "" H 7300 6900 60  0000 C CNN
F 3 "" H 7300 6900 60  0000 C CNN
	1    7300 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 6700 7300 6700
Wire Wire Line
	7300 6700 7300 6900
Wire Wire Line
	7300 6400 7450 6400
Wire Wire Line
	7300 6200 7300 6400
Wire Wire Line
	7300 5550 7300 5700
Wire Wire Line
	6800 5550 7300 5550
Wire Wire Line
	6800 6400 6800 6250
Wire Wire Line
	6800 6250 7300 6250
Connection ~ 7300 6250
Text GLabel 6800 5550 0    60   Input ~ 0
L_LINE_CONTROL
Text GLabel 8950 5550 2    60   UnSpc ~ 0
+12V
$Comp
L R R6
U 1 1 53E79041
P 8850 5950
F 0 "R6" V 8930 5950 40  0000 C CNN
F 1 "R" V 8857 5951 40  0000 C CNN
F 2 "~" V 8780 5950 30  0000 C CNN
F 3 "~" H 8850 5950 30  0000 C CNN
	1    8850 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 5550 8850 5550
Wire Wire Line
	8850 5550 8850 5700
Wire Wire Line
	8850 6400 8850 6200
Wire Wire Line
	8700 6400 8850 6400
$Comp
L GND #PWR023
U 1 1 53E790E5
P 8850 6900
F 0 "#PWR023" H 8850 6900 30  0001 C CNN
F 1 "GND" H 8850 6830 30  0001 C CNN
F 2 "" H 8850 6900 60  0000 C CNN
F 3 "" H 8850 6900 60  0000 C CNN
	1    8850 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 6700 8850 6700
Wire Wire Line
	8850 6700 8850 6900
Wire Wire Line
	8850 6250 9500 6250
Connection ~ 8850 6250
Text GLabel 9500 6250 2    60   Output ~ 0
L_LINE
Text Notes 3300 6000 0    60   ~ 0
L-line is unidirectional and used for initialization only. Optoisolation isolates\nthe vehicle's L-Line from the microcontroller. Diode protects optoisolator\nfrom reverse voltages. See\n"INITIALIZING COMMUNICATION TO VEHICLE OBDII SYSTEM"\nby Peter Dzhelekarski, Dimiter Alexiev
$EndSCHEMATC
