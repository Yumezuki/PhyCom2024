// กำหนดพอร์ตสำหรับ LED
const int LED_PIN = 9;
const int GREEN_PIN = 8;
const int BLUE_PIN = 7;

void setup() {
  // กำหนดพอร์ตให้เป็น OUTPUT
  pinMode(LED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // เปิด LED
  digitalWrite(LED_PIN, 1);
  digitalWrite(GREEN_PIN, 0);
  digitalWrite(BLUE_PIN, 0);
  delay(1000);

  digitalWrite(LED_PIN, 1);
  digitalWrite(GREEN_PIN, 1);
  digitalWrite(BLUE_PIN, 0);
  delay(1000);

  digitalWrite(LED_PIN, 0);
  digitalWrite(GREEN_PIN, 1);
  digitalWrite(BLUE_PIN, 0);
  delay(1000);

  digitalWrite(LED_PIN, 0);
  digitalWrite(GREEN_PIN, 1);
  digitalWrite(BLUE_PIN, 1);
  delay(1000);

  digitalWrite(LED_PIN, 0);
  digitalWrite(GREEN_PIN, 0);
  digitalWrite(BLUE_PIN, 1);
  delay(1000);

  digitalWrite(LED_PIN, 1);
  digitalWrite(GREEN_PIN, 0);
  digitalWrite(BLUE_PIN, 1);
  delay(1000);

  digitalWrite(LED_PIN, 1);
  digitalWrite(GREEN_PIN, 1);
  digitalWrite(BLUE_PIN, 1);
  delay(1000);
}