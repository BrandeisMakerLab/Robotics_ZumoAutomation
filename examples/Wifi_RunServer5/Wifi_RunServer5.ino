#ifdef ARDUINO_ESP8266_WEMOS_D1R1
#include <ESPServer.h> 

String possibleCodes[]={"this","that"};
ESPServer server(possibleCodes,2);
void setup() {
  Serial.begin(115200);
  while(!Serial){}
  Serial.println("Brandeis University Robotics Example Web Server");
}

void loop() {
  int indexUsed=server.runServer();
  //if the website has been told to do something, return the string command
  if(indexUsed!=-1){
    Serial.println("I have been told to do: "+possibleCodes[indexUsed]);
    }  

}
#else
  #error This class does not work for your board
#endif
