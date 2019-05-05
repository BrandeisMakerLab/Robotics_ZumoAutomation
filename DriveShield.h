/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
	Provides wrapper functions for the Zumo32U4Motors class.  It is documented
	to explain its function to a general audience
	April 2 2018
*/
//sets up the Drive Header file
#ifndef DriveShield_h
#define DriveShield_h
#if defined (ARDUINO_AVR_UNO) | defined(ARDUINO_ESP8266_WEMOS_D1R1)

//includes the libraries of code necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <MotorsGeneral.h>
#include <DriveShield.h>
#include <Timer.h>

class DriveShield{
	private:
		//the power the robot drives at [0,400]
		int power;
		//the  motors general object that will be used to interface with the robot
		MotorsGeneral drive;	
		//a timer to control how long the robot drives
		Timer driveTimer;
		
		//main driving method, allows robot to move for a period of time
		//while also checking for other variables
		void move(void (DriveShield::*command)(), int time);
	
	public:
		//constructor for Drive class, creates a new Drive object
		DriveShield();
		
		//commands the robot to (method name) for a certain time, good for beginner programs
		//but the robot can't do anything else while the method executes
		void driveForward(int time);
		void driveBackward(int time);
		void pivotRight(int time);
		void pivotLeft(int time);
		void turnRight(int time);
		void turnLeft(int time);
		void stopDrive(int time);
		
		
		//commands the robot to (method name), allows for advanced programs
		//because the robot can perform other operations while performing the action
		void driveForward();
		void driveBackward();
		void pivotRight();
		void pivotLeft();
		void turnRight();
		void turnLeft();
		void stopDrive();


		//returns the power the robot is using to drive
		int getPower();

		//sets the power
		void setPower(int power);
};
#elif defined (DONT_NEED_DRIVE)
	#warning : May lead to "error: 'DriveShield' does not name a type" ; Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html
	
#else
	#error : Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; Quick fix: add <#define DONT_NEED_DRIVE> to top ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html
#endif
#endif
