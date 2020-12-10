//LED Lamp - PID Temperature Contolled Fan

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <PID_v1.h>

#include <main.h>
#include <fan.h>
#include <temp.h>
#include <safe.h>

void startFanControl() {
  pinMode(FAN_CONTROL, OUTPUT);

  OCR2B = 255;

  TCCR2A |= (1 << COM2B1);
  TCCR2A |= (1 << WGM20);
  TCCR2B &= 0b11111000;

  TCCR2B |= (1 << CS20);
}

//Change the buck converter PWM duty cycle for the fan output
void changeFanSpeed( uint16_t speed) {
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

//Check analog pin and multiply divider ratio
uint16_t checkFanVoltage() {
  uint8_t pin_list[2] = {FAN_VOLTAGE, 0xFF};
  uint16_t voltage;
  safeAnalogRead(pin_list, &voltage, INTERNAL);
  voltage = (unsigned long)voltage * voltage_divider / 1023.0 * reference_voltage / 1000;
  return voltage;
}

//Check that a fan-like load is present
bool checkForFan() {
  startFanControl();

  //Check voltage at max speed
  changeFanSpeed(max_fan);
  uint16_t full_speed_voltage = checkFanVoltage();
  if (!((full_speed_voltage > (fan_nominal * 0.9)) && (full_speed_voltage < (fan_nominal * 1.1)))) {
    printError("NO FAN LOAD DETECTED OR OVERLOAD, " + (String)full_speed_voltage + " mV at max_fan");
    changeFanSpeed(0);
    return 1;
  }
  printDebug("Full speed fan voltage " + (String)full_speed_voltage + " mV");
  
  delay(500);

  //Check voltage at 25% power
  changeFanSpeed((max_fan + min_fan) / 4);
  uint16_t mid_speed_voltage = checkFanVoltage();
  if (!(mid_speed_voltage < (fan_nominal * 0.75))) {
    printError("NO LOAD DETECTED, " + (String)mid_speed_voltage + " mV");
    changeFanSpeed(0);
    return 1;
  }
  printDebug("Mid speed fan voltage " + (String)mid_speed_voltage + " mV at 25% duty cycle");

  delay(250);
  changeFanSpeed(0);
  return 0;
}

void fanTask(void *pvParameters) {
  (void) pvParameters;

  if (startTempSensor() != 0) {
    failSafe();
    printError("Temperature Sensor Not Responding");
    while (1) {}    //TODO: goto failsafe instead of spinning
  }

  double temperature;
  double output;

  PID fan_control(&temperature, &output, &set_temp, Kp, Ki, Kd, REVERSE);
  fan_control.SetOutputLimits(0, max_fan - min_fan);

  fan_control.SetMode(AUTOMATIC);

  uint8_t trip = 0;
  uint8_t count = 0;

  float smoothed_output;
  float history_1 = 0;
  float history_2 = 0;
  float history_3 = 0;

  for (;;) {
    temperature = checkTemperature();
    fan_control.Compute();

    if (temperature >= TEMP_LIMIT) {
      failSafe();
    }

    if (trip) {
      history_3 = history_2;
      history_2 = history_1;
      history_1 = output;

      smoothed_output = (history_1 + history_2 + history_3)/3;

      if (smoothed_output > 0) {
        count = 0;
        changeFanSpeed(smoothed_output);
      } else {
        if (count >= 60) {
          count = 0;
          changeFanSpeed(0);
        } else {
          count++;
        }
      }

      /*Serial.print("$");
      Serial.print(temperature);
      Serial.print(" ");
      Serial.print(output);
      Serial.print(" ");
      Serial.print(smoothed_output);
      Serial.print(" ");
      Serial.print(OCR2B);
      Serial.println(";");*/
    }
    trip = 1;
    vTaskDelayMS(100);
  }
}