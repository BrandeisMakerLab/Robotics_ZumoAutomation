/*Jacob Smith 2018.5.7 Brandeis Robotics Club.
  Uses the Line class to print line sensor values
  to the Serial Monitor*/

#define WHITE 0
#define GRAY 1
#define BLACK 2

#include <LineShield.h>
#include <DriveShield.h>
#include <PushButton.h>

LineShield lineReader;
DriveShield motors;
Pushbutton button(ZUMO_BUTTON);
void setup() {
  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  delay(3000);

  Serial.println("Brandeis University Example Line Sensor Printing Program");
  Serial.println("Press Button to start");
  //wait for user to press robot button
  motors.stopDrive();
  while(!button.isPressed()){
  }
  reset(motors,lineReader);
}

//main match logic
void loop() {

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
	 while(!button.isPressed()){
	 }
	lineReader.printAllSensors();
    motors.stopDrive(1000);
    reset(motors,lineReader);
  }else{
	  motors.driveForward();
  }

}
//outline for how the robot can reet its position
void reset(DriveShield robot, LineShield lineReader){
	robot.setPower(robot.getPower()/2);//halve robot power to reset
	Serial.print("Ressetting on region:");
	int region=lineReader.getRegion();
	if(region==BLACK){//if the robot is in the black region, just drive forward until you get to white
		Serial.println("BLACK");
		robot.driveForward();
		while(region==BLACK){
			region=lineReader.getRegion();
		}
		robot.stopDrive();
	}else if(region==WHITE){//if robot is in the white region, we need something more complicated
		Serial.println("WHITE");
		//because we don't know if it's facing toward or away from the ring
		pathFind(robot, lineReader,0, BLACK);
	}else{//if the robot is on the gray region, we also must pathfind
		Serial.println("GRAY");
		pathFind(robot, lineReader,0, WHITE);
	}
	robot.setPower(robot.getPower()*2);//reset robot power to play normal match
	Serial.println("Done Resetting, please press button!");
	//wait for user to press robot button
	motors.stopDrive();
	while(!button.isPressed()){
	}
}

//recursive method to find the goal region on a zumo field
void pathFind(DriveShield robot, LineShield LineReader,int tries, int goalRegion){
	int power=robot.getPower();

	//base case is if we reached the region
	int region=lineReader.getRegion();
	if (region==goalRegion){
		return;
	}
	//action is either to backtrack or go forward
	if(tries>2){//if we've travelled too far in the wrong direction, reset
			robot.driveBackward(200);
			robot.turnRight(200);
    }else if (region==goalRegion){
    		//otherwise, drive forward a smidge
    		robot.driveForward(200);
    }
	pathFind(robot,lineReader,tries+1,goalRegion);
}




