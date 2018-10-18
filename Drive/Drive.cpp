/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
	Provides wrapper functions for the Zumo32U4Motors class.  It is documented
	to explain its function to a general audience. Documentation is provided in the header file
	April 2 2018
*/

//includes the libraries of code necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <Zumo32U4Motors.h>
#include <Timer.h>
#include "Drive.h"

//creates a new Drive object
Drive::Drive(){
	
}


//the main driving method, performs one of public commands, such as driving forward 
//sets the robot to perform the basic action, waits for the specified period of time, and stops the robot
void Drive::move(void (Drive::*command) (),int time){
	driveTimer.resetTime();
	while (driveTimer.getTime()<time){
		(*this.*command)();  	  
	}
	stopDrive();
}	

//public methods to command the robot to perform an action for a specified period of time	
//refer to private move helper method
void Drive::driveForward (int time) {
  move(&Drive::driveForward,time);
}

void Drive::driveBackward(int time) {
  move(&Drive::driveBackward,time);
}

void Drive::turnRight(int time) {
  move(&Drive::turnRight,time);

}

void Drive::turnLeft(int time){
	move(&Drive::turnLeft,time);
	
}
	
void Drive::stopDrive (int time) {
	move(&Drive::stopDrive,time);
}

//sets the robot to perform the basic action, using the ZUMO32U4 class to interface with the robots
void Drive::driveForward() {
  drive.setSpeeds(300, 300);
}

void Drive::driveBackward() {
  drive.setSpeeds(-300, -300);
}

void Drive::turnRight() {
  drive.setSpeeds(300, -300);
}

void Drive::turnLeft() {
  drive.setSpeeds(-300, 300);
}

void Drive::stopDrive () {
  drive.setSpeeds(0, 0);
}
