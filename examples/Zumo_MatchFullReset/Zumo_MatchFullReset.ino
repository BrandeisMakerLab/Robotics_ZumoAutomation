/*Jacob Smith 2018.5.7 Brandeis Robotics Club.
  Displays two robots ability o play in a zumo match with automatic reseetting and match win detection
  Pritns updates to the Serial Monitor*/

#define WHITE 0
#define GRAY 1
#define BLACK 2

#include <LineShield.h>
#include <DriveShield.h>
#include <ZumoBuzzer.h>
#include <ZumoBuzzer.h>

LineShield lineReader;
DriveShield motors;
Pushbutton button(ZUMO_BUTTON);
ZumoBuzzer buzzer;
void setup() {

  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  delay(3000);

  Serial.println("Brandeis University Example Zumo Match Program");
  waitForSignal("connection");

  motors.setPower(motors.getPower() / 2); //halve robot power to reset
  while(1){getOnBlack(motors, lineReader);getToMatch(motors,lineReader);}
  motors.setPower(motors.getPower() * 2); //reset robot power to play normal match
}

//main match logic
void loop() {
  /*
    int region=lineReader.getRegion();
    //if robot won the match
    if(!button.isPressed()){
  	  Serial.println("I won!");
  	  reset(motors,lineReader);
    }else if(region==WHITE){
  	lineReader.printAllSensors();
      Serial.println("On White");
      motors.turnLeft(300);
    }else if (region==GRAY){
  	  Serial.println("On Gray");
  	 Serial.println("I lost, please press button");
  	 //wait for user to press robot button
  	 motors.stopDrive();
  	 waitForSignal("loss");
  	lineReader.printAllSensors();
      motors.stopDrive(1000);
      reset(motors,lineReader);
    }else{
  	  motors.driveForward();
    }
  */
}
//outline for how the robot can reet its position
void getOnBlack(DriveShield robot, LineShield lineReader) {
  
  Serial.print("Ressetting on region:");
  int region = lineReader.getRegion();
  if (region == BLACK) { //if the robot is in the black region, just drive forward until you get to white
    //get the robot to the white region
    Serial.print("BLACK");
    Serial.println("\tBase Case");
     buzzer.playNote(NOTE_A(5), 500, 15);
    return;

  } else if (region == WHITE) { //if robot is in the white region, we need something more complicated
    Serial.print("WHITE");
    Serial.println("\tRecursive Case");
    //because we don't know if it's facing toward or away from the ring
    pathFind(robot, lineReader, 0, BLACK);
 
  } else { //if the robot is on the gray region, we also must pathfind
    Serial.print("GRAY");
    Serial.println("\tRecursive Case");
    pathFind(robot, lineReader, 0, WHITE);
  }
  //recursive case
  getOnBlack(robot,lineReader);
}

//recursive method to find the goal region on a zumo field
void pathFind(DriveShield robot, LineShield LineReader, bool probed, int goalRegion) {
  //base case is if we reached the region
  int region = lineReader.getRegion();
  int driveTime=300;
  Serial.print("Pathfinding on region:");
  Serial.print(region);
  Serial.print("\tGoal Region:");
  Serial.print(goalRegion);

  if (region == goalRegion) {
    Serial.println("\t Base Case");
     buzzer.playNote(NOTE_D(3), 500, 15);
    return;
  }
  //action is either to backtrack or go forward
  if (probed==true) { //if we've travelled too far in the wrong direction, reset
    Serial.println("\t turn because timed out");
    robot.driveBackward(driveTime);
    robot.turnRight(200);
    probed=false;
  } else {
    Serial.println("\t drive forward to find goalRegion");
    //otherwise, drive forward a smidge
    robot.driveForward(driveTime);
    probed=true;
  }
  Serial.println("\t Recursive Case");
  pathFind(robot, lineReader, probed, goalRegion);
}

//prmopts the user to press the button on the zumo robot, this will
//be done wirelessl soon
void waitForSignal(String event) {
  Serial.print("Please Press Button to finish ");
  Serial.println(event);
  buzzer.playNote(NOTE_A(3), 500, 15);
  while (!button.isPressed()) {}
}

//reset method to prepare the robot for a zumo match oce it is on balck region
void getToMatch(DriveShield robot,LineShield reader) {
  robot.driveBackward();
  int region = lineReader.getRegion();
  while (region == BLACK) {
    Serial.println("Mark");
    region = lineReader.getRegion();
    lineReader.printAllSensors();
   //delay(100);
  }
  robot.stopDrive();
  //drive the robot forward to start
  robot.driveForward(1000);
  waitForSignal("Reset");
}
