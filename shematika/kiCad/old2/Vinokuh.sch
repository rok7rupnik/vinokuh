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
LIBS:Vinokuh-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Vinokuh"
Date "8 oct 2013"
Rev "0"
Comp "Rok Rupnik && Ozbolt Menegatti"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R_T1b1
U 1 1 524322ED
P 3450 2550
F 0 "R_T1b1" V 3530 2550 40  0000 C CNN
F 1 "R" V 3457 2551 40  0000 C CNN
F 2 "~" V 3380 2550 30  0000 C CNN
F 3 "~" H 3450 2550 30  0000 C CNN
	1    3450 2550
	0    -1   -1   0   
$EndComp
$Comp
L R R_T1a1
U 1 1 524322EE
P 3200 2300
F 0 "R_T1a1" V 3280 2300 40  0000 C CNN
F 1 "R" V 3207 2301 40  0000 C CNN
F 2 "~" V 3130 2300 30  0000 C CNN
F 3 "~" H 3200 2300 30  0000 C CNN
	1    3200 2300
	1    0    0    -1  
$EndComp
$Comp
L R R_RED8
U 1 1 524322F8
P 7100 6250
F 0 "R_RED8" V 7180 6250 40  0000 C CNN
F 1 "R" V 7107 6251 40  0000 C CNN
F 2 "~" V 7030 6250 30  0000 C CNN
F 3 "~" H 7100 6250 30  0000 C CNN
	1    7100 6250
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED4
U 1 1 524322F9
P 6000 6250
F 0 "R_RED4" V 6080 6250 40  0000 C CNN
F 1 "R" V 6007 6251 40  0000 C CNN
F 2 "~" V 5930 6250 30  0000 C CNN
F 3 "~" H 6000 6250 30  0000 C CNN
	1    6000 6250
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED3
U 1 1 524322FA
P 6000 6000
F 0 "R_RED3" V 6080 6000 40  0000 C CNN
F 1 "R" V 6007 6001 40  0000 C CNN
F 2 "~" V 5930 6000 30  0000 C CNN
F 3 "~" H 6000 6000 30  0000 C CNN
	1    6000 6000
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED6
U 1 1 524322FB
P 7100 5750
F 0 "R_RED6" V 7180 5750 40  0000 C CNN
F 1 "R" V 7107 5751 40  0000 C CNN
F 2 "~" V 7030 5750 30  0000 C CNN
F 3 "~" H 7100 5750 30  0000 C CNN
	1    7100 5750
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED5
U 1 1 524322FC
P 7100 5500
F 0 "R_RED5" V 7180 5500 40  0000 C CNN
F 1 "R" V 7107 5501 40  0000 C CNN
F 2 "~" V 7030 5500 30  0000 C CNN
F 3 "~" H 7100 5500 30  0000 C CNN
	1    7100 5500
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED2
U 1 1 524322FD
P 6000 5750
F 0 "R_RED2" V 6080 5750 40  0000 C CNN
F 1 "R" V 6007 5751 40  0000 C CNN
F 2 "~" V 5930 5750 30  0000 C CNN
F 3 "~" H 6000 5750 30  0000 C CNN
	1    6000 5750
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED1
U 1 1 524322FE
P 6000 5500
F 0 "R_RED1" V 6080 5500 40  0000 C CNN
F 1 "R" V 6007 5501 40  0000 C CNN
F 2 "~" V 5930 5500 30  0000 C CNN
F 3 "~" H 6000 5500 30  0000 C CNN
	1    6000 5500
	0    -1   -1   0   
$EndComp
$Comp
L 7805 DCDC1
U 1 1 52432307
P 7400 2150
F 0 "DCDC1" H 7550 1954 60  0001 C CNN
F 1 "7805" H 7400 2350 60  0000 C CNN
F 2 "~" H 7400 2150 60  0000 C CNN
F 3 "~" H 7400 2150 60  0000 C CNN
	1    7400 2150
	1    0    0    -1  
$EndComp
Text Label 8800 3000 0    40   ~ 0
5V
NoConn ~ 2300 3100
Text Label 2250 2900 2    39   ~ 8
GND
Text Label 8800 3100 0    40   ~ 0
3V
Text Label 8800 2900 0    40   ~ 0
GND
$Comp
L CONN_20X2 DSC_D1
U 1 1 5243289E
P 9400 3850
F 0 "DSC_D1" H 9400 5150 60  0001 C CNN
F 1 "DISCOVERY DESNA" V 9400 3850 50  0000 C CNN
F 2 "" H 9400 3850 60  0000 C CNN
F 3 "" H 9400 3850 60  0000 C CNN
	1    9400 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 52432CC3
P 7400 2450
F 0 "#PWR01" H 7400 2450 30  0001 C CNN
F 1 "GND" H 7400 2380 30  0001 C CNN
F 2 "" H 7400 2450 60  0000 C CNN
F 3 "" H 7400 2450 60  0000 C CNN
	1    7400 2450
	-1   0    0    -1  
$EndComp
Text Label 10000 2900 2    39   ~ 8
GND
Text Label 10000 3100 2    39   ~ 8
3V
Text Label 10000 3000 2    39   ~ 8
5V
$Comp
L DIODESCH D_REL1
U 1 1 52433174
P 6150 2950
F 0 "D_REL1" H 6150 2850 40  0000 C CNN
F 1 "DIODESCH" H 6150 2850 40  0001 C CNN
F 2 "~" H 6150 2950 60  0000 C CNN
F 3 "~" H 6150 2950 60  0000 C CNN
	1    6150 2950
	0    -1   -1   0   
$EndComp
$Comp
L MOSFET_N REL2
U 1 1 524331B0
P 5700 2250
F 0 "REL2" H 5700 2450 60  0000 R CNN
F 1 "MOSFET_N" H 5710 2100 60  0001 R CNN
F 2 "~" H 5700 2250 60  0000 C CNN
F 3 "~" H 5700 2250 60  0000 C CNN
	1    5700 2250
	0    -1   1    0   
$EndComp
$Comp
L R R_B1
U 1 1 5243357A
P 8550 5750
F 0 "R_B1" V 8630 5750 40  0000 C CNN
F 1 "R" V 8557 5751 40  0000 C CNN
F 2 "~" V 8480 5750 30  0000 C CNN
F 3 "~" H 8550 5750 30  0000 C CNN
	1    8550 5750
	0    -1   -1   0   
$EndComp
$Comp
L R R_BE1
U 1 1 52433580
P 8550 5400
F 0 "R_BE1" V 8630 5400 40  0000 C CNN
F 1 "R" V 8557 5401 40  0000 C CNN
F 2 "~" V 8480 5400 30  0000 C CNN
F 3 "~" H 8550 5400 30  0000 C CNN
	1    8550 5400
	0    -1   -1   0   
$EndComp
$Comp
L R R_B2
U 1 1 52433586
P 8550 6100
F 0 "R_B2" V 8630 6100 40  0000 C CNN
F 1 "R" V 8557 6101 40  0000 C CNN
F 2 "~" V 8480 6100 30  0000 C CNN
F 3 "~" H 8550 6100 30  0000 C CNN
	1    8550 6100
	0    -1   -1   0   
