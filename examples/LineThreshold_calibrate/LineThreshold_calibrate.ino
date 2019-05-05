/*Jacob Smith 1/23/2019 Brandeis University Robotics Club
 uses the LineThreeshold class to find the region the robot is over*/
#include<LineCalibrator.h>
#include<LineShield.h>
#include<LineThreshold.h>

//everything the lineThreshold class needs to convert brightness readings to the names of regions
int numRegions = 3;
String regions[] = { "WHITE", "GRAY", "BLACK" };
int thresholds[] = { 442, 1648 };
String regionsSeen[NUM_SENSORS];
//using parenthesis here does not work for some reason
LineThreshold thresh;
//runs once
void setup() {
	//starts serial connection at 9600 bits per second
	Serial.begin(9600);
	//guarantees robot will not continue until serial connection is established
	while (!Serial) {
	}
	//set all the arrays and numbers the LineThreshold object needs
	thresh.setElements(thresholds, regions, numRegions,
			regionsSeen);
}

//runs continously
void loop() {
	//convert the brightness readings to the names of regions
	thresh.convertToRegion();
	//display the names
	displayLineReadings();
	//wait 2 seconds
	delay(2000);
}

/**
 * Displays what each individual sensor sees and the overall region
 * @param region the region the robot is on
 */
void displayLineReadings() {
	Serial.print("Individual Sensors:\t");
	//print what region each individual sensor sees
	for (int i = 0; i < NUM_SENSORS; i++) {
		Serial.print(regionsSeen[i]);
		Serial.print("\t");
	}
}
