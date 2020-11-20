EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4450 3450 0    50   Input ~ 0
VIN
Text HLabel 7200 3450 2    50   Input ~ 0
FAN
Text HLabel 4450 4400 0    50   Input ~ 0
GND
Text HLabel 7200 4000 2    50   Input ~ 0
FB
$Comp
L Device:L L4
U 1 1 5F8E9295
P 6250 3450
F 0 "L4" V 6440 3450 50  0000 C CNN
F 1 "330U" V 6349 3450 50  0000 C CNN
F 2 "ArduinoLamp:SLD10" H 6250 3450 50  0001 C CNN
F 3 "~" H 6250 3450 50  0001 C CNN
F 4 "SLD10D40S331MTT" H 6250 3450 50  0001 C CNN "Manufacturer_Part_Number"
	1    6250 3450
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Schottky D3
U 1 1 5F8E9922
P 6100 3850
F 0 "D3" V 6054 3930 50  0000 L CNN
F 1 "SS24" V 6145 3930 50  0000 L CNN
F 2 "ArduinoLamp:D_SMA_Handsoldering_Shortened" H 6100 3850 50  0001 C CNN
F 3 "~" H 6100 3850 50  0001 C CNN
F 4 "" H 6100 3850 50  0001 C CNN "Mouser Part Number"
F 5 "C181203" H 6100 3850 50  0001 C CNN "Arrow Part Number"
	1    6100 3850
	0    1    1    0   
$EndComp
$Comp
L Device:C C17
U 1 1 5F8EC349
P 6550 3850
F 0 "C17" H 6665 3896 50  0000 L CNN
F 1 "2U2" H 6665 3805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6588 3700 50  0001 C CNN
F 3 "~" H 6550 3850 50  0001 C CNN
F 4 "C0805X5R225K500NT" H 6550 3850 50  0001 C CNN "Manufacturer_Part_Number"
	1    6550 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R18
U 1 1 5F8ECD7F
P 6950 3700
F 0 "R18" H 7020 3746 50  0000 L CNN
F 1 "25K5" H 7020 3655 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6880 3700 50  0001 C CNN
F 3 "~" H 6950 3700 50  0001 C CNN
F 4 "RS-05K2552FT" H 6950 3700 50  0001 C CNN "Manufacturer_Part_Number"
	1    6950 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R19
U 1 1 5F8ED5C2
P 6950 4200
F 0 "R19" H 7020 4246 50  0000 L CNN
F 1 "1K15" H 7020 4155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6880 4200 50  0001 C CNN
F 3 "~" H 6950 4200 50  0001 C CNN
F 4 "RS-03K1151FT" H 6950 4200 50  0001 C CNN "Manufacturer_Part_Number"
	1    6950 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 4050 6950 4000
Wire Wire Line
	6950 4000 7200 4000
Wire Wire Line
	5650 4400 5650 4300
Wire Wire Line
	6950 4350 6950 4400
Wire Wire Line
	6950 4400 6550 4400
Connection ~ 6550 4400
Wire Wire Line
	6550 3700 6550 3450
Wire Wire Line
	6550 3450 6950 3450
Wire Wire Line
	6950 3450 6950 3550
Connection ~ 6950 3450
Wire Wire Line
	6950 3450 7200 3450
Wire Wire Line
	6400 3450 6550 3450
Connection ~ 6550 3450
Wire Wire Line
	6100 3450 6100 3700
$Comp
L Device:R R27
U 1 1 5FAF10C0
P 5200 3600
F 0 "R27" H 5270 3646 50  0000 L CNN
F 1 "105K" H 5270 3555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5130 3600 50  0001 C CNN
F 3 "~" H 5200 3600 50  0001 C CNN
F 4 "RC0603FR-07105KL" H 5200 3600 50  0001 C CNN "Manufacturer_Part_Number"
	1    5200 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 5F8FA0B3
P 4750 3600
F 0 "R16" H 4820 3646 50  0000 L CNN
F 1 "105K" H 4820 3555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4680 3600 50  0001 C CNN
F 3 "~" H 4750 3600 50  0001 C CNN
F 4 "RC0603FR-07105KL" H 4750 3600 50  0001 C CNN "Manufacturer_Part_Number"
	1    4750 3600
	1    0    0    -1  
$EndComp
Connection ~ 5650 4400
Connection ~ 6100 3450
Wire Wire Line
	5850 3450 6100 3450
Connection ~ 6100 4400
Wire Wire Line
	6100 4400 6550 4400
Wire Wire Line
	5650 4400 6100 4400
$Comp
L Transistor_FET:2N7000 Q3
U 1 1 5F8F3832
P 5550 4100
F 0 "Q3" H 5754 4146 50  0000 L CNN
F 1 "2N7000" H 5754 4055 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 5750 4025 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 5550 4100 50  0001 L CNN
F 4 "2N7000" H 5550 4100 50  0001 C CNN "Manufacturer_Part_Number"
	1    5550 4100
	1    0    0    -1  
$EndComp
Connection ~ 5200 3450
Wire Wire Line
	4450 3450 4750 3450
Connection ~ 4750 3450
Wire Wire Line
	4750 3450 5200 3450
Wire Wire Line
	4750 3750 4750 3800
Wire Wire Line
	5200 3450 5450 3450
Wire Wire Line
	4450 4050 5200 4050
Text HLabel 4450 4050 0    50   Input ~ 0
PWM
Connection ~ 5200 4050
Wire Wire Line
	5200 4050 5200 4100
Wire Wire Line
	5200 4050 5350 4050
Wire Wire Line
	5350 4050 5350 4100
$Comp
L Transistor_FET:TSM2301ACX Q4
U 1 1 5F8E71B4
P 5650 3550
F 0 "Q4" H 5854 3596 50  0000 L CNN
F 1 "PJM2301PSA-S" H 5854 3505 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5850 3475 50  0001 L CIN
F 3 "https://www.taiwansemi.com/products/datasheet/TSM2301A_C15.pdf" H 5650 3550 50  0001 L CNN
F 4 "PJM2301PSA-S" H 5650 3550 50  0001 C CNN "Manufacturer_Part_Number"
	1    5650 3550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5200 3750 5200 4050
Wire Wire Line
	6100 4000 6100 4400
Wire Wire Line
	6550 4000 6550 4400
Wire Wire Line
	5650 3800 5650 3750
Wire Wire Line
	4750 3800 5650 3800
Wire Wire Line
	5650 3900 5650 3800
Connection ~ 5650 3800
Wire Wire Line
	6950 3850 6950 4000
Connection ~ 6950 4000
Wire Wire Line
	4450 4400 5200 4400
$Comp
L Device:D_Zener D7
U 1 1 5FB97005
P 5200 4250
F 0 "D7" V 5154 4330 50  0000 L CNN
F 1 "D_Zener" V 5245 4330 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 5200 4250 50  0001 C CNN
F 3 "~" H 5200 4250 50  0001 C CNN
	1    5200 4250
	0    1    1    0   
$EndComp
Connection ~ 5200 4400
Wire Wire Line
	5200 4400 5650 4400
$EndSCHEMATC
