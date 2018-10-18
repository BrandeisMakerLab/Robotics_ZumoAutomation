/* Name:Jacob Smith and Matthew Millendorf, Brandeis Robotics Club
    Date: April 4 2018
    Assignment: Line Follower, designed to keep the robot in a box of tape
      by backing up and turning whenever it sees a line. This is an example program
      for the Line Library. It is documented for the understanding of a general audience
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
Line lineReader;

//this method starts before the program enters the main loop
//the robot will display its program name, then display its sensor values
//finally it will drive forward for 100 milliseconds, so it clears the line of tape and is securely inside the ring
void setup() {
  //start robot on line, facing inward
  lcdInit();
  lineReader.printAllSensors(lcd);
  motors.driveForward(100);
}

//the main loop of the program, the robot will drive forward
//unless it sees a line, in which case it while drive backward for 600 milliseconds and turn right for 300 milliseconds
void loop() {
  motors.driveForward();
  if (lineReader.isOnEdge()) {
    motors.driveBackward(600);
    motors.turnRight(300);
  }
}

//puts the program name on the robot's display
void lcdInit() {
  lcd.clear();
  lcd.print("Example");
  delay(2000);
  lcd.clear();
  lcd.print("LineSensor");
  delay(2000);
  lcd.clear();
  lcd.gotoXY(0, 0);

}



