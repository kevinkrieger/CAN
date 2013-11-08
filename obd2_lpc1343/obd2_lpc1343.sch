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
LIBS:obd2-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "4 nov 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 389-MCP2515-I/ST U1
U 1 1 526DD841
P 6900 2300
F 0 "U1" H 6900 2330 60  0000 L CNN
F 1 "389-MCP2515-I/ST" H 6900 1170 60  0000 L CNN
F 2 "Plecharts/axxkb" H 6900 2600 60  0001 L CNN
F 3 "https://circuithub.com/parts/MICROCHIP/MCP2515-I%2FST/documents" H 6900 2700 60  0001 L CNN
F 4 "389" H 6900 2800 60  0001 L CNN "CircuitHubID"
F 5 "Plecharts/dibdy" H 6900 2900 60  0001 L CNN "symbolURN"
F 6 "e9496f50911a05a3985a913673c8533236c9a2d1" H 6900 3000 60  0001 L CNN "symbolRevision"
F 7 "028f70f0aec8d04754692d22800a5a283cb74d59" H 6900 3100 60  0001 L CNN "footprintRevision"
	1    6900 2300
	1    0    0    -1  
$EndComp
$Comp
L 1389-LPC1343FBD48,151 U3
U 1 1 526DE613
P 1300 1450
F 0 "U3" H 1300 1480 60  0000 L CNN
F 1 "1389-LPC1343FBD48,151" H 1300 -1080 60  0000 L CNN
F 2 "melissa/dintu" H 1300 1750 60  0001 L CNN
F 3 "https://circuithub.com/parts/NXP/LPC1343FBD48%2C151/documents" H 1300 1850 60  0001 L CNN
F 4 "1389" H 1300 1950 60  0001 L CNN "CircuitHubID"
F 5 "kevink/doa5f" H 1300 2050 60  0001 L CNN "symbolURN"
F 6 "56ccfccd48798171a0cd34034680f50893145aa8" H 1300 2150 60  0001 L CNN "symbolRevision"
F 7 "80f05cb86d9e67aacf426a027030eab4869b28e1" H 1300 2250 60  0001 L CNN "footprintRevision"
	1    1300 1450
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5277322F
P 8850 1350
F 0 "R?" V 8930 1350 40  0000 C CNN
F 1 "R" V 8857 1351 40  0000 C CNN
F 2 "~" V 8780 1350 30  0000 C CNN
F 3 "~" H 8850 1350 30  0000 C CNN
	1    8850 1350
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5277323C
P 8850 1850
F 0 "R?" V 8930 1850 40  0000 C CNN
F 1 "R" V 8857 1851 40  0000 C CNN
F 2 "~" V 8780 1850 30  0000 C CNN
F 3 "~" H 8850 1850 30  0000 C CNN
	1    8850 1850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 52773301
P 6800 1350
F 0 "#PWR?" H 6800 1440 20  0001 C CNN
F 1 "+5V" H 6800 1440 30  0000 C CNN
F 2 "" H 6800 1350 60  0000 C CNN
F 3 "" H 6800 1350 60  0000 C CNN
	1    6800 1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5277331D
P 6850 1950
F 0 "#PWR?" H 6850 1950 30  0001 C CNN
F 1 "GND" H 6850 1880 30  0001 C CNN
F 2 "" H 6850 1950 60  0000 C CNN
F 3 "" H 6850 1950 60  0000 C CNN
	1    6850 1950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 52773339
P 6550 3800
F 0 "#PWR?" H 6550 3800 30  0001 C CNN
F 1 "GND" H 6550 3730 30  0001 C CNN
F 2 "" H 6550 3800 60  0000 C CNN
F 3 "" H 6550 3800 60  0000 C CNN
	1    6550 3800
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 52773371
P 8450 2300
F 0 "#PWR?" H 8450 2260 30  0001 C CNN
F 1 "+3.3V" H 8450 2410 30  0000 C CNN
F 2 "" H 8450 2300 60  0000 C CNN
F 3 "" H 8450 2300 60  0000 C CNN
	1    8450 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 1450 6250 1450
Wire Wire Line
	6250 1450 6250 2400
Wire Wire Line
	6250 2400 6700 2400
Wire Wire Line
	7000 1750 6400 1750
Wire Wire Line
	6400 1750 6400 2500
Wire Wire Line
	6400 2500 6700 2500
Wire Wire Line
	8000 1650 8400 1650
Wire Wire Line
	8400 1650 8400 2100
