/* Prints distance to screen and demonstrates indiciator light
   Created from example program and turned into class by Jacob Smith
   Deis Robotics 10/16/2019
*/
//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
//Display display;
//The object used to interfact with the class
DistanceSensor distancesensor;
//the distance to the sensor
int distance;
//the port of the indicator light
int led = 3;

//runs once
void setup() {
  //sets up the class
  distancesensor.begin(10, 11);
  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //display distance to screen
  Serial.println(distance);
  //logic to control led, turn it on if it is within certain distance
  if (distance < 50) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    //turn led off if sensor greater than distance
  } else {                  // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  }
  //wait half a second to see results easier
  delay(500);
}
