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
  for (int i = 0; i < NUM_REGIONS-1; i++) {
    int min = regionMaxes[i];
    int minIndex = i;

    for (int j = i + 1; j < NUM_REGIONS; j++) {
      int num = regionMaxes[j];
     
      if (num < min) {
        min = num;
        minIndex = j;
      }

    }
   
    swap(minIndex, i, regionMaxes);
    swap(minIndex, i, regionMins);
    swap(minIndex, i, regions);
   

  }
  displayArrays("After Sorting");


}

void loop() {

}

void displayArrays(char* title) {
  Serial.println(title);
  printArr(regionMaxes,"MAXES  :", NUM_REGIONS);
  printArr(regionMins, "MINS   :", NUM_REGIONS);
  printArr(regions,    "REGIONS:", NUM_REGIONS);

}


void swap(int minIndex, int nonMinIndex, int nums[]) {
  //swap the two elements in the maxes array
  int temp = nums[minIndex];
  nums[minIndex] = nums[nonMinIndex];
  nums[nonMinIndex] = temp;
}

void swap(int minIndex, int nonMinIndex, char* regions[]) {
  //swap the two elements in the maxes array
  char* temp = regions[minIndex];
  regions[minIndex] = regions[nonMinIndex];
  regions[nonMinIndex] = temp;
}


void printArr(int nums[], char*name, int arrSize) {
  Serial.print(name);
  if (arrSize == 0) {
    return;
  }
  Serial.print(nums[0]);
  for (int i = 1; i < arrSize; i++) {
    Serial.print("\t");
    Serial.print(nums[i]);
  }
  Serial.println();
}

void printArr(char* nums[], char*name, int arrSize) {
  Serial.print(name);
  Serial.print(": ");
  if (arrSize == 0) {
    return;
  }
  Serial.print(nums[0]);
  for (int i = 1; i < arrSize; i++) {
    Serial.print("\t");
    Serial.print(nums[i]);
  }
  Serial.println();
}

