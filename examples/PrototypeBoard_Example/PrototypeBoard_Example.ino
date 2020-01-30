/* Demonstrates use of sensors wird in to zumo shield robot
 *  The actual sensors can be changed, but the pin numbers are hard wired
 *  deis Robotics 10/16/2019
*/
//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
//The object used to interfact with the class
DistanceSensor distancesensor;
//the distance to the sensor
int distance;
//the pin the led is on
int led = 13;
//the pin the potentiometer is on
int potPin = 0;    // select the input pin for the potentiometer
//the position of the potentiometer
int potPos = 0;  
//the threhsold for whether the light should come on
int threshold=0;

//runs once
void setup() {
  //sets up the class
  distancesensor.begin(2, 6);
  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  //set up pin for light
  pinMode(led, OUTPUT);
}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //read the position of the potentiometer 
  potPos = analogRead(potPin);
  //display distance to screen
  Serial.print("Distance\t");
  Serial.print(distance);
  //display pontiometer position to screen, scaled for convenience
  Serial.print("\tPotentiometer\t");
  threshold=potPos/6;
  Serial.print(threshold);
  //display light state to screen
  Serial.print("\tLED\t");
  //logic to control if light is on or off
  //light on if distance less than threshold
  if (distance < threshold) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.println("ON");
  //light off if distance greater than equal to threhsold
  } else {                  // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    Serial.println("OFF");
  }
  //wait for half a second for conveneince and so light stays on
  delay(500);
}
