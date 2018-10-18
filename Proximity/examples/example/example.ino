/* Written by Jacob Smith for Brandies Robotcs Club May 6 2018
  this program is designed to allow the ZUMO32U4 robot to navigate in a sumo ring
  with black tape on the inside, gray/blue tape in the in bounds edge, and a white
  out of bounds outer layer. The robot displays how many matches it lost and the current region it is
  in. */
//libraries used in this program
#include <Proximity.h>
#include <Zumo32U4.h>

Proximity prox;


void setup() {
 

}

void loop() {
  prox.printAllSensors();

}
