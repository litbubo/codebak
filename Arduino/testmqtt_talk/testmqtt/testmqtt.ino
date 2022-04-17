
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const char *ssid = "深夜快递飙车";
const char *password = "514.514.514.";
const char *mqttServer = "121.40.198.205";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.aliyun.com", 8 * 3600, 60000);

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.mode(WIFI_STA);
  connectWifi();
  mqttClient.setServer(mqttServer, 1883);
  mqttClient.setCallback(receiveCallback);
  connectMQTTServer();
  timeClient.begin();
}

void loop()
{
  if (mqttClient.connected())
  {
    if (Serial.available() > 0)
    {
      pubMQTTmsg();
    }
    mqttClient.loop();
  }
  else
  {
    connectMQTTServer();
  }
}

void connectMQTTServer()
{
  String clientId = "esp8266-" + WiFi.macAddress();
  if (mqttClient.connect(clientId.c_str()))
  {
    Serial.println("MQTT Server Connected.");
    Serial.println("Server Address: ");
    Serial.println(mqttServer);
    Serial.println("ClientId:");
    Serial.println(clientId);
    subscribeTopic();
  }
  else
  {
    Serial.print("MQTT Server Connect Failed. Client State:");
    Serial.println(mqttClient.state());
    delay(3000);
  }
}

void pubMQTTmsg()
{
  String topicString = "testsend";
  String messageString;
  while (Serial.available() > 0)
  {
    messageString += (char)Serial.read();

    delay(2);
  }
  messageString += "Open the door at ";
  timeClient.update();
  unsigned long epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime ((time_t *)&epochTime);
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon + 1;
  int currentYear = ptm->tm_year + 1900;
  String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);
  messageString += currentDate + "  ";
  messageString += timeClient.getFormattedTime();

  mqttClient.publish(topicString.c_str(), messageString.c_str());
}

void subscribeTopic()
{

  String topicString = "control";

  if (mqttClient.subscribe(topicString.c_str()))
  {
    Serial.println("Subscribe Topic:");
    Serial.println(topicString);
  }
  else
  {
    Serial.print("Subscribe Fail...");
  }
}

void receiveCallback(char *topic, byte *payload, unsigned int length)
{
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
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
