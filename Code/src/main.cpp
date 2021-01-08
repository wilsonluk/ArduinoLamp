#include <main.h>

//TaskHandle_t switch_handler;

void setup() {
	// put your setup code here, to run once:
	Serial.begin(115200);
	Serial.println(F("\n\n"));

	sleep_state = false;
	//pinMode(IDLE_LED, OUTPUT);
	pinMode(LED_BUILTIN, OUTPUT);

	printWelcomeMsg();

	#ifdef RAMP_TEST_MODE
		msg_prnt(F("Ramp Test Mode enabled, Controls will not be available. Disable in main\n     header to switch back to normal operation.\n"))
	#endif

	//Perform Power On Self Test
	postChecks();
	debug_prnt(F("Returned from postChecks\n"));
	debug_prnt(F("Creating Tasks and Attaching Interrupts\n"));

	//Attach Power Switch Interrupt
	attachInterrupt(digitalPinToInterrupt(2), digitalPinInterruptHandler, FALLING);

	//Create Voltage Monitoring Task
	xTaskCreate(&voltMonTask, "V", 110, nullptr, 1, &volt_mon);
	
	//Fan Control Task
	xTaskCreate(&fanControlTask, "F", 212, nullptr, 1, &fan_ctrl);

	//LED Control
	xTaskCreate(&ledTask, "L", 96, nullptr, 2, &led_ctrl);

	//Potentiometer Control
	xTaskCreate(&potentiometerTask, "P", 128, nullptr, 2, &pot_read);

	// Create task for FreeRTOS notification
	xTaskCreate(TaskNotification, "N", 144, nullptr, 3, &switch_handler);

	//vTaskStartScheduler();
}

void loop() {
	Serial.flush();
	DIDR0 = 0x3F;
	ACSR &= ~_BV(ACIE);
	ACSR |= _BV(ACD);
	
	set_sleep_mode( SLEEP_MODE_IDLE );
	
	portENTER_CRITICAL();
	sleep_enable();
	
	// Only if there is support to disable the brown-out detection.
	#if defined(BODS) && defined(BODSE)
		sleep_bod_disable();
	#endif
	
	portEXIT_CRITICAL();
	sleep_cpu(); // good night.
	
	// Ugh. I've been woken up. Better disable sleep mode.
	//sleep_reset(); // sleep_reset is faster than sleep_disable() because it clears all sleep_mode() bits.
	if (sleep_state) {
		digitalWrite(LED_BUILTIN, HIGH);
		for (uint8_t i = 0; i < 250; i++) {
			delayMicroseconds(50000U);
		}
		for (uint8_t i = 0; i < 250; i++) {
			delayMicroseconds(50000U);
		}
		digitalWrite(LED_BUILTIN, LOW);
		for (uint8_t i = 0; i < 100; i++) {
			delayMicroseconds(50000U);
		}
	}
}

void TaskNotification(void *pvParameters)
{
	taskENTER_CRITICAL();

	pinMode(PWR_EN, INPUT);
	vTaskSuspend(pot_read);
	vTaskSuspend(fan_ctrl);
	vTaskSuspend(led_ctrl);
	vTaskSuspend(volt_mon);

	msg_prnt(F("Goodnight! I'll wait for the power switch. (-.-)Zzz...\n"));
	sleep_state = true;

	taskEXIT_CRITICAL();

	for (;;) {
		if (ulTaskNotifyTake(pdTRUE, portMAX_DELAY)) {
			debug_prnt(F("Power Button pushed!\n"));
			if (!sleep_state) {
				vTaskSuspend(led_ctrl);

				while (OCR1A || OCR1B) {
					if (OCR1A) OCR1A --;
					if (OCR1B) OCR1B --;

					delay(3);
				}
				pinMode(PWR_EN, INPUT);
				sleep_state = true;

				vTaskSuspend(pot_read);
				vTaskSuspend(fan_ctrl);
				vTaskSuspend(volt_mon);

				msg_prnt(F("Goodnight! (-.-)Zzz...\n"));
			} else {
				msg_prnt(F("Good Morning! (⋟﹏⋞)\n"));

				startTempSensor();
				pinMode(PWR_EN, OUTPUT);
				digitalWrite(PWR_EN, LOW);
				vTaskResume(pot_read);
				vTaskResume(led_ctrl);
				vTaskResume(volt_mon);

				waitForTemp();
				vTaskResume(fan_ctrl);

				taskYIELD();
				sleep_state = false;
			}

			while (digitalRead(2) == LOW) {}
			taskYIELD();
		} 
	}
}


void digitalPinInterruptHandler() {
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	vTaskNotifyGiveFromISR(switch_handler, &xHigherPriorityTaskWoken);
	if (xHigherPriorityTaskWoken) {
		taskYIELD();
	}
}