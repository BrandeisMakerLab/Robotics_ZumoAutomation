#include <DRV8835MotorShield.h>

/*
 * This example uses the DRV8835MotorShield library to drive each motor with the
 * Pololu DRV8835 Dual Motor Driver Shield for Arduino forward, then backward. 
 * The yellow user LED is on when a motor is set to a positive speed and off when
 * a motor is set to a negative speed.
 */


DRV8835MotorShield motors;
///2 is right side leave
void setup(){}
void loop()
{
  driveRobot(100,100);
  driveRobot(0,0);
  driveRobot(-100,-100);
  driveRobot(0,0);
}
void driveRobot(int leftSpeed,int rightSpeed){
  motors.setSpeeds(leftSpeed,rightSpeed);
  delay(1000);
 }
