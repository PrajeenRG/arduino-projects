/**
 * Textsaver program using LCD display
 * 
 * This is a screensaver like program wherein the strings
 * in text variable are displayed on the screen one by one with
 * a delay specificed in milliseconds.
 * 
 */

#include <LiquidCrystal.h>

const int D7_PIN = 2;
const int D6_PIN = 4;
const int D5_PIN = 6;
const int D4_PIN = 8;
const int ENABLE_PIN = 10;
const int RS_PIN = 12;

const int DELAY_IN_MS = 2000;
const int NO_OF_COLS = 16;
const int NO_OF_ROWS = 2;

LiquidCrystal lcd(RS_PIN, ENABLE_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

int text_number = 0;
char text[][NO_OF_COLS] = { 
    "Hello, LCD!",
    "This is a text!", 
    "LCD Display!",
    "Sample text",
    "This works!"
};

void setup() {
    lcd.begin(NO_OF_COLS, NO_OF_ROWS);
}

void loop() {
    text_number = text_number % (sizeof(text) / sizeof(text[0]));
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(text[text_number]);
    
    delay(DELAY_IN_MS);
    
    ++text_number;
}
