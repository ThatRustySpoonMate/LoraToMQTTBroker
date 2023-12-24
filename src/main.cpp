#include "main.hpp"



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // initialize SX1276 with default settings
  Serial.print(F("[SX1276] Initializing ... "));
  int16_t state = radioTaskInit();
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }
  
  // Initialize display
  displayTaskInit();


  
}

void loop() {
  // put your main code here, to run repeatedly:
  displayTest();

  delay(500);
}
