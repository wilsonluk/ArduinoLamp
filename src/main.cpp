#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include <fan.h>
#include <uvlo.h>
#include <temp.h>
#include <main.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println(TEMP_SENSOR_TIME);

  //--------------------- TEMPORARY ----------------------//
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  ICR1=511;
  OCR1A=100;
  OCR1B=100;

  TCCR1A = 0;
  TCCR1B = 0;

  TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
  // set none-inverting mode

  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12)|(1 << WGM13);
  // set Fast PWM mode using ICR1 as TOP
    
  TCCR1B |= (1 << CS10);
  // START the timer with no prescaler
  //--------------------- TEMPORARY ----------------------//

  if (startTempSensor()) {
    for(;;) {}
  }

  startFanControl();

  xTaskCreate(
    temperatureTask,
    "Temperature",
    128,
    nullptr,
    2,
    nullptr);

  xTaskCreate(
    uvloTask,
    "Under Voltage Lockout",
    128,
    nullptr,
    2,
    nullptr);

  xTaskCreate(
    fanTask,
    "Fan",
    96,
    nullptr,
    2,
    nullptr);
  
  xTaskCreate(
    TaskBlink,
    "Blink",
    123,
    nullptr,
    2,
    nullptr);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelayMS(100);
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelayMS(1900);
  }
}