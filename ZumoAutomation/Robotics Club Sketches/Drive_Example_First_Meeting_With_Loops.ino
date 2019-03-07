/*Written by Brandeis Robotics Club
   The starting drive program for the club, the robot drives to push another out of the ring
   The program is documented for a general audience.
   September 27 2018
   
  500 milliseconds of driving forward is 19.5 inches
  300 milliseconds of turning is 90 degree turn

  The robot starts at end of ring facing center, trying to push robot across ring to the left
*/

//includes the header file of the library
#include <Drive.h>

//creates a global reference to a Drive object
Drive robot;

//occurs before the program enters its main loop
void setup() {
  //commands the robot to stop for 2 seconds
  robot.stopDrive(2000);

  //teamASequence();
  //teamBSequence();

}

//the main loop of the robot
void loop() {
  //move forward
  robot.driveForward(500);
  robot.turnLeft(300);
}

void teamASequence() {
  //move to center for half a second
  robot.driveForward(500);
  //turn left 45 degrees
  robot.turnLeft(150);
  //move back all the way
  robot.driveBackward (500);
  //move forward & ram other robot
  robot.driveForward(1000);

}

void teamBSequence() {
  //Turn left to face robot
  robot.turnLeft(70);
  //move forward to push the robot out of the arena
  robot.driveForward(1500);

}


