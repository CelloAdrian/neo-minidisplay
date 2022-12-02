#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int N1 = 15;
const int N2 = 2;
const int N3 = 4;
const int N4 = 5;
const int N5 = 18;
const int N6 = 19;
const int N7 = 13;
const int N8 = 12;
const int N9 = 14;
const int BACK = 27;
const int N0 = 26;
const int ENTER = 25;

int menuSelected = 0;
int menuEntered = -1;

void displayMenu() {
  int up = digitalRead(N8);
  int down = digitalRead(N0);
  int back = digitalRead(BACK);
  int enter = digitalRead(ENTER);

  if (down == LOW) {
    menuSelected++;
    delay(200);
  }
  if (up == LOW) {
    menuSelected--;
    delay(200);
  }
  if (back == LOW) {
    menuEntered = -1;
    menuSelected = 0;
    delay(200);
  }
  if (enter == LOW) {
    menuEntered = menuSelected;
    menuSelected = 0;
    delay(200);
  }

  int menuSize = 2;
  const char *menu[menuSize] = {"Notes", "Settings"};

  // prevent stuff from going out of bounds
  if (menuSelected < 0) {
    menuSelected = 0;
  }
  if (menuSelected > menuSize - 1) {
    menuSelected = menuSize - 1;
  }

  switch (menuEntered) {
    case -1:
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);

      for (int i = 0; i < menuSize; i++) {
        if (i == menuSelected) {
          display.print(">");
        } else {
          display.print(" ");
        }
        display.println(menu[i]);
      }

      display.display();
      break;
    case 0:
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);

      display.println("Screen 1");

      display.display();
      break;
    case 1:
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);

      display.println("Screen 2");

      display.display();
      break;
    case 2:
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);

      display.println("Screen 3");

      display.display();
      break;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(N1, INPUT_PULLUP);
  pinMode(N2, INPUT_PULLUP);
  pinMode(N3, INPUT_PULLUP);
  pinMode(N4, INPUT_PULLUP);
  pinMode(N5, INPUT_PULLUP);
  pinMode(N6, INPUT_PULLUP);
  pinMode(N7, INPUT_PULLUP);
  pinMode(N8, INPUT_PULLUP);
  pinMode(N9, INPUT_PULLUP);
  pinMode(BACK, INPUT_PULLUP);
  pinMode(N0, INPUT_PULLUP);
  pinMode(ENTER, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  displayMenu();

  delay(10);  // this speeds up the simulation
}