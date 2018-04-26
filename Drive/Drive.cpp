/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
	Provides wrapper functions for the Zumo32U4Motors class.  It is documented
	to explain its function to a general audience. Documentation is provided in the header file
	April 2 2018
*/

//includes the libraries of code necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <Zumo32U4Motors.h>
#include "Drive.h"

//creates a new Drive object
Drive::Drive(){

}

//sets the robot to perform the basic action, waits for the specified period of time, and stops the robot
void Drive::driveForward (int t) {
  driveForward();
  delay(t);
  stopDrive();
}

void Drive::driveBackward(int t) {
  driveBackward();
  delay(t);
  stopDrive();
}

void Drive::turnRight(int t) {
  turnRight();
  delay(t);
  stopDrive();

}

void Drive::turnLeft(int t){
	turnLeft();
	delay(t);
	stopDrive();
	
}
	
void Drive::stopDrive (int t) {
 stopDrive();
  delay(t);
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