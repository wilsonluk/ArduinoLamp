//______Arduino LED Lamp Power On Self Test______

#include <post.h>
#include <DallasTemperature.h>

bool postChecks() {
	debug_prnt(F("%S\n"), F("Starting Post Checks"));

	pinMode(COLD_WHITE_CONTROL, OUTPUT);
	pinMode(WARM_WHITE_CONTROL, OUTPUT);

	digitalWrite(COLD_WHITE_CONTROL, LOW);
	digitalWrite(WARM_WHITE_CONTROL, LOW);

	debug_prnt(F("LED Driver Lines Pulled LOW\n"));

	//Check Input Voltage
	unsigned int input_volt = checkSenseLine(INPUT_VOLTAGE);
	debug_prnt(F("Power Input Voltage -> %d mV\n"), input_volt);
	if (!checkInput(input_volt)) {
		error_prnt(F("Input Out of Tolerance\n"));
		failSafe(ALL);
	}

	//Turn on Main Power
	msg_prnt(F("Main Power Supply Turning On!\n"))
	digitalWrite(PWR_EN, LOW);
	pinMode(PWR_EN, OUTPUT);
	digitalWrite(PWR_EN, LOW);

	//Check Main Power
	unsigned int output_volt = checkSenseLine(MAIN_PWR_VOLTAGE);
	debug_prnt(F("Main Power Voltage -> %d mV\n"), output_volt);
	if (!checkOutput(output_volt)) {
		error_prnt(F("Main Power is out of tolerance! Shutting down\n"));
		digitalWrite(PWR_EN, HIGH);
		failSafe(ALL);
	}

	//Set UVO/UVP cutoffs
	setMonitorLimits(input_volt, output_volt);
	debug_prnt(F("Setting Voltage Protection Limits\n"));

	//Check for Fan
	if (!checkFanPresent()) failSafe(ALL);

	//Startup Temp Sensor
	if (!startTempSensor()) {
		error_prnt(F("Temperature Sensor Not Detected!\n"));
		failSafe(ALL);
	}

	msg_prnt(F("POST Checks Passed\n"));

	//Checks Passed
	return true;
}

bool checkFanPresent(){
	debug_prnt("Starting Fan Presence Detect\n");
	prepareFanPWM();
	
	changeFanSpeed(max_fan - min_fan);
	delay(300);
	unsigned int reading = checkSenseLine(FAN_VOLTAGE);
	debug_prnt(F("Full speed fan voltage -> %d mV\n"), reading);
	changeFanSpeed(0);
	if (reading > ovp_fan) {
		error_prnt(F("No load on fan output detected!\n"));
		return false;
	}

	changeFanSpeed((max_fan - min_fan) / 6);
	delay(250);
	reading = checkSenseLine(FAN_VOLTAGE);
	debug_prnt(F("Low speed fan voltage -> %d mV\n"), reading);
	changeFanSpeed(0);
	if (reading > (ovp_fan)) {
		error_prnt(F("Load on fan onput lower than expected!\n"));
		return false;
	} else if (reading < (ovp_fan / 4)) {
		error_prnt(F("Fan Output Overload!\n"));
		return false;
	}

	debug_prnt(F("Fan Present\n"));
	return true;
}