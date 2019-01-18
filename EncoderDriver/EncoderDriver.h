/* Written by Jacob Smith for Brandeis Robotics Club. Provides Wrapper function for the Zumo 32U4EncoderDrivers class,
	allowing the ZUMO32U4 robot's position and velocity to be read in centimeters and centiemters per second
*/
//Sets up the EncoderDriver header file
#ifndef EncoderDriver_h
#define EncoderDriver_h
//imports other classes to be used in this clas
#include<Zumo32U4Motors.h>
#include <Encoder.h>

class EncoderDriver : public Encoder{
	private:
		//the powers of each motor
		int leftPower;
		int rightPower;
		//a motor object to get robot to move
		Zumo32U4Motors drive;
	
	public:
		//creates a new EncoderDriver object
		EncoderDriver();
		//sets the speed of both sides of the robot in cm/s
		void setSpeeds(double leftVel,double rightVel);
		//returns the power being sent to the left side of robot
		int getLeftPower();
		//returns the power beings sent to the right side of the robot
		int getRightPower();
		
	
};
#endif