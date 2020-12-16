//______Arduino LED Lamp Power On Self Test______

#include <post.h>
#include <DallasTemperature.h>

bool postChecks() {
	Serial.println("Starting POST Checks");

	//Check Input Voltage
	unsigned int input_volt = checkSenseLine(INPUT_VOLTAGE);
	if (!checkInput(input_volt)) while (1) {}

	//Turn on Main Power
	digitalWrite(PWR_EN, LOW);
	pinMode(PWR_EN, OUTPUT);
	digitalWrite(PWR_EN, LOW);

	//Check Main Power
	unsigned int output_volt = checkSenseLine(MAIN_PWR_VOLTAGE);
	if (!checkOutput(output_volt)) {
		digitalWrite(PWR_EN, HIGH);
		while (1) {}
	}

	//Set UVO/UVP cutoffs
	setMonitorLimits(input_volt, output_volt);

	//Check for Fan
	if (!checkFanPresent()) while (1) {}

	if (!startTempSensor()) {
		Serial.println("Temperature sensor not detected!");
		while (1) {}
	}

	//Checks Passed
	return true;
}

bool checkFanPresent(){
	prepareFanPWM();
	
	changeFanSpeed(max_fan - min_fan);
	delay(300);
	unsigned int reading = checkSenseLine(FAN_VOLTAGE);
	changeFanSpeed(0);
	if (reading > ovp_fan) {
		Serial.println("Fan OVP!");
		return false;
	}

	changeFanSpeed((max_fan - min_fan) / 6);
	delay(300);
	reading = checkSenseLine(FAN_VOLTAGE);
	changeFanSpeed(0);
	if (reading > (ovp_fan)) {
		Serial.print("Load on fan input not detected!");
		Serial.println(reading);
		return false;
	} else if (reading < (ovp_fan / 4)) {
		Serial.println("Overload on fan input!");
		return false;
	}
	return true;
}