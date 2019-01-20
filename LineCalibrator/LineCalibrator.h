/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
	Provides wrapper functions for the Zumo32U4LineCalibratorShieldSensors class
	April 4 2018
*/
//set up the LineCalibratorShield header file
#ifndef LineCalibrator_h
#define LineCalibrator_h

//define the number of sensors that will be used
#define NUM_SENSORS 6

//include all the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include<LineShield.h>

//the number of regions the robot has
#define NUM_REGIONS 3
class LineCalibrator {

  private:
    //the LineReader object that will allow this class to use the line sensors
    LineShield lineReader;
    ////the number of times the robot will take a measrument per region
    int  NUM_READINGS = 3;
    //an array of ring regions
    char* regions[NUM_REGIONS] = {"BLACK", "WHITE", "GRAY"};

    //an array of the minimum sensor readig for each region
   int regionMins[NUM_REGIONS];
   //an array of the maximum brightness reading for each region
   int regionMaxes[NUM_REGIONS];
    
    //the minimum and maximum brighness readings
    int min;
    int max;
    //an array o thresholds between the regions
    int regionThresholds[NUM_REGIONS - 1];

    //reads the line sensors the specified number of times
    int takeReadingRegion(char* region);
    //updates the minimum and maimum bightness readings
    //passing the trial number so min an max can be initilized
    void updateMinMax(int reading);
    //sorts the arrays of brightness so regions can be in any order on sumo board
    //without this function,the sumo ing couldn't be in order black white gray, for example 
    void selectionSort();
    //swaps two elements in an array of intgers, for the slection sort
    void swap(int minIndex, int nonMinIndex, int nums[]);
    //swaps two elements in an array of strings, fo the slection sort
    void swap(int minIndex, int nonMinIndex, char* regions[]);

    //displays the brightness and region arrays to the screen
    void displayArrays();
    
  public:

    //creates a new LineCalibratorShield object with lineReader object to read sensor data
    LineCalibrator(LineShield lineReader);
    //moves the robot over the series of colors, and determines threshold values
    calibrateLineSensors();
};
#endif

