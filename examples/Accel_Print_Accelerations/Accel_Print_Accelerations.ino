/*Written by Jacob Smith for Brandeis Robotics Club
   contains an example program to use the Accel class.
   Prints Accelerations to the console in centimeters per second squared
   November 30 2018
*/
//includes the header file of the library and to Zumo library
#include <Accel.h>
#include<Wire.h>
//creates a global reference to an Accel object
Accel accelerometer;

//occurs before the program enters its main loop
void setup() {
  //set up USB communication with computer (only necessary if you want to print results to screen)
  Serial.begin(9600);//send data at 9600 bits per second, provided example value
  while (!Serial) {}
  //initialze accelerometer
  Wire.begin();
  accelerometer.initializeCompass();
  //print introduction
  Serial.println("Welcome to Brandeis Univeristy Acceleration demo");
  Serial.println("Results are in millimeters per second squared");
  delay(2000);
}

//the main loop of the robot
//prints the robot's accelerations on x y and z axes every tenth of a second
void loop() {
  accelerometer.printAccels();
  delay(100);
}
