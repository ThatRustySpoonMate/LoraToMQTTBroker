#include "mqttTask.hpp"

WiFiClient espClient;
PubSubClient client(espClient);

const char *BROKER_IP;
int BROKER_PORT;
const char *DEVICE_NAME;
const char *RX_TOPIC;

