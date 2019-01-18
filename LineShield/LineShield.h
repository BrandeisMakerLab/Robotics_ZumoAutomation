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
    //used for calibration, the minumum and maximum reflectance from the previous reading
    int min;
    int max;
    //an array to store the LineShieldShield sensor readings
    uint16_t reflections[NUM_SENSORS];

    //thresholds for tape colors, the difference between the black and white boundary
    uint16_t blackWhiteBoundary;

    //finds the minimum and maximums reflections from last reading
    void findMinMax();

  public:

    //creates a new LineShieldShield object with defual sensor reading
    LineShield();

    //creates a new LineShieldShield object with input sensor reading
    LineShield(int threshold);

    //returns whether the robot is on the edge of the ring
    bool isOnEdge();

    //returns the minimum sensor value from alst reading
    int getMin();
    
    //returns the maximum sensor value from alst reading
    int getMax();

    //prints all of the sensor readings to the lcd
    void printAllSensors();

   

};

#endif
