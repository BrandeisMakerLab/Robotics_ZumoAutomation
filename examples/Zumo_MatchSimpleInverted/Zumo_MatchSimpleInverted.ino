/*Jacob Smith 2018.5.7 Brandeis Robotics Club.
  Uses the Line class to print line sensor values
  to the Serial Monitor
  Modified for inverted sumo field where white is insie and black is outside*/
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
  pinMode(13,OUTPUT); 
  digitalWrite(13,HIGH);
  delay(500);
  digitalWrite(13,LOW);
  delay(500);
  digitalWrite(13,HIGH);
  delay(500);
  
}

//runs many times
void loop() {
  //if region is white, drive forward
  if (lineReader.getRegion()==WHITE) {
    digitalWrite(13,LOW);
    motors.driveForward();
  //otherwise, turn left
  } else {
    digitalWrite(13,HIGH);
    //print data to screen
    motors.driveBackward(100);
    motors.turnLeft(100);     
  }
}
