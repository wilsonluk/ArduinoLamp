//______Arduino LED Lamp LED Drive Signal Generator______

#include <led.h>

void ledDriverSetup() {
	pinMode(COLD_WHITE_CONTROL, OUTPUT);
	pinMode(WARM_WHITE_CONTROL, OUTPUT);

	ICR1 = 640;

	TCCR1A = 0;
	TCCR1B = 0;

	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12)|(1 << WGM13);
	// set Fast PWM mode using ICR1 as TOP

	TCCR1B |= (1 << CS10);
}

void changeTargetBrightness(unsigned int blue, unsigned int yellow) {
	target_blue = blue;
	target_yellow = yellow;
}

void updateBrightness() {
	while (1) {
		vTaskDelayMS(25); 
		
		if (OCR1A < target_blue) {
			TCCR1A |= (1 << COM1A1);

			if (target_blue - OCR1A >= 6) {
				OCR1A += 6;
			} else {
				OCR1A++;
			}

		} else if (OCR1A > target_blue) {
			if (OCR1A - target_blue >= 6) {
				OCR1A -= 6;
			} else {
				OCR1A--;
			}

			if (OCR1A == 0) {
				TCCR1A &= ~(1 << COM1A1);
			}
		}

		if (OCR1B < target_yellow) {
			TCCR1A |= (1 << COM1B1);

			if (target_yellow - OCR1B >= 6) {
				OCR1B += 6;
			} else {
				OCR1B++;
			}

		} else if (OCR1B > target_yellow) {
			if (OCR1B - target_yellow >= 6) {
				OCR1B -= 6;
			} else {
				OCR1B--;
			}

			if (OCR1B == 0) {
				TCCR1A &= ~(1 << COM1B1);
			}
		}
	}
}

void ledTask(void *pvParameters) {
	ledDriverSetup();

	updateBrightness();
}
