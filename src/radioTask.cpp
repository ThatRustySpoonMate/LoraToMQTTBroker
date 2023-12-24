#include "radioTask.hpp"

SX1276 radio = new Module(NSS, DIO0, RESET, DIO1);

int16_t radioTaskInit() {
  int16_t result;

  result = radio.begin();
  
  return result;
}
