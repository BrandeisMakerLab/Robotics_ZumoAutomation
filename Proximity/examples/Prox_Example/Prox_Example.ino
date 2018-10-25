/* Written by Jacob Smith for Brandies Robotcs Club October 18 2018
  this program is designed to allow the ZUMO32U4 robot to print its proximity sensors
  in. */
//libraries used in this program
#include <Proximity.h>
#include <Zumo32U4.h>

//prox is a proximity sensor that can be accessed prox.<method name>
//lcd is the screen on the zumo32u4 robot that can be accessed using 
Proximity prox;
Zumo32U4LCD lcd;

//The setup method only runs once
void setup() {
 //initialize the robot's display
 lcd.init();
 //set the top of the display to label which readout is which
 //left, center left, center right, right
 lcd.print("L CL CR R");

}

//the loop method repeats forever
void loop() {
  //ask the prox sensor to print its sensor values to the lCD
  prox.printAllSensors(lcd);

}
