#include <Arduino.h>

#include "credentials.h"
#include "displayTask.hpp"
#include "radioTask.hpp"
#include "mqttTask.hpp"
#include "wifiTask.hpp"



const char *MQTT_MANAGEMENT_TOPIC = "manage/lora";