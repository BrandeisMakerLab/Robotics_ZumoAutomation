/*Written by Jacob Smith for Brandeis Robotics club
	A wrapper class for the pololu LSM303 class, which interfaces with the accelerometer on the ZUMO32U4 robot
	Allows for simple initialization of the accelerometer in the class constructor and provides getter methods to
	get the robot's x, y, and z axis acceleration. April 23 201 8
*/

//includes the libraries of code necessary to make this one work
#include <Zumo32U4.h>
#include <Wire.h>
#include <Arduino.h>
#include "Accel.h"

//constants necessary to convert the acceleromter's raw values into millimiters per second squared 
#define MG_PER_LSB .061
#define MSS_PER_G 9.80665
#define CM_PER_MM .1

//a constant I made up to represent how much the resting accelerometer varies
#define VARIATION 20
//creates a new Accel object by setting up the Serial connection to print output and initializing the accelerometer on the robot
//will calibrate the acceleration X, Y, and Z to the offset
Accel::Accel(){
	//set what resting state of accelerometer should be
	resting[X]=0;
	resting[Y]=0;
	resting[Z]=980;
}


//Wire.begin must be in setup of client program
//IPrints an error message if acceleromter was not initialized
//sets up default settings of compass
void Accel::initializeCompass(){
	if(!compass.init()&& Serial){
		Serial.println("accelerometer failed");
	}
	compass.enableDefault();
	setOffsets();
}

//Sets the offsets of the acceleromoter values so they start at 0 for X and Y or 980 for Z
void Accel::setOffsets(){
	//finds offsets for accelerometer channels
	Serial.println("Starting Calibration");
	double numSamples=0;
	double sumX=0,sumY=0,sumZ=0;
	while (numSamples<100){
		sumX+=getRawAcceleration(X);
		sumY+=getRawAcceleration(Y);
		sumZ+=getRawAcceleration(Z);
		numSamples++;
		delay(50);  
	}
	offsets[X]=resting[X]-(sumX/numSamples);
	offsets[Y]=resting[Y]-(sumY/numSamples);
	offsets[Z]=resting[Z]-(sumZ/numSamples);
	Serial.print("X offset:");
	Serial.println(offsets[X]);
	Serial.print("Y offset:");
	Serial.println(offsets[Y]);
	Serial.print("Z offset:");
	Serial.println(offsets[Z]);
	
}

//tells the accelerometer to update its acceleration fields
//converts those fields to centimeters per second squared to store in Accel object
void Accel::updateAccels() {
  
  for (int i=0;i<3;i++){
		//take initial compass reading
		int tempAccel=getRawAcceleration(i);
		//add offset
		tempAccel+=offsets[i];
		if (tempAccel<resting[i]+VARIATION &&tempAccel>resting[i] -VARIATION){//if acceleration is near 0, code it to 0
			accels[i]=resting[i];
		}
		else if (tempAccel<accels[i]-VARIATION ||tempAccel>accels[i]+VARIATION){//if acceleration has changed more than natural variation of sensor, update it
			accels[i]=tempAccel;
		}
		
	}
 
}

//input is number representing what axis of acceleration is required
//output is acceleration in centimeters per second squared in that axis
double Accel::getRawAcceleration(int i){
	compass.read();
	double accel=0;
	if (i==X){
		accel=compass.a.x;
	}else if (i==Y){
		accel=compass.a.y;
	}else if (i==Z){
		accel=compass.a.z;

	}
	double acceleration=accel * MG_PER_LSB * MSS_PER_G*CM_PER_MM; //acceleration in centimeters per second squared 
	return acceleration;
}


//tells the accelerometer to update its acceleration fields
//returns the x axis acceleration field
double Accel:: getX() {
	updateAccels();
	return accels[X];
}

//tells the accelerometer to update its acceleration fields
//returns the y axis acceleration field
double Accel:: getY() {
	updateAccels();
	return accels[Y];
}

//tells the accelerometer to update its acceleration fields
//returns the z axis acceleration field
double Accel:: getZ() {
	updateAccels();
	return accels[Z];
}

//prints the accelerations to the serial monitor
void Accel::printAccels(){
	Serial.print("X Accel\t");
	Serial.print(getX());
	Serial.print("\tY Accel\t");
	Serial.print(getY());
	Serial.print("\tZ Accel\t");
	Serial.println(getZ());
}
