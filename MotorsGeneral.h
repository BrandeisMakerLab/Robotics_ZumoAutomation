/*Written by Jacob Smith for Brandeis Robotics Club using
	combined approaches of https://github.com/pololu/drv8835-motor-shield
	and https://github.com/indrekots/esp8266-rc-car-controller/blob/master/esp8266-rc-car/esp8266-rc-car.ino
	May 1 2019
	
	Allows the Zumo Shield Robot or anything using the drv8835 motor driver (see link above)
	to be driven by any of defined boards here with no extra work on behalf of the user
*/
//sets up the Drive Header file
#ifndef MotorsGeneral_h
#define MotorsGeneral_h

//only compile this class if the board is correct
#if defined(ARDUINO_ESP8266_WEMOS_D1R1) | defined (ARDUINO_AVR_UNO)

//includes the libraries of code necessary to make this one work
#include <MotorsGeneral.h>
#include <Arduino.h>

class MotorsGeneral{
	private:
		//the channel that controls whether the left motor should move backward
		int leftInversePin;
		//the channel that controls whether the right motor shoul move backward
		int rightInversePin;
		//the channel that controls the power of the left motor
		int leftPowerPin;
		//the channel that contols the power of the right motor
		int rightPowerPin;
		
		//helper function to set pins based on board type
		void setPins();
		//hlper function 
		void initPins();
		
		void setMotorDirection(int motorPin, int motorPower);
		void setMotorPower(int motorPin, int motorPower);
	
	public:
		//constructor for Motors General Clas, creates a new Motors General object
		MotorsGeneral();
		//allows the user to set the speeds of the motor driver
		void setSpeeds(int leftSpeed, int rightSpeed);
		
};
#elif defined (DONT_NEED_DRIVE)
	#warning : May lead to "error: 'MotorsGeneral' does not name a type" ; Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html
	
#else
	#error : Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; Quick fix: add <#define DONT_NEED_DRIVE> to top ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html
#endif
#endif