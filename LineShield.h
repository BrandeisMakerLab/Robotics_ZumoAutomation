/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
	Provides wrapper functions for the Zumo32U4LineShieldShieldSensors class
	April 4 2018
*/
//set up the LineShieldShield header file
#ifndef LineShield_h
#define LineShield_h

//only compile this class if the board is correct
#ifdef ARDUINO_AVR_UNO

//include all the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>

#include <ZumoReflectanceSensorArray.h>


class LineShield {

  private:
    
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

    int lastRegion;

  public:

    //creates a new LineShieldShield object with defualt sensor reading
    LineShield();

    //creates a new LineShieldShield object with provided thresholds
    LineShield(int minThresh, int maxThresh);

    //initializes all the variables that this class needs, like a constructor
    void initializeVars(int minThresh, int maxThresh);

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

    //return the region the robot is on, gray, white or black
    int getRegion();


};
#elif defined (DONT_NEED_LINE)
	#warning : May lead to "error: 'LineShield' does not name a type" ; Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html
	
#else
	#error : Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; Quick fix: add <#define DONT_NEED_LINE> to top ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html
#endif
#endif