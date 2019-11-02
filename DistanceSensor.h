/*Ultrasonic Library created from these examples
https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
https://www.theengineeringprojects.com/2017/08/ultrasonic-sensor-arduino-interfacing.html
by Jacob Smith 7/8/2019 for Brandeis Automation Lab Workshop
Reads distacne from an ultrasonic sensor 2019/07/08*/

//sets up the DistanceSensor Header file
#ifndef DistanceSensor_h
#define DistanceSensor_h

//this should work on all boards, so there is no preprocessor directive here

//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
#include <Arduino.h>


class DistanceSensor{
  private:
    //defines pins numbers for trigger
    int trigPin;
    //defines pin numbers for echo
    int echoPin;
  public:
    //Creates a new DistanceSensor object
    DistanceSensor();
    //Initializes the class, can't always be done at same time as constructor
    void begin(int trigPin, int echoPin);
    //gets the distance from the ultrasonic sensor
    int getDistance();
};
#endif