$EndComp
Text Notes 8300 5200 0    60   ~ 12
Knofi
Text Notes 6200 5250 0    60   ~ 12
ArrayLEDic
Text Notes 3150 1800 0    60   ~ 12
Uporovni delilniki za termistorje
$Comp
L CONN_20X2 DSC_L1
U 1 1 524328AD
P 1650 3850
F 0 "DSC_L1" H 1650 5150 60  0001 C CNN
F 1 "DISCOVERY LEVA" V 1650 3850 50  0000 C CNN
F 2 "" H 1650 3850 60  0000 C CNN
F 3 "" H 1650 3850 60  0000 C CNN
	1    1650 3850
	1    0    0    -1  
$EndComp
$Comp
L DIODESCH D_REL2
U 1 1 52433165
P 6150 2250
F 0 "D_REL2" H 6150 2150 40  0000 C CNN
F 1 "DIODESCH" H 6150 2150 40  0001 C CNN
F 2 "~" H 6150 2250 60  0000 C CNN
F 3 "~" H 6150 2250 60  0000 C CNN
	1    6150 2250
	0    -1   -1   0   
$EndComp
Text Notes 5600 3700 0    60   ~ 12
Encoder
$Comp
L R R_RED7
U 1 1 52433CA9
P 7100 6000
F 0 "R_RED7" V 7180 6000 40  0000 C CNN
F 1 "R" V 7107 6001 40  0000 C CNN
F 2 "~" V 7030 6000 30  0000 C CNN
F 3 "~" H 7100 6000 30  0000 C CNN
	1    7100 6000
	0    -1   -1   0   
$EndComp
$Comp
L MOSFET_N REL1
U 1 1 524331A1
P 5700 2950
F 0 "REL1" H 5700 3150 60  0000 R CNN
F 1 "MOSFET_N" V 5450 3150 60  0001 R CNN
F 2 "~" H 5700 2950 60  0000 C CNN
F 3 "~" H 5700 2950 60  0000 C CNN
	1    5700 2950
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 52434A5A
P 6300 2550
F 0 "#PWR02" H 6300 2550 30  0001 C CNN
F 1 "GND" H 6300 2480 30  0001 C CNN
F 2 "" H 6300 2550 60  0000 C CNN
F 3 "" H 6300 2550 60  0000 C CNN
	1    6300 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 52434A69
P 6300 3250
F 0 "#PWR03" H 6300 3250 30  0001 C CNN
F 1 "GND" H 6300 3180 30  0001 C CNN
F 2 "" H 6300 3250 60  0000 C CNN
F 3 "" H 6300 3250 60  0000 C CNN
	1    6300 3250
	1    0    0    -1  
$EndComp
Text Label 3550 7050 1    39   ~ 8
V30
Text Label 3650 7050 1    39   ~ 8
V29
Text Label 3750 7050 1    39   ~ 8
V28
Text Label 3850 7050 1    39   ~ 8
V27
Text Label 3950 7050 1    39   ~ 8
V26
Text Label 4050 7050 1    39   ~ 8
V25
Text Label 4150 7050 1    39   ~ 8
V24
Text Label 4250 7050 1    39   ~ 8
V23
Text Label 4350 7050 1    39   ~ 8
V22
Text Label 4450 7050 1    39   ~ 8
V21
Text Label 4550 7050 1    39   ~ 8
V20
Text Label 4650 7050 1    39   ~ 8
V19
Text Label 4750 7050 1    39   ~ 8
V18
Text Label 4900 7050 1    39   ~ 8
V17
Text Label 5000 7050 1    39   ~ 8
V16
Text Label 5100 7050 1    39   ~ 8
V15
Text Label 5200 7050 1    39   ~ 8
V14
Text Label 5300 7050 1    39   ~ 8
V13
Text Label 5400 7050 1    39   ~ 8
V12
Text Label 5500 7050 1    39   ~ 8
V11
Text Label 5600 7050 1    39   ~ 8
V10
Text Label 5700 7050 1    39   ~ 8
V9
Text Label 5800 7050 1    39   ~ 8
V8
Text Label 5900 7050 1    39   ~ 8
V7
Text Label 6000 7050 1    39   ~ 8
V6
Text Label 6100 7050 1    39   ~ 8
V5
Text Label 6200 7050 1    39   ~ 8
V4
Text Label 6300 7050 1    39   ~ 8
V3
Text Label 6400 7050 1    39   ~ 8
V2
Text Label 6500 7050 1    39   ~ 8
V1
Text Label 5250 2450 0    39   ~ 8
U?
Text Label 5250 3150 0    39   ~ 8
U?
Text Label 6200 2050 0    39   ~ 8
P?
Text Label 6200 2750 0    39   ~ 8
P?
Text Label 7850 2100 0    39   ~ 8
5V
Text Label 6930 2100 2    39   ~ 8
U15
Text Label 5600 5500 0    39   ~ 8
P?
Text Label 5600 5750 0    39   ~ 8
P?
Text Label 5600 6000 0    39   ~ 8
P?
Text Label 5600 6250 0    39   ~ 8
P?
Text Label 6700 6250 0    39   ~ 8
P?
Text Label 6700 6000 0    39   ~ 8
P?
Text Label 6700 5750 0    39   ~ 8
P?
Text Label 6700 5500 0    39   ~ 8
P?
Text Label 6350 5500 0    39   ~ 8
V?
Text Label 6350 5750 0    39   ~ 8
V?
Text Label 6350 6000 0    39   ~ 8
V?
Text Label 6350 6250 0    39   ~ 8
V?
Text Label 7450 6250 0    39   ~ 8
V?
Text Label 7450 6000 0    39   ~ 8
V?
Text Label 7450 5750 0    39   ~ 8
V?
Text Label 7450 5500 0    39   ~ 8
V?
$Comp
L R R_GREEN8
U 1 1 52436514
P 4550 6250
F 0 "R_GREEN8" V 4630 6250 40  0000 C CNN
F 1 "R" V 4557 6251 40  0000 C CNN
F 2 "~" V 4480 6250 30  0000 C CNN
F 3 "~" H 4550 6250 30  0000 C CNN
	1    4550 6250
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN4
U 1 1 5243651A
P 3450 6250
F 0 "R_GREEN4" V 3530 6250 40  0000 C CNN
F 1 "R" V 3457 6251 40  0000 C CNN
F 2 "~" V 3380 6250 30  0000 C CNN
F 3 "~" H 3450 6250 30  0000 C CNN
	1    3450 6250
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN3
U 1 1 52436520
P 3450 6000
F 0 "R_GREEN3" V 3530 6000 40  0000 C CNN
F 1 "R" V 3457 6001 40  0000 C CNN
F 2 "~" V 3380 6000 30  0000 C CNN
F 3 "~" H 3450 6000 30  0000 C CNN
	1    3450 6000
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN6
U 1 1 52436526
P 4550 5750
F 0 "R_GREEN6" V 4630 5750 40  0000 C CNN
F 1 "R" V 4557 5751 40  0000 C CNN
F 2 "~" V 4480 5750 30  0000 C CNN
F 3 "~" H 4550 5750 30  0000 C CNN
	1    4550 5750
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN5
U 1 1 5243652C
P 4550 5500
F 0 "R_GREEN5" V 4630 5500 40  0000 C CNN
F 1 "R" V 4557 5501 40  0000 C CNN
F 2 "~" V 4480 5500 30  0000 C CNN
F 3 "~" H 4550 5500 30  0000 C CNN
	1    4550 5500
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN2
U 1 1 52436532
P 3450 5750
F 0 "R_GREEN2" V 3530 5750 40  0000 C CNN
F 1 "R" V 3457 5751 40  0000 C CNN
F 2 "~" V 3380 5750 30  0000 C CNN
F 3 "~" H 3450 5750 30  0000 C CNN
	1    3450 5750
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN1
U 1 1 52436538
P 3450 5500
F 0 "R_GREEN1" V 3530 5500 40  0000 C CNN
F 1 "R" V 3457 5501 40  0000 C CNN
F 2 "~" V 3380 5500 30  0000 C CNN
F 3 "~" H 3450 5500 30  0000 C CNN
	1    3450 5500
	0    -1   -1   0   
