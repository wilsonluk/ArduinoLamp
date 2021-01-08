//______Arduino LED Lamp Vltage Monitor______

#include <voltmon.h>

void voltMonTask(void *pvParameters) {

	for (;;) {
		unsigned int read_value;

		bool trip = false;

		digitalWrite(LED_BUILTIN, LOW);
		read_value = checkSenseLine(INPUT_VOLTAGE);
		trip |= !checkInput(read_value);

		vTaskDelayMS(300);

		read_value = checkSenseLine(MAIN_PWR_VOLTAGE);
		trip |= !checkOutput(read_value);

		vTaskDelayMS(300);

		read_value = checkSenseLine(FAN_VOLTAGE);
		trip |= !checkFan(read_value);

		if (trip) {
			failSafe(ALL);
		}

		digitalWrite(LED_BUILTIN, HIGH);
		
		vTaskDelayMS(300);
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
	return (!(val < uvp_input) && !(val > ovp_input));
}

//Check Output Voltage
bool checkOutput(unsigned int val){
	return (!(val < uvp_output) && !(val > ovp_output));
}

//Check Fan Voltage
bool checkFan(unsigned int val) {
	return !(val > ovp_fan);
}