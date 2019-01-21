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
	regionsPriority=new String[3];
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
void LineThreshold::setElements(int* regionThresholds, String* regions,
		String* regionsPriority, int numRegions, String* regionsSeen) {
	this->thresholds = regionThresholds;
	this->regions = regions;
	this->regionsPriority = regionsPriority;
	this->numRegions = numRegions;
	this->regionsSeen = regionsSeen;
}


/**
 *
 * @return the region the robot is on
 */
String LineThreshold::getRegion() {
	//create an array of reflections
	unsigned int reflections[NUM_SENSORS];
	//modify the array with the current sensor values
	getReflections(reflections);
	//modify the array with current regions seen
	getRegionsSeen(regionsSeen, reflections);
	//go through priority array
	for (int i = numRegions - 1; i >= 0; i--) {
		//get the region next in priority
		String region = regionsPriority[i];
		//if that region is found, return it
		boolean found = checkSensorsForRegion(region, regionsSeen);
		if (found) {
			return region;
		}
	}
	//if gotten this far, return an error
	return "ERROR";
}

/**
 * checks the array of sensors for a particular region
 * @param region the name of the region to be checked
 * @param reflections an array of reflections of the sensors
 * @return that region if found, null otherwise
 */
boolean LineThreshold::checkSensorsForRegion(String region,
		String regionsSeen[]) {
	//for a given region check, loop through the sensors
	for (int i = 0; i < NUM_SENSORS; i++) {
		if (region == regionsSeen[i])
			return true;
	}
	//if you've gotten this far, none of the sensors are in the region
	return false;
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