$EndComp
Text Notes 3650 5250 0    60   ~ 12
ArrayLEDic
$Comp
L R R_GREEN7
U 1 1 52436540
P 4550 6000
F 0 "R_GREEN7" V 4630 6000 40  0000 C CNN
F 1 "R" V 4557 6001 40  0000 C CNN
F 2 "~" V 4480 6000 30  0000 C CNN
F 3 "~" H 4550 6000 30  0000 C CNN
	1    4550 6000
	0    -1   -1   0   
$EndComp
Text Label 3050 5500 0    39   ~ 8
P?
Text Label 3050 5750 0    39   ~ 8
P?
Text Label 3050 6000 0    39   ~ 8
P?
Text Label 3050 6250 0    39   ~ 8
P?
Text Label 4150 6250 0    39   ~ 8
P?
Text Label 4150 6000 0    39   ~ 8
P?
Text Label 4150 5750 0    39   ~ 8
P?
Text Label 4150 5500 0    39   ~ 8
P?
Text Label 3800 5500 0    39   ~ 8
V?
Text Label 3800 5750 0    39   ~ 8
V?
Text Label 3800 6000 0    39   ~ 8
V?
Text Label 3800 6250 0    39   ~ 8
V?
Text Label 4900 6250 0    39   ~ 8
V?
Text Label 4900 6000 0    39   ~ 8
V?
Text Label 4900 5750 0    39   ~ 8
V?
Text Label 4900 5500 0    39   ~ 8
V?
$Comp
L R R_T2b1
U 1 1 524366BA
P 3450 3250
F 0 "R_T2b1" V 3530 3250 40  0000 C CNN
F 1 "R" V 3457 3251 40  0000 C CNN
F 2 "~" V 3380 3250 30  0000 C CNN
F 3 "~" H 3450 3250 30  0000 C CNN
	1    3450 3250
	0    -1   -1   0   
$EndComp
$Comp
L R R_T2a1
U 1 1 524366C0
P 3200 3000
F 0 "R_T2a1" V 3280 3000 40  0000 C CNN
F 1 "R" V 3207 3001 40  0000 C CNN
F 2 "~" V 3130 3000 30  0000 C CNN
F 3 "~" H 3200 3000 30  0000 C CNN
	1    3200 3000
	1    0    0    -1  
$EndComp
$Comp
L R R_T3b1
U 1 1 524366C6
P 3450 3950
F 0 "R_T3b1" V 3530 3950 40  0000 C CNN
F 1 "R" V 3457 3951 40  0000 C CNN
F 2 "~" V 3380 3950 30  0000 C CNN
F 3 "~" H 3450 3950 30  0000 C CNN
	1    3450 3950
	0    -1   -1   0   
$EndComp
$Comp
L R R_T3a1
U 1 1 524366CC
P 3200 3700
F 0 "R_T3a1" V 3280 3700 40  0000 C CNN
F 1 "R" V 3207 3701 40  0000 C CNN
F 2 "~" V 3130 3700 30  0000 C CNN
F 3 "~" H 3200 3700 30  0000 C CNN
	1    3200 3700
	1    0    0    -1  
$EndComp
$Comp
L R R_T4b1
U 1 1 524366D2
P 3450 4650
F 0 "R_T4b1" V 3530 4650 40  0000 C CNN
F 1 "R" V 3457 4651 40  0000 C CNN
F 2 "~" V 3380 4650 30  0000 C CNN
F 3 "~" H 3450 4650 30  0000 C CNN
	1    3450 4650
	0    -1   -1   0   
$EndComp
$Comp
L R R_T4a1
U 1 1 524366D8
P 3200 4400
F 0 "R_T4a1" V 3280 4400 40  0000 C CNN
F 1 "R" V 3207 4401 40  0000 C CNN
F 2 "~" V 3130 4400 30  0000 C CNN
F 3 "~" H 3200 4400 30  0000 C CNN
	1    3200 4400
	1    0    0    -1  
$EndComp
$Comp
L R R_T5b1
U 1 1 524366DE
P 4400 2550
F 0 "R_T5b1" V 4480 2550 40  0000 C CNN
F 1 "R" V 4407 2551 40  0000 C CNN
F 2 "~" V 4330 2550 30  0000 C CNN
F 3 "~" H 4400 2550 30  0000 C CNN
	1    4400 2550
	0    -1   -1   0   
$EndComp
$Comp
L R R_T5a1
U 1 1 524366E4
P 4150 2300
F 0 "R_T5a1" V 4230 2300 40  0000 C CNN
F 1 "R" V 4157 2301 40  0000 C CNN
F 2 "~" V 4080 2300 30  0000 C CNN
F 3 "~" H 4150 2300 30  0000 C CNN
	1    4150 2300
	1    0    0    -1  
$EndComp
$Comp
L R R_T6b1
U 1 1 524366EA
P 4400 3250
F 0 "R_T6b1" V 4480 3250 40  0000 C CNN
F 1 "R" V 4407 3251 40  0000 C CNN
F 2 "~" V 4330 3250 30  0000 C CNN
F 3 "~" H 4400 3250 30  0000 C CNN
	1    4400 3250
	0    -1   -1   0   
$EndComp
$Comp
L R R_T6a1
U 1 1 524366F0
P 4150 3000
F 0 "R_T6a1" V 4230 3000 40  0000 C CNN
F 1 "R" V 4157 3001 40  0000 C CNN
F 2 "~" V 4080 3000 30  0000 C CNN
F 3 "~" H 4150 3000 30  0000 C CNN
	1    4150 3000
	1    0    0    -1  