Wire Wire Line
	8400 2100 9250 2100
Wire Wire Line
	8000 1550 8400 1550
Wire Wire Line
	8400 1550 8400 1100
Wire Wire Line
	6800 1350 6800 1650
Wire Wire Line
	6800 1650 7000 1650
Wire Wire Line
	7000 1550 6850 1550
Wire Wire Line
	6850 1550 6850 1950
Wire Wire Line
	8300 2400 8450 2400
Wire Wire Line
	8450 2400 8450 2300
Wire Wire Line
	6700 3300 6550 3300
Wire Wire Line
	6550 3300 6550 3800
$Comp
L R R?
U 1 1 527733B3
P 6400 3700
F 0 "R?" V 6480 3700 40  0000 C CNN
F 1 "R" V 6407 3701 40  0000 C CNN
F 2 "~" V 6330 3700 30  0000 C CNN
F 3 "~" H 6400 3700 30  0000 C CNN
	1    6400 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3100 6400 3450
$Comp
L GND #PWR?
U 1 1 527733CE
P 6400 3950
F 0 "#PWR?" H 6400 3950 30  0001 C CNN
F 1 "GND" H 6400 3880 30  0001 C CNN
F 2 "" H 6400 3950 60  0000 C CNN
F 3 "" H 6400 3950 60  0000 C CNN
	1    6400 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3950 6400 3800
Wire Wire Line
	6700 3100 6400 3100
$Comp
L GND #PWR?
U 1 1 52773433
P 5000 2350
F 0 "#PWR?" H 5000 2350 30  0001 C CNN
F 1 "GND" H 5000 2280 30  0001 C CNN
F 2 "" H 5000 2350 60  0000 C CNN
F 3 "" H 5000 2350 60  0000 C CNN
	1    5000 2350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 52773439
P 900 2000
F 0 "#PWR?" H 900 2000 30  0001 C CNN
F 1 "GND" H 900 1930 30  0001 C CNN
F 2 "" H 900 2000 60  0000 C CNN
F 3 "" H 900 2000 60  0000 C CNN
	1    900  2000
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 5277343F
P 5000 1900
F 0 "#PWR?" H 5000 1860 30  0001 C CNN
F 1 "+3.3V" H 5000 2010 30  0000 C CNN
F 2 "" H 5000 1900 60  0000 C CNN
F 3 "" H 5000 1900 60  0000 C CNN
	1    5000 1900
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 52773445
P 900 2250
F 0 "#PWR?" H 900 2210 30  0001 C CNN
F 1 "+3.3V" H 900 2360 30  0000 C CNN
F 2 "" H 900 2250 60  0000 C CNN
F 3 "" H 900 2250 60  0000 C CNN
	1    900  2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  2250 1100 2250
Wire Wire Line
	4800 1950 5000 1950
Wire Wire Line
	4800 2250 5000 2250
NoConn ~ 8200 2900
Text GLabel 9600 2600 2    60   Input ~ 0
CAN_CNTRL_CS!
Wire Wire Line
	8300 2600 9600 2600
Text GLabel 9600 2750 2    60   Input ~ 0
SPI_MISO
Text GLabel 9600 2900 2    60   Output ~ 0
SPI_MOSI
Wire Wire Line
	8300 2700 9500 2700
Wire Wire Line
	9500 2700 9500 2750
Wire Wire Line
	9500 2750 9600 2750
Wire Wire Line
	8300 2800 9450 2800
Wire Wire Line
	9450 2800 9450 2900
Wire Wire Line
	9450 2900 9600 2900
Text GLabel 9600 2450 2    60   Input ~ 0
CAN_CNTRL_RESET!
Text GLabel 9600 3050 2    60   Input ~ 0
SPI_SCK
Wire Wire Line
	9600 3050 9400 3050
Wire Wire Line
	9400 3050 9400 3000
Wire Wire Line
	9400 3000 8300 3000
Text GLabel 9600 3350 2    60   Output ~ 0
CAN_CNTRL_RX0!
Text GLabel 9600 3500 2    60   Output ~ 0
CAN_CNTRL_RX1!
Text GLabel 9600 3200 2    60   Output ~ 0
CAN_CNTRL_INT!
Wire Wire Line
	9600 3200 8750 3200
Wire Wire Line
	8750 3200 8750 3100
Wire Wire Line
	8750 3100 8300 3100
Wire Wire Line
	8300 3200 8700 3200
Wire Wire Line
	8700 3200 8700 3350
