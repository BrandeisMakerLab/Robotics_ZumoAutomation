#include <ESP8266WiFi.h>
#include <ESP_SSD1306.h>    // Modification of Adafruit_SSD1306 for ESP8266 compatibility
#include <Adafruit_GFX.h>   // Needs a little change in original Adafruit library (See README.txt file)
#include <SPI.h>            // For SPI comm (needed for not getting compile error)
#include <Wire.h>           // For I2C comm, but needed for not getting compile error

#define OLED_RESET  16  // Pin 15 -RESET digital signal

ESP_SSD1306 display(OLED_RESET); // FOR I2C

const char* ssid     = "ZyXEL";
const char* password = "password";

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
    Serial.println(c);
  }

  Serial.println(result);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print(result);
  display.display();
  client.stop(); //stop client

}

void setup() {
  Serial.begin(115200);
  delay(10);
   display.begin(SSD1306_SWITCHCAPVCC);  // Switch OLED

  display.display();
  display.clearDisplay();
  delay(2000);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Connecting to ");
  display.print(ssid);
  display.display();


  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  display.println("\nWiFi connected");  
  display.println("IP address: ");
  display.println(WiFi.localIP());
  display.display();
}


void loop() {
  result="";
  delay(5000);
  sendGET();
}


