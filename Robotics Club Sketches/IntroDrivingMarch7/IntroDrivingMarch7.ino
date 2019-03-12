/*Robotics Club example file
   March 7 2019
*/
//includes the header file of the library
#include <DriveShield.h>

//creates a global reference to a Drive object
DriveShield robot;

//occurs before the program enters its main loop
void setup() {
  //commands the robot to stop for 2 seconds
  robot.stopDrive(2000);

}
//the main loop of the robot

void loop() {
  //commands the robot to perform each step for half a second
  //robot speed in cm/sec is 50 
  int distance = 100;
  int speed= 50;    
  robot.driveForward(distance/speed*1000);  
  robot.stopDrive(2000);

}
