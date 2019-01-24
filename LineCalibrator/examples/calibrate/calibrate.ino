/*Jacob Smith 1/19/2019 Brandeis University Robotics Club
 uses the LineCalibrator class to find thrshold values for the line sensors in the sumo ring*/
#include<LineCalibrator.h>
#include<LineShield.h>
#include <Arduino.h>
#include<Wire.h>
//LineShield lineReader;
//using parenthesis here doesn't work for some reason
String regions[] = { "BLACK", "WHITE", "GRAY" };
int numRegions = 3;
LineCalibrator cali(regions, numRegions);

void setup() {
  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  while (!Serial) {
  }
  // calibrates the line sensors
  cali.calibrateLineSensors();
  //get the regions and threhsolds calculated
  String* regions = cali.getRegions();
  int* thresholds = cali.getThresholds();
  //print the arrays
  Serial.println("Final Results");
  printArrs(regions,thresholds);
}

void loop() {

}

/**
 *  Prints the regions and threshold levels to the Serial Monitor
 * @param regions a pointer to an array of region names
 * @param thresholds the brightness levels that are the cutoffs between regions
 */
void printArrs(String* regions, int* thresholds) {
  //iterate along the regions array
  for (int i = 0; i < numRegions-1; i++) {
    //print the region and its cutoff
    Serial.print(*(regions + i));
    Serial.print("\t");
    Serial.println(*(thresholds+i));

  }
  //print the last region, which wont have a cutoff
  Serial.println(*(regions + numRegions-1));

}