$EndComp
$Comp
L R R_T7b1
U 1 1 524366F6
P 4400 3950
F 0 "R_T7b1" V 4480 3950 40  0000 C CNN
F 1 "R" V 4407 3951 40  0000 C CNN
F 2 "~" V 4330 3950 30  0000 C CNN
F 3 "~" H 4400 3950 30  0000 C CNN
	1    4400 3950
	0    -1   -1   0   
$EndComp
$Comp
L R R_T7a1
U 1 1 524366FC
P 4150 3700
F 0 "R_T7a1" V 4230 3700 40  0000 C CNN
F 1 "R" V 4157 3701 40  0000 C CNN
F 2 "~" V 4080 3700 30  0000 C CNN
F 3 "~" H 4150 3700 30  0000 C CNN
	1    4150 3700
	1    0    0    -1  
$EndComp
$Comp
L R R_T8b1
U 1 1 52436702
P 4400 4650
F 0 "R_T8b1" V 4480 4650 40  0000 C CNN
F 1 "R" V 4407 4651 40  0000 C CNN
F 2 "~" V 4330 4650 30  0000 C CNN
F 3 "~" H 4400 4650 30  0000 C CNN
	1    4400 4650
	0    -1   -1   0   
$EndComp
$Comp
L R R_T8a1
U 1 1 52436708
P 4150 4400
F 0 "R_T8a1" V 4230 4400 40  0000 C CNN
F 1 "R" V 4157 4401 40  0000 C CNN
F 2 "~" V 4080 4400 30  0000 C CNN
F 3 "~" H 4150 4400 30  0000 C CNN
	1    4150 4400
	1    0    0    -1  
$EndComp
Text Label 3300 2050 0    39   ~ 8
U1
Text Label 3050 2550 0    39   ~ 8
DT1
Text Label 3050 3250 0    39   ~ 8
DT2
Text Label 3050 3950 0    39   ~ 8
DT3
Text Label 3050 4650 0    39   ~ 8
DT4
Text Label 4000 2550 0    39   ~ 8
DT5
Text Label 4000 3250 0    39   ~ 8
DT6
Text Label 4000 3950 0    39   ~ 8
DT7
Text Label 4000 4650 0    39   ~ 8
DT8
Text Label 3300 2750 0    39   ~ 8
U2
Text Label 3300 3450 0    39   ~ 8
U3
Text Label 3300 4150 0    39   ~ 8
U4
Text Label 4250 4150 0    39   ~ 8
U8
Text Label 4250 3450 0    39   ~ 8
U7
Text Label 4250 2750 0    39   ~ 8
U6
Text Label 4250 2050 0    39   ~ 8
U5
$Comp
L GND #PWR04
U 1 1 52436BF2
P 3750 2600
F 0 "#PWR04" H 3750 2600 30  0001 C CNN
F 1 "GND" H 3750 2530 30  0001 C CNN
F 2 "" H 3750 2600 60  0000 C CNN
F 3 "" H 3750 2600 60  0000 C CNN
	1    3750 2600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 52436C01
P 3750 3300
F 0 "#PWR05" H 3750 3300 30  0001 C CNN
F 1 "GND" H 3750 3230 30  0001 C CNN
F 2 "" H 3750 3300 60  0000 C CNN
F 3 "" H 3750 3300 60  0000 C CNN
	1    3750 3300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 52436C09
P 3750 4000
F 0 "#PWR06" H 3750 4000 30  0001 C CNN
F 1 "GND" H 3750 3930 30  0001 C CNN
F 2 "" H 3750 4000 60  0000 C CNN
F 3 "" H 3750 4000 60  0000 C CNN
	1    3750 4000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 52436C11
P 3750 4700
F 0 "#PWR07" H 3750 4700 30  0001 C CNN
F 1 "GND" H 3750 4630 30  0001 C CNN
F 2 "" H 3750 4700 60  0000 C CNN
F 3 "" H 3750 4700 60  0000 C CNN
	1    3750 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 52436C19
P 4700 2600
F 0 "#PWR08" H 4700 2600 30  0001 C CNN
F 1 "GND" H 4700 2530 30  0001 C CNN
F 2 "" H 4700 2600 60  0000 C CNN
F 3 "" H 4700 2600 60  0000 C CNN
	1    4700 2600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 52436C21
P 4700 3300
F 0 "#PWR09" H 4700 3300 30  0001 C CNN
F 1 "GND" H 4700 3230 30  0001 C CNN
F 2 "" H 4700 3300 60  0000 C CNN
F 3 "" H 4700 3300 60  0000 C CNN
	1    4700 3300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 52436C29
P 4700 4000
F 0 "#PWR010" H 4700 4000 30  0001 C CNN
F 1 "GND" H 4700 3930 30  0001 C CNN
F 2 "" H 4700 4000 60  0000 C CNN
F 3 "" H 4700 4000 60  0000 C CNN
	1    4700 4000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 52436C31
P 4700 4700
F 0 "#PWR011" H 4700 4700 30  0001 C CNN
F 1 "GND" H 4700 4630 30  0001 C CNN
F 2 "" H 4700 4700 60  0000 C CNN
F 3 "" H 4700 4700 60  0000 C CNN
	1    4700 4700
	1    0    0    -1  
$EndComp
Text Label 8100 5400 0    39   ~ 8
V?
Text Label 8100 5750 0    39   ~ 8
V?
Text Label 8100 6100 0    39   ~ 8
V?
Text Label 8100 5550 0    39   ~ 8
P?
Text Label 8100 5900 0    39   ~ 8
P?
Text Label 8100 6250 0    39   ~ 8
P?
$Comp
L GND #PWR012
U 1 1 52437A5F
P 8850 5450
F 0 "#PWR012" H 8850 5450 30  0001 C CNN
F 1 "GND" H 8850 5380 30  0001 C CNN
F 2 "" H 8850 5450 60  0000 C CNN
F 3 "" H 8850 5450 60  0000 C CNN
	1    8850 5450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 52437A6E
P 8850 5800
F 0 "#PWR013" H 8850 5800 30  0001 C CNN
F 1 "GND" H 8850 5730 30  0001 C CNN
F 2 "" H 8850 5800 60  0000 C CNN
F 3 "" H 8850 5800 60  0000 C CNN
	1    8850 5800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 52437A76
P 8850 6150
F 0 "#PWR014" H 8850 6150 30  0001 C CNN
F 1 "GND" H 8850 6080 30  0001 C CNN
F 2 "" H 8850 6150 60  0000 C CNN
F 3 "" H 8850 6150 60  0000 C CNN
	1    8850 6150
	1    0    0    -1  
$EndComp
$Comp
L R R_E1
U 1 1 52437BC1
P 5800 3900
F 0 "R_E1" V 5880 3900 40  0000 C CNN
F 1 "R" V 5807 3901 40  0000 C CNN
F 2 "~" V 5730 3900 30  0000 C CNN
F 3 "~" H 5800 3900 30  0000 C CNN
	1    5800 3900
	0    -1   -1   0   
