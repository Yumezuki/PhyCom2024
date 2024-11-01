/*
 *
 * This Arduino UNO R4 code is made available for public use without any restriction
 *
 */

#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = ";-;";          // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "23092547";  // CHANGE TO YOUR WIFI PASSWORD

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th";  // CHANGE TO MQTT BROKER'S ADDRESS
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "Yumezuki";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "";                                            // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";                                            // CHANGE IT IF REQUIRED, empty if not required

// The MQTT topics that Arduino should publish/subscribe
const char PUBLISH_pckzy[] = "66070223/sunray_pckzy";
const char SUBSCRIBE_pckzy[] = "66070223/sunray_pckzy";  // ถ้ำของคุณปิ๊ก

const char PUBLISH_somchoon[] = "66070223/sunray_somchoon";
const char SUBSCRIBE_somchoon[] = "66070223/sunray_somchoon";  // ถ้ำของคุณส้มฉุน

const char PUBLISH_ohm[] = "66070223/sunray_ohm";
const char SUBSCRIBE_ohm[] = "66070223/sunray_ohm";  // ถ้ำของคุณโอม

const char PUBLISH_main[] = "66070223/sunray";
const char SUBSCRIBE_main[] = "66070223/sunray";  // ถ้ำของคุณโอม

const int PUBLISH_INTERVAL = 2 * 1000;  // 60 seconds

const int RED_PIN = 9;    // ขา Red
const int GREEN_PIN = 10;  // ขา Green
const int BLUE_PIN = 11;   // ขา Blue

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

int sunray_pckzy = 0;
int sunray_somchoon = 0;
int sunray_ohm = 0;

int MAX = 0;
String who;

void setup() {
  Serial.begin(9600);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    Serial.print("Arduino UNO R4 - Attempting to connect to SSID: ");
    Serial.println(WIFI_SSID);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    // wait 10 seconds for connection:
    delay(10000);
  }
  // print your board's IP address:
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  connectToMQTT();
}

void loop() {
  mqtt.loop();

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendToMQTT();
    lastPublishTime = millis();
  }
}

void connectToMQTT() {
  // Connect to the MQTT broker
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);

  // Create a handler for incoming messages
  mqtt.onMessage(messageHandler);

  Serial.print("Arduino UNO R4 - Connecting to MQTT broker");

  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  if (!mqtt.connected()) {
    Serial.println("Arduino UNO R4 - MQTT broker Timeout!");
    return;
  }

  // Subscribe to a topic, the incoming messages are processed by messageHandler() function
  if (mqtt.subscribe(SUBSCRIBE_pckzy) &&
      mqtt.subscribe(SUBSCRIBE_somchoon) &&
      mqtt.subscribe(SUBSCRIBE_ohm)  && 
      mqtt.subscribe(SUBSCRIBE_main))
    Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  else
    Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  Serial.print(SUBSCRIBE_pckzy);
  Serial.print(" , ");
  Serial.print(SUBSCRIBE_somchoon);
  Serial.print(" , ");
  Serial.println(SUBSCRIBE_ohm);
  Serial.print(" , ");
  Serial.println(SUBSCRIBE_main);
  Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

void sendToMQTT() {

  // String sunrey_str = String(MAX); // ทศนิยม 2 ตำแหน่ง
  char messageBuffer[10];
  // delay(1000); // หน่วงเวลา 1 วินาที

  if (who == "sunray_pckzy") {
    mqtt.publish(String(MAX), messageBuffer);
  } else if (who == "sunray_somchoon") {
    mqtt.publish(String(MAX), messageBuffer);
  } else if (who == "sunray_ohm") {
    mqtt.publish(String(MAX), messageBuffer);
  }


  // Convert the string to a char array for MQTT publishing
  
  // temperature_str.toCharArray(messageBuffer, 10);
  // val_str.toCharArray(messageBuffer, 10);

  // Publish the message to the MQTT topic
  

  // Print debug information to the Serial Monitor in one line
  Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(MAX) + " | payload: " + String(messageBuffer));
}

// "66070223/sunray_pckzy";  // ถ้ำของคุณปิ๊ก
// "66070223/sunray_somchoon";
// "66070223/sunray_ohm";  // ถ้ำขอ

void messageHandler(String &topic, String &payload) {
  Serial.println("Arduino UNO R4 - received from MQTT: topic: " + topic + " | payload: " + payload);

  if (topic == "66070223/sunray_pckzy") {
    sunray_pckzy = payload.toInt();
  } else if (topic == "66070223/sunray_somchoon") {
    sunray_somchoon = payload.toInt();
  } else if (topic == "66070223/sunray_ohm") {
    sunray_ohm = payload.toInt();
  }

  if ((sunray_pckzy > sunray_somchoon) && (sunray_pckzy > sunray_ohm) ) {
    MAX = sunray_pckzy;
    who = "sunray_pckzy";
  } else if ((sunray_somchoon > sunray_pckzy) && (sunray_somchoon > sunray_ohm)) {
    MAX = sunray_somchoon;
    who = "sunray_somchoon";
  } else if ((sunray_ohm > sunray_pckzy) && (sunray_ohm > sunray_somchoon)) {
    MAX = sunray_ohm;
    who = "sunray_ohm";
  }

  if (MAX > 1000) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
  } else if (MAX >= 700 && MAX <= 1000) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, HIGH);
  }  else if (MAX >= 300 && MAX <= 700) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
  }  else if (MAX < 300) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
  } 

  // You can process the incoming data , then control something
  /*
  process something
  */
}
