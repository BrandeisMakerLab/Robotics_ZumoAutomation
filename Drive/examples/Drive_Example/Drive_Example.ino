/*Written by Jacob Smith for Brandeis Robotics Club
   contains an example program to use our Drive class.
   The program is documented for a general audience.
   April 2 2018
*/
//includes the header file of the library
#include <Drive.h>

//creates a global reference to a Drive object
Drive robot;

//occurs before the program enters its main loop
void setup() {
  //commands the robot to stop for 2 seconds
  robot.stopDrive(2000);

}
//the main loop of the robot

void loop() {
  //commands the robot to perform each step for half a second
  robot.driveForward(500);
  robot.turnRight(300);
  robot.turnLeft(300);
  robot.driveBackward(500);
  robot.stopDrive(500);

}
