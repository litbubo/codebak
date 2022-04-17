#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const char *ssid = "RedmiK40";
const char *password = "11119999";
const char *mqttServer = "121.40.198.205";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.ntsc.ac.cn", 8 * 3600, 60000);

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.print("#WiFi Connected*");

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
    subscribeTopic();
  }
  else
  {
    delay(3000);
  }
}

void pubMQTTmsg()
{
  String messageString;
  while (Serial.available() > 0)
  {
    messageString += (char)Serial.read();
    delay(2);
  }

  if (messageString == "1")
  {
    messageString = "Open";
  }
  else if (messageString == "0")
  {
    messageString = "Close";
  }
  messageString += " the door at ";

  timeClient.update();

  String time_now = timeClient.getFormattedTime();

  messageString += time_now;
  /*
    unsigned long epochTime = timeClient.getEpochTime();

    struct tm *ptm = gmtime ((time_t *)&epochTime);
    int monthDay = ptm->tm_mday;
    int currentMonth = ptm->tm_mon + 1;
    int currentYear = ptm->tm_year + 1900;
    String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);

    messageString += currentDate;*/

  mqttClient.publish("testsend", messageString.c_str());
}

void subscribeTopic()
{
  mqttClient.subscribe("control");
  /*
    if (mqttClient.subscribe("control"))
    {
    Serial.println("Subscribe Topic:");
    Serial.println(topicString);
    }
    else
    {
    Serial.print("Subscribe Fail...");
    }*/
}

void receiveCallback(char *topic, byte *payload, unsigned int length)
{
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
}
