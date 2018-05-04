/*Written by Jacob Smith,Daniel Kang and Matthew Millendorf for Brandeis Robotics club
Provides readable wrapper functions for Zumo32U4LCD.h. The program is documented for
understanding by a general audience
April 4 2018*/
//include the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include<Zumo32U4LineSensors.h>
#include <Zumo32U4LCD.h>
#include "Line.h"


//create a new Line object, and initialize the robot's sensors
Line::Line(){
	lineReader.initThreeSensors();
}

//assigns line sensor threshold values 
//edge are leftMost and Rightmost line sensors
//middle is middle Line Sensor
Line::Line(int edgeLow,int edgeHigh,int middleLow,int middleHigh){
	lineReader.initThreeSensors();
	this->edgeLow=edgeLow;
	this->edgeHigh=edgeHigh;
	this->middleLow=middleLow;
	this->middleHigh=middleHigh;
}


//update the array of line sensor readings
//and iterate through it, if any of the sensors are on the line, then rthe sensor is on the line
bool Line::isOnEdge () {
	lineReader.read(reflections, true);
	for (int i=0;i<NUM_SENSORS;i++){
		if (reflections[i]>804){
			return true;
		
		}
	}
	return false;
}

//returns a string representing where the robot is in the zumo ring, using three colors of tape going from dark on inside to blue on edge to white on out  of bounds
//INRING,EDGE,OUTBOUNDS
const char* Line::getRegion(){
	lineReader.read(reflections,true);
	if(within(reflections[0],edgeLow,edgeHigh)||within(reflections[1],middleLow,middleHigh)||within(reflections[2],edgeLow,edgeHigh)){
		return "EDGE";
	}else if(reflections[0]<edgeLow || reflections[1]<middleLow  || reflections[2]<edgeHigh){
		return "OUTBOUNDS";
	}else{
		return "INRING";
	}
}
//iterates through the array of current line sensor readings and prints each one to the robot's display
void Line::printAllSensors(Zumo32U4LCD lcd) {
	lineReader.read(reflections,true);
	for (int i=0;i<NUM_SENSORS;i++){
		lcd.clear();
		lcd.print(i);
		lcd.print(":");
		lcd.print(reflections[i]);
		delay(1000);
	}
	lcd.clear();
	
}

//returns whether the first arument is within the second and third
bool Line::within(int num, int min,int max){
	return num>min && num<max;
}

