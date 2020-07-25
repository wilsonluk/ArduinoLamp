//LED Lamp - Under Voltage Lockout (UVLO)

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include <main.h>
#include <uvlo.h>
#include <safe.h>

void uvloSetup() {
    initial_voltage = inputVoltage();
    uvp_threshold   = initial_voltage * 0.95;
}

void uvloTask (void *pvParameters) {
    uvloSetup();

    for (;;) {
        uint16_t read_voltage = inputVoltage();

        if ((read_voltage < uvlo_threshold) || (read_voltage < uvlo_limit)) {
            failSafe();
        }

        vTaskDelayMS(500);
    }
}