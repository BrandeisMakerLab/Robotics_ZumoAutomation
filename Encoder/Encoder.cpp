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
#define TIME_INTERVAL 50
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
//unit conversion constant for getVel methods
#define MS_PER_S 1000

//creates a new Encoder Object
Encoder::Encoder(){
	initLeft=getLeftPos();
	initRight=getRightPos();

}

//calls getPos helper method to find left and right positions, and averages them
//reutrns absolute value of position if one side is negative
double Encoder::getAvgPos(){
	double leftPos=getLeftPos();
	double rightPos=getRightPos();
	if (leftPos<0 && rightPos>0){
		leftPos=fabs(leftPos);
	}else if (leftPos>0 && rightPos<0){
		rightPos=fabs(rightPos);
	}
	double avgPos=(leftPos+rightPos)/2;
	return avgPos;
}

//calls getPos helper method to find left and right positions, and averages them
//if one velocity is negative, the absolute value of position is returned
double Encoder::getAvgVel(){
	double leftVel=getLeftVel();
	double rightVel=getRightVel();
	const char* dir=getDirection();
	if (strcmp(dir,"TURNRIGHT")==0){
		rightVel=fabs(rightVel);
	}else if (strcmp(dir,"TURNLEFT")==0){
		rightVel*=-1;
	}
	double avgVel=(leftVel+rightVel)/2;
	return avgVel;
	
}

//calls getPos helper method to return the position of the robot's left side
double Encoder::getLeftPos(){
	return getPos(LEFT);
	
}

//calls getPos helper method to return the position of the robot's right side
double Encoder::getRightPos(){
	return getPos(RIGHT);
	
}

//converts encoder value in ticks into distance in centimeters
double Encoder::getPos(int side){
	int ticks=0;
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
	float time=(float) leftTimer.getTime();
	if (time>TIME_INTERVAL){
		finalLeft=getLeftPos();
		time/=MS_PER_S;//convert time to seconds
		dLeft=(finalLeft-initLeft)/time;	
		initLeft=finalLeft;
		leftTimer.resetTime();
	}
	return dLeft;
}

//calculates velocity of left side of the robot, using a timer interval to find the change in position over a time interval
double Encoder::getRightVel(){
	float time=(float) rightTimer.getTime();
	if (time>TIME_INTERVAL){
		finalRight=getRightPos();
		time/=MS_PER_S;//convert time to seconds
		dRight=(finalRight-initRight)/time;	
		initRight=finalRight;
		rightTimer.resetTime();
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
	}else if (dLeft<-THRESHOLD && dRight>THRESHOLD){
		return "TURNLEFT";
	}else if (dLeft>THRESHOLD && dRight<-THRESHOLD)
			return "TURNRIGHT";
	else {
		return "STOPPED";
	}
}
