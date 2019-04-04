/*Written by Jacob Smith for Brandeis Robotics Club
  contains an example program to use our Drive class.
  The program is documented for a general audience.
  April 2 2018
*/
//includes the header file of the library
#include <DriveShield.h>
#include <Arduino.h>
#include<LineGlobal.h>
#include<Wire.h>
#include <Timer.h>

//creates a global reference to a Drive object
DriveShield robot;
Timer t;
#define NUM_SENSORS 6
//the number of regions and names of them in order the robot should go over them
int numRegions = 3;

String regions[] = { "BLACK", "WHITE", "GRAY" };
String regionsSeen[NUM_SENSORS];

//an array of the regions the robot has seen
//create an array for the threshold to populate with what region the line sensors see
LineGlobal reader;

int numLost;

//occurs before the program enters its main loop
void setup() {
  reader.setElements(regions, numRegions, regionsSeen, true);

  //commands the robot to stop for 2 seconds
  robot.driveBackward(500);
  int numLost=0;
  t.resetTime();
  while (t.getTime() < 60000) {
    numLost=navigate(numLost);
  }
  Serial.print("TRIAL OVER, NUMBER LOST:");
  Serial.println(numLost);
  robot.stopDrive(5000);
 
}
/*
 * Detects the region the robot is on and moves accordingly
 * @param losses the number of times the robot has reached the gray region
 * @return the number of times the robot lost
 */
int navigate(int numLosses) {

  //get what region the robot is over
  String region = reader.getRegion();

  reader.displayLineReadings(region);
  /*if (region == "WHITE") {
    robot.driveBackward(500);
    robot.turnLeft(300);
  } else if (region == "GRAY") {
    numLosses++;
    Serial.print("LOST: ");
    Serial.println(numLosses);
    robot.driveBackward(500);
    delay(2000);

  } else { //region is Black
    robot.driveForward();
  }*/
  robot.driveForward();
  return numLosses;
}




//the main loop of the robot

void loop() {


}


