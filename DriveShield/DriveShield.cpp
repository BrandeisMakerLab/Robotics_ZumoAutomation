/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
	Provides wrapper functions for the Zumo32U4Motors class.  It is documented
	to explain its function to a general audience. Documentation is provided in the header file
	April 2 2018
*/

//includes the libraries of code necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <ZumoShield.h>
#include <Timer.h>
#include "DriveShield.h"

//creates a new Drive object
DriveShield::DriveShield(){
	
}


//the main driving method, performs one of public commands, such as driving forward 
//sets the robot to perform the basic action, waits for the specified period of time, and stops the robot
void DriveShield::move(void (DriveShield::*command) (),int time){
	driveTimer.resetTime();
	while (driveTimer.getTime()<time){
		(*this.*command)();  	  
	}
	stopDrive();
}	

//public methods to command the robot to perform an action for a specified period of time	
//refer to private move helper method
void DriveShield::driveForward (int time) {
  move(&DriveShield::driveForward,time);
}

void DriveShield::driveBackward(int time) {
  move(&DriveShield::driveBackward,time);
}

void DriveShield::turnRight(int time) {
  move(&DriveShield::turnRight,time);

}

void DriveShield::turnLeft(int time){
	move(&DriveShield::turnLeft,time);
	
}
	
void DriveShield::stopDrive (int time) {
	move(&DriveShield::stopDrive,time);
}

//sets the robot to perform the basic action, using the ZUMO32U4 class to interface with the robots
void DriveShield::driveForward() {
  drive.setSpeeds(300, 300);
}

void DriveShield::driveBackward() {
  drive.setSpeeds(-300, -300);
}

void DriveShield::turnRight() {
  drive.setSpeeds(300, -300);
}

void DriveShield::turnLeft() {
  drive.setSpeeds(-300, 300);
}

void DriveShield::stopDrive () {
  drive.setSpeeds(0, 0);
}
