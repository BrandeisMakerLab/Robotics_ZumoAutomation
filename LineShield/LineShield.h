/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
	Provides wrapper functions for the Zumo32U4LineShieldShieldSensors class
	April 4 2018
*/
//set up the LineShieldShield header file
#ifndef LineShield_h
#define LineShield_h

//define the number of sensors that will be used
#define NUM_SENSORS 6

//include all the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include<ZumoShield.h>

class LineShield {

  private:
    //the provided class, which will interface with the robot's LineShieldShield sensors
    ZumoReflectanceSensorArray lineReader;

    //an array to store the LineShieldShield sensor readings
    unsigned int reflections[NUM_SENSORS];

    //finds the minimum and maximums reflections from last reading
    void findMinMax();

    //the minimum and maximum brightness values in one read
    int min;
    int max;

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


};

#endif
