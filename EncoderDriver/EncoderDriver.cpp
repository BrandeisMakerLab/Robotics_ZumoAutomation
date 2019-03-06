/* Written by Jacob Smith for Brandeis Robotics Club. Provides Wrapper function for the Zumo 32U4EncoderDrivers class,
	allowing the ZUMO32U4 robot's position and velocity to be read in centimeters and centiemters per second
*/
//includes the libraries of code necessary to make this one work
//#include <Zumo32U4Motors.h>
//Brandeis Timer class to find velocity as change in distance over time

//this class
#include <EncoderDriver.h>

//constants used for getting motion of side
#define LEFT 0
#define RIGHT 1

//how much variation in velocity is ok
#define TOLERANCE 1

//the highgest possible powers
#define MAXPOWER 400
#define MINPOWER -400

//creates a new EncoderDriver Object
EncoderDriver::EncoderDriver(){
	leftPower=0;
	rightPower=0;
}

//returns the power being sent to left side of robot
int EncoderDriver::getLeftPower(){
	return leftPower;
}

//returns the power being sent to the right side of the robot
int EncoderDriver::getRightPower(){
	return rightPower;
}

//uses the Encoder class and the Motor class to increment speed of robot is driving slow, and slow down if robot is driving to fsat
//based on leftVel and rightVel
//to work, this has to be in a loop
void EncoderDriver::setSpeeds(double leftVel,double rightVel){
	double curLeftVel= getLeftVel();
	if(curLeftVel<leftVel-TOLERANCE && leftPower<MAXPOWER){
		leftPower++;
	}else if (curLeftVel>leftVel+TOLERANCE &&leftPower>MINPOWER){
		leftPower--;
	}
	
	double curRightVel= getRightVel();
	if(curRightVel<rightVel-TOLERANCE && rightPower<MAXPOWER){
		rightPower++;

	}else if (curRightVel>rightVel+TOLERANCE && rightPower>MINPOWER){
		rightPower--;
	
	}
	drive.setSpeeds(leftPower,rightPower);
		
}