$EndComp
$Comp
L R R_E2
U 1 1 52437BC7
P 5800 4250
F 0 "R_E2" V 5880 4250 40  0000 C CNN
F 1 "R" V 5807 4251 40  0000 C CNN
F 2 "~" V 5730 4250 30  0000 C CNN
F 3 "~" H 5800 4250 30  0000 C CNN
	1    5800 4250
	0    -1   -1   0   
$EndComp
Text Label 5350 3900 0    39   ~ 8
V?
Text Label 5350 4250 0    39   ~ 8
V?
Text Label 5350 4050 0    39   ~ 8
P?
Text Label 5350 4400 0    39   ~ 8
P?
Text Label 6200 3900 0    39   ~ 8
5V
Text Notes 7150 1800 0    60   ~ 12
Napajanje\n
Text Notes 5550 1850 0    60   ~ 12
Relays
Wire Wire Line
	2300 3100 2050 3100
Wire Wire Line
	2300 3200 2050 3200
Wire Wire Line
	2300 3300 2050 3300
Wire Wire Line
	2050 3400 2300 3400
Wire Wire Line
	2300 3500 2050 3500
Wire Wire Line
	2050 3600 2300 3600
Wire Wire Line
	2300 3700 2050 3700
Wire Wire Line
	2300 3800 2050 3800
Wire Wire Line
	2050 3900 2300 3900
Wire Wire Line
	2300 4000 2050 4000
Wire Wire Line
	2050 4100 2300 4100
Wire Wire Line
	2300 4200 2050 4200
Wire Wire Line
	2300 4300 2050 4300
Wire Wire Line
	2050 4400 2300 4400
Wire Wire Line
	2300 4500 2050 4500
Wire Wire Line
	2050 4600 2300 4600
Wire Wire Line
	2300 4700 2050 4700
Wire Wire Line
	2300 4800 2050 4800
Wire Wire Line
	9000 3000 8750 3000
Wire Wire Line
	8750 3100 9000 3100
Wire Wire Line
	8750 3200 9000 3200
Wire Wire Line
	8750 3300 9000 3300
Wire Wire Line
	9000 3400 8750 3400
Wire Wire Line
	8750 3500 9000 3500
Wire Wire Line
	9000 3600 8750 3600
Wire Wire Line
	8750 3700 9000 3700
Wire Wire Line
	8750 3800 9000 3800
Wire Wire Line
	8750 4000 9000 4000
Wire Wire Line
	9000 4100 8750 4100
Wire Wire Line
	8750 4200 9000 4200
Wire Wire Line
	8750 4300 9000 4300
Wire Wire Line
	9000 4400 8750 4400
Wire Wire Line
	8750 4500 9000 4500
Wire Wire Line
	9000 4600 8750 4600
Wire Wire Line
	8750 4700 9000 4700
Wire Wire Line
	8750 4800 9000 4800
Wire Wire Line
	1000 3100 1250 3100
Wire Wire Line
	1000 3200 1250 3200
Wire Wire Line
	1000 3300 1250 3300
Wire Wire Line
	1250 3400 1000 3400
Wire Wire Line
	1000 3500 1250 3500
Wire Wire Line
	1250 3600 1000 3600
Wire Wire Line
	1000 3700 1250 3700
Wire Wire Line
	1000 3800 1250 3800
Wire Wire Line
	1250 3900 1000 3900
Wire Wire Line
	1000 4000 1250 4000
Wire Wire Line
	1250 4100 1000 4100
Wire Wire Line
	1000 4200 1250 4200
Wire Wire Line
	1000 4300 1250 4300
Wire Wire Line
	1250 4400 1000 4400
Wire Wire Line
	1000 4500 1250 4500
Wire Wire Line
	1250 4600 1000 4600
Wire Wire Line
	1000 4700 1250 4700
Wire Wire Line
	1000 4800 1250 4800
Wire Wire Line
	1250 2900 1000 2900
Wire Wire Line
	2050 2900 2300 2900
Wire Wire Line
	10050 3200 9800 3200
Wire Wire Line
	10050 3300 9800 3300
Wire Wire Line
	9800 3400 10050 3400
Wire Wire Line
	10050 3500 9800 3500
Wire Wire Line
	9800 3600 10050 3600
Wire Wire Line
	10050 3700 9800 3700
Wire Wire Line
	10050 3800 9800 3800
Wire Wire Line
	10050 4000 9800 4000
Wire Wire Line
	9800 4100 10050 4100
Wire Wire Line
	10050 4200 9800 4200
Wire Wire Line
	10050 4300 9800 4300
Wire Wire Line
	9800 4400 10050 4400
Wire Wire Line
	10050 4500 9800 4500
Wire Wire Line
	9800 4600 10050 4600
Wire Wire Line
	10050 4700 9800 4700
Wire Wire Line
	10050 4800 9800 4800
Wire Wire Line
	9800 3000 10050 3000
Wire Notes Line
	2850 1950 2850 4850
Wire Notes Line
	4850 4850 4850 1900
Wire Notes Line
	2850 1900 2850 2000
Wire Notes Line
	5350 5300 7750 5300
Wire Wire Line
	5500 2450 5500 2350
Wire Wire Line
	5900 2350 5900 2450
Wire Wire Line
	5900 3050 5900 3150
Wire Wire Line
	5200 2450 5500 2450
Wire Wire Line
	5700 2050 6300 2050
Wire Wire Line
	5700 2750 6300 2750
Wire Wire Line
	5200 3150 5500 3150
Wire Notes Line
	5100 3400 5100 1900
Wire Notes Line
	6400 1900 6400 3400
Wire Notes Line
	5100 1900 6400 1900
Wire Notes Line
	6400 3400 5100 3400
Wire Wire Line
	3550 6850 3550 7150
Wire Wire Line
	3650 6850 3650 7150
Wire Wire Line
	3750 6850 3750 7150
Wire Wire Line
	3850 6850 3850 7150
Wire Wire Line
	3950 6850 3950 7150
Wire Wire Line
	4050 6850 4050 7150
Wire Wire Line
	4150 6850 4150 7150
Wire Wire Line
	4250 6850 4250 7150
Wire Wire Line
	4350 6850 4350 7150
Wire Wire Line
	4450 6850 4450 7150
Wire Wire Line
	4550 6850 4550 7150
Wire Wire Line
	4650 6850 4650 7150
Wire Wire Line
	4750 6850 4750 7150
Wire Wire Line
	4900 6850 4900 7150
Wire Wire Line
	5000 6850 5000 7150
Wire Wire Line
	5100 6850 5100 7150
Wire Wire Line
	5200 6850 5200 7150
Wire Wire Line
	5300 6850 5300 7150
Wire Wire Line
	5400 6850 5400 7150
Wire Wire Line
	5500 6850 5500 7150
Wire Wire Line
	5600 6850 5600 7150
Wire Wire Line
	5700 6850 5700 7150
Wire Wire Line
	5800 6850 5800 7150
Wire Wire Line
	5900 6850 5900 7150
Wire Wire Line
	6000 6850 6000 7150
