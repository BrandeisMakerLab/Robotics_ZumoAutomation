/*Brandeis botics club modoifed file from
  https://github.com/indrekots/esp8266-rc-car-controller
  and https://github.com/pololu/drv8835-motor-shield/blob/master/DRV8835MotorShield.cpp
  to allow simple motor driving with esp8266 and drv8835.
  This file also includes a scan function to see which  pins are used in motor ports*/

//the pins that each motor and directino is on
#define LEFTINVERSE  0
#define RIGHTINVERSE  13
#define LEFTPOWER  2
#define RIGHTPOWER  15

//constants for code readibility
#define TOTALPINS 30
#define WAITTIME 2000 //in milliseconds

void setup() {
  //connect to computer and display welcome message
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println("Brandeis University Example Driving Program with Zumo Shield and ESP8266");
  initOutputs();
  
  //test some of the pins on the robot
 // scan(11,15);

}

void loop() {
  //set the robot to perform basic driving functions
  driveForward();
  driveBackward();
  turnLeft();
  turnRight();
  stopDrive();
 
}


//set pin settings
void initOutputs() {
  //set all the ports to off and set thir pinmodes
  digitalWrite(LEFTPOWER, LOW);
  pinMode(LEFTPOWER, OUTPUT);
  digitalWrite(LEFTPOWER, LOW);
  digitalWrite(RIGHTPOWER, LOW);
  pinMode(RIGHTPOWER, OUTPUT);
  digitalWrite(RIGHTPOWER, LOW);
  digitalWrite(LEFTINVERSE, LOW);
  pinMode(LEFTINVERSE, OUTPUT);
  digitalWrite(LEFTINVERSE, LOW);
  digitalWrite(RIGHTINVERSE, LOW);
  pinMode(RIGHTINVERSE, OUTPUT);
  digitalWrite(RIGHTINVERSE, LOW);
  pinMode(LEFTINVERSE, OUTPUT);
  pinMode(RIGHTINVERSE, OUTPUT);
  pinMode(LEFTPOWER, OUTPUT);
  pinMode(RIGHTPOWER, OUTPUT);

}

//turns every pin on or off to deduce wiring
//this doens't use delays to ensure maximum control of pins
//if done too much, get some kind of error
void scan(int startPin, int stopPin) {
  Serial.print("Scanning pins "); Serial.print(startPin);Serial.print(" to ");Serial.println(stopPin);
  if (stopPin<startPin){
   Serial.println("Start can't be greater than stop");
  }

  turnOffAllPins();
  //Successively turn pins on
  int elapsedTime = 0;
  int initTime;
  for (int i = startPin; i <= stopPin; i++) {
    Serial.println(i);
    //turn pin on for 2 seconds
    digitalWrite(i, HIGH);
    delay(WAITTIME);
    //turn that pin back off to avoid crossing
    digitalWrite(i, LOW);
  }
  turnOffAllPins();
  Serial.println("Done Scanning");
}

//Turn of all Pins on board
void turnOffAllPins(){
  for (int i= 0; i < TOTALPINS; i++) {
    digitalWrite(i, LOW);
  }
  delay(WAITTIME);
}

//sets pins to drive forward at full power
void driveForward() {
  Serial.println("Drive Forward");
  digitalWrite(LEFTINVERSE, LOW);
  digitalWrite(RIGHTINVERSE, LOW);
  digitalWrite(LEFTPOWER, HIGH);
  digitalWrite(RIGHTPOWER, HIGH);
  delay(1000);
}

//sets pins to drive backward at full power
void driveBackward() {
  Serial.println("Drive Backward");
  digitalWrite(LEFTINVERSE, HIGH);
  digitalWrite(RIGHTINVERSE, HIGH);
  digitalWrite(LEFTPOWER, HIGH);
  digitalWrite(RIGHTPOWER, HIGH);
  delay(1000);
}

//sets pins to turn right at full power
void turnRight() {
  Serial.println("Turn Right");
  digitalWrite(LEFTINVERSE, LOW);
  digitalWrite(RIGHTINVERSE, HIGH);
  digitalWrite(LEFTPOWER, HIGH);
  digitalWrite(RIGHTPOWER, HIGH);
  delay(1000);
}

//sets pins to turn left at full power
void turnLeft() {
  Serial.println("Stop Drive");
  digitalWrite(LEFTINVERSE, HIGH);
  digitalWrite(RIGHTINVERSE, LOW);
  digitalWrite(LEFTPOWER, HIGH);
  digitalWrite(RIGHTPOWER, HIGH);
  delay(1000);
}

//sets pins to drive forward at full power
void stopDrive() {
  Serial.println("Drive Forward");
  digitalWrite(LEFTINVERSE, LOW);
  digitalWrite(RIGHTINVERSE, LOW);
  digitalWrite(LEFTPOWER, LOW);
  digitalWrite(RIGHTPOWER, LOW);
  delay(1000);
}
