EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4000 3000 0    50   Input ~ 0
VIN
Text HLabel 6650 3000 2    50   Input ~ 0
VOUT
Text HLabel 4000 3650 0    50   Input ~ 0
GND
$Comp
L Transistor_FET:SUD08P06-155L Q5
U 1 1 5FC4B104
P 5350 3100
F 0 "Q5" V 5692 3100 50  0000 C CNN
F 1 "SUD08P06-155L" V 5601 3100 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 5545 3025 50  0001 L CIN
F 3 "https://www.vishay.com/docs/62843/sud08p06-155l-ge3.pdf" H 5350 3100 50  0001 C CNN
	1    5350 3100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4000 3000 5150 3000
Wire Wire Line
	5550 3000 5700 3000
$Comp
L Device:D_Zener D6
U 1 1 5FC4D9A6
P 5700 3150
F 0 "D6" V 5654 3230 50  0000 L CNN
F 1 "D_Zener" V 5745 3230 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 5700 3150 50  0001 C CNN
F 3 "~" H 5700 3150 50  0001 C CNN
	1    5700 3150
	0    1    1    0   
$EndComp
Connection ~ 5700 3000
Wire Wire Line
	5700 3000 6650 3000
Wire Wire Line
	5350 3300 5700 3300
$Comp
L Device:R R11
U 1 1 5FC4E57E
P 5350 3450
F 0 "R11" H 5420 3496 50  0000 L CNN
F 1 "R" H 5420 3405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5280 3450 50  0001 C CNN
F 3 "~" H 5350 3450 50  0001 C CNN
F 4 "RS-05K2552FT" H 5350 3450 50  0001 C CNN "Manufacturer_Part_Number"
	1    5350 3450
	1    0    0    -1  
$EndComp
Connection ~ 5350 3300
Wire Wire Line
	4000 3650 5350 3650
Wire Wire Line
	5350 3650 5350 3600
$EndSCHEMATC
