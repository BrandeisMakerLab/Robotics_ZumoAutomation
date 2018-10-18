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
		uint16_t reflections[NUM_SENSORS];
		
		//thresholds for tape colors, the difference between the black and white boundary
		uint16_t blackWhiteBoundary;

	public:
	
		//creates a new line object with defual sensor reading
		Line();
	
		//creates a new line object with input sensor reading
		Line(int threshold);
		
		//returns whether the robot is on the edge of the ring
		bool isOnEdge();
		
		//prints all of the sensor readings to the lcd
		void printAllSensors(Zumo32U4LCD lcd);
		
};

#endif