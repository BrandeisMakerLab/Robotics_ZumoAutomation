/*Jacob Smith 2018.5.7 Brandeis Robotics Club.
  Uses the Line class to print line sensor values
  to the Zumo32U4 robot's liqqiod crystal display*/

#include <Line.h>
#include <Zumo32U4LCD.h>
Line lineReader;
Zumo32U4LCD lcd;
void setup() {
  lcd.print("LINE");
  lcd.gotoXY(0, 1);
  lcd.print("PRINTER");
  delay(2000);
}

void loop() {
  lineReader.printAllSensors(lcd);

}
