/* Jacob Smith 10/16/2019 Brandeis Robotics Club
 * Shows Usage of MusicPLayer class to play a song
 * and individual notes on a popolulu buzzer
 */
//include library needed for this example
#include <MusicPlayer.h>
//create music player object to interact with, number is mode
MusicPlayer player(7);
//runs once
void setup() {
  //plays the preloaded song
  player.play();
  //plays indiviudal notes, this can be modified
  //the number is the octave
  player.play(NOTE_C(5));
  player.play(NOTE_D(5));
  player.play(NOTE_E(5));
  player.play(NOTE_F(5));
  player.play(NOTE_G(5));
  player.play(NOTE_A(5));
  player.play(NOTE_B(5));
  player.play(NOTE_C(6));

}
//not used for this example
void loop() {}
