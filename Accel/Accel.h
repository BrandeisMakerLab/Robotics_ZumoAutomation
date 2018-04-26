/*Written by Jacob Smith  for Brandeis Robotics club
	Provides wrapper functions for the Pololu LSM303 class, which allows functions to 
	return the robot's accelerations in centimeters per second squared
	April 23 2018
*/
//sets up the Accel Header file
#ifndef Accel_h
#define Accel_h

//includes the libraries of code necessary to make this one work
#include<LSM303.h>
#include <Wire.h>
#include <Arduino.h>
#include <Accel.h>

class Accel{
	private:
		//the ZUMO32U4 object that will be used to interface with the robot
		LSM303 compass;
		//the robot's acceleration on the axes in centimeters per second squared
		double accelX;
		double accelY;
		double accelZ;
		
	public:
		//Helper method to create an Accel object
		void initializeCompass();
		//constructor for Accel class, creates a new Accel object
		Accel();
		
		//returns the robot's acceleration in millimeters per second squared
		double getX(); 
		double getY();
		double getZ();

		//interfaces with the robot's accelerometer to update acceleration fields
		void updateAccels(); 
};

#endif