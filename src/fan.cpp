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

void changeFanSpeed( uint16_t duty_cycle) {
    OCR2B = duty_cycle;
}

//Placeholder; Ramps fan up and down
void fanTask(void *pvParameters) {
    (void) pvParameters;

    if (startTempSensor() != 0) {
        failSafe();
        Serial.println("WARN: Temperature Sensor Not Responding");
        while (1) {}
    }

    double temperature;
    double output;

    PID fan_control(&temperature, &output, &set_temp, Kp, Ki, Kd, REVERSE);
    fan_control.SetOutputLimits(0, 250);

    startFanControl();

    changeFanSpeed(0);

    fan_control.SetMode(AUTOMATIC);

    uint8_t trip = 0;
    uint8_t count = 0;

    float smoothed_output;
    float history_1 = 0;
    float history_2 = 0;
    float history_3 = 0;

    for (;;) {
        digitalWrite(13, LOW);
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

            if (smoothed_output > 1) {
                count = 0;
                changeFanSpeed(smoothed_output + 4);
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
        digitalWrite(13, HIGH);
        vTaskDelayMS(100);
    }
}