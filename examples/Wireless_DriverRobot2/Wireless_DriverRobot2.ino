/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
  https://randomnerdtutorials.com/esp8266-web-server/
  Moified by Dies Robotics Club to be simpler
*********/

// Load Wi-Fi library
#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid     = "brandeis_open";
const char* password = "";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String driveCode = "stop";

void setup() {
  Serial.begin(115200);
  initOutputs();
  // Initialize the output variables as outputs
  wifiConnect();
}

//the pins that each motor and directino is on
#define LEFTINVERSE  0
#define RIGHTINVERSE  13
#define LEFTPOWER  2
#define RIGHTPOWER  15

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // move robot
            if (header.indexOf("GET /driveF") >= 0) {
              driveCode = "driveF";
              driveForward();
            } else if (header.indexOf("GET /driveB") >= 0) {
              driveCode = "driveB";
              driveBackward();
            } else if (header.indexOf("GET /stopF")>=0){
              driveCode = "stopF";
              stopDrive();  
            } else {//if (header.indexOf("GET /stopB")>=0)
              driveCode = "stopB";
              stopDrive();  
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");

             // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println("</style></head>");

               
            // Web Page Heading
            client.println("<body><h1>Dies Robotics Test Web Server</h1>");
            Serial.println(driveCode);

            // If the output5State is off, it displays the ON button       
            if (driveCode=="driveF") {
               client.println("<p><a href=\"/stopF\"><button class=\"button\">Stop Robot</button></a></p>");
            } else if(driveCode=="driveB"){
              client.println("<p><a href=\"/stopB\"><button class=\"button button2\">Stop Robot</button></a></p>");
            } else if(driveCode=="stopF"){
               client.println("<p><a href=\"/driveB\"><button class=\"button button2\"> Drive Backward</button></a></p>");
           }else if(driveCode=="stopB"){
               client.println("<p><a href=\"/driveF\"><button class=\"button button2\">  DriveForward </button></a></p>");
           }
               
 
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
  }
}

void wifiConnect(){
   // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  
}

void initOutputs() {
  //set all the ports to off and set thir pinmodes
  digitalWrite(LEFTPOWER, LOW);
  pinMode(LEFTPOWER, OUTPUT);
  digitalWrite(LEFTPOWER, LOW);
  digitalWrite(RIGHTPOWER, LOW);
  pinMode(RIGHTPOWER, OUTPUT);
  digitalWrite(RIGHTPOWER, LOW);
  digitalWrite(LEFTINVERSE, LOW);
  pinMode(LEFTINVERSE, OUTPUT);
  digitalWrite(LEFTINVERSE, LOW);
  digitalWrite(RIGHTINVERSE, LOW);
  pinMode(RIGHTINVERSE, OUTPUT);
  digitalWrite(RIGHTINVERSE, LOW);
  pinMode(LEFTINVERSE, OUTPUT);
  pinMode(RIGHTINVERSE, OUTPUT);
  pinMode(LEFTPOWER, OUTPUT);
  pinMode(RIGHTPOWER, OUTPUT);

}

//sets pins to drive forward at full power
void driveForward() {
  Serial.println("Drive Forward");
  digitalWrite(LEFTINVERSE, LOW);
  digitalWrite(RIGHTINVERSE, LOW);
  digitalWrite(LEFTPOWER, HIGH);
  digitalWrite(RIGHTPOWER, HIGH);
}
//sets pins to drive forward at full power
void stopDrive() {
  Serial.println("Stop Drive");
  digitalWrite(LEFTINVERSE, LOW);
  digitalWrite(RIGHTINVERSE, LOW);
  digitalWrite(LEFTPOWER, LOW);
  digitalWrite(RIGHTPOWER, LOW);
}

//sets pins to drive forward at full power
void driveBackward() {
  Serial.println("Drive Backward");
  digitalWrite(LEFTINVERSE, HIGH);
  digitalWrite(RIGHTINVERSE, HIGH);
  digitalWrite(LEFTPOWER, HIGH);
  digitalWrite(RIGHTPOWER, HIGH);
}
