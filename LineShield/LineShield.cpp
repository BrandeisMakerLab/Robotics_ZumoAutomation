/*Written by Jacob Smith,Daniel Kang and Matthew Millendorf for Brandeis Robotics club
Provides readable wrapper functions for Zumo32U4LCD.h. The program is documented for
understanding by a general audience
April 4 2018*/
//include the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <ZumoShield.h>
#include "LineShield.h"

//assigns line sensor threshold values  to default
LineShield::LineShield(){
	lineReader.init();
	this->blackWhiteBoundary=500;

}

//assigns line sensor threshold values 
LineShield::LineShield(int blackWhiteBoundary){
	lineReader.init();
	this->blackWhiteBoundary=blackWhiteBoundary;


}

//first takes line sensor readings to see where the robot is in the sumo ring, and
//returns true if all of the sensors are darker than the edge tape, false otherwise
bool LineShield::isOnEdge(){
	lineReader.read(reflections);
	if (reflections[0]<=blackWhiteBoundary || reflections[1]<=blackWhiteBoundary || reflections[2]<=blackWhiteBoundary){
		return true;
	}
	return false;
	
}

//iterates through the array of current line sensor readings and prints each one to the robot's display
void LineShield::printAllSensors() {
	lineReader.read(reflections);
	for (int i=0;i<NUM_SENSORS;i++){
		Serial.print(i);
		Serial.print(":");
		Serial.println(reflections[i]);
		delay(1000);
	}
	
}
