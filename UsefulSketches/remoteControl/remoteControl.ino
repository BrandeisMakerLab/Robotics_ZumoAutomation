/* Brandeis University Robotics Club Jacob Smith
    Allows the User to remote control a Zumo Shield Robot
    Source for some of this https://www.teachmemicro.com/arduino-bluetooth/
*/

//include the two libraries we need to run the remote control
#include <SoftwareSerial.h>
#include <ZumoMotors.h>
//create the serial and robot objects
SoftwareSerial Bluetooth(12, 13); // RX, TX
ZumoMotors robot;
char Data; // the data received

//runs once
void setup() {
  //start connection, wait 5 seconds to start up window, and display welcome message
  Bluetooth.begin(9600);
  delay(3000);
  Bluetooth.println("Welcome to Brandeis University Remote Control");
  Bluetooth.println("w to Drive Forward  a to Turn Left");
  Bluetooth.println("s to Drive Backward d to Turn Right");
}
//happens continously
void loop() {
  //if bluetoorh recieves command
  if (Bluetooth.available()) { //wait for data received
    //process it
    obeyCommand();
  } else{
    robot.setSpeeds(0,0);  
  }
  delay(25);
}

//runs once user typed key
void obeyCommand() {
  //store they key in a character variable
  Data = Bluetooth.read();
  //if the character is a w
  if (Data == 'w') {
    //print drive forward and tell the robot to drive forward
    Bluetooth.println("Drive Forward");
    robot.setSpeeds(400,400);
    //etc for other letters
  } else if (Data == 'a') {
    Bluetooth.println("Turn Left");
     robot.setSpeeds(-200,200);
  } else if (Data == 's') {
    Bluetooth.println("Drive Backward");
    robot.setSpeeds(-400,-400);
  } else if (Data == 'd') {
    Bluetooth.println("Turn Right");
    robot.setSpeeds(200,-200);
  }else if (Data=='q'){
    robot.setSpeeds(0,0); 
   }
  //if letter isn't one of these, nothing happens
}
