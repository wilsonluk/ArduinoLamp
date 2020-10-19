//LED Lamp - Fail Safe (safe mode)

#include <Arduino.h>

#include <main.h>
#include <safe.h>

void disableLeds() {
    pinMode(COLD_WHITE_CONTROL, INPUT);
    pinMode(WARM_WHITE_CONTROL, INPUT);
}

void maxFan() {
    TCCR2A &= !(1 << WGM20);
    pinMode(FAN_CONTROL, OUTPUT);
    digitalWrite(FAN_CONTROL, HIGH);
}

void failSafe() {
    disableLeds();
    maxFan();
}