#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <main.h>
#include <potentiometer.h>

void pollPotentiometers(uint16_t *brightness, uint16_t *color) {
    *brightness = analogRead(BRIGHTNESS_POTENTIOMETER);
    *color      = 511/*analogRead(COLOR_POTENTIOMETER)*/;
}

void calculateLogValues(uint16_t *brightness, uint16_t *color) {
    uint16_t log_brightness = pgm_read_word_near(&brightness_lut[*brightness]);

    if (log_brightness > max_brightness) {
        log_brightness = max_brightness;
    }

    uint32_t yellow_driver_val = (uint32_t) log_brightness * (*color) / 1025;
    uint32_t blue_driver_val   = (uint32_t) log_brightness * (1024 - (*color)) / 1025;

    target_blue   = blue_driver_val;
    target_yellow = yellow_driver_val;
}

void potentiometerTask(void *pvParameters) {
    uint16_t brightness, color;

    while (1) {
        pollPotentiometers(&brightness, &color);
        calculateLogValues(&brightness, &color);

        vTaskDelayMS(100);
    }
}