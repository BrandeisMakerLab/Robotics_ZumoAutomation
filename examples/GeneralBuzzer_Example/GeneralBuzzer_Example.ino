/*Jacob Smith Brandeis University Robotics Club
Shows how the General Buzzer class will either play a buzzer 
on the Zumo Shield robot or display an error if the board is not
correct*/
//include the general buzzer class
#include <GeneralBuzzer.h>
//make a general buzzer object
GeneralBuzzer buzzer;
//store the octave in a variable
int variable=0;
//runs onve
void setup() {
  //for a couple cycles
  while (playType<36){
    //play the note
    buzzer.playNote(playType);
    //wait a quarter second
    delay(250);
    //go to a higher octave (the program loops octaves automatically)
    playType++;  
  }
}

void loop() {}
