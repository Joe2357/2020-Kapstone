#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <string.h>
#include <SoftwareSerial.h>

#define OLED_D1 9
#define OLED_D0 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RES 13
Adafruit_SSD1306 display(OLED_D1, OLED_D0, OLED_DC, OLED_RES, OLED_CS);

#define RX 2
#define TX 3
SoftwareSerial BTSerial(RX,TX);

void setup() {
  Serial.begin(9600); // 시리얼 모니터 기본설정
  BTSerial.begin(9600); // 블루투스 기본설정

  // LED 기본설정
  display.begin();
  display.display();
  delay(500);
  display.clearDisplay();
}

String readLine2() {
  String str = "";
  char ch;

  while (BTSerial.available() > 0) {
    ch = BTSerial.read();
    str.concat(ch);
    delay(2);
  }

  return str;
}

String readLine1() {
  String str = "";
  char ch;

  while (Serial.available() > 0) {
    ch = Serial.read();
    str.concat(ch);
    delay(2);
  }

  return str;
}

void loop() {
  if (BTSerial.available()) {
    String str = readLine2();
    Serial.println(str);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println(str);
    display.display();
    delay(1000);
    display.clearDisplay();
  }

  if (Serial.available()) {
    String str = readLine1();
    Serial.println(str);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println(str);
    display.display();
    delay(1000);
    display.clearDisplay();
  }
}
