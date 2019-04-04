/*Jacob Smith 2019.4.1 Brandeis Robotics Club.
  Uses the Line class to follow a line around a circle*/

#define WHITE 0
#define GRAY 1
#define BLACK 2

#include <LineShield.h>
#include <DriveShield.h>
#include <Timer.h>
#include <PushButton.h>

LineShield lineReader;
DriveShield motors;
Timer timer;
Pushbutton button(ZUMO_BUTTON);

void setup() {
  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  delay(2000);

  //display welcome message
  Serial.println("Brandeis University Example Line Sensor Folowwing Program");
  delay(500);

  //wait for 5 deconds to give passive time to set up
  delay(5000);

  //assuming the robot is in the middle of the ring, drive to the edge
  motors.driveForward();
  while (lineReader.getRegion()==BLACK){}
  motors.stopDrive();

  //set robot to use low power
  motors.setPower(motors.getPower()/1.2);
 //sets kill time to 1.5 seconds, if a robot's action takes longer than that it must have collided
  int abort=1500;
  bool collided=false;
  bool foundLine=true;
  bool buttonPressed=false;
  while ((!foundLine || !collided) && !buttonPressed){
	  timer.resetTime();
	  //the robot will pivot left until it stops seeing white
	  motors.pivotLeft();
	  while (lineReader.getRegion()==WHITE && timer.getTime()<abort &&  !buttonPressed){
		 if (button.isPressed()) {
		 	buttonPressed = true;
		 }

	  }
	  if(timer.getTime()>abort){collided=true;}
	  Serial.println(timer.getTime());
	  timer.resetTime();
	  //the robot will privot right until it sees white
	  motors.pivotRight();
	  while (lineReader.getRegion()!=WHITE && timer.getTime()<abort &&  !buttonPressed){
		  if (button.isPressed()) {
		 		 buttonPressed = true;
		  }
	  }
	  Serial.println(timer.getTime());
	  //these two behaviors allow the robot to follow a line!
	  if(timer.getTime()>abort){collided=true;}
	  foundLine=true;
  }
  motors.stopDrive();
  Serial.println("Collided");
}

//main loop that runs the program
void loop(){}
