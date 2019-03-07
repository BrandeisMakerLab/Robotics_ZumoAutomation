/* Brandeis Robotics Club
    Date: October 4 2018
    Assignment: Line Follower, designed to keep the robot in a box of tape
      by turnign left whenever it sees a line. It is documented for the understanding of a general audience
	  See the documentation of the Brandeis Robotics Club Drive Class for more information on how the motors are used here

*/
//include all the libraries that this program needs to use
#include <Wire.h>
#include <Drive.h>
#include <Line.h>
#include <Zumo32U4LCD.h>

//declare objects to control the robot's display, motors, and an object to tell if the robot sees a line
Zumo32U4LCD lcd;
Drive motors;
Line lineReader(527);

//this method starts before the program enters the main loop
//the robot will display its program name, then display its sensor values
//finally it will drive forward for 100 milliseconds, so it clears the line of tape and is securely inside the ring
void setup() {
  //start robot on line, facing inward
  lineReader.printAllSensors(lcd);

}

//the main loop of the program, the robot will drive forward
//unless it sees a line, in which case it while drive backward for 600 milliseconds and turn right for 300 milliseconds
void loop() {
  if (lineReader.isOnEdge()) {
    motors.stopDrive(500);
    motors.turnLeft(450);
  }else{
    motors.driveForward();
  }
}

