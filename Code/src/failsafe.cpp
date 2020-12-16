/*_______________Arduino LED Lamp Failsafe Shutdown______________
Cuts power to various systems on the board. Calledin case of anomaly.
*/

#include <failsafe.h>

//___________________________Functions___________________________

//Shutdown functions of the lamp depending on the input
void failSafe(byte err_type){
	taskENTER_CRITICAL();

	//Turn off LEDs (regardless of error type)
	pinMode(WARM_WHITE_CONTROL, INPUT);
	pinMode(COLD_WHITE_CONTROL, INPUT);

	switch (err_type) {
		case OTP:
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