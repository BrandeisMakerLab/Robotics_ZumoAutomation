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
	this->edgeLow=393;
	this->edgeHigh=1028;
	this->middleLow=243;
	this->middleHigh=741;
	
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

//returns a string representing where the robot is in the zumo ring, using three colors of tape going from dark on inside to blue on edge to white on out  of bounds
//INRING,EDGE,OUTBOUNDS
const char* Line::getRegion(){
	if (isInRing()){
		return "INRING";
	}else if (isOnEdge()){
		return "ONEDGE";
	}else if (isOutBounds()){
		return "OUTBOUNDS";
	}else{
		return "";
	}
	
}

//first takes line sensor readings to see where the robot is in the sumo ring, and
//returns true if all of the sensors are darker than the edge tape, false otherwise
bool Line::isInRing(){
	lineReader.read(reflections,true);
	if (reflections[0]>=edgeHigh && reflections[1]>=middleHigh && reflections[2]>=edgeHigh){
		return true;
	}
	return false;
	
}

//first takes line sensor readings to see where the robot is in the sumo ring, and
//returns true if any of the line sensor reflections are bright enough to be the out of bounds tape
bool Line::isOutBounds(){
	lineReader.read(reflections,true);
	if(reflections[0]<edgeLow || reflections[1]<middleLow  || reflections[2]<edgeLow){
		return true;
	}
	return false;
}

//first takes line sensor readings to see where the robot is in the sumo ring, and
//returns true if any of the sensors are brigher than the inside tape but darker than the out of bounds tape
bool Line::isOnEdge(){
	lineReader.read(reflections,true);
	if(within(reflections[0],edgeLow,edgeHigh)||within(reflections[1],middleLow,middleHigh)||within(reflections[2],edgeLow,edgeHigh)){
		return true;
	}
	return false;
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

//returns whether the first argument is within the second and third
//helper method for isOnEdge function
bool Line::within(int num, int min,int max){
	return num>min && num<max;
}
