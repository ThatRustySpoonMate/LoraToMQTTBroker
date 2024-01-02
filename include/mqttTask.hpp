#include "WifiTask.hpp"
#include <PubSubClient.h>
#include "commonTypes.h"

void setup_mqtt(const char *MQTT_BROKER_IP, const int MQTT_BROKER_PORT, const char *DEV_NAME, const char *MANAGE_PORT);

void mqtt_transmit(const char *topic, const char *payload);

void mqtt_transmit(const char *topic, const PayloadType *payload);

void mqtt_keep_alive();

void mqtt_reconnect();

void message_rx_callback(char* topic, byte* message, unsigned int length);

void mqtt_disconnect();