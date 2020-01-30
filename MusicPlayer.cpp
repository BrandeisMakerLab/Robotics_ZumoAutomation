/*Written by Jacob Smith  for Brandeis Robotics club
 Allows ZumoShield and Zumo 32U4 robots to play music with their buzzers
 Uses ZumoBuzzer xample as a template fo array of notes
 March 3 20219 2018
 https://stackoverflow.com/questions/38837859/cannot-convert-brace-enclosed-initializer-list-to-double-in-return?rq=1
 */
//only compile this class if the board is correct
#if defined (ARDUINO_AVR_UNO)
 
//includes the libraries of code necessary to make this one work
#include "MusicPlayer.h"

//create new music player object with default values
MusicPlayer::MusicPlayer(int mode) {
	this->wait = 1000;
	this->mode = mode;

}
//play the song
void MusicPlayer::play() {
	//iterate through list of notes to play song
	for (int note = 0; note < songLength; note++) {
		play(song[note]+mode);
	}
}
//play an individual note
void MusicPlayer::play(unsigned char note){
		//interact with object to actually play note
		//volume is last number
		buzzer.playNote(note, wait, 15);
		//wait for specified time
		delay(wait*1.25);
}
#endif