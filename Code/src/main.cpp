#include <main.h>

void setup() {
	// put your setup code here, to run once:

	//Start Serial Monitor
	Serial.begin(115200);

	//Perform Power On Self Test
	postChecks();

	Serial.println("POST Checks Passed");


	//Create Voltage Monitoring Task
	xTaskCreate(&voltMonTask, "Voltage Monitor", 112, nullptr, 1, nullptr);

	//Temperature Monitoring Task
	xTaskCreate(&tempTask, "Temperature Monitor", 112, nullptr, 1, nullptr);
	
	//Fan Control Task
	xTaskCreate(&fanControlTask, "Fan Control", 176, nullptr, 1, nullptr);

	vTaskStartScheduler();
}

void loop() {
	// put your main code here, to run repeatedly:
}