/*
 * Jacob Smith Brandeis Robotics Club April 16 2019
 * Uses the DRV88 Motor Driver to  go forward, stop ,and Drive Backward
 * Interfacing with the motor driver is helpful when progrmaming the zumo
 * with the wemos d1r1 board
 */

#include <DRV8835MotorShield.h>
DRV8835MotorShield motors;
void setup(){}
void loop()
{
  //drive forward
  driveRobot(100,100);
  //stop
  driveRobot(0,0);
  //drive backward
  driveRobot(-100,-100);
  //stop
  driveRobot(0,0);
}

//helper method to drive the robot and wait
void driveRobot(int leftSpeed,int rightSpeed){
  motors.setSpeeds(leftSpeed,rightSpeed);
  delay(1000);
 }
