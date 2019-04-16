/*Jacob Smith Timothy Hebert April 14 2019 Brandeis University obotics Club
   Shows how the Board Type in Arduno can be accessed in arduino, which is useful when working with programs
   that run of of different boards, like in controlling motors
*/

#include <ArduinoBoardManager.h>
ArduinoBoardManager arduino = ArduinoBoardManager();

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println("Brandeis University Robotics Board Printing program");
  Serial.println("Shows many different ways of getting the current board definition with code");
  Serial.println("METHOD           :RESULT");
        printMsg("Board Manager    : ",arduino.BOARD_NAME);
		    printMsg("if defined no _  : ",getBoardDef());
        printMsg("if defined with _: ",getBoardIfDefined());
        printMsg("ifdefs           : ",getBoardIfDef());

}

void loop() {}

//uses compiler definitions to get board type
//with if defines and no underscores
String getBoardDef() {
#if defined(ARDUINO_AVR_UNO)
  // Uno pin assignments
  return "Uno";
#elif defined( ESP8266_WEMOS_D1MINI)
  // Pro Mini assignments
  return "Wemos";
#else
  //code here
  return "Other Board";
#endif

}

//used compiler defitions to get boad type
// with if defines an underscore
String getBoardIfDefined() {
#if defined(__AVR_ATmega328P__)
  return "Mega 328P";
#elif defined(__ESP8266_WEMOS_D1R1__)
  return "Wemos D1 R1";
#elif defined(__ARDUINO_ESP8266_WEMOS_D1R1__)
  return "Wemos D1 R1";
#elif defined(__ARDUINO_WEMOS_D1R1__)
  return "Wemos D1 R1";
#elif defined(__ESP8266_WEMOS_D1MINI__)
  return "Wemos D1 mini";
#elif defined(__ESP8266_NODEMCU__)
  return "esp8266 nodemcu";
#elif defined(__ARDUINO_ESP8266_NODEMCU__)
  return "esp8266 nodemcu";
#else
  return "other board";
#endif
}

//uses compiler definitions to get boad type
//with ifdefs
String getBoardIfDef() {
#ifdef ARDUINO_AVR_UNO
  return "Uno"; 
#elif Arduino_ESP8266_WEMOS_D1MINI
  return "Wemos mini";
#elif ARDUINO_ESP8266_NODEMCU
  return "Nodemcu";
#else
  return "Other Board";
#endif
}

//helper method to print messages to the console
void printMsg(String A,String B){
  Serial.print(A);
  Serial.println(B);
}

