/*
 *
 * This Arduino UNO R4 code is made available for public use without any restriction
 *
 */

#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "";          // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "";  // CHANGE TO YOUR WIFI PASSWORD

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th";  // CHANGE TO MQTT BROKER'S ADDRESS
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "";                                            // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";                                            // CHANGE IT IF REQUIRED, empty if not required

// The MQTT topics that Arduino should publish/subscribe
// const char PUBLISH_TOPIC[] = "MockExam/66070223";    // CHANGE IT AS YOU DESIRE
// const char SUBSCRIBE_TOPIC[] = "MockExam/66070223";  // CHANGE IT AS YOU DESIRE
const char PUBLISH_TEMP_TOPIC[] = "66070223/temp";
const char SUBSCRIBE_TEMP_TOPIC[] = "66070223/temp";    // Topic สำหรับค่าอุณหภูมิ

const char PUBLISH_LIGHT_TOPIC[] = "66070223/light";
const char SUBSCRIBE_LIGHT_TOPIC[] = "66070223/light";  // Topic สำหรับค่าตัวต้านทานปรับได้

const char PUBLISH_FOOD_TOPIC[] = "66070223/food";
const char SUBSCRIBE_FOOD_TOPIC[] = "66070223/food";

const char PUBLISH_VENUS_TOPIC[] = "66070223/venus";
const char SUBSCRIBE_VENUS_TOPIC[] = "66070223/venus";

const int PUBLISH_INTERVAL = 20 * 1000;  // 20 seconds

const int trigPin = 3;
const int echoPin = 2;

const int RED_PIN = 9;    // ขา Red
const int GREEN_PIN = 10;  // ขา Green
const int BLUE_PIN = 11;   // ขา Blue

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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
    sendTemperature();
    sendLight();
    sendFood();
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
  if (mqtt.subscribe(SUBSCRIBE_TEMP_TOPIC) &&
      mqtt.subscribe(SUBSCRIBE_LIGHT_TOPIC) &&
      mqtt.subscribe(SUBSCRIBE_FOOD_TOPIC)  && 
      mqtt.subscribe("66070223/venus"))
    Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  else
    Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  Serial.print(SUBSCRIBE_TEMP_TOPIC);
  Serial.print(" , ");
  Serial.print(SUBSCRIBE_LIGHT_TOPIC);
  Serial.print(" , ");
  Serial.println(SUBSCRIBE_FOOD_TOPIC);
  Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

// void sendToMQTT() {

//   // int val = millis();
//   int val = analogRead(A1); //ตัวต้านทานที่ปรับค่าได้

//   int sensorValue = analogRead(A0); //Temperator
//   float voltage = sensorValue * (5.0 / 1023.0); // แปลงค่า Analog เป็น Voltage
//   float temperatureC = voltage * 100; // แปลง Voltage เป็น อุณหภูมิ (Celsius)

//   String val_str = String(val);

//   String temperature_str = String(temperatureC, 2); // ทศนิยม 2 ตำแหน่ง

//   // Convert the string to a char array for MQTT publishing
//   char messageBuffer[10];
//   val_str.toCharArray(messageBuffer, 10);

//   temperature_str.toCharArray(messageBuffer, 10);

//   // Publish the message to the MQTT topic
//   mqtt.publish(PUBLISH_TOPIC, messageBuffer);

//   // Print debug information to the Serial Monitor in one line
//   Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(messageBuffer));
// }

void sendTemperature() {
  int sensorValue = analogRead(A0); // อ่านค่าเซนเซอร์อุณหภูมิ
  float voltage = sensorValue * (5.0 / 1023.0); // แปลงค่า Analog เป็น Voltage
  float temperatureC = voltage * 100; // แปลง Voltage เป็น อุณหภูมิ (Celsius)

  String temperature_str = String(temperatureC, 2); // ทศนิยม 2 ตำแหน่ง
  char tempBuffer[10];
  temperature_str.toCharArray(tempBuffer, 10);

  mqtt.publish(PUBLISH_TEMP_TOPIC, tempBuffer);

  Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TEMP_TOPIC) + " | payload: " + String(tempBuffer));
}

void sendLight() {
  int val = analogRead(A1); // อ่านค่าตัวต้านทานปรับค่าได้
  String val_str = String(val);
  char lightBuffer[10];
  val_str.toCharArray(lightBuffer, 10);

  mqtt.publish(PUBLISH_LIGHT_TOPIC, lightBuffer);

  Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_LIGHT_TOPIC) + " | payload: " + String(lightBuffer));
}

void sendFood() {
  long duration;
  int distanceCm, distanceInch;

  String foodBuffer_str;
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
    
  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    
  // Read the echoPin, return the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
    
  // Calculate the distance in cm and inches
  distanceCm = duration * 0.034 / 2;
  // distanceInch = duration * 0.0133 / 2;

  if (distanceCm > 20) {
    foodBuffer_str = "off";
  } else {
    foodBuffer_str = "on"; // ถ้าระยะทางไม่เกิน
  }

  char foodBuffer[10];
  foodBuffer_str.toCharArray(foodBuffer, 10);

  mqtt.publish(PUBLISH_FOOD_TOPIC, foodBuffer);

  Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_FOOD_TOPIC) + " | payload: " + String(foodBuffer));
}

void messageHandler(String &topic, String &payload) {
  Serial.println("Arduino UNO R4 - received from MQTT: topic: " + topic + " | payload: " + payload);

  int val = payload.toInt();

  if (val >= 36 && val <= 50) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, HIGH);
  } else if (val >= 26 && val <= 35) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
  }  else if (val >= 10 && val <= 25) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
  } else {
    // ปิด LED หากค่าที่ได้รับอยู่นอกช่วงที่กำหนด
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, HIGH);
  }

  // You can process the incoming data , then control something
  /*
  process something
  */
}
