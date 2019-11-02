/*Jacob Smith 2018.5.7 Brandeis Robotics Club.
  A Sumo match senario where the robot drives around
  https://www.youtube.com/watch?v=MGx0tyK4sc8&feature=youtu.be
  to the Serial Monitor
  Modified for inverted sumo field where white is insie and black is outside*/
//define the regions conveniently
#define WHITE 0
#define GRAY 1
#define BLACK 2
//include necessary libraries for the program
#include <LineShield.h>
#include <DriveShield.h>
#include <DistanceSensor.h>
//The object used to interfact with the class
DistanceSensor distancesensor;
//create lineReader object to interact with line sensors
LineShield lineReader;
//create DriveShield object to interact with motors
DriveShield motors;
//the distance to the sensor
int distance;
//the port the led is on
int led=14;
//runs once
void setup() {
  //sets up the class
  distancesensor.begin(2, 6);
  pinMode(led,OUTPUT); 
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);
  
}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //attack protocol if robot sees opponent
  if(distance>1 && distance<26){
    //double power so robot will drive forward quickly
    motors.setPower(motors.getPower()*2);
    motors.driveForward();
    //keep driving until robot sees the edge of the field
    while(lineReader.getRegion() == BLACK){}
    //rive an extra bit to get opponnent over line
    motors.driveForward(300);
    motors.stopDrive();
    //stop robot
    exit(0);
   
  //if region is black drive forward because you are at the center
  }else if (lineReader.getRegion()==BLACK) {
    //turn light off
    digitalWrite(13,LOW);
    motors.driveForward();
  //otherwise, turn left because you are a the edge
  } else {
    //turn light on
    digitalWrite(13,HIGH);
    //print data to screen
    motors.turnLeft(600);     
  }
}
