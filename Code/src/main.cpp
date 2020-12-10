#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include <main.h>
#include <led.h>
#include <potentiometer.h>
#include <fan.h>
#include <uvlo.h>
#include <safe.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.println("______Arduino LED Lamp______");
  Serial.println("Beginning Power On Self Test");

  //Run Startup Sequence
  bootUpSequence();

  Serial.println("Self test passed, continuing startup");

  /*xTaskCreate(
    uvloTask,
    "Under Voltage Lockout",
    128,
    nullptr,
    4,
    nullptr);

  xTaskCreate(
    fanTask,
    "Fan",
    256,
    nullptr,
    3,
    nullptr);

  xTaskCreate(
    potentiometerTask,
    "User Input",
    128,
    nullptr,
    2,
    nullptr);

  xTaskCreate(
    ledTask,
    "LED Driver",
    128,
    nullptr,
    2,
    nullptr);*/
}

void loop() {
}
  // put your main code here, to run repeatedly:


  //TODO: Startup Sequence

  //check for the input voltage
  //ensure the LED Driver signals are LOW
  
  //ensure fan signal is HIGH

  //enable main power
  //wait for voltage settling

  //check main voltage
  //check fan voltage

  //shutdown fan

  //

void bootUpSequence() {

  printDebug("Starting Main Power Supply Self Checks");
  if (mainPowerOn()) {
    //failSafe(ALL);
    while(1){}
  }

  printDebug("Starting Fan Controller Self Checks");
  if (checkForFan()) {
    //failSafe(ALL);
    while(1){}
  }

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

bool mainPowerOn() {
  uint16_t input_voltage = safeAnalogReadSingle(INPUT_VOLTAGE, INTERNAL);
  
  if (input_voltage < uvlo_limit || input_voltage > ovp_limit) {
    printError("Input Voltage out of tolerance: " + (String)input_voltage + " mV");
    return 1;
  }

  printDebug("Input Voltage in tolerence: " + (String)input_voltage + " mV");
  printWarn("Main power supply coming online");
  pinMode(PWR_EN, OUTPUT);
  digitalWrite(PWR_EN, LOW);
  delay(100);

  uint16_t output_voltage = safeAnalogReadSingle(MAIN_PWR_VOLTAGE, INTERNAL);

  if (output_voltage < nominal_output * (1 - margin) || output_voltage > nominal_output * (1 + margin)) {
    printError("Output Voltage out of tolerence: " + (String)output_voltage + " mV");
    return 1;
  }

  printDebug("Output Voltage in tolerence: " + (String)output_voltage + " mV");

  return 0;
}

uint16_t safeAnalogReadSingle(uint8_t pin, uint8_t adc_mode) {
  uint8_t pin_list[2] = {pin, 0xFF};
  uint16_t voltage;
  safeAnalogRead(pin_list, &voltage, INTERNAL);
  voltage = (unsigned long)voltage * voltage_divider / 1023.0 * reference_voltage / 1000;
  return voltage;
}

void safeAnalogRead(uint8_t *pin_list, uint16_t *readings, uint8_t adc_mode) {
  //Stop the scheduler from context switching while reading
  vTaskSuspendAll();

  //Change the ADC mode if needed
  if (adc_mode == INTERNAL) {
    analogReference(INTERNAL);

    //Run an analogRead to complete ADC change over
    analogRead(A1);
    delay(10);
  }

  //Sample all of the pins needed
  uint8_t index = 0;
  while (*(pin_list + index) != 0xFF) {
    uint16_t reading = analogRead(*(pin_list + index));
    *(readings + index) = reading;
    index++;
  }

  //Reset ADC and resume scheduler
  changeADCReference(DEFAULT);
  xTaskResumeAll();
}