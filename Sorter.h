/*Written by Jacob Smith Brandeis Robotics Club
 * Allows arrays to be sorted for line calibration
	Jan 19 2019
  https://stackoverflow.com/questions/15013077/arrayn-vs-array10-initializing-array-with-variable-vs-real-number
  https://www.tutorialspoint.com/cplusplus/cpp_pointer_to_an_array.htm
  https://computer.howstuffworks.com/c34.htm
*/
//set up the SorterShield header file
#ifndef Sorter_h
#define Sorter_h
//include the Arduino library so Strings can be used
#include<Arduino.h>

class Sorter  {

  private:
    //the size of the three parallel arrays
    int arrSize;
    
    //an array of the regions that the sensor will use
    String* regions;

    //an array of the minimum sensor readig for each region
    int* regionMins ;
    //an array of the maximum brightness reading for each region
    int* regionMaxes ;

    //swaps two elements in an array of intgers, for the slection sort
    void swap(int minIndex, int nonMinIndex, int* nums);
    //swaps two elements in an array of strings, fo the slection sort
    void swap(int minIndex, int nonMinIndex,  String* regions);

  public:

    //creates a new sorter object with the trhee parallel arrays and their size
    Sorter(int* regionMaxes,int* regionMins,  String* regions,int arrSize);

    //sorts the arrays of brightness so regions can be in any order on sumo board
    //without this function,the sumo ing couldn't be in order black white gray, for example
    void selectionSort();

};
#endif

