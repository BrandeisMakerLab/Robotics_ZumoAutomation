/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
	Provides wrapper functions for the Zumo32U4Motors class.  It is documented
	to explain its function to a general audience. Documentation is provided in the header file
	April 2 2018
	randomSeed(analogRead(5)); // randomize using noise from analog pin 5
	https://www.tutorialspoint.com/arduino/arduino_random_numbers.htm
*/

//includes the libraries of code necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <ZumoShield.h>
#include <Timer.h>
#include "DriveShield.h"




//creates a new Drive object, which won't have random motor power
DriveShield::DriveShield(){
	power=300;
}


//returns the motor power the robot is using
int DriveShield::getPower(){
	return power;
}

//sets the motor power the robot is using
void DriveShield::setPower(int power){
	this->power=power;
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
  drive.setSpeeds(power, power);
}

void DriveShield::driveBackward() {
  drive.setSpeeds(-power, -power);
}

void DriveShield::turnRight() {
  drive.setSpeeds(power, -power);
}

void DriveShield::turnLeft() {
  drive.setSpeeds(-power, power);
}

void DriveShield::stopDrive () {
  drive.setSpeeds(0, 0);
}
