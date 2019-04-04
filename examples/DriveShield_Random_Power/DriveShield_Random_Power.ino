/*Written by Jacob Smith for Brandeis Robotics Club
 contains an example program to use the DriveShield class
 with a random motor power each time the robot turns on
 March 8 2018
 */
//includes the header file of the library
#include <DriveShield.h>

//creates a global reference to a Drive object
DriveShield robot;

//occurs before the program enters its main loop
void setup() {

	Serial.begin(9600);
	while (!Serial) {
	}
	Serial.println("ready");

	// randomize using noise from analog pin 1
	randomSeed(analogRead(1));
	int power=random(100, 400);

	//set motor power to random number
	robot.setPower(power);
	//reading port to get truly random number
	randomSeed(analogRead(1));
	Serial.println(robot.getPower());

	//commands the robot to stop for 2 seconds
	robot.stopDrive(2000);

}
//the main loop of the robot

void loop() {
	//commands the robot to perform each step for half a second
	robot.driveForward(500);
	robot.turnRight(300);
	robot.turnLeft(300);
	robot.driveBackward(500);
	robot.stopDrive(500);
}
