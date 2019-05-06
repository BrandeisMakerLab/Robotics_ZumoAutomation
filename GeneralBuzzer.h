/*Written by Jacob Smith  for Brandeis Robotics club
	Interface class to play a buzzer at a certain note
	May 5 2019
*/
//sets up the Drive Header file
#ifndef GeneralBuzzer_h
#define GeneralBuzzer_h

//this class will compile for any board, so no using a preprocessor directive here

//only use this buzzer if uno board is in use
#ifdef ARDUINO_AVR_UNO
//includes the libraries of code necessary to make this one work
#include <ZumoBuzzer.h>
#endif

class GeneralBuzzer{
	private:
	//only use this buzzer if uno board is in use
	#ifdef ARDUINO_AVR_UNO
		ZumoBuzzer buzzer;
	#endif	
	
	public:
		//constructor for Drive class, creates a new Drive object
		GeneralBuzzer();
		//plays a note with a buzzer if the board supports, prints error message if board not found
		void playNote(int playOctave);
		
};
#endif