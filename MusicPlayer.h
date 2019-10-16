/*Written by Jacob Smith  for Brandeis Robotics club
	Allows ZumoShield and Zumo 32U4 robots to play music with their buzzers
	March 3 20219 2018
*/
//sets up the Drive Header file
#ifndef MusicPlayer_h
#define MusicPlayer_h

//only compile this class if the board is correct
#if defined(ARDUINO_AVR_UNO)

//includes the libraries of code necessary to make this one work
#include <Arduino.h>
#include<Wire.h>
#include <PololuBuzzer.h>
class MusicPlayer{
	//hidded from client
	private:
		//the octave of song
		int octave=5;
		//the song to play
		unsigned char song[16]={
				 NOTE_E(octave), NOTE_E(octave), NOTE_E(octave), NOTE_E(octave),
				 NOTE_A(octave), NOTE_A(octave), NOTE_E(octave), NOTE_E(octave),
				 NOTE_B(octave), NOTE_A(octave), NOTE_E(octave), NOTE_E(octave),
				 NOTE_B(octave), NOTE_A(octave), NOTE_E(octave), NOTE_E(octave),

			 };
		//logic to store how long song is
		int songLength=sizeof(song)/sizeof(song[0]);
		//how long to play a note
		int wait;
		//the mode for the buzzer
		int mode;
		//the buzzer object to interface with
		PololuBuzzer buzzer;
	//can be used by client
	public:
		//creates a new music player
		MusicPlayer(int mode);
		//play a song
		void play();
		//play a specific note
		void play(unsigned char note);
};
//logic to handle if using baord that can't support music player 
#elif defined (DONT_NEED_MUSIC)
	#warning : May lead to "error: 'MusicPlayer' does not name a type" ; Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html
	
#else
	#error : Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; Quick fix: add <#define DONT_NEED_MUSIC> to top ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html
#endif
#endif
