#ifndef LED_LAMP_LED_CONTROL
#define LED_LAMP_LED_CONTROL

#include <main.h>

//______Arduino LED Lamp LED Drive Signal Generator______

void ledDriverSetup();
void updateBrightness();

void changeTargetBrightness(unsigned int blue, unsigned int yellow);

void ledTask(void *pvParameters);

static volatile unsigned int target_blue;
static volatile unsigned int target_yellow;

#endif