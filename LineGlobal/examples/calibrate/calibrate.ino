/*Jacob Smith 1/19/2019 Brandeis University Robotics Club
 uses the LineCalibrator class to find thrshold values for the line sensors in the sumo ring*/

#include <Arduino.h>
#include<LineGlobal.h>
#include<Wire.h>

#define NUM_SENSORS 6
//the number of regions and names of them in order the robot should go over them
int numRegions = 3;

String regions[] = { "BLACK", "WHITE", "GRAY" };
String regionsSeen[NUM_SENSORS];

//an array of the regions the robot has seen
//create an array for the threshold to populate with what region the line sensors see
LineGlobal reader;

void setup() {
	reader.setElements(regions, numRegions, regionsSeen, true);
}
void loop() {
	//get what region the robot is over
	String region=reader.getRegion();
	//display the region and individual line sensor readings
	reader.displayLineReadings();
	//wait 2 seconds
	delay(2000);
}



