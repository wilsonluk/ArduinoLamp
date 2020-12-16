//______Arduino LED Lamp VOltage Monitor______

#include <voltmon.h>

void voltMonTask(void *pvParameters) {
	pinMode(LED_BUILTIN, OUTPUT);

	for (;;) {
		unsigned int read_value;

		digitalWrite(LED_BUILTIN, HIGH);
		read_value = checkSenseLine(INPUT_VOLTAGE);
		digitalWrite(LED_BUILTIN, LOW);
		if (!checkInput(read_value)) failSafe(ALL);

		digitalWrite(LED_BUILTIN, HIGH);
		read_value = checkSenseLine(MAIN_PWR_VOLTAGE);
		digitalWrite(LED_BUILTIN, LOW);
		if (!checkOutput(read_value)) failSafe(ALL);

		digitalWrite(LED_BUILTIN, HIGH);
		read_value = checkSenseLine(FAN_VOLTAGE);
		digitalWrite(LED_BUILTIN, LOW);
		if (!checkFan(read_value)) failSafe(ALL);

		
		vTaskDelayMS(1000);
	}
}

unsigned int checkSenseLine(byte analogPin) {
	//Prevent Scheduler from context switching while ADC swtiched to AREF
	vTaskSuspendAll();

	//Change to AREF reference instead of VCC to reduce noise
	analogReference(INTERNAL);
	//analogReads and/or delay needed to complete switch over (https://www.arduino.cc/reference/en/language/functions/analog-io/analogreference)
	for (uint8_t i = 0; i < 2; i++) {
		analogRead(A0);
	}
	delay(25);

	//Sample given pin
	unsigned int reading = 0;
	for (byte loop = 0; loop < 2; loop++) {
		reading += analogRead(analogPin);
	}
	reading = reading / 2;

	//Set ADC Reference back to default
	analogReference(DEFAULT);
	//analogReads and/or delay needed to complete switch over (https://www.arduino.cc/reference/en/language/functions/analog-io/analogreference)
	for (uint8_t j = 0; j < 2; j++) {
		analogRead(A0);
	}
	delay(25);

	//Resume Scheduler
	xTaskResumeAll();

	//Convert from ADC value to mV using resistor divider ratio (see main.h)
	return (unsigned long)reading * voltage_divider / 1023.0 * reference_voltage / 1000;
}

void setMonitorLimits(unsigned int input_volt, unsigned int output_volt) {
	//Set Input UVP
	uvp_input = max(uvp_input, input_volt * (1 - margin));

	//Set Input OVP
	ovp_input = min(ovp_input, input_volt * (1 + margin));

	//Set Output UVP
	uvp_output = max(uvp_output, output_volt * (1 - margin));

	//Set Output OVP
	ovp_output = min(ovp_output, output_volt * (1 + margin));
}

//Check Input Voltage
bool checkInput(unsigned int val) {
	if (val < uvp_input) {
		Serial.print("Input UVP Triggered: ");
		Serial.print(val);
		Serial.println(" mV");
		return false;
	} else if (val > ovp_input) {
		Serial.print("Input OVP Triggered: ");
		Serial.println(val);
		Serial.println(" mV");
		return false;
	}
	return true;
}

//Check Output Voltage
bool checkOutput(unsigned int val){
	if (val < uvp_output) {
		Serial.print("Output UVP Triggered: ");
		Serial.print(val);
		Serial.println(" mV");
		return false;
	} else if (val > ovp_output) {
		Serial.print("Output OVP Triggered: ");
		Serial.print(val);
		Serial.println(" mV");
		return false;
	}
	return true;
}

//Check Fan Voltage
bool checkFan(unsigned int val) {
	Serial.println(val);
	if (val > ovp_fan) {
		Serial.print("Fan OVP Triggered: ");
		Serial.print(val);
		Serial.println(" mV");
		return false;
	}
	return true;
}