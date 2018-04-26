/* Written by Jacob Smith for Brandeis Robotics Club. Provides Wrapper function for the Zumo 32U4Encoders class,
	allowing the ZUMO32U4 robot's position and velocity to be read in centimeters and centiemters per second
*/
//Sets up the Encoder header file
#ifndef Encoder_h
#define Encoder_h
//imports other classes to be used in this clas
#include<Zumo32U4Encoders.h>
#include<Timer.h>
#include <Encoder.h>
class Encoder{
	private:
		//starting position of left and right tracks
		double initLeft;
		double initRight;
		
		//ending position of left and right tracks
		double finalLeft;
		double finalRight;
		
		//change in left and right trakcs over time, velocity
		double dLeft;
		double dRight;
		
		//the Zumo object to interface with the robot's encoders
		Zumo32U4Encoders enc;
		
		//brandeis timers to calculate velocity
		Timer leftTimer;
		Timer rightTimer;
		
		//helper method to calculate position of robot in centimeters
		double getPos(int side);
	
	public:
		//creates a new Encoder object
		Encoder();
		//return robot's left side position in centimeters
		double getLeftPos();
		//same for right side
		double getRightPos();
		//returns robot's left side velocity in centimeters
		double getLeftVel();
		//same for right side
		double getRightVel();
		//returns robot's direction
		const char* getDirection();
	
};
#endif