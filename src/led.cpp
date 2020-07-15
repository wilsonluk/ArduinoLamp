#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <main.h>
#include <led.h>

void ledDriverSetup() {
    pinMode(COLD_WHITE_CONTROL, OUTPUT);
    pinMode(WARM_WHITE_CONTROL, OUTPUT);

    ICR1=511;

    TCCR1A = 0;
    TCCR1B = 0;

    TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
    // set none-inverting mode

    TCCR1A |= (1 << WGM11);
    TCCR1B |= (1 << WGM12)|(1 << WGM13);
    // set Fast PWM mode using ICR1 as TOP

    TCCR1B |= (1 << CS10);
}

void changeTargetBrightness(uint16_t blue, uint16_t yellow) {
    target_blue = blue;
    target_yellow = yellow;
}

void updateBrightness() {
    while (1) {
        vTaskDelayMS(15);
                
        if (OCR1A < target_blue) {
            OCR1A++;
        } else if (OCR1A > target_blue) {
            OCR1A--;
        }

        if (OCR1B < target_yellow) {
            OCR1B++;
        } else if (OCR1B > target_yellow) {
            OCR1B--;
        }
    }
}

void ledTask(void *pvParameters) {
    ledDriverSetup();
    updateBrightness();
}

