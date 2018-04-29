/*Written by Jacob Smith for Brandeis Robotics Club, April 29 2018.
  An example file for the Encoder class, prints the robot' left position,
  right position, avergae position, left velocity, right velocity, average velocity, 
  and overall direction to the Serial Monitor. Units are centimeters and centimeters per second*/
//include the source library
#include <Encoder.h>
//the encoder object that will asked for position, velocity, and direction
Encoder enc;

//will be called before main loop
void setup() {

  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  while (!Serial) {}

  //prints program introduction
  Serial.println("Welcome to Brandeis University Position Printing Program");
  Serial.println("Position is in cm, Velocity is in cm/s");
  Serial.println("Try moving the robot on the ground and watching how the display changes!");
  //wait one second
  delay(1000);
}

//main loop, prints the robot's position, velocity, and direction every half second
void loop() {
  printNumber("LEFTPOS:", enc.getLeftPos());
  printNumber("RIGHTPOS:", enc.getRightPos());
  printNumber("AVGPOS:", enc.getAvgPos());
  printNumber("LEFTVEL:", enc.getLeftVel());
  printNumber("RIGHTVEL:", enc.getRightVel());
  printNumber("AVGVEL:", enc.getAvgVel());
  Serial.print("\t");
  Serial.println(enc.getDirection());
  delay(500);

}

//prints a message and a number to the Serial port
void printNumber(const char* message, double number) {
  Serial.print(message);
  Serial.print(number);
  Serial.print("\t");
}
