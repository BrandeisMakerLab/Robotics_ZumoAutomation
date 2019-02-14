/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(A0, 6); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("Transmitter MOdule");
  delay(500);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  const char text[] = "Ok Get This!";
  radio.write(&text, sizeof(text));
  delay(1000);
}
