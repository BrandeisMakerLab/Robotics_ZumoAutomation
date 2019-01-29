/*Written by Jacob Smith for Brandeis Robotics Club
   contains an example program to tell the robot to stop
   thoeugh bluetooth
   //from https://www.teachmemicro.com/arduino-bluetooth/

*/
//includes the header file of the library
#include <DriveShield.h>
#include <SoftwareSerial.h>
//creates a global reference to a Drive object
DriveShield robot;

SoftwareSerial Bluetooth(12, 13); // RX, TX

char Data; // the data received

//occurs before the program enters its main loop
void setup() {
  Bluetooth.begin(9600);
  while (!Bluetooth) {}
  //commands the robot to stop for 2 seconds
  robot.stopDrive(2000);
  Bluetooth.println("Welcome to the Brandeis Unversity Robotics Club");
  Bluetooth.println("Remote Control Program!");
  Bluetooth.println(" w to Move Forward,   a to Turn Right");
  Bluetooth.println(" s to Drive Backward, s to Turn Left");

}
//the main loop of the robot

void loop() {
  if (Bluetooth.available()) { //wait for data received
    readCommand();
  }
  delay(100);
}
void readCommand() {

  Data = Bluetooth.read();
  if (Data == 'w') {
    Bluetooth.println("Drive Forward");
    robot.driveForward(500);
  } else if (Data == 'a') {
    Bluetooth.println("Turn Left");
    robot.turnLeft(300);
  } else if (Data == 's') {
    Bluetooth.println("Drive Backward");
    robot.driveBackward(500);
  }
  else if (Data == 'd') {
    Bluetooth.println("Turn Right");
    robot.turnRight(300);
  }
}
