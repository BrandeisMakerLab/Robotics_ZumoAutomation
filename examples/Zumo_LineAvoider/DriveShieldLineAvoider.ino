/*Jacob Smith 2018.5.7 Brandeis Robotics Club.
  Uses the Line class to print line sensor values
  to the Serial Monitor*/

#define WHITE 0
#define GRAY 1
#define BLACK 2

#include <LineShield.h>
#include <DriveShield.h>
LineShield lineReader;
DriveShield motors;
void setup() {
  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  delay(3000);

  Serial.println("Brandeis University Example Line Sensor Printing Program");
  delay(2000);
}


void loop() {

  int region=lineReader.getRegion();
  if(region==WHITE){
	lineReader.printAllSensors();
    Serial.println("On White");
    motors.turnLeft(300);
  }else if (region==GRAY){
	lineReader.printAllSensors();
    Serial.println("On Gray");
    motors.stopDrive(100);
    motors.driveBackward(500);
  }else{
	  motors.driveForward();
  }

}




