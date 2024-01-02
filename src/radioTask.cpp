#include "radioTask.hpp"

SX1276 radio = new Module(NSS, DIO0, RESET, DIO1);

volatile bool loraReceivedFlag = false;


int16_t radioTaskInit() {
  int16_t result;

  result = radio.begin();

  radio.setPacketReceivedAction(setRXFlag);
  
  return result;
}

int16_t radioTaskStartListen() {
  int16_t result;
  
  result = radio.startReceive();
  
  return result;
}


#if defined(ESP8266) || defined(ESP32)
  ICACHE_RAM_ATTR
#endif
void setRXFlag(void) {
  // we got a packet, set the flag
  loraReceivedFlag = true;
}

int16_t radioTaskGetMessage(LORAMsgType *data) {
  int16_t state;

  state = radio.readData( (uint8_t*)data, sizeof(LORAMsgType) );

  loraReceivedFlag = false;

  return state;
}

