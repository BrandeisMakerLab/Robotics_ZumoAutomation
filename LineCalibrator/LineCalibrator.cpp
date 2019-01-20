/*Written by Jacob Smith,Daniel Kang and Matthew Millendorf for Brandeis Robotics club
  Provides readable wrapper functions for Zumo32U4LCD.h. The program is documented for
  understanding by a general audience
  April 4 2018*/
//include the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include<LineShield.h>
#include "LineCalibrator.h"


LineCalibrator::LineCalibrator(LineShield lineReader) {
  this->lineReader=lineReader;
}


LineCalibrator::calibrateLineSensors() {
  lineReader.printAllSensors();
}
/*
  Serial.println("Brandeis University Line Sensor Calibration");
  Serial.println("This Program allows for the regions of a sumo battle ring to be measured");
  delay(2000);
  //loop through regions
  for (int i = 0; i < NUM_REGIONS; i++) {
    //take the region and display name of that region
    double average = takeReadingRegion(regions[i]);
    regionMins[i] = min;
    regionMaxes[i] = max;
  }

  //sort the arrays
  Serial.println("Before Sorting Regions");
  displayArrays();
  selectionSort();
  Serial.println("After Sorting Regions");
  displayArrays();

  //after sensor data has been taken, calculate the boundaries between regions
  Serial.println("Final Results");
  for (int i = 0; i < NUM_REGIONS - 1; i++) {
    //take the maximum sensor value o the previous and the minimum of this one
    int maxPrev = regionMaxes[i];
    int minNext = regionMins[i + 1];
    //print header
    Serial.print("Boundary between "); Serial.print(regions[i]); Serial.print(" and ");
    Serial.print(regions[i + 1]); Serial.print(" is ");
    //if they ovelap, print an error
    if (maxPrev >= minNext) {
      Serial.println("Error, thresholds aren't discrete");
      //otherwise tkae the average between them to be the threhold
    } else {
      //take the average between the max of the previous region and the min of the next
      int average = (regionMaxes[i] + regionMins[i + 1]) / 2;
      regionThresholds[i]=average;
      //display results to screen
      Serial.println(average);
    }

  }

  //print region Thresholds
  Serial.print("FINAL THRESHOLDS: ");
  for(int i=0;i<NUM_REGIONS-1;i++){
    Serial.print(regionThresholds[i]);
    Serial.print(" ");
  }
  Serial.println();

  
  //print program is finished
  Serial.println("Finished");
}
*/

//given a string representing the region being covered,
//promprts the person to place robot over region and takes line sensor reading
//returns the average for that reading
int LineCalibrator:: takeReadingRegion(char* region) {
  Serial.print("Please Move Robot to "); Serial.println(region);
  delay(5000);

  //loop for number of readings
  for (int reading = 1; reading <= NUM_READINGS; reading++) {
    //display readings number and wait for robot to be placed
    Serial.print("Reading: "); Serial.print(reading); Serial.print('\t');
    delay(3000);
    
    //take line sensor reading and display
    lineReader.printAllSensors();
    //update the running minimum and maximum readings
    updateMinMax(reading);
  }
  Serial.print("\tMin "); Serial.print(min); Serial.print(" Max "); Serial.println(max);
}


//uses the LineReader object to find the mimum and maximum reflection readings
//and updates the current min max with them
void LineCalibrator::updateMinMax(int reading) {
  //if this is the first reading, then set min and max to be that
  if (reading == 1) {
    min = lineReader.getMin();
    max = lineReader.getMax();
    return;

  }
  //otherwise, get the minimum and maximum from this reading
  int curMin = lineReader.getMin();
  int curMax = lineReader.getMax();
  //update the global minum and maximum
  if (curMin < min) {
    min = curMin;
  }
  if (curMax > max) {
    max = curMax;
  }

}
//sorts the maxes array, and then the min and regions arrrays to match
void LineCalibrator::selectionSort() {
  //goes through whole array, putting the minimum value in the start
  for (int i = 0; i < NUM_REGIONS - 1; i++) {
    //start the minumum as the first element
    int min = regionMaxes[i];
    int minIndex = i;
    //search rest of array for a smaller number
    for (int j = i + 1; j < NUM_REGIONS; j++) {
      int num = regionMaxes[j];
      //if number is less than unning min, it is new running min
      if (num < min) {
        min = num;
        minIndex = j;
      }

    }
    //swap the first element with the minimum
    swap(minIndex, i, regionMaxes);
    //swap for the min array
    swap(minIndex, i, regionMins);
    //sap for the regions array
    swap(minIndex, i, regions);


  }
}

//swap two elements in an array of integer
void LineCalibrator::swap(int minIndex, int nonMinIndex, int nums[]) {
  //swap the two elements in the maxes array
  int temp = nums[minIndex];
  nums[minIndex] = nums[nonMinIndex];
  nums[nonMinIndex] = temp;
}

//swap two elements in an array of strings
void LineCalibrator::swap(int minIndex, int nonMinIndex, char* regions[]) {
  //swap the two elements in the maxes array
  char* temp = regions[minIndex];
  regions[minIndex] = regions[nonMinIndex];
  regions[nonMinIndex] = temp;
}

//display the regions, mins, and maxes arrays
void LineCalibrator::displayArrays() {
  Serial.print("REGIONS: ");
  for (int i = 0; i < NUM_REGIONS; i++) {
    Serial.print(regions[i]);
    Serial.print("\t");
  }
  Serial.println();
  Serial.print("MINS: ");
  for (int i = 0; i < NUM_REGIONS; i++) {
    Serial.print(regionMins[i]);
    Serial.print("\t");
  }
  Serial.println();
  Serial.print("MAXS: ");
  for (int i = 0; i < NUM_REGIONS; i++) {
    Serial.print(regionMaxes[i]);
    Serial.print("\t");
  }
  Serial.println("");
}
