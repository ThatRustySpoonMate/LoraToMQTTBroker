
#include <RadioLib.h>
#include "commonTypes.h"

#define NSS 18
#define DIO0 26
#define RESET 23
#define DIO1  33

int16_t radioTaskInit();

int16_t radioTaskStartListen();

#if defined(ESP8266) || defined(ESP32)
  ICACHE_RAM_ATTR
#endif

void setRXFlag(void);

int16_t radioTaskGetMessage(LORAMsgType *data);