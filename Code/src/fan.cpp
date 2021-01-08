//_______Arduino LED Lamp Fan Controller________

#include <fan.h>
#include <PID_v1.h>

void prepareFanPWM() {
  pinMode(FAN_CONTROL, OUTPUT);
  digitalWrite(FAN_CONTROL, LOW);

  OCR2B = 255;

  TCCR2A |= (1 << COM2B1);
  TCCR2A |= (1 << WGM20);
  TCCR2B &= 0b11111000;

  TCCR2B |= (1 << CS20);

  debug_prnt(F("Fan PWM Hardware Timer Setup\n"));
}

void changeFanSpeed(byte speed) {

  //Change PWM state and duty cycle
  if (speed > 0) {
    //Turn Timer2B PWM On
    TCCR2A |= (1 << COM2B1);
    OCR2B = speed + min_fan;
  } else {
    //Turn Timer2B PWM Off
    TCCR2A &= ~(1 << COM2B1);
    OCR2B = 0;
  }
}

void fanControlTask(void *pvParameters) {
  double output = 0;
  double temperature = getTemp();

  PID fan_control(&temperature, &output, &target_temp, Kp, Ki, Kd, REVERSE);
  fan_control.SetOutputLimits(0, max_fan - min_fan);

  fan_control.SetMode(AUTOMATIC);

  byte trip = 0;
  byte count = 0;

  double history_1 = 0;
  double history_2 = 0;

  for (;;) {
    temperature = getTemp();

    debug_prnt(F("Temperature - %d.%02d C\n"), int(temperature), int(100 *(temperature - int(temperature))));

    fan_control.Compute();

    if (trip) {
      history_2 = history_1;
      history_1 = output;

      double smoothed_output = (history_1 + history_2)/2;

      if (smoothed_output > 0.0) {
        count = 0;
        changeFanSpeed(smoothed_output + 1);
      } else {
        if (count >= 30) {
          count = 0;
          changeFanSpeed(0);
        } else {
          count++;
        }
      }
    }
    trip = 1;
  }
}