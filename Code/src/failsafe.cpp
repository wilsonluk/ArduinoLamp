/*_______________Arduino LED Lamp Failsafe Shutdown______________
Cuts power to various systems on the board. Calledin case of anomaly.
*/

#include <failsafe.h>

//___________________________Functions___________________________

//Shutdown functions of the lamp depending on the input
void failSafe(byte err_type){
	error_prnt(F("Failsafe Triggered!\n"));

	taskENTER_CRITICAL();

	//Turn off LEDs (regardless of error type)
	pinMode(COLD_WHITE_CONTROL, OUTPUT);
	pinMode(WARM_WHITE_CONTROL, OUTPUT);

	digitalWrite(COLD_WHITE_CONTROL, LOW);
	digitalWrite(WARM_WHITE_CONTROL, LOW);

	switch (err_type) {
		case OTP:
			OCR1A = 0;
			OCR1B = 0;
			changeFanSpeed(max_fan - min_fan);
			break;
		
		case ALL:
			pinMode(PWR_EN, INPUT);
			changeFanSpeed(0);
			break;

		default:
			break;
	}
	Serial.flush();
	blinkCode(err_type);
}

void blinkCode(byte err_type) {
	for (;;) {
		switch (err_type) {
			case OTP:
				ON(SHORT_DELAY);
				OFF(LONG_DELAY);
				ON(LONG_DELAY);
				OFF(SHORT_DELAY);
				break;

			case ALL:
				ON(SHORT_DELAY);
				OFF(LONG_DELAY);
				ON(SHORT_DELAY);
				OFF(LONG_DELAY);
				break;

			default:
				break;
		}

		END_DELAY;
	}
}