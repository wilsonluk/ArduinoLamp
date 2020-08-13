//LED Lamp - Under Voltage Lockout (UVLO)

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include <main.h>
#include <uvlo.h>
#include <safe.h>

void uvloSetup() {
    initial_voltage = inputVoltage();
    uvp_threshold   = initial_voltage * 0.9;
    ovp_threshold   = initial_voltage * 1.1;
}

void changeADCReference(uint8_t mode) {
    analogReference(mode);
    analogRead(INPUT_VOLTAGE);
    delay(20);
}

uint16_t inputVoltage() {
    uint16_t read_value;

    vTaskSuspendAll();
    changeADCReference(INTERNAL);
    read_value = analogRead(INPUT_VOLTAGE);
    changeADCReference(DEFAULT);
    xTaskResumeAll();
    
    uint16_t input_voltage = read_value * voltage_divider / 1023.0 * reference_voltage;

    return input_voltage;
}

void uvloTask (void *pvParameters) {
    uvloSetup();

    for (;;) {
        uint16_t read_voltage = inputVoltage();

        Serial.print("$");
        Serial.print(read_voltage);
        Serial.println(";");
        
        if ((read_voltage < uvp_threshold) || (read_voltage < uvlo_limit) || (read_voltage > ovp_threshold)) {
            vTaskSuspendAll();
            failSafe();
            Serial.println("ERR:  Input Voltage Deviation");
            Serial.print("Measured Voltage: ");
            Serial.print(read_voltage);
            Serial.println(" mV");
            while (1) {}
        }

        vTaskDelayMS(750);
    }
}