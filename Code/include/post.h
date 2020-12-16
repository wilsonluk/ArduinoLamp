#ifndef ARDUINO_LAMP_POST
#define ARDUINO_LAMP_POST

#include <main.h>

/*______Arduino LED Lamp Power On Self Test______
Tests for basic functionality of core components
before handing off control of the LED Lamp to the
RTOS. Tests the main power supply and fan
controller voltages. Fan controller is also tested
to ensure there is a reasonable load on the output
to make sure a fan is present, and is reasonsible
for main power supply turn on at boot time.
*/

//_________________Functions____________________

//Main POST function, returns True if POST successful
bool postChecks();

//Check resistance on fan output similar to a fan
bool checkFanPresent();

#endif
