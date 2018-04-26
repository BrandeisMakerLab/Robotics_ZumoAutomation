/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
	Provides wrapper functions for the Zumo32U4LineSensors class
	April 4 2018
*/
//set up the Line header file
#ifndef Line_h
#define Line_h

//define the number of sensors that will be used
#define NUM_SENSORS 3

//include all the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <Zumo32U4LineSensors.h>
#include <Zumo32U4LCD.h>
#include <Line.h>

class Line{
	
	private:
		//the provided class, which will interface with the robot's line sensors
		Zumo32U4LineSensors lineReader;	
		//an array to store the line sensor readings
		uint16_t lineSensorReadings[NUM_SENSORS];
	public:
		//creates a new line object
		Line();
		//returns whether the robot is currently sensing a line of tape on the ground
		bool isOnLine();
		//prints all of the sensor readings to the lcd
		void printAllSensors(Zumo32U4LCD lcd);
		
};

#endif