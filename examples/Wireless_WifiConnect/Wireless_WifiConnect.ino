/* Simplified Example Code from http://educ8s.tv/arduino-esp8266-tutorial-first-look-at-the-wemos-d1-arduino-compatible-esp8266-wifi-board/
Jacob Smith
*/

//include examples to make this one work
#include <ESP8266WiFi.h>
#include <SPI.h>            // For SPI comm (needed for not getting compile error)
#include <Wire.h>           // For I2C comm, but needed for not getting compile error

#define OLED_RESET  16  // Pin 15 -RESET digital signal

const char* ssid     = "brandeis_open";
const char* password = "";

char servername[]="educ8s.com";  // remote server we will connect to

WiFiClient client;

String result;

void deleteHttpHeader()
{
if(result.endsWith("Content-Type: text/plain"))
{
  result="";
}

}

void sendGET() //client function to send/receive GET request data.
{
  if (client.connect(servername, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /test.txt HTTP/1.1"); //download text
    client.println("Host: educ8s.tv");
    client.println("Connection: close");  //close 1.1 persistent connection  
    client.println(); //end of get request
  } 
  else {
    Serial.println("connection failed"); //error message if no client connect
    Serial.println();
  }

  while(client.connected() && !client.available()) delay(1); //waits for data
  while (client.connected() || client.available()) { //connected or data available
    char c = client.read(); //gets byte from ethernet buffer
    result = result+c;
    deleteHttpHeader();
  }
  Serial.println(result);
  client.stop(); //stop client

}

void setup() {
  //set up Serial Connection
  Serial.begin(115200);
  delay(2000);
  //Display Chip's unique adress
  Serial.println("Connecting");
  Serial.print("MAC Adress is      ");
  Serial.println(WiFi.macAddress());
  Serial.print("Local IP adress is ");
  Serial.println(WiFi.localIP());
  //connect to wifi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  //display dots while waiting to connect
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  //get webpage
  result="";
  delay(500);
  sendGET();
}

//not using loop function
void loop() {}