Wire Wire Line
	6100 6850 6100 7150
Wire Wire Line
	6200 6850 6200 7150
Wire Wire Line
	6300 6850 6300 7150
Wire Wire Line
	6400 6850 6400 7150
Wire Wire Line
	6500 6850 6500 7150
Wire Wire Line
	7800 2100 7950 2100
Wire Wire Line
	6800 2100 7000 2100
Wire Notes Line
	5350 5300 5350 6400
Wire Notes Line
	5350 6400 7750 6400
Wire Notes Line
	7750 6400 7750 5300
Wire Wire Line
	5550 5500 5750 5500
Wire Wire Line
	5550 5750 5750 5750
Wire Wire Line
	5550 6000 5750 6000
Wire Wire Line
	5550 6250 5750 6250
Wire Wire Line
	6450 6250 6250 6250
Wire Wire Line
	6450 6000 6250 6000
Wire Wire Line
	6450 5750 6250 5750
Wire Wire Line
	6450 5500 6250 5500
Wire Wire Line
	7550 6250 7350 6250
Wire Wire Line
	7550 6000 7350 6000
Wire Wire Line
	7550 5750 7350 5750
Wire Wire Line
	7550 5500 7350 5500
Wire Wire Line
	6650 5500 6850 5500
Wire Wire Line
	6650 5750 6850 5750
Wire Wire Line
	6650 6000 6850 6000
Wire Wire Line
	6650 6250 6850 6250
Wire Notes Line
	2800 5300 5200 5300
Wire Notes Line
	2800 5300 2800 6400
Wire Notes Line
	2800 6400 5200 6400
Wire Notes Line
	5200 6400 5200 5300
Wire Wire Line
	3000 5500 3200 5500
Wire Wire Line
	3000 5750 3200 5750
Wire Wire Line
	3000 6000 3200 6000
Wire Wire Line
	3000 6250 3200 6250
Wire Wire Line
	3900 6250 3700 6250
Wire Wire Line
	3900 6000 3700 6000
Wire Wire Line
	3900 5750 3700 5750
Wire Wire Line
	3900 5500 3700 5500
Wire Wire Line
	5000 6250 4800 6250
Wire Wire Line
	5000 6000 4800 6000
Wire Wire Line
	5000 5750 4800 5750
Wire Wire Line
	5000 5500 4800 5500
Wire Wire Line
	4100 5500 4300 5500
Wire Wire Line
	4100 5750 4300 5750
Wire Wire Line
	4100 6000 4300 6000
Wire Wire Line
	4100 6250 4300 6250
Wire Wire Line
	3200 2050 3400 2050
Wire Wire Line
	3200 2550 3000 2550
Wire Wire Line
	3200 3250 3000 3250
Wire Wire Line
	3200 3950 3000 3950
Wire Wire Line
	3200 4650 3000 4650
Wire Wire Line
	4150 2550 3950 2550
Wire Wire Line
	4150 3250 3950 3250
Wire Wire Line
	4150 3950 3950 3950
Wire Wire Line
	4150 4650 3950 4650
Wire Wire Line
	3200 2750 3400 2750
Wire Wire Line
	3200 3450 3400 3450
Wire Wire Line
	3200 4150 3400 4150
Wire Wire Line
	4150 4150 4350 4150
Wire Wire Line
	4150 3450 4350 3450
Wire Wire Line
	4150 2750 4350 2750
Wire Wire Line
	4150 2050 4350 2050
Wire Wire Line
	3700 2550 3750 2550
Wire Wire Line
	3750 2550 3750 2600
Wire Wire Line
	3700 3250 3750 3250
Wire Wire Line
	3750 3250 3750 3300
Wire Wire Line
	3700 3950 3750 3950
Wire Wire Line
	3750 3950 3750 4000
Wire Wire Line
	3700 4650 3750 4650
Wire Wire Line
	3750 4650 3750 4700
Wire Wire Line
	4650 2550 4700 2550
Wire Wire Line
	4700 2550 4700 2600
Wire Wire Line
	4650 3250 4700 3250
Wire Wire Line
	4700 3250 4700 3300
Wire Wire Line
	4650 3950 4700 3950
Wire Wire Line
	4700 3950 4700 4000
Wire Wire Line
	4650 4650 4700 4650
Wire Wire Line
	4700 4650 4700 4700
Wire Notes Line
	4850 1900 2850 1900
Wire Notes Line
	2850 4850 4850 4850
Wire Wire Line
	8050 5400 8250 5400
Wire Wire Line
	8250 5400 8300 5400
Wire Wire Line
	8050 5750 8250 5750
Wire Wire Line
	8250 5750 8300 5750
Wire Wire Line
	8050 6100 8250 6100
Wire Wire Line
	8250 6100 8300 6100
Wire Wire Line
	8250 5400 8250 5550
Wire Wire Line
	8250 5550 8050 5550
Connection ~ 8250 5400
Wire Wire Line
	8250 5750 8250 5900
Wire Wire Line
	8250 5900 8050 5900
Connection ~ 8250 5750
Wire Wire Line
	8250 6100 8250 6250
Wire Wire Line
	8250 6250 8050 6250
Connection ~ 8250 6100
Wire Wire Line
	8800 5400 8850 5400
Wire Wire Line
	8850 5400 8850 5450
Wire Wire Line
	8800 5750 8850 5750
Wire Wire Line
	8850 5750 8850 5800
Wire Wire Line
	8800 6100 8850 6100
Wire Wire Line
	8850 6100 8850 6150
Wire Notes Line
	7950 5250 8950 5250
Wire Notes Line
	8950 5250 8950 6400
Wire Notes Line
	8950 6400 7950 6400
Wire Notes Line
	7950 6400 7950 5250
Wire Wire Line
	5300 3900 5500 3900
Wire Wire Line
	5500 3900 5550 3900
Wire Wire Line
	5300 4250 5500 4250
Wire Wire Line
	5500 4250 5550 4250
Wire Wire Line
	5500 3900 5500 4050
Wire Wire Line
	5500 4050 5300 4050
Connection ~ 5500 3900
Wire Wire Line
	5500 4250 5500 4400
Wire Wire Line
	5500 4400 5300 4400
Connection ~ 5500 4250
Wire Wire Line
	6050 3900 6150 3900
Wire Wire Line
	6150 3900 6300 3900
Wire Wire Line
	6050 4250 6150 4250
Wire Wire Line
	6150 4250 6150 3900
Connection ~ 6150 3900
Wire Notes Line
	5200 3750 6350 3750
Wire Notes Line
	6350 3750 6350 4500
Wire Notes Line
	6350 4500 5200 4500
Wire Notes Line
	5200 4500 5200 3750
