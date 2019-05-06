#include <GeneralBuzzer>
GeneralBuzzer buzzer;
int playType=0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  buzzer.playNote(plaType);
  delay(250);
  playType++;
}
