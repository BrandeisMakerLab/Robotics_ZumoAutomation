/*Written by Jacob Smith  for Brandeis Robotics club
	Interface class to play a buzzer at a certain note
	May 5 2019
*/
//this class will work for any buzzer
//includes the libraries of code necessary to make this one work
#include <GeneralBuzzer.h>
#include <Arduino.h>

//creates a new Buzzer object, which won't have random motor power
GeneralBuzzer::GeneralBuzzer(){

}
//allows the buzzer to be played if the board has one
void GeneralBuzzer:: playNote(int playType){
  #ifdef ARDUINO_AVR_UNO
    if(playType %6==1){
       //a buzzer to display when robot turns back
       buzzer.playNote(NOTE_A(1),250, 15);
     }else if (playType %6==2 ){
        buzzer.playNote(NOTE_A(2),250, 15);
     }else if (playType %6 ==3 ){
        buzzer.playNote(NOTE_A(3),250,  15);
     }else if (playType %6 ==4 ){
        buzzer.playNote(NOTE_A(4),250,  15);
     }else if (playType %6 ==5 ){
        buzzer.playNote(NOTE_A(5),250,  15);
     } 
#else
  #warning : Buzzer will not play ; Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html
  Serial.print("Not Playing note: ");
  Serial.print(playType);
  Serial.println("But this board doesn't have a buzzer");
#endif
}

