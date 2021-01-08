#include <pot.h>
#include <led.h>


void pollPotentiometers(unsigned int *brightness, unsigned int *color) {
	taskENTER_CRITICAL();
	delay(25);
	*brightness = 1023 - analogRead(BRIGHTNESS_POTENTIOMETER);
	*color      = analogRead(COLOR_POTENTIOMETER);
	delay(25);
	taskEXIT_CRITICAL();
}

void calculateLogValues(unsigned int *brightness, unsigned int *color) {
	unsigned int log_brightness = pgm_read_word_near(&brightness_lut[*brightness]);

	if (log_brightness > 640) {
		log_brightness = 640;
	}

	unsigned int yellow_driver_val = (unsigned long) log_brightness * (*color) / 1025;
	unsigned int blue_driver_val   = (unsigned long) log_brightness * (1024 - (*color)) / 1025;

	changeTargetBrightness((unsigned int) blue_driver_val, (unsigned int) yellow_driver_val);
}

void potentiometerTask(void *pvParameters) {
	unsigned int brightness, color;

	while (1) {
		#ifdef RAMP_TEST_MODE
			brightness = random(1023);
			color = random(1023);
			msg_prnt(F("Ramp Test Mode ---- B:%d, C:%d\n"), brightness, color);
			calculateLogValues(&brightness, &color); 
			vTaskDelayMS(1000);
		#else
			pollPotentiometers(&brightness, &color);
			calculateLogValues(&brightness, &color);
		#endif
		
		vTaskDelayMS(75);
	}
}