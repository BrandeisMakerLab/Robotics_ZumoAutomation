/*Jacob Smith 2018.5.7 Brandeis Robotics Club.
  Uses the Line class to print line sensor values
  to the Serial Monitor*/
//define the regions conveniently
#define WHITE 0
#define GRAY 1
#define BLACK 2
//include necessary libraries for the program
#include <LineShield.h>
#include <DriveShield.h>
//create lineReader object to interact with line sensors
LineShield lineReader;
//create DriveShield object tointeract with motors
DriveShield motors;
//runs once
void setup() {
  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  delay(3000);
  //print welcome message
  Serial.println("Brandeis University Example Line Sensor Printing Program");
  delay(2000);
}

//runs many times
void loop() {
  //get the current region of robot
  int region = lineReader.getRegion();
  //if region is white, turn left
  if (region == WHITE) {
    //print line data to screen
    lineReader.printAllSensors();
    Serial.println("On White");
    motors.turnLeft(300);
  //if region is gray, stop and drive backward
  } else if (region == GRAY) {
    //print data to screen
    lineReader.printAllSensors();
    Serial.println("On Gray");
    motors.stopDrive(3000);
    motors.driveBackward(500);
  //if region is black, stay driving forward
  //default cause
  } else {
    motors.driveForward();
  }
}
