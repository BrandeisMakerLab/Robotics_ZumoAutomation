#include <ESPServer.h> 

String possibleCodes[]={"this","that"};
ESPServer server(possibleCodes);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int indexUsed=server.runServer();
  //if the website has been told to do something, return the string command
  if(indexUsed!=-1){
    Serial.println("I have been told to do"+possibleCodes[indexUsed]);
    }  

}
