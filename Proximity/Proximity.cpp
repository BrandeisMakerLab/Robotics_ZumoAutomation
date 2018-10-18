/*Written by Jacob Smith for Brandeis Robotics club
Provides readable wrapper functions for the Zumo Proximity Sensors
October 11 2018*/
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

int Proximity::getLeftCounts(){
	prox.read();
	return prox.countsLeftWithLeftLeds();
	
	
}

int Proximity::getCenterLeftCounts(){
	prox.read();
	return prox.countsFrontWithLeftLeds();
	
	
}

int Proximity::getCenterRightCounts(){
	prox.read();
	return prox.countsFrontWithRightLeds();
	
	
}

int Proximity::getRightCounts(){
	prox.read();
	return prox.countsRightWithRightLeds();

}

//iterates through the array of current line sensor readings and prints each one to the robot's display
void Proximity::printAllSensors(Zumo32U4LCD lcd) {
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
