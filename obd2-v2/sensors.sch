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
Sheet 7 7
Title ""
Date "11 aug 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 3850 4150 2    60   Output ~ 0
TEMP
$Comp
L TC1047A U8
U 1 1 53E81912
P 3250 4150
F 0 "U8" H 3300 3950 60  0000 C CNN
F 1 "TC1047A" H 3200 4350 60  0000 C CNN
F 2 "~" H 3000 4200 60  0000 C CNN
F 3 "~" H 3000 4200 60  0000 C CNN
	1    3250 4150
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR061
U 1 1 53E8215A
P 3750 3850
F 0 "#PWR061" H 3750 3810 30  0001 C CNN
F 1 "+3.3V" H 3750 3960 30  0000 C CNN
F 2 "" H 3750 3850 60  0000 C CNN
F 3 "" H 3750 3850 60  0000 C CNN
	1    3750 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 4050 3750 4050
Wire Wire Line
	3750 4050 3750 3850
Wire Wire Line
	3850 4150 3650 4150
$Comp
L GND #PWR062
U 1 1 53E8217B
P 3750 4350
F 0 "#PWR062" H 3750 4350 30  0001 C CNN
F 1 "GND" H 3750 4280 30  0001 C CNN
F 2 "" H 3750 4350 60  0000 C CNN
F 3 "" H 3750 4350 60  0000 C CNN
	1    3750 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 4350 3750 4250
Wire Wire Line
	3750 4250 3650 4250
$EndSCHEMATC
