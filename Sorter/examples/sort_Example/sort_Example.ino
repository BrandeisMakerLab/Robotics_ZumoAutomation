/*Jacob Smith 1/19/2019 Brandeis University Robotics Club
  Sorts three arrays to represent a line sensor calibration example*/
#include<Sorter.h>


void setup() {
  //starts serial connection at 9600 bits per second
  Serial.begin(9600);
  //guarantees robot will not continue until serial connection is established
  while (!Serial) {}
  //populate mins, maximum, and regions arrays
  int numRegions=3;
  int mins[] = {300, 100, 200};
  int maxes[] = {350, 150, 250};
  String regions [numRegions]= {"BLACK", "WHITE", "GRAY"};
 
  //display the arrays before the sort
  Serial.println("Before Sort");
  dispArrays(maxes, mins, regions,numRegions);
  //use the arrays and size to create a new Sorter Object
  Sorter lineSorter(maxes, mins, regions,numRegions);
  
  //perform the selection sort
  lineSorter.selectionSort();

  //display the values of the arrays after the sort
  Serial.println("After Sort");
  dispArrays(maxes, mins, regions,numRegions);
}

void loop() {

}


//displays all three arrays to the screen
void dispArrays(int maxes[], int mins[],  String regions [], int sizeArr) {
  //if array size is 0, do nothing
  if (sizeArr == 0) {
    return;
  }
  //otherwise, print headers and first element
  Serial.println("REGIONS\tMAXES\tMINS");
  Serial.print(regions[0]); Serial.print("\t");
  Serial.print(maxes[0]); Serial.print("\t");
  Serial.print(mins[0]); Serial.print("\t");
  //loop through rest of arrays, printing elements
  for (int i = 1; i < sizeArr; i++) {
    Serial.println("");
    Serial.print(regions[i]); Serial.print("\t");
    Serial.print(maxes[i]); Serial.print("\t");
    Serial.print(mins[i]); Serial.print("\t");
  }
  Serial.println();

}
