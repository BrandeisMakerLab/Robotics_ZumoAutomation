/*Written by Jacob Smith\for Brandeis Robotics club
 Allows the robot's line sensors to be calibrated
 January 20 2019*/
//include the libraries necessary to make this one work
#include <Arduino.h>
#include<LineShield.h>
#include<LineCalibrator.h>
#include<LineThreshold.h>
#ifdef ARDUINO_AVR_UNO
	#include <ZumoBuzzer.h>	

#include <LineGlobal.h>


/**
 * default constructor for LineGlobal class
 */
LineGlobal::LineGlobal(){

}

/**
 * Sets the elements that the LineGlobal class needs
 * @param regions an array of the regions the field has
 * @param numRegions the number of regions the robot has
 * @param regionsSeen anarray of the regions the robot has seen
 * @param USB whether a serial connection should be opened with the USB
 */
void LineGlobal::setElements(String* regions, int numRegions,String regionsSeen[], bool USB) {

	//save the regions in a new array
	String* regionsPriority = new String[numRegions];
	for(int i=0;i<numRegions;i++){
		regionsPriority[i]=regions[i];
	}
	//establishes serial connection if needed
	if (USB) {
		//starts serial connection at 9600 bits per second
		Serial.begin(9600);
		//guarantees robot will not continue until serial connection is established
		while (!Serial) {
		}
	}
	//create a calibrator object
	LineCalibrator cali(regions, numRegions);

	// calibrates the line sensors
	cali.calibrateLineSensors();

	//get the regions and thresholds calculated
	int* thresholds=cali.getThresholds();

	//print the arrays
	Serial.println("Final Calibration Results");
	printArrs(regions, thresholds,numRegions);
	this->regionsSeen=regionsSeen;
	this->numRegions=numRegions;
	//use information from calibration to set state of threshold object
	thresh.setElements(thresholds, regions, numRegions, regionsSeen);
}

/**
 *
 * @return the region the robot is over
 */
String LineGlobal:: getRegion(){
	//get the regions that each line sensor sees
	thresh.convertToRegion();
	//generate a frequency array of those regions
	/*
	int frequencies [numRegions];
	for(int i=0;i<numRegions;i++){
		frequencies[i]=0;
	}

	//loop through all the sensors
	for(int i=0;i<NUM_SENSORS;i++){
		String region=regionsSeen[i];
		//loop through all the region names
		for(int j=0;j<numRegions;j++){
			//add that region to the frequency array
			if(region==regionsPriority[j]){
				frequencies[j]=frequencies[j]+1;
			}
		}
	}

	//loop through fruequency array
	for(int i=numRegions-1;i>=0;i--){
		//if more than one sensor saw it, return that region
		if(frequencies[i]>=2){
			return regionsPriority[i];
		}
	}
	//otherwise, return the lowest priority region
	return regionsPriority[0];
	*/
	//return region of first sensor
	return regionsSeen[0];
}


/**
 *  Prints the regions and threshold levels to the Serial Monitor
 * @param regions a pointer to an array of region names
 * @param thresholds the brightness levels that are the cutoffs between regions
 */
void LineGlobal::printArrs(String* regions, int* thresholds,int numRegions) {
  //iterate along the regions array
  for (int i = 0; i < numRegions - 1; i++) {
    //print the region and its cutoff
    Serial.print(*(regions + i));
    Serial.print("\t");
    Serial.println(*(thresholds + i));

  }
  //print the last region, which wont have a cutoff
  Serial.println(*(regions + numRegions - 1));

}

/**
 * Displays what each individual sensor sees and the overall region
 * @param region the region the robot is on
 */
void LineGlobal::displayLineReadings(String region) {
	Serial.print("Individual Sensors:\t");
	//print what region each individual sensor sees
	for (int i = 0; i < NUM_SENSORS; i++) {
		Serial.print(regionsSeen[i]);
		Serial.print("\t");
	}
	//print the overall region
	Serial.print("Final Region:\t");
	Serial.println(region);
}

/**
 * Overloaded display method to display default region estimate
 */
void LineGlobal::displayLineReadings() {
	String region=getRegion();
	displayLineReadings(region);
}
#else
	#warning This class doesn't work for your board
#endif
