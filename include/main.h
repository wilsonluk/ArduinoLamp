#ifndef LED_LAMP_CONTROL
#define LED_LAMP_CONTROL

//Libraries
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//______Digital Pin Assignments______
#define TEMP_SENSOR_INPUT  2
#define FAN_CONTROL        3    //Timer 2 Control prevents use of pin 11 for PWM
#define COLD_WHITE_CONTROL 9
#define WARM_WHITE_CONTROL 10

//_______Analog Pin Assignments______
#define BRIGHTNESS_POTENTIOMETER A4
#define COLOR_POTENTIOMETER      A5
#define INPUT_VOLTAGE            A6

//______________Macros_______________
#define vTaskDelayMS(ms) (vTaskDelay(ms / portTICK_PERIOD_MS))

#define waitForTemp()    (vTaskDelayMS(TEMP_SENSOR_TIME))
#define TEMP_SENSOR_TIME ((750 / (1 << (12 - temp_resolution))) + 1)
#define TEMP_LIMIT 85

//__________Constant Values__________
static const uint16_t voltage_divider  = 5700;
static const uint16_t uvlo_limit = 4000;
static const uint8_t  temp_resolution = 10;

//_____________Variables_____________
static uint16_t initial_voltage;
static uint16_t sag_voltage;
static uint8_t uvlo_status = 0;
static uint16_t brightness = 450;

static uint8_t otp_status = 0;

//Temperature Sensor
static OneWire one_wire;
static DallasTemperature temp_sensor;
static DeviceAddress temp_sensor_addr;

//_____________Functions_____________

void TaskBlink(void *pvParameters);

#endif

