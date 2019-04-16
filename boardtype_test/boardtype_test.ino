void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
  #if defined(__AVR_ATmega328P__)
    Serial.println("im a mega 328p");
  #elif defined(__AVR_ATmega168__)
    Serial.println("im a mega 168");
  #elif defined(__AVR_ATmega1280__)
    Serial.println("im a mega 1280");
  #elif defined(__AVR_ATmega2560__)
    Serial.println("im a mega 2560");
  #elif defined(__AVR_ATtiny85__)
    Serial.println("im a ATtiny85");
  #elif defined(__ESP8266_WEMOS_D1R1__)
    Serial.println("im a Wemos D1 R1");
  #elif defined(__ARDUINO_ESP8266_WEMOS_D1R1__)
    Serial.println("im a Wemos D1 R1");
  #elif defined(__ARDUINO_WEMOS_D1R1__)
    Serial.println("im a Wemos D1 R1");
  #elif defined(__ESP8266_WEMOS_D1MINI__)
    Serial.println("im a Wemos D1 mini");
  #elif defined(__ESP8266_NODEMCU__)
    Serial.println("im a esp8266 nodemcu");
  #elif defined(__ARDUINO_ESP8266_NODEMCU__)
    Serial.println("im a esp8266 nodemcu");
  #else
    Serial.println("other board");
  #endif

#ifdef Arduino_ESP8266_WEMOS_D1MINI
  Serial.println("wemos mini");
#elif ARDUINO_ESP8266_ESP01
  Serial.println("esp01");
#elif ARDUINO_ESP8266_NODEMCU
  Serial.println("nodemcu");
#elif ARUDINO_ESP8266_WEMOS_D1R1
  Serial.println("d1r1");
#else
  Serial.println("sad day");
#endif

}

void loop() {
  // put your main code here, to run repeatedly:

}
