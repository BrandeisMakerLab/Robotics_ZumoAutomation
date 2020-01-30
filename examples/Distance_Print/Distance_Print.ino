/* Prints distance to screen
   Created from example program and turned into class by Jacob Smith
   Brandeis Robotics Club 10/16/2019
*/
//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
//Display display;
//The object used to interfact with the class
DistanceSensor distancesensor;
//the distance to the sensor
int distance;

//runs once
void setup() {
  //sets up the class
  distancesensor.begin(10, 11);
  //sets up the class with minimum and maximum values
  Serial.begin(9600);
}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //display distance to screen
  Serial.println(distance);
}
