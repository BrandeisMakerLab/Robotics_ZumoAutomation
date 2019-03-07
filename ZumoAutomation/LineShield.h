/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
	Provides wrapper functions for the Zumo32U4LineShieldShieldSensors class
	April 4 2018
*/
//set up the LineShieldShield header file
#ifndef LineShield_h
#define LineShield_h

//include all the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <ZumoReflectanceSensorArray.h>

class LineShield {

  private:
    //the provided class, which will interface with the robot's LineShieldShield sensors
    ZumoReflectanceSensorArray lineReader;

    //an array to store the LineShieldShield sensor readings
    //declared at an arbitrary size and then actually used with numSensors
    unsigned int reflections[10];

    //an array to store the number of sensors for convenineve
    int numSensors;

    //finds the minimum and maximums reflections from last reading
    void findMinMax();

    //the minimum and maximum brightness values in one read
    int min;
    int max;

    int minThresh;
    int maxThresh;

  public:

    //creates a new LineShieldShield object with defual sensor reading
    LineShield();

    //returns the minimum sensor value from alst reading
    int getMin();

    //returns the maximum sensor value from alst reading
    int getMax();

    //prints all of the sensor readings to the lcd
    void printAllSensors();

    //modify an array of line sensor values
    void getReflections(unsigned int clientArray []);

    //returns whether robot is on gray region
    bool isOnWhite();


};

#endif
