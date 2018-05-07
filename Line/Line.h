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
		
		//thresholds for tape colors, edge is used for left and right sensors
		//middle is used for middle sensor
		uint16_t edgeLow;
		uint16_t edgeHigh;
		uint16_t middleLow;
		uint16_t middleHigh;
		
		//returns whether the first arument is within the second and third
		bool within(int num, int min,int max);

	public:
		//creates a new line object
		Line();
		//creates a new Line object, with given presets
		Line(int edgeLow,int edgeHigh,int middleLow,int middleHigh);
		//returns whether the robot is inside the sumo ring
		bool isInRing();
		//returns whether the robot is over the in bounss tape on the edge of the ring
		bool isOnEdge();
		//returns whether the robot is over the out of bounds tape on the outside of the ring
		bool isOutBounds();
		//returns the region of the robot on lines of tape
		const char* getRegion();
		//prints all of the sensor readings to the lcd
		void printAllSensors(Zumo32U4LCD lcd);
		
};

#endif