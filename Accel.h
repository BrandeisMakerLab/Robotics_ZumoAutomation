/*Written by Jacob Smith  for Brandeis Robotics club
	Provides wrapper functions for the Pololu LSM303 class, which allows functions to 
	return the robot's accelerations in centimeters per second squared
	April 23 2018
*/
//sets up the Accel Header file
#ifndef Accel_h
#define Accel_h

//only compile this class if the board is correct
#if defined(ARDUINO_AVR_UNO) 

//includes the libraries of code necessary to make this one work
#include<LSM303.h>
#include <Wire.h>
#include <Arduino.h>

//defines the indeces of the acceleration readings
#define X 0
#define Y 1
#define Z 2

class Accel{
	private:
		//the ZUMO32U4 object that will be used to interface with the robot
		LSM303 compass;
		
		//array to hold current acceleration values
		double accels[3];
		//array to hold accelerationi offsets
		double offsets[3];
		
		//array to hold resting acceleration values
		double  resting [3];
		
		//the robot's acceleration on the axes in centimeters per second squared
		double accelX;
		double accelY;
		double accelZ;

		//the offsets of acceleration
		double xOffset;
		double yOffset;
		double zOffset;
		
		//Helper method to create an Accel object
		void setOffsets();
		//helper method to get the acceleration from sensor and return in cm/s squared
		double getRawAcceleration(int i);
		
	public:
		
		//constructor for Accel class, creates a new Accel object
		Accel();
		
		//sets up the accelerometer's compass
		void initializeCompass();
		
		//returns the robot's acceleration in millimeters per second squared
		double getX(); 
		double getY();
		double getZ();

		//interfaces with the robot's accelerometer to update acceleration fields
		void updateAccels(); 
		
		//prints the acclerations to the seral monitor
		void printAccels();

		//returns whether a stationary robot has detected a collision with its accelerometer
		bool collided();
};
#elif defined (DONT_NEED_ACCEL)
	#warning : May lead to "error: 'Accel' does not name a type" ; Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html
	
#else
	#error : Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; Quick fix: add <#define DONT_NEED_ACCEL> to top ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html
#endif
#endif
