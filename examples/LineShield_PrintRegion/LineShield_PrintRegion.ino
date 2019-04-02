/*Jacob Smith 2018.5.7 Brandeis Robotics Club.
  Uses the Line class to print line sensor values
  to the Serial Monitor*/

#include <LineShield.h>
LineShield lineReader;
void setup() {
  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  while (!Serial) {}

  Serial.println("Brandeis University Example Line Sensor Printing Program");
  delay(2000);
}


void loop() {
  lineReader.printAllSensors();
  int region=lineReader.getRegion();
  if(region==0){
    Serial.println("On White");  
  }else if (region==1){
    Serial.println("On Gray");
  }else{
	  Serial.println("On Black");
  }
 
}




