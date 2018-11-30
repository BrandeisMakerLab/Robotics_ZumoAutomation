/*Written by Jacob Smith for Brandeis Robotics Club
   contains an example program to use the Accel class.
   Prints Accelerations to the console in centimeters per second squared.
   The robot will drive forward to show it's ready, and if it is flipped over, it will know and turn right.
   November 30 2018
*/
//includes the header file of the library and to Zumo library
#include<Wire.h>
#include <Accel.h>
#include <Drive.h>
#include <Timer.h>

//creates a global reference to an Accel object
Accel accelerometer;

//creates a global reference to a Drive object
Drive robot;

//a timer to abort trying to connect to serial
Timer timer;

//occurs before the program enters its main loop
void setup() {
  //set up USB communication with computer (only necessary if you want to print results to screen)
  Serial.begin(9600);//send data at 9600 bits per second, provided example value
  //this will wait a bit for serial to connect, but move on because of the abort timer
  while (!Serial ||timer.getTime()<2000) {}
  //initialze accelerometer
  Wire.begin();
  accelerometer.initializeCompass();
  //print introduction
  Serial.println("Welcome to Brandeis Univeristy Acceleration demo");
  Serial.println("Results are in millimeters per second squared");
  delay(2000);
  robot.driveForward(100);
}

//the main loop of the robot
void loop() {
  //as long as the robot is upside down, it will turn right
  while (accelerometer.getZ()<0){
      robot.turnRight(); 
	  //still prints the accelerations while it's upside down
      accelerometer.printAccels();
      
  }
  //otherwise, robot will stop and print accelerations
  robot.stopDrive();
  accelerometer.printAccels();
  delay(100);
}