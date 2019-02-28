/* Written by Jacob Smith for Brandeis Robotics club.
    Provides sample usage of the Timer class, which allows
    a task to be repeated on an interval without delay statements, see the
    loop. In the setup, the more basic functions of the Timer class are
    demonstrated.
    April 12 2018
*/

//include the classes necessary to make this one work
#include <Timer.h>


//declare robot display timer, and secondCount variable

Timer timer;
int secCount;

//setup is executed before main loop
void setup() {
  Serial.begin(9600);
  while(!Serial){}
  printNumber("getTime:", timer.getTime());//should be 0
  waitAndClear();

  printNumber("Rsetime:", timer.resetTime());//should be 0
  waitAndClear();

  printNumber("getReset", timer.getAndResetTime());//should be 2000
  waitAndClear();

  printNumber("getTime:", timer.getTime());//should be 2000
  waitAndClear();
}

//main loop of execution
//prints the time every second without usage of delay statements
void loop() {
  if (timer.interval(1000)) {
 
    printNumber("Secs ", secCount);
    secCount++;
  }
}

//wait for 2 seconds and clears the robot's display
void waitAndClear() {
  delay(2000);

}

//print a message and a number to the robot's display
void printNumber (const char *message, long number) {
  Serial.print(message);
  Serial.println(number);
}
