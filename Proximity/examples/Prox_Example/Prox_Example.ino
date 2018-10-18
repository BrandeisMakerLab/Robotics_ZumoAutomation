/* Written by Jacob Smith for Brandies Robotcs Club May 6 2018
  this program is designed to allow the ZUMO32U4 robot to print its proximity sensors
  in. */
//libraries used in this program
#include <Proximity.h>
#include <Zumo32U4.h>

Proximity prox;
Zumo32U4LCD lcd;

void setup() {
 lcd.init();

}

void loop() {
  
  prox.printAllSensors(lcd);

}
