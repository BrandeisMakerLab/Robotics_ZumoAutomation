/*Comment goes here
*/
#ifndef Template_h
#define Template_h

//this should work on all boards, so there is no preprocessor directive here

#include <Arduino.h>
#include<Template.h>

class Template{
	
	private:
		//the beginning time of the interval
		long initTime;
	public:
		//creates a new Template object
		Template();
		//resets time
		long method1();
		//returns the current time
		long method2();
		//returns the current time and resets it
		long method2();
		
};

#endif