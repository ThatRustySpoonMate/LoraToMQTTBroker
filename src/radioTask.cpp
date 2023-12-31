#include "radioTask.hpp"

SX1276 radio = new Module(NSS, DIO0, RESET, DIO1);

volatile bool receivedFlag = false;


int16_t radioTaskInit() {
  int16_t result;

  result = radio.begin();

  radio.setPacketReceivedAction(setRXFlag);
  
  return result;
}


#if defined(ESP8266) || defined(ESP32)
  ICACHE_RAM_ATTR
#endif
void setRXFlag(void) {
  // we got a packet, set the flag
  receivedFlag = true;
}

