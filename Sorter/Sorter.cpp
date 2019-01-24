/*Written by Jacob Smith
 * Allows arrays to be sorted for line calibration
  Jan 19 2019*/
//include the libraries necessary to make this one work
#include "Sorter.h"

//creates a new Sorter object
Sorter::Sorter(int* regionMaxes ,int* regionMins, String* regions,int arrSize ) {
  this->regionMaxes=regionMaxes;
  this->regionMins=regionMins;
  this->regions=regions;
  this->arrSize=arrSize;
}

//sorts the maxes array, and then the min and regions arrrays to match
void Sorter::selectionSort() {
  //goes through whole array, putting the minimum value in the start
  for (int i = 0; i < arrSize - 1; i++) {
    //start the minumum as the first element
    int min = *(regionMaxes+i);
    int minIndex = i;
    //search rest of array for a smaller number
    for (int j = i + 1; j < arrSize; j++) {
      int num = *(regionMaxes+j);
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
void Sorter::swap(int minIndex, int nonMinIndex, int* nums) {
  //swap the two elements in the maxes array
  int temp = *(nums+minIndex);
  *(nums+minIndex)= *(nums+nonMinIndex);
  *(nums+nonMinIndex) = temp;
}

//swap two elements in an array of strings
void Sorter::swap(int minIndex, int nonMinIndex, String* regions) {
  //swap the two elements in the maxes array
  String temp = *(regions+minIndex);
  *(regions+minIndex) = *(regions+nonMinIndex);
  *(regions+nonMinIndex) = temp;
}
