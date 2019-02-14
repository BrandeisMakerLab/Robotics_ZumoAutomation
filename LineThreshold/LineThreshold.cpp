/*Written by Jacob Smith\for Brandeis Robotics club
 Allows the robot's line sensors to be calibrated
 January 20 2019*/
//include the libraries necessary to make this one work
#include <Arduino.h>
#include<LineShield.h>
#include<LineCalibrator.h>
#include "LineThreshold.h"

/**
 * Creates a LineThreshold object with default states
 */
LineThreshold::LineThreshold(){
	regionsSeen=new String[6];
	numRegions=0;
	thresholds=new int[2];
	regions=new String[3];

}


/**
 * //creates a new LineThreshold object with dual sensor reading
 * @param regionThresholds an array of the brightness readings that divide regions
 * @param regions an array of the name of regions in order of thresholds
 * @param regionsPriority an array of the name of regions in order of their priority
 * @param numRegions the number of regions
 * @param regionsSeen an array of the regions the line sensors have seen to be populated
 */
void LineThreshold::setElements(int* regionThresholds, String* regions, int numRegions, String* regionsSeen) {
	this->thresholds = regionThresholds;
	this->regions = regions;
	this->numRegions = numRegions;
	this->regionsSeen = regionsSeen;
}


/**
 *
 *updates the regionsSeen array with what regions each line sensor has seen
 */
void LineThreshold::convertToRegion() {
	//create an array of reflections
	unsigned int reflections[NUM_SENSORS];
	//modify the array with the current sensor values
	getReflections(reflections);
	//modify the array with current regions seen
	getRegionsSeen(regionsSeen, reflections);

}

/**
 *
 * @return an array of the names of regions the line sensors see
 */
void LineThreshold::getRegionsSeen(String decodedRegions[],
		unsigned int reflections[]) {
	//loop through all sensors
	for (int i = 0; i < NUM_SENSORS; i++) {
		int reflection = reflections[i];
		//get the sensor for that region
		decodedRegions[i] = getIndividualRegion(reflection);
	}
}

/**
 *
 * @param reflection the relflection of one sensor
 * @return the region that sensor is on
 */
String LineThreshold::getIndividualRegion(int reflection) {
	//loop through all the regions
	for (int i = 0; i < numRegions - 1; i++) {
		//if reflection is within the threshold, return that region
		int threshold = thresholds[i];
		if (reflection <= threshold) {
			return *(regions + i);
		}

	}
	//if you've reached the end, you're at the last region by definition
	return *(regions + numRegions - 1);
}


