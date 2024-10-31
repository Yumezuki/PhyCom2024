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
const char PUBLISH_TOPIC[] = "MockExam/66070223";    // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "MockExam/66070223";  // CHANGE IT AS YOU DESIRE

const int PUBLISH_INTERVAL = 60 * 1000;  // 60 seconds

const int trigPin = 3;
const int echoPin = 2;

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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
  if (mqtt.subscribe(SUBSCRIBE_TOPIC))
    Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  else
    Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  Serial.println(SUBSCRIBE_TOPIC);
  Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

void sendToMQTT() {

  // int val = millis();
  // int val = analogRead(A0);
  // String val_str = String(val);

  // int sensorValue = analogRead(A0); // อ่านค่าเซนเซอร์
  // float voltage = sensorValue * (5.0 / 1023.0); // แปลงค่า Analog เป็น Voltage
  // float temperatureC = voltage * 100; // แปลง Voltage เป็น อุณหภูมิ (Celsius)

  // String temperature_str = String(temperatureC, 2); // ทศนิยม 2 ตำแหน่ง

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
    foodBuffer_str = String(distanceCm); // ถ้าระยะทางไม่เกิน ให้แสดงค่าเซนเซอร์
  }
  // delay(1000); // หน่วงเวลา 1 วินาที

  // Convert the string to a char array for MQTT publishing
  char foodBuffer_str[10];
  // temperature_str.toCharArray(messageBuffer, 10);
  // val_str.toCharArray(messageBuffer, 10);
  foodBuffer_str.toCharArray(foodBuffer, 10);

  // Publish the message to the MQTT topic
  mqtt.publish(PUBLISH_TOPIC, foodBuffer);

  // Print debug information to the Serial Monitor in one line
  Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(foodBuffer));
}

// void sendToMQTT() {
//   // Check if there's data available to read from the Serial Monitor
//   if (Serial.available() > 0) {
//     // Read the input from the Serial Monitor as a string
//     String val_str = Serial.readStringUntil('\n');

//     // Convert the string to a char array for MQTT publishing
//     char messageBuffer[10];
//     val_str.toCharArray(messageBuffer, 10);

//     // Publish the message to the MQTT topic
//     mqtt.publish(PUBLISH_TOPIC, messageBuffer);

//     // Print debug information to the Serial Monitor in one line
//     Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(messageBuffer));
//   }
// }

void messageHandler(String &topic, String &payload) {
  Serial.println("Arduino UNO R4 - received from MQTT: topic: " + topic + " | payload: " + payload);

  // You can process the incoming data , then control something
  /*
  process something
  */
}