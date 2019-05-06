/*Written by Jacob Smith for Brandeis Robotics Club using
	combined approaches of https://github.com/pololu/drv8835-motor-shield
	and https://github.com/indrekots/esp8266-rc-car-controller/blob/master/esp8266-rc-car/esp8266-rc-car.ino
	May 1 2019
	
	Allows the Zumo Shield Robot or anything using the drv8835 motor driver (see link above)
	to be driven by any of defined boards here with no extra work on behalf of the user
*/

//only compile this class if the board is correct
#if defined(ARDUINO_ESP8266_WEMOS_D1R1) | defined (ARDUINO_AVR_UNO)


//includes the libraries of code necessary to make this one work
#include "MotorsGeneral.h"

//creates a new Drive object, which won't have random motor power
MotorsGeneral::MotorsGeneral(){
	Serial.println("init");
	setPins();
	initPins();
}

//set the pins on the robot for the board used
void MotorsGeneral::setPins(){
	//checks for the wemos board and sets pins appropriately 
	#ifdef ARDUINO_ESP8266_WEMOS_D1R1
		leftInversePin=0;
		rightInversePin=13;
		leftPowerPin=2;
		rightPowerPin=15;
	//checks for the arduino board and sets pins appropriately 
	#elif ARDUINO_AVR_UNO 
		leftInversePin=7;
		rightInversePin=8;
		leftPowerPin=9;
		rightPowerPin=10;
	#elif ARDUINO_ESP8266_NODEMCU
	
		leftInversePin=0;
		rightInversePin=13;
		leftPowerPin=2;
		rightPowerPin=15;
	
	#else
		//if one of these boards isn't found, throw a compiler error
		#error Board not supported by Motors General Class, please lookup the pins you are using and an ifdef as above in MotorsGeneral .cpp files	
	#endif
	
}

//initilize pins used to drive motors
void MotorsGeneral::initPins(){
  digitalWrite(leftPowerPin, LOW);
  pinMode(leftPowerPin, OUTPUT);
  digitalWrite(leftPowerPin, LOW);
  digitalWrite(rightPowerPin, LOW);
  pinMode(rightPowerPin, OUTPUT);
  digitalWrite(rightPowerPin, LOW);
  digitalWrite(leftInversePin, LOW);
  pinMode(leftInversePin, OUTPUT);
  digitalWrite(leftInversePin, LOW);
  digitalWrite(rightInversePin, LOW);
  pinMode(rightInversePin, OUTPUT);
  digitalWrite(rightInversePin, LOW);
  pinMode(leftInversePin, OUTPUT);
  pinMode(rightInversePin, OUTPUT);
  pinMode(leftPowerPin, OUTPUT);
  pinMode(rightPowerPin, OUTPUT);
	
}

//sets the motors to move by writing indiviudal pins
void MotorsGeneral::setSpeeds(int leftSpeed, int rightSpeed){
		setMotorDirection(leftInversePin,leftSpeed);
		setMotorDirection(rightInversePin,rightSpeed);
		setMotorPower(leftPowerPin,leftSpeed);
		setMotorPower(rightPowerPin,rightSpeed);
		
}

//sets the motor direction by setting the inverse pin for each motor
void MotorsGeneral::setMotorDirection(int motorPin, int motorPower){
	if(motorPower>=0){
		 digitalWrite(motorPin, LOW);
	}else{
		digitalWrite(motorPin, HIGH);
	}

}

//sets the motor power by setting the inverse pin for each motor
void MotorsGeneral::setMotorPower(int motorPin, int motorPower){
	//for now, there is no intermediate motor power
	if(motorPower==0){
		 digitalWrite(motorPin, LOW);
	}else{
		digitalWrite(motorPin, HIGH);
	}

}
#endif