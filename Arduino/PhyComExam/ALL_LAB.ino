#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

uint32_t frame1[3] = {0xFFF80199, 0x9801A059, 0xF9801FFF};
uint32_t frame2[3] = {0xFFF80199, 0x98018019, 0xF9801FFF};
uint32_t frame3[3] = {0xFFF80199, 0x98019F9A, 0x05801FFF};

void setup() {
  matrix.begin();
}

void loop() {
  int interval = 1000;

  matrix.loadFrame(frame1);
  delay(interval);
  matrix.loadFrame(frame2);
  delay(interval);
  matrix.loadFrame(frame3);
  delay(interval);
  matrix.loadFrame(frame2);
  delay(interval);
}

//--//
// กำหนดพอร์ตสำหรับ LED RGB
const int RED_PIN = 8;    // ขา Red
const int GREEN_PIN = 6;  // ขา Green
const int BLUE_PIN = 7;   // ขา Blue

void setup() {
  // กำหนดพอร์ตให้เป็น OUTPUT
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // let you cook here
}

//ขา A (ขา 7) → Digital Pin 2  // 10 9 8 7 6 
//ขา B (ขา 6) → Digital Pin 3  //  G F   A B

//ขา C (ขา 4) → Digital Pin 4  //  E D   C
//ขา D (ขา 2) → Digital Pin 5. //  5 4 3 2 1
//ขา E (ขา 1) → Digital Pin 6
//ขา F (ขา 9) → Digital Pin 7
//ขา G (ขา 10) → Digital Pin 8
//ขา Common (ขา 3) → GND (ถ้าเป็น Common Cathode) หรือ +5V (ถ้าเป็น Common Anode)

// กำหนดขาเชื่อมต่อ 7-segment display
int A = 0, B = 1, C = 2, D = 3, E = 4, F_seg = 5, G = 6;
int A_2 = 7, B2 = 8, C2 = 9, D_2 = 10, E2 = 11, F_seg2 = 12, G2 = 13; // เปลี่ยนชื่อ F เป็น F_seg
int port1[7] = {A, B, C, D, E, F_seg, G}; // อาเรย์เพื่อจัดเก็บหมายเลขขาของ display 1
int port2[7] = {A_2, B2, C2, D_2, E2, F_seg2, G2}; // อาเรย์เพื่อจัดเก็บหมายเลขขาของ display 2

void setup() {
  Serial.begin(9600); // เริ่มการสื่อสารผ่าน Serial ที่ 9600 bps
  for (int i = 0; i < 7; i++) {
    pinMode(port1[i], OUTPUT); // กำหนดขา 7-segment display 1 เป็น OUTPUT
    pinMode(port2[i], OUTPUT); // กำหนดขา 7-segment display 2 เป็น OUTPUT
  }
}

void loop() {
  displayNumber(0);
  for (int num = 0; num <= 9; num++) {
    displayNumber2(num); // เรียกใช้ฟังก์ชันเพื่อแสดงเลข
    delay(1000); // หน่วงเวลา 1 วินาทีก่อนแสดงเลขถัดไป
  }
  displayNumber(6);  // แสดงเลข 6 บน display 1
  displayNumber2(6); // แสดงเลข 0 บน display 2
  delay(1000);       // หน่วงเวลา 1 วินาที
  displayNumber(0);  // แสดงเลข 6 บน display 1
  displayNumber2(7); // แสดงเลข 0 บน display 2
  delay(1000);       // หน่วงเวลา 1 วินาที
  displayNumber(0);  // แสดงเลข 6 บน display 1
  displayNumber2(1); // แสดงเลข 0 บน display 2
  delay(1000);       // หน่วงเวลา 1 วินาที
  displayNumber(3);  // แสดงเลข 6 บน display 1
  displayNumber2(8); // แสดงเลข 0 บน display 2
  delay(1000);       // หน่วงเวลา 1 วินาที
}

