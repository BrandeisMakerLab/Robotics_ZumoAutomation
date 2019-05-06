/*Jacob Smith Timothy Hebert April 14 2019 Brandeis University obotics Club
   Shows how the Board Type in Arduno can be accessed in arduino, which is useful when working with programs
   that run of of different boards, like in controlling motors
*/

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Brandeis University Robotics Board Printing program");
  Serial.println("Shows many different ways of getting the current board definition with code");
  Serial.println("METHOD           :RESULT");
     	   printMsg("Chip        Type: ",getChipDef());
        printMsg("Board Type       : ",getBoardDef());

}

void loop() {}


//used compiler defitions to get boad type
// with if defines an underscore
String getChipDef() {
  #ifdef __AVR_ATmega328P__
  return "Uno"; 
#elif tttt
  return "Wemos mini";
#elif __ets__
  return "Nodemcu";
#else
  return "Other Chip";
#endif
}

//uses compiler definitions to get boad type
//with ifdefs
String getBoardDef() {
#ifdef ARDUINO_AVR_UNO
  return "Uno"; 
#elif ARDUINO_ESP8266_WEMOS_D1R1
  return "Wemos";
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
