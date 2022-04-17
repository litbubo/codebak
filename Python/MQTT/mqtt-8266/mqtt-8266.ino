#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "深夜快递飙车";
const char* password = "514.514.514.";
const char* mqttServer = "121.40.198.205";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);

  connectWifi();

  mqttClient.setServer(mqttServer, 1883);
  mqttClient.setCallback(receiveCallback);
  connectMQTTserver();
}

void loop() {
  if (mqttClient.connected())
  {
    mqttClient.loop();
  }
  else
  {
    connectMQTTserver();
  }
}

void connectMQTTserver() {
  String clientId = "esp8266-" + WiFi.macAddress();

  if (mqttClient.connect(clientId.c_str()) )
  {
    Serial.println("MQTT Server Connected.");
    subscribeTopic();
  }
  else
  {
    Serial.print("MQTT Server Connect Failed. Client State:");
    Serial.println(mqttClient.state());
    delay(5000);
  }
}

void receiveCallback(char* topic, byte* payload, unsigned int length)
{
  if ((char)payload[0] == '1')
  {
    digitalWrite(BUILTIN_LED, LOW);
    Serial.println("LED ON");
  }
  else
  {
    digitalWrite(BUILTIN_LED, HIGH);
    Serial.println("LED OFF");
  }
}

void subscribeTopic()
{
  String topicString = "control";
  if (mqttClient.subscribe(topicString.c_str()))
  {
    Serial.println("Subscrib Topic:");
    Serial.println(topicString);
  }
  else
  {
    Serial.print("Subscribe Fail...");
  }
}

void connectWifi()
{

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected!");
  Serial.println("");
}
