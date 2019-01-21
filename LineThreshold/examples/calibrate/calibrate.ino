/*Jacob Smith 1/20/2019 Brandeis University Robotics Club
 uses the LineThreeshold class to find the region the robot is over*/
#include<LineCalibrator.h>
#include<LineShield.h>
#include<LineThreshold.h>

//LineShield lineReader;
//using parenthesis here doesn't work for some reason
int numRegions = 3;
String regionsPriority[] = { "BLACK", "WHITE", "GRAY" };
String regions[] = { "WHITE", "GRAY", "BLACK" };
int thresholds[] = { 442, 1648 };
String regionsSeen[NUM_SENSORS];
//LineShield lineReader;
LineThreshold thresh();

void setup() {
	//starts serial connection at 9600 bits per second
	Serial.begin(9600);
	//guarantees robot will not continue until serial connection is established
	while (!Serial) {
	}
	//set all the arrays and numbers the LineThreshold object needs
	thresh.setElements(thresholds, regions, regionsPriority, numRegions,
			regionsSeen);
}
void loop() {

	String region = thresh.getRegion();
	displayLineReadings(region);
	delay(2000);
}

/**
 * Displays what each individual sensor sees and the overall region
 * @param region the region the robot is on
 */
void displayLineReadings(String region) {
	Serial.print("Individual Sensors:\t");
	//print what region each indiivual sensor sees
	for (int i = 0; i < NUM_SENSORS; i++) {
		Serial.print(regionsSeen[i]);
		Serial.print("\t");
	}
	//print the overall region
	Serial.print("Final Region:\t");
	Serial.println(region);
}
