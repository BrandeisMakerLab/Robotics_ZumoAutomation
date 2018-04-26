/* Written by Jacob Smith for Brandeis Robotics Club. Provides Wrapper function for the Zumo 32U4Encoders class,
	allowing the ZUMO32U4 robot's position and velocity to be read in centimeters and centiemters per second
*/
//includes the libraries of code necessary to make this one work
//pololu class to interface with the robot
#include<Zumo32U4Encoders.h>
//Brandeis Timer class to find velocity as change in distance over time
#include<Timer.h>
//this class
#include <Encoder.h>

//how often the velocities will be updated
#define TIME_INTERVAL 50.0
//this constant depends on which gearing robot is
#define TICKS_PER_REV 909.7
//the approximate radius and circumference of one wheel in cm
#define RADIUS 1.95
#define CIRCUM 2*PI*RADIUS

//constants used for getting motion of side
#define LEFT 0
#define RIGHT 1

//the velocity threshold to determine whether the robot is stopped or moving, in cm/s
#define THRESHOLD .01

//creates a new Encoder Object
Encoder::Encoder(){
	initLeft=getLeftPos();

}

//calls helper method to get the position of the robots left track
double Encoder::getLeftPos(){
	return getPos(LEFT);
}

//same but for right track
double Encoder::getRightPos(){
	return getPos(RIGHT);
}

//converts encoder value in ticks into distance in centimeters
double Encoder::getPos(int side){
	int ticks;
	if(side==LEFT){
		ticks=enc.getCountsLeft();
	}else if (side==RIGHT){
		ticks=enc.getCountsRight();
	}
	double revs=ticks/TICKS_PER_REV;
	double distance=revs*CIRCUM;
	return distance;
}

//calculates velocity of left side of the robot, using a timer interval to find the change in position over a time interval
double Encoder::getLeftVel(){
	if (leftTimer.interval(TIME_INTERVAL)){
		finalLeft=getLeftPos();
		dLeft=(finalLeft-initLeft)/TIME_INTERVAL;
		initLeft=finalLeft;
	}
	return dLeft;
}

//same but for right side
double Encoder::getRightVel(){
	if (rightTimer.interval(TIME_INTERVAL)){
		finalRight=getRightPos();
		dRight=(finalRight-initRight)/TIME_INTERVAL;
		initRight=finalRight;
	}
	return dRight;
}

//returns the robot's direction based on if each track is moving forward passed the threshold,
//if each track is behind the threshold, etc
const char* Encoder::getDirection(){
	getLeftVel();
	getRightVel();
	if (dLeft>THRESHOLD && dRight>THRESHOLD){
		return "FORWARD";
	}else if (dLeft<-THRESHOLD && dRight<-THRESHOLD){
		return "BACKWARD";
	}else if (dLeft<THRESHOLD && dRight>THRESHOLD){
		return "TURNLEFT";
	}else if (dLeft>THRESHOLD && dRight<THRESHOLD)
			return "TURNRIGHT";
	else {
		return "STOPPED";
	}
}
