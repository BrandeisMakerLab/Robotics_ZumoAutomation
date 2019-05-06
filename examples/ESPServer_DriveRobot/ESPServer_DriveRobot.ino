/* Wifi Server with Motor Driving Jacob Smith Brandeis Robotics Club May 5 2019
 *  Uses a Wii Server and Motor Driving class to run a website that allows the robot 
 *  to be controlled by a browser
*/
//inclue the necessary libraries
#include <DriveShield.h>
#include <ESPServer.h> 
//the title of the webite
String title="Test Title";
//the possible options of the website
String possibleCodes[]={"Drive_Forward","Drive_Backward","Turn_Right","Turn_Left","Stop"};
//create a new ESPServer 
ESPServer server(title,possibleCodes,5);
//create a new moors general object
DriveShield robot;

void setup() {
  //establish a USB connection to the computer
  Serial.begin(115200);
  //wait for a bit so connection can be established
  delay(2000);
  //display example message
  Serial.println("Brandeis University Robotics Example Web Server with Robot Driving");
  //connect to the internet
  server.wifiConnect();
}

void loop() {
  //run the server and display the action prformed
  int indexUsed=server.runServer();
  //only print when user has experienced action
  if(indexUsed!=-1){
    conveyAction(indexUsed);
   }  
}

//converts the index of actions into a driving action by the robot
void conveyAction(int indexUsed){
  //convert the action to a string
  String action=possibleCodes[indexUsed];
   //print the action
  Serial.println(action);
  if(action=="Drive_Forward"){
    robot.driveForward(400);
  }else if (action=="Drive_Backward"){
    robot.driveBackward(400);
  }else if (action=="Turn_Right"){
    robot.turnRight(200);
  }else if (action=="Turn_Left"){
    robot.turnLeft(200);
  }else if (action=="Stop"){
    robot.stopDrive();
  }
}