// ฟังก์ชันสำหรับแสดงเลขบน display 1
void displayNumber2(int num) {
  // ปิด segment ทั้งหมดของ display 1 ก่อน
  for (int i = 0; i < 7; i++) {
    digitalWrite(port1[i], LOW); // ปิดทุก segment ของ display 1
  }

  // ใช้ switch-case เพื่อตรวจสอบเลขที่ต้องการแสดงบน display 1
  switch (num) {
    case 0:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F_seg, HIGH);
      break;
    case 1:
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 2:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      break;
    case 4:
      digitalWrite(F_seg, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(F_seg, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      break;
    case 6:
      digitalWrite(A, HIGH);
      digitalWrite(F_seg, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      break;
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 8:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(F_seg, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(F_seg, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      break;
  }
}

// ฟังก์ชันสำหรับแสดงเลขบน display 2
void displayNumber(int num) {
  // ปิด segment ทั้งหมดของ display 2 ก่อน
  for (int i = 0; i < 7; i++) {
    digitalWrite(port2[i], LOW); // ปิดทุก segment ของ display 2
  }

  // ใช้ switch-case เพื่อตรวจสอบเลขที่ต้องการแสดงบน display 2
  switch (num) {
    case 0:
      digitalWrite(A_2, HIGH);
      digitalWrite(B2, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(D_2, HIGH);
      digitalWrite(E2, HIGH);
      digitalWrite(F_seg2, HIGH);
      break;
    case 1:
      digitalWrite(B2, HIGH);
      digitalWrite(C2, HIGH);
      break;
    case 2:
      digitalWrite(A_2, HIGH);
      digitalWrite(B2, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(E2, HIGH);
      digitalWrite(D_2, HIGH);
      break;
    case 3:
      digitalWrite(A_2, HIGH);
      digitalWrite(B2, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(D_2, HIGH);
      break;
    case 4:
      digitalWrite(F_seg2, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(B2, HIGH);
      digitalWrite(C2, HIGH);
      break;
    case 5:
      digitalWrite(A_2, HIGH);
      digitalWrite(F_seg2, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(D_2, HIGH);
      break;
    case 6:
      digitalWrite(A_2, HIGH);
      digitalWrite(F_seg2, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(D_2, HIGH);
      digitalWrite(E2, HIGH);
      break;
    case 7:
      digitalWrite(A_2, HIGH);
      digitalWrite(B2, HIGH);
      digitalWrite(C2, HIGH);
      break;
    case 8:
      digitalWrite(A_2, HIGH);
      digitalWrite(B2, HIGH);
      digitalWrite(F_seg2, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(D_2, HIGH);
      digitalWrite(E2, HIGH);
      break;
    case 9:
      digitalWrite(A_2, HIGH);
      digitalWrite(B2, HIGH);
      digitalWrite(F_seg2, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(D_2, HIGH);
      break;
  }
}
//-สวิต-//
const int BTN = 2;
const int LED = 3;

bool is_led_on = true;

void setup()
{
  pinMode(BTN, INPUT_PULLUP);  // Use internal pull-up resistor
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (digitalRead(BTN) == LOW) {
    is_led_on = !is_led_on;
    delay(100);
  }
  
  if (is_led_on) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  delay(5);
}

//หมุน ไฟ-//
const int ledPin = 3;  // Pin for LED (PWM pin)
const int potPin = A0; // Pin for Potentiometer (Analog input pin)

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as OUTPUT
}

void loop() {
  int potValue = analogRead(potPin); // Read the value from the Potentiometer

  // Scale the potValue directly
  int brightness = potValue / 4; // Scale down from 0-1023 to 0-255
  
  analogWrite(ledPin, brightness); // Write the brightness value to the LED
}

//--//
const int ledPin1 = 5;  // เลือก PWM Pin สำหรับ LED1 ฝั่งลบ
const int ledPin2 = 6; // เลือก PWM Pin สำหรับ LED2  ฝั่งลบ

int brightness1 = 0; // ความสว่างของ LED1
int brightness2 = 0; // ความสว่างของ LED2

void setup() {
  // กำหนด Pin เป็น Output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Fading LED1 จาก Off ไปยัง Full-Bright
  analogWrite(ledPin1, brightness1);
  brightness1++;

  // Fading LED2 จาก Off ไปยัง Full-Bright เร็วเป็นสองเท่า
  analogWrite(ledPin2, brightness2);
  brightness2 += 2;

  // ตรวจสอบความสว่าง 
  if (brightness1 > 255) {
    brightness1 = 0;
  }
  if (brightness2 > 255) {
    brightness2 = 0;
  }

  delay(10); // หน่วงเวลาเล็กน้อยสำหรับการปรับความสว่าง
}