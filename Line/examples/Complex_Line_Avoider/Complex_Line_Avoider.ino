/* Written by Jacob Smith for Brandies Robotcs Club May 4 2018
  this program is designed to allow the ZUMO32U4 robot to navigate in a sumo ring
  with black tape on the inside, gray/blue tape in the in bounds edge, and a white
  out of bounds outer layer. The robot displays how many matches it lost and the current region it is
  in. */
//libraries used in this program
#include <Drive.h>
#include <Zumo32U4.h>
#include <Line.h>

//to drive the robot
Drive robot;
//to display results
Zumo32U4LCD lcd;
//470 is average between the whitest tape and middle tape on the left and right sensors
//1116 is the average between the middle tape and the darkest tape on the left and right sensors
//293 is the average between the whitest tape and the middle tape on the middle sensor
//790 is the average between the middle tape and the darkest tape on the middle sensor
Line line(470, 1116, 293, 790);
//for playing the losing tone
Zumo32U4Buzzer speaker;
//ghow many times the robot has reached out of bounds
int numLosses;
//where the robot is in the zumo ring, either "INRING","EDGE", or "OUTBOUNDS"
const char* region;

//runs before loop method
void setup() {
  lcd.init();
}

//main loop of program, and updates lcd and navigates robot around ring
void loop() {
  //use the Line Sensors to determine where the robot is in the Zumo ring
  region = line.getRegion();
  //display the results to the LCD
  printToLCD();

  //navigate the robot through the ring
  navigate();

  delay(10);
  lcd.clear();
}

//displays where the robot is in the region and number of matches lost on robot's screen
void printToLCD() {
  lcd.print(region);
  lcd.gotoXY(0, 1);
  lcd.print("LOST:");
  lcd.print(numLosses);
}

//allows the robot to decide where to drive based on where it is in the zumo ring
void navigate() {
  robot.driveForward();
  if (strcmp(region, "EDGE") == 0) {
    turnBack();
  } else if (strcmp(region, "OUTBOUNDS") == 0) {
    numLosses++;
    robot.stopDrive();
    speaker.playNote(NOTE_D(6), 500, 15);
    delay(2000);
    turnBack();
  }
}

//get the robot back in the ring if it is on the edge
void turnBack() {
  robot.driveBackward(250);
  robot.turnRight(200);
}
