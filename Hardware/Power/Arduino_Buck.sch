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
Text HLabel 4450 3600 0    50   Input ~ 0
VIN
Text HLabel 7200 3600 2    50   Input ~ 0
FAN
Text HLabel 4450 4400 0    50   Input ~ 0
GND
Text HLabel 7200 4000 2    50   Input ~ 0
FB
$Comp
L Transistor_FET:TSM2301ACX Q4
U 1 1 5F8E71B4
P 5650 3700
F 0 "Q4" H 5854 3746 50  0000 L CNN
F 1 "PJM2301PSA-S" H 5854 3655 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5850 3625 50  0001 L CIN
F 3 "https://www.taiwansemi.com/products/datasheet/TSM2301A_C15.pdf" H 5650 3700 50  0001 L CNN
F 4 "PJM2301PSA-S" H 5650 3700 50  0001 C CNN "Manufacturer_Part_Number"
	1    5650 3700
	0    -1   -1   0   
$EndComp
$Comp
L Device:L L4
U 1 1 5F8E9295
P 6250 3600
F 0 "L4" V 6440 3600 50  0000 C CNN
F 1 "330U" V 6349 3600 50  0000 C CNN
F 2 "ArduinoLamp:SLD10" H 6250 3600 50  0001 C CNN
F 3 "~" H 6250 3600 50  0001 C CNN
F 4 "SLD10D40S331MTT" H 6250 3600 50  0001 C CNN "Manufacturer_Part_Number"
	1    6250 3600
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Schottky D3
U 1 1 5F8E9922
P 6100 4000
F 0 "D3" V 6054 4080 50  0000 L CNN
F 1 "SS24" V 6145 4080 50  0000 L CNN
F 2 "ArduinoLamp:D_SMA_Handsoldering_Shortened" H 6100 4000 50  0001 C CNN
F 3 "~" H 6100 4000 50  0001 C CNN
F 4 "" H 6100 4000 50  0001 C CNN "Mouser Part Number"
F 5 "C181203" H 6100 4000 50  0001 C CNN "Arrow Part Number"
	1    6100 4000
	0    1    1    0   
$EndComp
$Comp
L Device:C C17
U 1 1 5F8EC349
P 6550 4000
F 0 "C17" H 6665 4046 50  0000 L CNN
F 1 "2U2" H 6665 3955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6588 3850 50  0001 C CNN
F 3 "~" H 6550 4000 50  0001 C CNN
F 4 "C0805X5R225K500NT" H 6550 4000 50  0001 C CNN "Manufacturer_Part_Number"
	1    6550 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R18
U 1 1 5F8ECD7F
P 6950 3850
F 0 "R18" H 7020 3896 50  0000 L CNN
F 1 "25K5" H 7020 3805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6880 3850 50  0001 C CNN
F 3 "~" H 6950 3850 50  0001 C CNN
F 4 "RS-05K2552FT" H 6950 3850 50  0001 C CNN "Manufacturer_Part_Number"
	1    6950 3850
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
Connection ~ 6950 4000
$Comp
L Device:R R17
U 1 1 5F8F67F8
P 5200 4250
F 0 "R17" H 5270 4296 50  0000 L CNN
F 1 "25K5" H 5270 4205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5130 4250 50  0001 C CNN
F 3 "~" H 5200 4250 50  0001 C CNN
F 4 "RS-05K2552FT" H 5200 4250 50  0001 C CNN "Manufacturer_Part_Number"
	1    5200 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 4400 5650 4300
Wire Wire Line
	6550 4150 6550 4400
Wire Wire Line
	6950 4350 6950 4400
Wire Wire Line
	6950 4400 6550 4400
Connection ~ 6550 4400
Wire Wire Line
	6550 3850 6550 3600
Wire Wire Line
	6550 3600 6950 3600
Wire Wire Line
	6950 3600 6950 3700
Connection ~ 6950 3600
Wire Wire Line
	6950 3600 7200 3600
Wire Wire Line
	6400 3600 6550 3600
Connection ~ 6550 3600
Wire Wire Line
	6100 3600 6100 3850
Wire Wire Line
	6100 4150 6100 4400
$Comp
L Device:R R27
U 1 1 5FAF10C0
P 5200 3750
F 0 "R27" H 5270 3796 50  0000 L CNN
F 1 "105K" H 5270 3705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5130 3750 50  0001 C CNN
F 3 "~" H 5200 3750 50  0001 C CNN
F 4 "RC0603FR-07105KL" H 5200 3750 50  0001 C CNN "Manufacturer_Part_Number"
	1    5200 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 5F8FA0B3
P 4750 3750
F 0 "R16" H 4820 3796 50  0000 L CNN
F 1 "105K" H 4820 3705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4680 3750 50  0001 C CNN
F 3 "~" H 4750 3750 50  0001 C CNN
F 4 "RC0603FR-07105KL" H 4750 3750 50  0001 C CNN "Manufacturer_Part_Number"
	1    4750 3750
	1    0    0    -1  
$EndComp
Connection ~ 5650 4400
Connection ~ 6100 3600
Wire Wire Line
	5850 3600 6100 3600
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
Connection ~ 5200 3600
Wire Wire Line
	5200 4400 5650 4400
Wire Wire Line
	4450 3600 4750 3600
Connection ~ 4750 3600
Wire Wire Line
	4750 3600 5200 3600
Wire Wire Line
	4750 3900 4750 3950
Wire Wire Line
	5200 3600 5450 3600
Wire Wire Line
	5650 3850 5400 3850
Wire Wire Line
	5400 3850 5400 3950
Wire Wire Line
	5400 3950 4750 3950
Connection ~ 4750 3950
Wire Wire Line
	4750 3950 4750 4100
Wire Wire Line
	4450 4050 5200 4050
Text HLabel 4450 4050 0    50   Input ~ 0
PWM
Connection ~ 5200 4050
Wire Wire Line
	5200 4050 5200 4100
Wire Wire Line
	5200 3900 5200 4050
Wire Wire Line
	5200 4050 5350 4050
Wire Wire Line
	5350 4050 5350 4100
$Comp
L Device:R R28
U 1 1 5FB23D33
P 4750 4250
F 0 "R28" H 4820 4296 50  0000 L CNN
F 1 "25K5" H 4820 4205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4680 4250 50  0001 C CNN
F 3 "~" H 4750 4250 50  0001 C CNN
F 4 "RS-05K2552FT" H 4750 4250 50  0001 C CNN "Manufacturer_Part_Number"
	1    4750 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 4400 4750 4400
Wire Wire Line
	4750 4400 5200 4400
Connection ~ 4750 4400
Connection ~ 5200 4400
$EndSCHEMATC