NoConn ~ 10050 3200
NoConn ~ 10050 3300
NoConn ~ 10050 3400
NoConn ~ 10050 3500
NoConn ~ 10050 3600
NoConn ~ 10050 3700
NoConn ~ 10050 3800
NoConn ~ 10050 4000
NoConn ~ 10050 4100
NoConn ~ 10050 4200
NoConn ~ 10050 4300
NoConn ~ 10050 4400
NoConn ~ 10050 4500
NoConn ~ 10050 4600
NoConn ~ 10050 4700
NoConn ~ 10050 4800
NoConn ~ 8750 4800
NoConn ~ 8750 4700
NoConn ~ 8750 4600
NoConn ~ 8750 4500
NoConn ~ 8750 4400
NoConn ~ 8750 4300
NoConn ~ 8750 4200
NoConn ~ 8750 4100
NoConn ~ 8750 4000
NoConn ~ 8750 3800
NoConn ~ 8750 3700
NoConn ~ 8750 3600
NoConn ~ 8750 3500
NoConn ~ 8750 3400
NoConn ~ 8750 3300
NoConn ~ 8750 3200
NoConn ~ 1000 3200
NoConn ~ 1000 3300
NoConn ~ 1000 3400
NoConn ~ 1000 3500
NoConn ~ 1000 3600
NoConn ~ 1000 3700
NoConn ~ 1000 3800
NoConn ~ 1000 3900
NoConn ~ 1000 4100
NoConn ~ 1000 4200
NoConn ~ 1000 4300
NoConn ~ 1000 4400
NoConn ~ 1000 4500
NoConn ~ 1000 4600
NoConn ~ 1000 4700
NoConn ~ 1000 4800
NoConn ~ 2300 4800
NoConn ~ 2300 4700
NoConn ~ 2300 4600
NoConn ~ 2300 4500
NoConn ~ 2300 4400
NoConn ~ 2300 4300
NoConn ~ 2300 4200
NoConn ~ 2300 4100
NoConn ~ 2300 4000
NoConn ~ 2300 3900
NoConn ~ 2300 3800
NoConn ~ 2300 3700
NoConn ~ 2300 3600
NoConn ~ 2300 3500
NoConn ~ 2300 3400
NoConn ~ 2300 3300
NoConn ~ 2300 3200
NoConn ~ 3650 6850
NoConn ~ 3750 6850
NoConn ~ 3850 6850
NoConn ~ 3950 6850
NoConn ~ 4050 6850
NoConn ~ 4150 6850
NoConn ~ 4250 6850
NoConn ~ 4350 6850
NoConn ~ 4450 6850
NoConn ~ 4550 6850
NoConn ~ 4650 6850
NoConn ~ 4750 6850
NoConn ~ 4900 6850
NoConn ~ 5000 6850
NoConn ~ 5100 6850
NoConn ~ 5200 6850
NoConn ~ 5300 6850
NoConn ~ 6500 6850
NoConn ~ 6400 6850
NoConn ~ 6300 6850
NoConn ~ 6200 6850
NoConn ~ 6100 6850
NoConn ~ 6000 6850
NoConn ~ 5900 6850
NoConn ~ 5800 6850
NoConn ~ 5700 6850
NoConn ~ 5600 6850
NoConn ~ 5500 6850
NoConn ~ 5400 6850
Wire Wire Line
	9800 3100 10050 3100
Wire Wire Line
	7400 2400 7400 2450
Wire Wire Line
	9000 2900 8750 2900
Wire Wire Line
	10050 2900 9800 2900
Wire Notes Line
	8100 1850 8100 2550
$Comp
L MOSFET_N MOS_BL1
U 1 1 5245755A
P 7550 4250
F 0 "MOS_BL1" H 7560 4420 60  0000 R CNN
F 1 "BackLight1" H 7560 4100 60  0001 R CNN
F 2 "~" H 7550 4250 60  0000 C CNN
F 3 "~" H 7550 4250 60  0000 C CNN
	1    7550 4250
	1    0    0    -1  
$EndComp
Text Notes 6950 3000 0    60   ~ 0
Mosfet za LCD lucko
Wire Wire Line
	7650 4050 7800 4050
Wire Wire Line
	7800 4450 7650 4450
Wire Wire Line
	7100 4250 7350 4250
Text Label 7700 4050 0    60   ~ 0
U?
$Comp
L GND #PWR015
U 1 1 52457DA5
P 7800 4500
F 0 "#PWR015" H 7800 4500 30  0001 C CNN
F 1 "GND" H 7800 4430 30  0001 C CNN
F 2 "" H 7800 4500 60  0000 C CNN
F 3 "" H 7800 4500 60  0000 C CNN
	1    7800 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4450 7800 4500
Text Label 7150 4250 0    60   ~ 0
P?
$Comp
L CONN_17 30_UP1
U 1 1 524589EB
P 5200 700
F 0 "30_UP1" V 5151 700 60  0001 C CNN
F 1 "Zgornja Letvica" V 5250 700 60  0000 C CNN
F 2 "" H 5200 700 60  0000 C CNN
F 3 "" H 5200 700 60  0000 C CNN
	1    5200 700 
	0    -1   -1   0   
$EndComp
Text Label 6000 1150 3    39   ~ 8
U17
Text Label 5900 1150 3    39   ~ 8
U16
Text Label 5800 1150 3    39   ~ 8
U15
Text Label 5700 1150 3    39   ~ 8
U14
Text Label 5600 1150 3    39   ~ 8
U13
Text Label 5500 1150 3    39   ~ 8
U12
Text Label 5400 1150 3    39   ~ 8
U11
Text Label 5300 1150 3    39   ~ 8
U10
Text Label 5200 1150 3    39   ~ 8
U9
Text Label 5100 1150 3    39   ~ 8
U8
Text Label 5000 1150 3    39   ~ 8
U7
Text Label 4900 1150 3    39   ~ 8
U6
Text Label 4700 1150 3    39   ~ 8
U4
Text Label 4600 1150 3    39   ~ 8
U3
Text Label 4500 1150 3    39   ~ 8
U2
Text Label 4400 1150 3    39   ~ 8
U1
Wire Wire Line
	6000 1050 6000 1400
Wire Wire Line
	5700 1350 5700 1050
Wire Wire Line
	5600 1350 5600 1050
Wire Wire Line
	5500 1350 5500 1050
Wire Wire Line
	5400 1350 5400 1050
Wire Wire Line
	5300 1350 5300 1050
Wire Wire Line
	5200 1350 5200 1050
Wire Wire Line
	5100 1350 5100 1050
Wire Wire Line
	5000 1350 5000 1050
Wire Wire Line
	4900 1350 4900 1050
Wire Wire Line
	4800 1350 4800 1050
Wire Wire Line
	4700 1350 4700 1050
Wire Wire Line
	4600 1350 4600 1050
Wire Wire Line
	4500 1350 4500 1050
Wire Wire Line
	4400 1350 4400 1050
Text Label 4800 1150 3    39   ~ 8
U5
Wire Notes Line
	8100 1850 6650 1850
Wire Notes Line
	6650 1850 6650 2550
Wire Notes Line
	6650 2550 8100 2550
Wire Wire Line
	5900 2450 6300 2450
Wire Wire Line
	6300 2450 6300 2550
Wire Wire Line
	5900 3150 6300 3150
