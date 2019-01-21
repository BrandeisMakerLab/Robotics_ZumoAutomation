/*Written by Jacob Smith for Brandeis Robotics club
	Calibrates the zumo robots line sensors
	April 4 2018
*/
//set up the LineCalibratorShield header file
#ifndef LineCalibrator_h
#define LineCalibrator_h

//include all the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include<LineShield.h>
#include<Sorter.h>

//the number of regions the robot has

class LineCalibrator : public LineShield {

  private:
    //the LineReader object that will allow this class to use the line sensors
    LineShield lineReader;
    ////the number of times the robot will take a measrument per region
    int  NUM_READINGS = 3;

    //the number of regions the ring has
    int numRegions;
    
    //an array of ring regions
    String* regions;

    //an array of String regions in the order of their importance
    String *regionsPriority;
    
    //an array of the minimum sensor readig for each region
    int* regionMins;
    //an array of the maximum brightness reading for each region
    int* regionMaxes;

    //an array to thresholds between the regions
    int* regionThresholds;
   
    //the minimum and maximum brightness values globally
    int minGlobal;
    int maxGlobal;  
     
    //reads the line sensors the specified number of times
    void takeReadingRegion(String region);
    //updates the minimum and maimum bightness readings
    //passing the trial number so min an max can be initilized
    void updateMinMax(int reading);
   
    //displays the brightness and region arrays to the screen
    void displayArrays();

  public:

    //creates a new LineCalibratorShield object with lineReader object to read sensor data
    LineCalibrator(String* regions,int numRegions);
    //moves the robot over the series of colors, and determines threshold values
    void calibrateLineSensors();

    //returns the array of thresholds
    int* getThresholds();
};
#endif

