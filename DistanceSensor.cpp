/*Ultrasonic Library created from these examples
https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
https://www.theengineeringprojects.com/2017/08/ultrasonic-sensor-arduino-interfacing.html
by Jacob Smith 7/8/2019 for Brandeis Automation Lab Workshop
Reads distacne from an ultrasonic sensor 2019/07/08*/

//this should work on all boards, so there is no preprocessor directive here

//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>

//Creates a new DistanceSensor object
DistanceSensor::DistanceSensor() {
}

//Initializes the class, can't always be done at same time as constructor
void DistanceSensor::begin(int trigPin, int echoPin) {
    //defines pins numbers for trigger
    this->trigPin = trigPin;
    //defines pin numbers for echo
    this->echoPin = echoPin;
	// Sets the trigPin as an Output
    pinMode(trigPin, OUTPUT);
    // Sets the echoPin as an Input
    pinMode(echoPin, INPUT);

}

//gets the distance from the ultrasonic sensor
int DistanceSensor::getDistance() {
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    int duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    int distance = duration * .034/ 2;
    // Prints the distance on the Serial Monitor
    return distance;

}