/*Jacob Smith 2019.4.1 Brandeis Robotics Club.
  Uses the Line class to follow a line around a circle*/

#define WHITE 0
#define GRAY 1
#define BLACK 2

#include <LineShield.h>
#include <DriveShield.h>
LineShield lineReader;
DriveShield motors;

void setup() {
  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  delay(3000);

  //display welcome message
  Serial.println("Brandeis University Example Line Sensor Folowwing Program");
  delay(1000);

  //assuming the robot is in the middle of the ring, drive to the edge
  motors.driveForward();
  while (lineReader.getRegion()==BLACK){}
  motors.stopDrive();

  //set robot to use low power
  motors.setPower(motors.getPower()/1.2);

}

//main loop that runs the program
void loop(){
	//the robot will pivot left until it stops seeing white
	motors.pivotLeft();
	while (lineReader.getRegion()==WHITE){}
	//the robot will privot right until it sees white
	motors.pivotRight();
	while (lineReader.getRegion()!=WHITE){}
	//these two behaviors allow the robot to follow a line!

}



