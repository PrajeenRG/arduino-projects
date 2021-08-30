/**
 * Hello World program with LCD screen
 * 
 * this is a simple program that displays hello world on the lcd screen.
 *
 */

#include <LiquidCrystal.h>

const int D7_PIN = 2;
const int D6_PIN = 4;
const int D5_PIN = 6;
const int D4_PIN = 8;
const int ENABLE_PIN = 10;
const int RS_PIN = 12;

const int NO_OF_COLS = 16;
const int NO_OF_ROWS = 2;

LiquidCrystal lcd(RS_PIN, ENABLE_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup() {
    lcd.begin(NO_OF_COLS, NO_OF_ROWS);
    lcd.clear();
    lcd.print("Hello, World!!");
}

void loop() {
  // left empty because of no use
}
