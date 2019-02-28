//Overall Method: Robot will start driving, and will stop when sensor senses white, and then Timer will getTime().

#include <Timer.h>
#include <LineShield.h>
#include <DriveShield.h>
//declare robot display timer
Timer timer;
LineShield lineReader;
DriveShield robot;
void setup() {
  Serial.begin(9600);
  Serial.println("ready");
  timer.resetTime();
  while(!lineReader.isOnWhite()){
    robot.driveForward();
  }
  Serial.println("mark");
  Serial.println(timer.getTime());
  robot.stopDrive();
  // put your setup code here, to run once:
  //While loop runs until sensor hits white
  //driveFoward should not have any arguments because there will be a lag.

}

void loop() {
  // put your main code here, to run repeatedly:
  //robot name: WALL-E JR.
} 
