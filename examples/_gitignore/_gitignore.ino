
#include <ESPServer.h>
String possibleCodes []= {"Drive_Forward", "Drive_Backward","Turn_Right","Turn_Left", "Stop_Robot"};
ESPServer website(possibleCodes);
void setup() {
  
}

void loop() {
  //this can't be a method becuase it would always print something
  int indexUsed = website.runServer();
  //if the website has been told to do something, return the string command
  if (indexUsed != -1) {
    Serial.println("I am doing");
    Serial.println(indexUsed);
    //Serial.println("I have been told to " + possibleCodes[indexUsed]);
  }
}
