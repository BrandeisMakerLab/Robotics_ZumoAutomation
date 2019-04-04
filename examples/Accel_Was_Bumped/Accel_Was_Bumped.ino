/*Written by Jacob Smith for Brandeis Robotics Club
 An Example program to print whether the robot has experienced a collision
 using its accelerometers
 April 2 2019
 */
//includes the header file of the library and to Zumo library
#include<Wire.h>
#include <Accel.h>
#include <DriveShield.h>

//creates a global reference to an Accel object
Accel accelerometer;
//creates a global reference to a Drive object
DriveShield robot;

//occurs before the program enters its main loop
void setup() {
	//set up USB communication with computer (only necessary if you want to print results to screen)
	Serial.begin(9600); //send data at 9600 bits per second, provided example value
	//this will wait a bit for serial to connect, but move on because of the abort timer
	delay(2000);
	//initialze accelerometer
	Wire.begin();
	accelerometer.initializeCompass();
	//print introduction
	Serial.println(
			"Welcome to Brandeis Univeristy Line Following and Collision Detection Demo");
	Serial.println("Results are in millimeters per second squared");
	Serial.println("The Robot will pivot and print if collided");
	//move robot to show it's ready
	robot.driveForward(200);
	delay(2000);
	accelerometer.printAccels();
}

//main loop that runs the program, not used here
void loop() {
	//wait until robot collides
	while (!accelerometer.collided()) {}
	//print collision information
	Serial.println("Collided!");
	accelerometer.printAccels();
	//move robot to show it has collided
	robot.driveForward(150);
	robot.stopDrive(500);

}
