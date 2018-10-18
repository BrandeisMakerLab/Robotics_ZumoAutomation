/*Written by Jacob Smith for Brandeis Robotics club
Provides readable wrapper functions for the Zumo Proximity Sensors
October 11 2018 using https://www.youtube.com/watch?v=ddPo6HQvxzQ as model*/
//include the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <Zumo32U4ProximitySensors.h>
#include <Zumo32U4LCD.h>
#include "Proximity.h"


//create a new Line object, and initialize the robot's sensors
Proximity::Proximity(){
	prox.initThreeSensors();
	
}

//reads the proximity sensors and returns the left distance
int Proximity::getLeftCounts(){
	prox.read();
	return prox.countsLeftWithLeftLeds();
	
	
}

//reads the proximity sensors and returns the center left distance
int Proximity::getCenterLeftCounts(){
	prox.read();
	return prox.countsFrontWithLeftLeds();
	
	
}

//reads the proximity sensors and returns the center right distance
int Proximity::getCenterRightCounts(){
	prox.read();
	return prox.countsFrontWithRightLeds();
	
	
}

//reads the proximity sensors and returns the right distance
int Proximity::getRightCounts(){
	prox.read();
	return prox.countsRightWithRightLeds();

}

//iterates through the array of current line sensor readings and prints each one to the robot's display
void Proximity::printAllSensors(Zumo32U4LCD lcd) {
	//set the top of the display to label which readout is which
 //left, center left, center right, right
 lcd.print("L CL CR R");
	
	lcd.gotoXY(0,0);
	
	lcd.print(getLeftCounts());
	lcd.print(" ");
	
	
	lcd.print(getCenterLeftCounts());
	lcd.print(" ");
	
	lcd.print(getCenterRightCounts());
	lcd.print(" ");
	
	lcd.print(getRightCounts());
	lcd.print("  ");
	
	
	
}
