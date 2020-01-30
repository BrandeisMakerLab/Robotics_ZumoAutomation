/*Motors General Example File Brandeis Robotics Club
This example file can be run on the ZumoShield obot using 
an Arduino Uno Board or Wemos Board with no extra user code*/
//include the Motors general library
#include <MotorsGeneral.h>
MotorsGeneral robot;

//happens once to set up the program
void setup() {
  //initialize connection to computer to allow printing
  Serial.begin(115200);
  delay(3000);
  //print message
  Serial.println("Brandeis Univeristy Cross Platform Driving Program");

}

//runs continously
//shows how thte library can be used to perform basic drive functions
void loop() {
  //print drive forward message
  Serial.println("Drive Forward");
  //set the motor speeds to drive forward
  robot.setSpeeds(400,400);  
  //wait one second
  delay(1000);
  
  //print drive backwar message...
  Serial.println("Drive Backward");
  robot.setSpeeds(-400,-400);  
  delay(1000);

  Serial.println("Turn Right");
  robot.setSpeeds(-400,400);  
  delay(1000);

  Serial.println("Turn Left");
  robot.setSpeeds(400,-400);  
  delay(1000);

  Serial.println("Stop Robot");
  robot.setSpeeds(0,0);  
  delay(1000);
 
}
