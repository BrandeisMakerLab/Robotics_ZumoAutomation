/*Jacob Smith 1/19/2019 Brandeis University Robotics Club
uses the LineCalibrator class to find thrshold values for the line sensors in the sumo ring*/
#include<LineCalibrator.h>
#include<LineShield.h>
LineShield lineReader;
//LineCalibrator cali(lineReader);
void setup() {
  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  while (!Serial) {}
  // put your setup code here, to run once:
  //cali.calibrateLineSensors();

}

void loop() {
  //cali.calibrateLineSensors();
  lineReader.printAllSensors();

}
