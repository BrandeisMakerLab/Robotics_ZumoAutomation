/*Written by Jacob Smith,Daniel Kang and Matthew Millendorf for Brandeis Robotics club
Provides readable wrapper functions for Zumo32U4LCD.h. The program is documented for
understanding by a general audience
April 4 2018*/
//include the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include<Zumo32U4LineSensors.h>
#include <Zumo32U4LCD.h>
#include <ZumoShield.h>
#include "Line.h"

//assigns line sensor threshold values  to default
Line::Line(){
	lineReader.initThreeSensors();
	this->blackWhiteBoundary=500;

}

//assigns line sensor threshold values 
Line::Line(int blackWhiteBoundary){
	lineReader.initThreeSensors();
	this->blackWhiteBoundary=blackWhiteBoundary;

}

//first takes line sensor readings to see where the robot is in the sumo ring, and
//returns true if all of the sensors are darker than the edge tape, false otherwise
bool Line::isOnEdge(){
	lineReader.read(reflections,true);
	if (reflections[0]<=blackWhiteBoundary || reflections[1]<=blackWhiteBoundary || reflections[2]<=blackWhiteBoundary){
		return true;
	}
	return false;
	
}

//Prints the robot's location using senosr values
void Line::detectRegion(Zumo32U4LCD lcd) {
	lineReader.read(reflections,true);
	relfections[];//[0,1,2]
	intx= relfections[0];
	inty= relfections[1];
	intz= relfections[2];
	if (x>800 || y>800||z>800){print "hey, you are in the boundary";}
	elseif(){}
	elseif(){}
	else{}
	
	
	lcd.clear();
	
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
