/*Written by Jacob Smith for Brandeis Robotics club
Keeps track of current time
March 15 2018*/

//this should work on all boards, so there is no preprocessor directive here

//include all of the classes necessary to make this one work
#include <Arduino.h>
#include <Timer.h>

//Timer constructor
Timer::Timer(){
	initTime=millis();
}

//resets the initial time
long Timer::resetTime () {
	initTime=millis();
	return getTime();
}

//returns the current time
long Timer::getTime(){
	return millis()-initTime;
}

//returns the current time and resets the initial time
long Timer::getAndResetTime(){
	long curTime=getTime();
	resetTime();
	return curTime;
}

//keeps track of a specified interval, so a procedure can be performed every second for example
bool Timer::interval(long interval){
	bool intPassed=false;
	if (getTime()>interval){
		intPassed=true;
		resetTime();
	}
	return intPassed;
	
}