Wire Wire Line
	6300 3150 6300 3250
Wire Wire Line
	5500 3150 5500 3050
$Comp
L GND #PWR016
U 1 1 5245A1FD
P 6000 1400
F 0 "#PWR016" H 6000 1400 30  0001 C CNN
F 1 "GND" H 6000 1330 30  0001 C CNN
F 2 "" H 6000 1400 60  0000 C CNN
F 3 "" H 6000 1400 60  0000 C CNN
	1    6000 1400
	1    0    0    -1  
$EndComp
Text Label 5900 1600 1    50   ~ 0
5V
$Comp
L DIODESCH D_LCD_1
U 1 1 5245AE39
P 7000 3200
F 0 "D_LCD_1" H 7000 3300 40  0000 C CNN
F 1 "DIODESCH" H 7000 3100 40  0001 C CNN
F 2 "~" H 7000 3200 60  0000 C CNN
F 3 "~" H 7000 3200 60  0000 C CNN
	1    7000 3200
	1    0    0    -1  
$EndComp
$Comp
L DIODESCH D_LCD_2
U 1 1 5245AE46
P 7500 3200
F 0 "D_LCD_2" H 7500 3300 40  0000 C CNN
F 1 "DIODESCH" H 7500 3100 40  0001 C CNN
F 2 "~" H 7500 3200 60  0000 C CNN
F 3 "~" H 7500 3200 60  0000 C CNN
	1    7500 3200
	1    0    0    -1  
$EndComp
$Comp
L C C_LCD_1
U 1 1 5245AF6D
P 7250 3550
F 0 "C_LCD_1" H 7250 3650 40  0000 L CNN
F 1 "C" H 7256 3465 40  0000 L CNN
F 2 "~" H 7288 3400 30  0000 C CNN
F 3 "~" H 7250 3550 60  0000 C CNN
	1    7250 3550
	1    0    0    -1  
$EndComp
$Comp
L C C_LCD_2
U 1 1 5245AF95
P 7750 3550
F 0 "C_LCD_2" H 7750 3650 40  0000 L CNN
F 1 "C" H 7756 3465 40  0000 L CNN
F 2 "~" H 7788 3400 30  0000 C CNN
F 3 "~" H 7750 3550 60  0000 C CNN
	1    7750 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 3200 7300 3200
Wire Wire Line
	7250 3350 7250 3200
Wire Wire Line
	7750 3200 7750 3350
Wire Wire Line
	6800 3200 6650 3200
Wire Wire Line
	6650 3750 7250 3750
Wire Wire Line
	7750 3750 7750 3800
$Comp
L GND #PWR017
U 1 1 5245B7A3
P 7750 3800
F 0 "#PWR017" H 7750 3800 30  0001 C CNN
F 1 "GND" H 7750 3730 30  0001 C CNN
F 2 "" H 7750 3800 60  0000 C CNN
F 3 "" H 7750 3800 60  0000 C CNN
	1    7750 3800
	1    0    0    -1  
$EndComp
Connection ~ 7750 3200
Text Label 6700 3200 0    39   ~ 0
5V
Text Label 6700 3750 0    60   ~ 0
P?
$Comp
L R R_LCD1
U 1 1 5245B8D9
P 8100 3500
F 0 "R_LCD1" V 8180 3500 40  0000 C CNN
F 1 "R" V 8107 3501 40  0000 C CNN
F 2 "~" V 8030 3500 30  0000 C CNN
F 3 "~" H 8100 3500 30  0000 C CNN
	1    8100 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 3200 7750 3200
Wire Wire Line
	7750 3200 8100 3200
Wire Wire Line
	8100 3750 8300 3750
Text Label 8200 3750 0    60   ~ 0
U?
Wire Notes Line
	6550 2850 8400 2850
Wire Notes Line
	8400 2850 8400 4650
Wire Notes Line
	8400 4650 6550 4650
Wire Notes Line
	6550 4650 6550 2850
Wire Wire Line
	8100 3200 8100 3250
Wire Wire Line
	5900 1050 5900 1600
$Comp
L CONN_17 LET_SP1
U 1 1 5245C38B
P 3950 7500
F 0 "LET_SP1" V 3910 7500 60  0000 C CNN
F 1 "Spodnja letva1" V 4030 7500 60  0000 C CNN
F 2 "" H 3950 7500 60  0000 C CNN
F 3 "" H 3950 7500 60  0000 C CNN
	1    3950 7500
	0    1    1    0   
$EndComp
$Comp
L CONN_17 LET_SP2
U 1 1 5245C3B8
P 5700 7500
F 0 "LET_SP2" V 5660 7500 60  0000 C CNN
F 1 "Spodnja letva2" V 5780 7500 60  0000 C CNN
F 2 "" H 5700 7500 60  0000 C CNN
F 3 "" H 5700 7500 60  0000 C CNN
	1    5700 7500
	0    1    1    0   
$EndComp
Text Label 3150 7050 1    39   ~ 8
V34
Text Label 3250 7050 1    39   ~ 8
V33
Text Label 3350 7050 1    39   ~ 8
V32
Text Label 3450 7050 1    39   ~ 8
V31
Wire Wire Line
	3150 6850 3150 7150
Wire Wire Line
	3250 6850 3250 7150
Wire Wire Line
	3350 6850 3350 7150
Wire Wire Line
	3450 6850 3450 7150
NoConn ~ 3250 6850
NoConn ~ 3350 6850
NoConn ~ 3450 6850
NoConn ~ 3550 6850
NoConn ~ 3150 6850
Text Notes 1600 4830 1    27   ~ 0
B15 B13 B11 E15 E13 E11 E09 E07 GND B01 C05 A07 A05 A03 A01 C03 C01 GND VDD GND
Text Notes 1750 4830 1    27   ~ 0
D08 B14 B12 B10 E14 E12 E10 E08 B02 B00 C04 A06 A04 A02 A00 C02 C00 RST VDD GND
Text Notes 9350 4830 1    27   ~ 0
A14 C10 C12 D01 D03 D05 D07 B04 B06 BT0 B08 E00 E02 E04 E06 C14 H00  3V  5V GND
Text Notes 9500 4830 1    27   ~ 0
A15 C11 D00 D02 D04 D06 B03 B05 B07 VDD B09 E01 E03 E05 C13 C15 H01  3V  5V GND
Text Label 1050 4000 0    39   ~ 8
GND
Wire Wire Line
	1250 3000 1000 3000
Wire Wire Line
	2300 3000 2050 3000
Text Label 1200 2900 2    39   ~ 8
GND
Text Label 1200 3090 2    39   ~ 8
GND
NoConn ~ 2300 3000
NoConn ~ 1000 3000
Wire Wire Line
	10050 3900 9800 3900
Wire Wire Line
	8750 3900 9000 3900
NoConn ~ 8750 3900
NoConn ~ 10050 3900
Wire Wire Line
	5800 1050 5800 1360
Wire Wire Line
	5800 1360 5800 1360
$EndSCHEMATC
