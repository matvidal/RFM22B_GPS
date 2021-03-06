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
LIBS:adaptadorRF23-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X08 Right_in1
U 1 1 56326EAB
P 6550 3550
F 0 "Right_in1" H 6550 4000 50  0000 C CNN
F 1 "CONN_01X08" V 6650 3550 50  0000 C CNN
F 2 "Pin_Headers_2:Pin_Header_1x08" H 6550 3550 60  0001 C CNN
F 3 "" H 6550 3550 60  0000 C CNN
	1    6550 3550
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X08 Left_in1
U 1 1 56326F7F
P 5950 3550
F 0 "Left_in1" H 5950 4000 50  0000 C CNN
F 1 "CONN_01X08" V 6050 3550 50  0000 C CNN
F 2 "Pin_Headers_2:Pin_Header_1x08" H 5950 3550 60  0001 C CNN
F 3 "" H 5950 3550 60  0000 C CNN
	1    5950 3550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 Right_out1
U 1 1 563270D4
P 7300 3550
F 0 "Right_out1" H 7300 4000 50  0000 C CNN
F 1 "CONN_01X08" V 7400 3550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 7300 3550 60  0001 C CNN
F 3 "" H 7300 3550 60  0000 C CNN
	1    7300 3550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 Left_out1
U 1 1 5632714F
P 5300 3550
F 0 "Left_out1" H 5300 4000 50  0000 C CNN
F 1 "CONN_01X08" V 5400 3550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 5300 3550 60  0001 C CNN
F 3 "" H 5300 3550 60  0000 C CNN
	1    5300 3550
	-1   0    0    -1  
$EndComp
Text Label 5500 3200 0    60   ~ 0
GND
Text Label 5500 3300 0    60   ~ 0
SDO
Text Label 5500 3500 0    60   ~ 0
SCK
Text Label 5500 3600 0    60   ~ 0
NSEL
Text Label 5500 3700 0    60   ~ 0
NIRQ
Text Label 5500 3800 0    60   ~ 0
SDN
Text Label 5500 3400 0    60   ~ 0
SDI
Text Label 5500 3900 0    60   ~ 0
GND
Text Label 6750 3200 0    60   ~ 0
GPIO_2
Text Label 6750 3300 0    60   ~ 0
GPIO_1
Text Label 6750 3400 0    60   ~ 0
GPIO_0
Text Label 6750 3500 0    60   ~ 0
VCC
Text Label 6750 3600 0    60   ~ 0
RXON
Text Label 6750 3700 0    60   ~ 0
TXON
Text Label 6750 3800 0    60   ~ 0
GND
Text Label 6750 3900 0    60   ~ 0
ANT
$Comp
L GND #PWR01
U 1 1 5632748E
P 5700 4000
F 0 "#PWR01" H 5700 3750 50  0001 C CNN
F 1 "GND" H 5700 3850 50  0000 C CNN
F 2 "" H 5700 4000 60  0000 C CNN
F 3 "" H 5700 4000 60  0000 C CNN
	1    5700 4000
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X05 SMA1
U 1 1 563275C9
P 7300 4350
F 0 "SMA1" H 7300 4650 50  0000 C CNN
F 1 "CONN_01X05" V 7400 4350 50  0000 C CNN
F 2 "Pin_Headers_2:SMA" H 7300 4350 60  0001 C CNN
F 3 "" H 7300 4350 60  0000 C CNN
	1    7300 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 3200 5750 3200
Wire Wire Line
	5500 3300 5750 3300
Wire Wire Line
	5500 3400 5750 3400
Wire Wire Line
	5500 3500 5750 3500
Wire Wire Line
	5500 3600 5750 3600
Wire Wire Line
	5500 3700 5750 3700
Wire Wire Line
	5500 3800 5750 3800
Wire Wire Line
	5500 3900 5750 3900
Wire Wire Line
	6750 3200 7100 3200
Wire Wire Line
	6750 3300 7100 3300
Wire Wire Line
	6750 3400 7100 3400
Wire Wire Line
	6750 3500 7100 3500
Wire Wire Line
	6750 3600 7100 3600
Wire Wire Line
	6750 3700 7100 3700
Wire Wire Line
	6750 3800 7100 3800
Wire Wire Line
	6750 3900 7100 3900
Wire Wire Line
	5700 4000 5700 3900
Connection ~ 5700 3900
Wire Wire Line
	7100 4150 7000 4150
Wire Wire Line
	7000 4150 7000 3900
Connection ~ 7000 3900
Wire Wire Line
	7100 4250 7000 4250
Wire Wire Line
	7000 4250 7000 4600
Wire Wire Line
	7000 4550 7100 4550
Wire Wire Line
	7100 4350 7000 4350
Connection ~ 7000 4350
Wire Wire Line
	7100 4450 7000 4450
Connection ~ 7000 4450
Connection ~ 7000 4550
$Comp
L GND #PWR02
U 1 1 5632790F
P 7000 4600
F 0 "#PWR02" H 7000 4350 50  0001 C CNN
F 1 "GND" H 7000 4450 50  0000 C CNN
F 2 "" H 7000 4600 60  0000 C CNN
F 3 "" H 7000 4600 60  0000 C CNN
	1    7000 4600
	1    0    0    -1  
$EndComp
Text Label 7000 4450 1    60   ~ 0
GND
$EndSCHEMATC
