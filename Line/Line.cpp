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

//update the array of line sensor readings
//and iterate through it, if any of the sensors are on the line, then rthe sensor is on the line
bool Line::isOnLine () {
	lineReader.read(lineSensorReadings, true);
	for (int i=0;i<NUM_SENSORS;i++){
		if (lineSensorReadings[i]>804){
			return true;
		
		}
	}
	return false;
}

//iterates through the array of current line sensor readings and prints each one to the robot's display
void Line::printAllSensors(Zumo32U4LCD lcd) {
	lineReader.read(lineSensorReadings,true);
	for (int i=0;i<NUM_SENSORS;i++){
		lcd.clear();
		lcd.print(i);
		lcd.print(":");
		lcd.print(lineSensorReadings[i]);
		delay(1000);
	}
	lcd.clear();
	
}

