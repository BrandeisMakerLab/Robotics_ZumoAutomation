/*Jacob Smith 2019.4.1 Brandeis Robotics Club.
 Allows the Robot to line itself up on the edge of the zumo ring and wait for the active robot.*/
//define constants to refer to regions, so I can type WHITE instead of 0
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
	delay(2000);

	//display welcome message
	Serial.println("Brandeis University Example Line Sensor Folowwing Program");
	delay(500);

	//assuming the robot is in the middle of the ring, drive to the edge
	motors.driveForward();
	while (lineReader.getRegion() == BLACK) {
	}
	motors.stopDrive();

	//set robot to use low power
	motors.setPower(motors.getPower() / 1.2);

	//the robot follows the line 10 times, to make sure it is lined up and in position
	for (int i = 0; i < 10; i++) {
		//the robot will pivot left until it stops seeing white
		motors.pivotLeft();
		while (lineReader.getRegion() == WHITE) {
		}
		//the robot will pivot right until it sees white
		motors.pivotRight();
		while (lineReader.getRegion() != WHITE) {
		}
		//these two behaviors allow the robot to follow a line!
	}
	motors.stopDrive(500);
	//this will wait unil the robot sees a different region with the line sensor
	int oldRegion=lineReader.getRegion();
	while(oldRegion==lineReader.getRegion()){}
	//print and pivot to show robot knows to collide
	Serial.println("Collided!");
	motors.driveBackward(250);
}

//main loop that runs the program, not used
void loop() {}
