/*Written by Jacob Smith for Brandeis Robotics Club
	Provides wrapper functions for Zumo prximity senors class
	October 17 2018, using https://www.youtube.com/watch?v=ddPo6HQvxzQ as model
*/
//set up the Proximity header file
#ifndef Proximity_h
#define Proximity_h



//include all the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <Zumo32U4ProximitySensors.h>
#include <Zumo32U4LCD.h>
#include <Proximity.h>

class Proximity{
	
	private:
		//the provided class, which will interface with the robot's Proximity
		Zumo32U4ProximitySensors prox;	
		

	public:
		//creates a new Proximity object
		Proximity();
		int Proximity::getLeftCounts();
		int Proximity::getCenterLeftCounts();
		int Proximity::getCenterRightCounts();
		int Proximity::getRightCounts();
		//prints all of the sensor readings to the lcd
		void printAllSensors(Zumo32U4LCD lcd);
		
};

#endif