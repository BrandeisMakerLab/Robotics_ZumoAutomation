//Overall Method: Robot will start driving, and will stop when sensor senses white, and then Timer will getTime().

#include <Timer.h>
#include <LineShield.h>
#include <DriveShield.h>
#include<ZumoShield.h>
//declare robot display timer
Timer timer;
LineShield lineReader;
DriveShield robot;
ZumoBuzzer buzzer;

void setup() {
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("Connection found");
  
  // put your setup code here, to run once:
  //While loop runs until sensor hits white
  //driveFoward should not have any arguments because there will be a lag.

}

void loop() {
  // put your main code here, to run repeatedly:
  //robot name: WALL-E JR.
  bool completed=travel(3200);
  robot.stopDrive(3000);

} 
//tells the robot to travel a certain amount of time, if it travels longer than that without seeing the edge
//mark error
bool travel(int expectedTime){
  timer.resetTime();
  printTime(expectedTime,1);
  int elapsedTime;
  while(!lineReader.isOnWhite()){
    robot.driveForward();
    elapsedTime=timer.getTime();
    if (elapsedTime>expectedTime){
      printTime(elapsedTime,3);
      return false;
    }
  }
  printTime(elapsedTime,2);
  return true;
  
}
//prints the elapsed time of a trip
//and plays a beginning, completion, and error tone
void printTime(int elapsedTime, int mode){
  if (mode==1){
    buzzer.playNote(NOTE_D(5), 200, 15);
    Serial.print("Trip Should Take:\t");  
  }else if (mode==2){
     buzzer.playNote(NOTE_A(5), 200, 15);
     Serial.print("Completed: Trip Took:\t");
    
  }else {
    buzzer.playNote(NOTE_E(4), 200, 15);
    Serial.print("Collided! Trip Took:\t");
  }
  Serial.print(elapsedTime);
  Serial.println(" ms");  
}
