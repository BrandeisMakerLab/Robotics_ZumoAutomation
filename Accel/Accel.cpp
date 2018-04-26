/*Written by Jacob Smith for Brandeis Robotics club
	A wrapper class for the pololu LSM303 class, which interfaces with the accelerometer on the ZUMO32U4 robot
	Allows for simple initialization of the accelerometer in the class constructor and provides getter methods to
	get the robot's x, y, and z axis acceleration. April 23 2018
*/

//includes the libraries of code necessary to make this one work
#include <LSM303.h>
#include <Wire.h>
#include <Arduino.h>
#include "Accel.h"

//constants necessary to convert the acceleromter's raw values into millimiters per second squared 
#define MG_PER_LSB .061
#define MSS_PER_G 9.80665
#define CM_PER_MM .1

//creates a new Accel object by setting up the Serial connection to print output and initializing the accelerometer on the robot
Accel::Accel(){
	
}


//Wire.begin must be in setup of client program
//IPrints an error message if acceleromter was not initialized
//sets up default settings of compass
void Accel::initializeCompass(){
	if(!compass.init()&& Serial){
		Serial.println("acceleromter failed");
	}
	compass.enableDefault();
}

//tells the accelerometer to update its acceleration fields
//converts those fields to centimeters per second squared to store in Accel object
void Accel::updateAccels() {
  compass.read();
  accelX= compass.a.x * MG_PER_LSB * MSS_PER_G*CM_PER_MM; //acceleration in centimeters per second squared
  accelY = compass.a.y * MG_PER_LSB * MSS_PER_G*CM_PER_MM; //acceleration in centimeters per second squared
  accelZ = compass.a.z * MG_PER_LSB * MSS_PER_G*CM_PER_MM; //acceleration in centimeters per second squared
}

//tells the accelerometer to update its acceleration fields
//returns the x axis acceleration field
double Accel:: getX() {
	updateAccels();
	return accelX;
}

//tells the accelerometer to update its acceleration fields
//returns the y axis acceleration field
double Accel:: getY() {
	updateAccels();
	return accelY;
}

//tells the accelerometer to update its acceleration fields
//returns the z axis acceleration field
double Accel:: getZ() {
	updateAccels();
	return accelZ;
}