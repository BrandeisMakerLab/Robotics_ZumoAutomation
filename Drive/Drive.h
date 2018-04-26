/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
	Provides wrapper functions for the Zumo32U4Motors class.  It is documented
	to explain its function to a general audience
	April 2 2018
*/
//sets up the Drive Header file
#ifndef Drive_h
#define Drive_h

//includes the libraries of code necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <Zumo32U4Motors.h>
#include <Drive.h>

class Drive{
	private:
		//the ZUMO32U4 object that will be used to interface with the robot
		Zumo32U4Motors drive;	
	public:
		//constructor for Drive class, creates a new Drive object
		Drive();
		
		//commands the robot to (method name) for a certain time, good for beginner programs
		//but the robot can't do anything else while the method executes
		void driveForward(int t);
		void driveBackward(int t);
		void turnRight(int t);
		void turnLeft(int t);
		void stopDrive(int t);
		
		//commands the robot to (method name), allows for advanced programs
		//because the robot can perform other operations while performing the action
		void driveForward();
		void driveBackward();
		void turnRight();
		void turnLeft();
		void stopDrive();
};

#endif