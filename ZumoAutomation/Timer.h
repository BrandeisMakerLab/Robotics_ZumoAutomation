/*Written by Jacob Smith for Brandeis Robotics club
	Keeps track of current time, can be used for intervals
	without delay statements
	March 15 2018
*/
#ifndef Timer_h
#define Timer_h

#include <Arduino.h>
#include<Timer.h>

class Timer{
	
	private:
		//the beginning time of the interval
		long initTime;
	public:
		//creates a new Timer object
		Timer();
		//resets time
		long resetTime();
		//returns the current time
		long getTime();
		//returns the current time and resets it
		long getAndResetTime();
		//returns true every interval, without any delay statements
		bool interval(long interval);
		
};

#endif