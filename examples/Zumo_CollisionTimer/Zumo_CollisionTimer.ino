/*Jacob Smith 2.28.2019 This program builds on robotics club work to write a kill Timer for the Zumo robot. 
The idea is that if the robot knows how much time it should take to cros the field, roughly 3 seconds, then
if it does not reach the end of the field by 3 seconds, it knows it has been collided with*/
//include libraries needed to make this one work
#include <Timer.h>
#include <LineShield.h>
#include <DriveShield.h>
#include<ZumoShield.h>
//set up timer, lineReader, robot, and buzzer
Timer timer;
LineShield lineReader;
DriveShield robot;
ZumoBuzzer buzzer;
//runs only once,connects robot to computer
void setup() {
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("Connection found");
}
//main loop of robot, runs the travel function, waits 3 seconds, and repeats
void loop() {
  // put your main code here, to run repeatedly:
  //robot name: WALL-E JR.
  bool completed=travel(3200);
  robot.stopDrive(3000);

} 
//tells the robot to travel a certain amount of time, if it travels longer
//than that without seeing the edge mark error
bool travel(int expectedTime){
  timer.resetTime();
  printTime(expectedTime,1);
  int elapsedTime;
  //drive forward until you hit white region
  while(!lineReader.isOnWhite()){
    robot.driveForward();
    elapsedTime=timer.getTime();
    //or until kill timer has reached
    if (elapsedTime>expectedTime){
      //collision
      printTime(elapsedTime,3);
      return false;
    }
  }
  //no collision
  printTime(elapsedTime,2);
  return true;
  
}

//prints the elapsed time of a trip
//and plays a beginning, completion, and error tone
void printTime(int elapsedTime, int mode){
  //print the first part of the message depending on the mode
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
  //print the time given
  Serial.print(elapsedTime);
  Serial.println(" ms");  
}
