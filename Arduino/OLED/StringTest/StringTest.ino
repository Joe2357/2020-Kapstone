#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_D1 9
#define OLED_D0 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RES 13

Adafruit_SSD1306 OLED(OLED_D1, OLED_D0, OLED_DC, OLED_RES, OLED_CS);
bool isReady = false;
String stringTemplate = "Multimeter Value :: ";

void JGM_init() {
  OLED.setTextSize(1);
  OLED.setTextColor(WHITE);
  OLED.setCursor(0, 0);

  String readyString = "Initialize OLED...";
  for (int i = 0; readyString[i]; i++) {
    OLED.print(readyString[i]);
    OLED.display();
    delay(100);
  }
  OLED.println();
  delay(1000);

  String CompleteString = "Initialize completed!";
  for (int i = 0; CompleteString[i]; i++) {
    OLED.print(CompleteString[i]);
    OLED.display();
    delay(100);
  }

  OLED.clearDisplay();
  isReady = true;
  return;
}

void JGM_test() {
  isReady = false;
  OLED.setCursor(0, 0);
  String t1 = "Operate test function";
  for (int i = 0; t1[i]; i++) {
    OLED.print(t1[i]);
    OLED.display();
    delay(20);
  }
  for (int i = 0; i < 3; i++) {
    delay(500);
    OLED.print(".");
    OLED.display();
  }
  OLED.clearDisplay();

  // same function in loop()
  for (int i = 0; i < 500; i++) {
    OLED.clearDisplay();
    OLED.setCursor(0, 0);
    OLED.println(stringTemplate);
    OLED.setCursor(70, 15);
    OLED.println(i);
    OLED.display();
    delay(10);
  }
  OLED.clearDisplay();
  OLED.setCursor(0, 0);
  OLED.println(stringTemplate);
  OLED.setCursor(70, 15);
  OLED.println("NO SIGNAL");
  OLED.display();

  isReady = true;
}

String readString() {
  String temp = "";
  while (Serial.available()) {
    temp.concat((char)Serial.read());
    delay(10);
  }
  return temp;
}

// initialize
void setup() {
  Serial.begin(9600);

  OLED.begin();
  OLED.clearDisplay();

  JGM_init();

  delay (1000);
  JGM_test();

}

void loop() {
  if (isReady) {
    if (Serial.available()) {
      OLED.clearDisplay();
      OLED.setCursor(0, 0);
      OLED.println(stringTemplate);
      String str = readString();
      OLED.setCursor(70, 15);
      OLED.println(str);
      OLED.display();
      delay(100);
    }
  }
}
