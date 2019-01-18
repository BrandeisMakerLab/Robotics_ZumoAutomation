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
int numRegions=NUM_REGIONS;
//an array of ring regions
char* regions[] = {"Black", "Gray", "White"};
double regionAverages[NUM_REGIONS];

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
}

//main part of program, for evey region, prints messages and takes line sensor readings
void loop() {
  //loop through regions
  for (int i = 0; i < NUM_REGIONS; i++) {
    //take the region and display name of that region
    double average=takeReadingRegion(regions[i]);
    regionAverages[i]=average;
  }
  //after senso data has been taken, calculate the boundaries between regions
  Serial.println("Final Results");
  for(int i=0;i<NUM_REGIONS-1;i++){
      //average adjacent regions
      double average=(regionAverages[i]+regionAverages[i+1])/2;
      //display results to screen
      Serial.print("Boundary between "); Serial.print(regions[i]);Serial.print(" and ");
      Serial.print(regions[i+1]);Serial.print(" is ");Serial.println(average);
  }

  
  //when at end wait to end program
  Serial.println("Finished");
  delay(500000);
}

//given a string representing the region being covered,
//promprts the person to place robot over region and takes line sensor reading
//returns the average for that reading
double takeReadingRegion(char* region) {
  Serial.print("Please Move Robot to "); Serial.println(region);
  delay(5000);
  double sum = 0;
  //loop for number of readings
  for (int reading = 1; reading <= NUM_READINGS; reading++) {
    //display readings number and wait for robot ot be place
    Serial.print("Reading: "); Serial.print(reading); Serial.print('\t');
    delay(3000);
    speaker.playNote(NOTE_D(6), 500, 15);
    //take line sensor reading and display
    lineReader.printAllSensors();
    //add the average reaing to the sum
    sum += lineReader.getAverageReading();
  }
  double average = sum / NUM_READINGS;
  Serial.print("\t average for this region:"); Serial.println(average);
  return average;
}
