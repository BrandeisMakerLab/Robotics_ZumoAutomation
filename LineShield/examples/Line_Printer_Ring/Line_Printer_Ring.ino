/*Jacob Smith 2019.1.17 Brandeis Robotics Club.
  Uses the LineShield class to print line data of the regions of the sumo ring to the monitor
  for declaring string https://www.arduino.cc/reference/en/language/variables/data-types/string/
*/
//libraries needed for the example file
#include <LineShield.h>

//a speaker object to play notes and prompt the user
ZumoBuzzer speaker;

//the number of times the robot will take a measrument per region
int  NUM_READINGS = 3;
//the number of regions to be seached
#define NUM_REGIONS 3
int numRegions = NUM_REGIONS;
//an array of ring regions
char* regions[] = {"BLACK", "WHITE", "GRAY"};
int regionMins[NUM_REGIONS];
int regionMaxes[NUM_REGIONS];
//the minimum and maximum readings, useful for calibration
int min = 5000;
int max = -5000;

//the object that can print sensor data
LineShield lineReader;

///occurs bfore the main program is run, connects to robot displays message
void setup() {
  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  while (!Serial) {}
  Serial.println("Brandeis University Example Line Sensor Printing Program");
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
      //display results to screen
      Serial.println(average);
    }

  }


  //print program is finished
  Serial.println("Finished");
}

void loop(){}

//given a string representing the region being covered,
//promprts the person to place robot over region and takes line sensor reading
//returns the average for that reading
int takeReadingRegion(char* region) {
  Serial.print("Please Move Robot to "); Serial.println(region);
  delay(5000);

  //loop for number of readings
  for (int reading = 1; reading <= NUM_READINGS; reading++) {
    //display readings number and wait for robot to be placed
    Serial.print("Reading: "); Serial.print(reading); Serial.print('\t');
    delay(3000);
    speaker.playNote(NOTE_D(6), 500, 15);
    //take line sensor reading and display
    lineReader.printAllSensors();
    //update the running minimum and maximum readings
    updateMinMax(reading);
  }
  Serial.print("\tMin "); Serial.print(min); Serial.print(" Max "); Serial.println(max);
}


//uses the LineReader object to find the mimum and maximum reflection readings
//and updates the current min max with them
void updateMinMax(int reading) {
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
void selectionSort() {
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
void swap(int minIndex, int nonMinIndex, int nums[]) {
  //swap the two elements in the maxes array
  int temp = nums[minIndex];
  nums[minIndex] = nums[nonMinIndex];
  nums[nonMinIndex] = temp;
}

//swap two elements in an array of strings
void swap(int minIndex, int nonMinIndex, char* regions[]) {
  //swap the two elements in the maxes array
  char* temp = regions[minIndex];
  regions[minIndex] = regions[nonMinIndex];
  regions[nonMinIndex] = temp;
}

//display the regions, mins, and maxes arrays
void displayArrays() {
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
