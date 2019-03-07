/* Jacob Smith for Brandeis Univeristy Robotics Club
    Performs a seleltcion sort on an arrray of max values, an also sorts the min and names arrays
    This is for calibrating the line sensors
    prabug@brandeis.edu
*/

#define NUM_REGIONS 4
//int numRegions = NUM_REGIONS;
//an array of ring regions
char* regions[] = {"BLACK", "GRAY", "BLUE","WHITE"};
int regionMins[NUM_REGIONS] = {4000,3000,2000,1000};;
int regionMaxes[NUM_REGIONS] = {4500,3500,2500,1500};;


void setup() {
  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  while (!Serial) {}
  Serial.println("Brandeis University Example Array Sorting Program");
  Serial.println("This Program allows for the regions of a sumo battle ring to be sorted");
  delay(2000);
  displayArrays("Before Sorting");

  //goes through whole array, putting the minimum value in the start
  for (int i = 0; i < NUM_REGIONS-1; i++) {
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
  //print the arrays after sorting
  displayArrays("After Sorting");


}

void loop() {

}

//print all the arrays with parameter message
void displayArrays(char* title) {
  Serial.println(title);
  printArr(regionMaxes,"MAXES  :", NUM_REGIONS);
  printArr(regionMins, "MINS   :", NUM_REGIONS);
  printArr(regions,    "REGIONS:", NUM_REGIONS);

}

//swap teo elements in an array of integer
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

//print an array of integers
void printArr(int nums[], char*name, int arrSize) {
  Serial.print(name);
  //if array is empy, do nothing more
  if (arrSize == 0) {
    return;
  }
  //print first element in array, fencepost solution to printing
  Serial.print(nums[0]);
  //go through rest of array, printing tab and element
  for (int i = 1; i < arrSize; i++) {
    Serial.print("\t");
    Serial.print(nums[i]);
  }
  //print newLine
  Serial.println();
}

//print an array of strings
void printArr(char* nums[], char*name, int arrSize) {
  Serial.print(name);
  //if array size is 0, print nothing
  if (arrSize == 0) {
    return;
  }
  //print first element of array, fencepos solution
  Serial.print(nums[0]);
  //go through rest of array, printing elements and spaces
  for (int i = 1; i < arrSize; i++) {
    Serial.print("\t");
    Serial.print(nums[i]);
  }
  //print newLine
  Serial.println();
}

