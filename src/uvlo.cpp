//LED Lamp Under Voltage Lockout (UVLO)

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <main.h>
#include <uvlo.h>

void uvloTask (void *pvParameters) {
    uint16_t initial_voltage = inputVoltage();
    uint16_t uvp_threshold   = initial_voltage * 0.95;  
    uint16_t uvlo_threshold  = initial_voltage * 0.9;

    for (;;) {
        uint16_t read_voltage = inputVoltage();
        //Under Voltage Lockout
        vTaskDelayMS(500);
    }
}