Wire Wire Line
	8700 3350 9600 3350
Wire Wire Line
	9600 3500 8600 3500
Wire Wire Line
	8600 3500 8600 3300
Wire Wire Line
	8600 3300 8300 3300
Wire Wire Line
	8300 2500 9450 2500
Wire Wire Line
	9450 2500 9450 2450
Wire Wire Line
	9450 2450 9600 2450
Text GLabel 9250 1100 2    60   BiDi ~ 0
CAN_H
Text GLabel 9250 2100 2    60   BiDi ~ 0
CAN_L
Connection ~ 8850 2100
$Comp
L C C?
U 1 1 527739DD
P 9400 1600
F 0 "C?" V 9400 1700 40  0000 L CNN
F 1 "C" V 9406 1515 40  0000 L CNN
F 2 "~" H 9438 1450 30  0000 C CNN
F 3 "~" H 9400 1600 60  0000 C CNN
	1    9400 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	8850 1600 9200 1600
$Comp
L GND #PWR?
U 1 1 52773A2C
P 9600 1750
F 0 "#PWR?" H 9600 1750 30  0001 C CNN
F 1 "GND" H 9600 1680 30  0001 C CNN
F 2 "" H 9600 1750 60  0000 C CNN
F 3 "" H 9600 1750 60  0000 C CNN
	1    9600 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 1600 9600 1750
Text GLabel 8250 900  2    60   Input ~ 0
CAN_XCVR_RS
$Comp
L 385-MCP2551-I/SN U2
U 1 1 526DD860
P 7200 1350
F 0 "U2" H 7200 1380 60  0000 L CNN
F 1 "385-MCP2551-I/SN" H 7200 820 60  0000 L CNN
F 2 "Plecharts/b6cyy" H 7200 1650 60  0001 L CNN
F 3 "https://circuithub.com/parts/MICROCHIP/MCP2551-I%2FSN/documents" H 7200 1750 60  0001 L CNN
F 4 "385" H 7200 1850 60  0001 L CNN "CircuitHubID"
F 5 "Plecharts/dnxnz" H 7200 1950 60  0001 L CNN "symbolURN"
F 6 "66bceff0599b42362f1b4cbba58621412a2c76b6" H 7200 2050 60  0001 L CNN "symbolRevision"
F 7 "9b1445d34c4b29c2b170047ceeef7d3549b64a82" H 7200 2150 60  0001 L CNN "footprintRevision"
	1    7200 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 1450 8000 900 
Wire Wire Line
	8000 900  8250 900 
Wire Wire Line
	8400 1100 9250 1100
Connection ~ 8850 1100
$Comp
L R R?
U 1 1 52773D91
P 8600 1600
F 0 "R?" V 8680 1600 40  0000 C CNN
F 1 "R" V 8607 1601 40  0000 C CNN
F 2 "~" V 8530 1600 30  0000 C CNN
F 3 "~" H 8600 1600 30  0000 C CNN
	1    8600 1600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8350 1600 8200 1600
Wire Wire Line
	8200 1600 8200 1750
Wire Wire Line
	8200 1750 8000 1750
Connection ~ 8850 1600
Text GLabel 6150 2700 0    60   Input ~ 0
CAN_CNTRL_TX0!
Text GLabel 6150 2850 0    60   Input ~ 0
CAN_CNTRL_TX1!
Text GLabel 6150 3000 0    60   Input ~ 0
CAN_CNTRL_TX2!
Text GLabel 6150 2550 0    60   Output ~ 0
CAN_CNTRL_CLKOUT_SOF
Wire Wire Line
	6150 2550 6300 2550
Wire Wire Line
	6300 2550 6300 2600
Wire Wire Line
	6300 2600 6700 2600
Wire Wire Line
	6150 2700 6700 2700
Wire Wire Line
	6150 2850 6400 2850
Wire Wire Line
	6400 2850 6400 2800
Wire Wire Line
	6400 2800 6700 2800
Wire Wire Line
	6150 3000 6700 3000
Text GLabel 6200 3150 0    60   Input ~ 0
CAN_CNTRL_CLKIN
Wire Wire Line
	6200 3150 6500 3150
Wire Wire Line
	6500 3150 6500 3200
Wire Wire Line
	6500 3200 6700 3200
Wire Wire Line
	900  2000 900  1950
Wire Wire Line
	900  1950 1100 1950
Wire Wire Line
	5000 2250 5000 2350
Wire Wire Line
	5000 1950 5000 1900
$EndSCHEMATC
