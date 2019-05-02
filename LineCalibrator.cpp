/*Written by Jacob Smith for Brandeis Robotics club
 Calibrates the Zumo robot's line Sensors
 April 4 2018*/
//include the libraries necessary to make this one work
#include <Wire.h>
#include<LineShield.h>
#include <Sorter.h>

//add optional buzzer if using arduino uno
#ifdef ARDUINO_AVR_UNO
#include<PololuBuzzer.h>
#endif	
#include "LineCalibrator.h"

//creates a new LineCalibrator object
LineCalibrator::LineCalibrator(String* regions, int numRegions) {
	//assigns the pointer parameter to instance field
	this->regions = regions;
	//assings the size to instance field
	this->numRegions = numRegions;
	//creates new arrays of correct size
	this->regionThresholds = new int[numRegions - 1];
	this->regionMins = new int[numRegions];
	this->regionMaxes = new int[numRegions];
	//to save the order of the regions to use as a priority list
	//to do that we need to actually copy a new array
	this->regionsPriority = new String[numRegions];
	//loop through regions array
	for (int i = 0; i < numRegions; i++) {
		//use pointers to copy strings to priority Array
		*(regionsPriority + i) = *(regions + i);
	}
	minGlobal = 9999;
	maxGlobal = -9999;

}

//calibrates the line sensors according to the given regions
void LineCalibrator::calibrateLineSensors() {

	Serial.println("Brandeis University Line Sensor Calibration");
	Serial.println(
			"This Program allows for the regions of a sumo battle ring to be measured");
	delay(2000);
	
	//if using arduino uno
	#ifdef ARDUINO_AVR_UNO
	//create a buzzer to prompt user so the robot can be used without a screen
	ZumoBuzzer buzzer;
	#endif	
	//loop through regions
	for (int i = 0; i < numRegions; i++) {
		//if using arduino uno
		#ifdef ARDUINO_AVR_UNO
		//play the buzzer
		//the math is to make sure the note is at a pleasing octave
		buzzer.playNote(NOTE_D(i%4+3), 500, 15);
		#endif	
		
		//take the region and display name of that region
		takeReadingRegion(*(regions + i));
		regionMins[i] = minGlobal;
		regionMaxes[i] = maxGlobal;
	}

	Sorter lineSorter(regionMaxes, regionMins, regions, numRegions);
	lineSorter.selectionSort();

	//after sensor data has been taken, calculate the boundaries between regions
	for (int i = 0; i < numRegions - 1; i++) {
		//take the maximum sensor value o the previous and the minimum of this one
		int maxPrev = regionMaxes[i];
		int minNext = regionMins[i + 1];
		//print header
		//if they overlap, print an error
		if (maxPrev >= minNext) {
			Serial.println("Error, thresholds aren't discrete");
			regionThresholds[i] = -999;
			//otherwise take the average between them to be the threshold
		} else {
			//take the average between the max of the previous region and the min of the next
			int average = (regionMaxes[i] + regionMins[i + 1]) / 2;
			regionThresholds[i] = average;
		}

	}

	//print program is finished
	Serial.println("Finished Calibration");
}

//given a string representing the region being covered,
//prompts the person to place robot over region and takes line sensor reading
void LineCalibrator::takeReadingRegion(String region) {
	Serial.print("Please Move Robot to ");
	Serial.println(region);
	delay(1000);
	//loop for number of readings
	for (int reading = 1; reading <= NUM_READINGS; reading++) {
		//display readings number and wait for robot to be placed
		Serial.print("Reading: ");
		Serial.print(reading);
		Serial.print('\t');
		delay(1000);

		//take line sensor reading and display
		printAllSensors();

		//update the running minimum and maximum readings
		updateMinMax(reading);
	}
	Serial.print("\tMin ");
	Serial.print(minGlobal);
	Serial.print(" Max ");
	Serial.println(maxGlobal);
}

//uses the LineReader object to find the mimum and maximum reflection readings
//and updates the current min max with them
void LineCalibrator::updateMinMax(int reading) {
	//if this is the first reading, then set min and max to be that
	if (reading == 1) {
		minGlobal = getMin();
		maxGlobal = getMax();
		return;
	}
	//otherwise, get the minimum and maximum from this reading
	int curMin = getMin();
	int curMax = getMax();
	//update the global minum and maximum
	if (curMin < minGlobal) {
		minGlobal = curMin;
	}
	if (curMax > maxGlobal) {
		maxGlobal = curMax;
	}

}

//returns the array of thresholds
int* LineCalibrator::getThresholds() {
	return this->regionThresholds;
}

//returns the array of regions
String* LineCalibrator::getRegions() {
	return this->regions;
}
