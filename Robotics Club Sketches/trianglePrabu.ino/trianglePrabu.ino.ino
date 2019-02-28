/*name:prabu Gugagantha
 * Date 02/07/18
 * tried to make bot go in triangle illuminati style
*/
//includes the header file of the library
#include <DriveShield.h>

//creates a global reference to a Drive object
DriveShield robot;

//occurs before the program enters its main loop
void setup() {
  //commands the robot to stop for 2 seconds
  robot.stopDrive(1000);
 // robot.driveForward(500);


}
//the main loop of the robot

void loop() {
  robot.turnRight(308);
  robot.driveForward(300);
  robot.stopDrive(1000);
  //commands the robot to perform each step for half a second

}
