#include "main.hpp"


bool debug_log; // Flag for logging messages to Serial Terminal
extern bool loraReceivedFlag;

void setup() {
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

  // Start listening for packets
  Serial.print(F("[SX1276] Starting to listen ... "));
  state = radioTaskStartListen();
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }
  
  // Initialize display
  displayTaskInit();

  // Initialize WiFi 
  setup_wifi(WIFI_SSID, WIFI_PASSWORD);
  
  // Connect to MQTT Broker over WIFI
  setup_mqtt(MQTT_BROKER_IP, MQTT_BROKER_PORT, DEVICE_ID, MQTT_MANAGEMENT_TOPIC);
  
}

void loop() {
  static LORAMsgType loraMsg;
  static int16_t rxMsgStatus;
  displayTest();


  // Keep MQTT Session alive
  mqtt_keep_alive();

  // Check for received message
  if(loraReceivedFlag) {
    // Get message
    rxMsgStatus = radioTaskGetMessage(&loraMsg); 

    if(rxMsgStatus == RADIOLIB_ERR_NONE) {
      // Successfully received a message

      mqtt_transmit(loraMsg.MQTT_Topic, &loraMsg.data); // Transmit newly received message over mqtt
    }

  }

  delay(500);
}
