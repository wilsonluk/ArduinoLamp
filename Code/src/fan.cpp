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

  Serial.println("Fan Task Alive");
  double output;
  double temperature;

  PID fan_control(&temperature, &output, &target_temp, Kp, Ki, Kd, REVERSE);
  fan_control.SetOutputLimits(0, max_fan - min_fan);

  fan_control.SetMode(AUTOMATIC);

  byte trip = 0;
  byte count = 0;

  float smoothed_output;
  float history_1 = 0;
  float history_2 = 0;
  float history_3 = 0;

  //Wait for first reading from the sensor
  vTaskDelayMS(1000);

  for (;;) {
    temperature = getTemp();
    fan_control.Compute();

    if (trip) {
      history_3 = history_2;
      history_2 = history_1;
      history_1 = output;

      smoothed_output = (history_1 + history_2 + history_3)/3;

      if (smoothed_output > 0) {
        count = 0;
        changeFanSpeed(smoothed_output);
      } else {
        if (count >= 30) {
          count = 0;
          changeFanSpeed(0);
        } else {
          count++;
        }
      }

      Serial.flush();
    }
    trip = 1;
    vTaskDelayMS(500);
  }
}