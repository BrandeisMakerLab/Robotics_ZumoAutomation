/*Written by Jacob Smith and Matthew Millendorf for Brandeis Robotics club
 Provides wrapper functions for the Zumo32U4LineShieldShieldSensors class
 April 4 2018
 */
/**
 *  set up the LineShieldShield header file
 */
#ifndef LineGlobal_h
#define LineGlobal_h

/**
 * define the number of sensors that will be used
 */
#define NUM_SENSORS 6

#include<Arduino.h>
#include<LineThreshold.h>
#ifdef ARDUINO_AVR_UNO
#include <ZumoBuzzer.h>
class LineGlobal {

private:

	/**
	 * a LineTheshold object to tell the robot where it is
	 */
	LineThreshold thresh;

	/**
	 * an array of string representing the regions individual line sensors have seen
	 */
	String* regionsSeen;
	/**
	 * prints the regions and thresholds arrays for display
	 */
	void printArrs(String* regions, int* thresholds, int numRegions);

	/**
	 * the number of regions the field has
	 */
	int numRegions;

	/**
	 * a list of the regions the robot goes through
	 */
	String* regionsPriority;

public:

	/**
	 * creates a new lineGlobal object, but setElements function must be called for the class to work porperly
	 */
	LineGlobal();
	/**
	 * sets the object given an array of regions, the number of regions, and whether a serial connection shouold be established
	 */
	void setElements(String* regions, int numRegions, String regionsSeen[],
			bool USB);

	/**
	 *
	 * @return the region the robot is on
	 */
	String getRegion();

	/**
	 * displays the region the robot is on and individual sensor values
	 */
	void displayLineReadings();

	/**
	 * displays the region the robot is on and individual sensor values
	 */
	void displayLineReadings(String region);

};
#else
	#warning This class does not work for your board
#endif
#endif
