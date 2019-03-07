/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
 Provides wrapper functions for the Zumo32U4LineShieldShieldSensors class
 April 4 2018
 */
/**
 *  set up the LineShieldShield header file
 */
#ifndef LineThreshold_h
#define LineThreshold_h

/**
 * define the number of sensors that will be used
 */
#define NUM_SENSORS 4

#include<Arduino.h>
#include<LineShield.h>
#include<LineThreshold.h>

class LineThreshold: public LineShield {

private:
	/**
	 * an array of the names of the regions in order of threshold
	 */
	String* regions;
	/**
	 * an array of the thresholds between the regions
	 */
	int* thresholds;

	/**
	 * the number of regions in the filed
	 */
	int numRegions;

	/**
	 * an array of the regions that each line sensor sees
	 */
	String* regionsSeen;

	/**
	 *gets the region that one sensor sees
	 */
	String getIndividualRegion(int reflection);

	/**
	 * converts the numbers the robot sees into the names of regions
	 */
	void getRegionsSeen(String decodedRegions[], unsigned int* reflections);

public:
	/*
	 * default constructor, need to give the object necessary elements
	 */
	LineThreshold();

	/**
	 * creates a new LineShieldShield object with defual sensor reading
	 */
	void setElements(int* regionThresholds, String* regions, int numRegions, String* regionsSeen);

	/**
	 * updates the regionsSeen array with what region each indivual line sensor has seen
	 */
	void convertToRegion();

};

#endif
