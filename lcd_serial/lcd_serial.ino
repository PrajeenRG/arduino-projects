/**
 * LCD Screen as Serial Display
 *
 * Displays the contents entered in the serial
 * monitor on the lcd screen. It changes 
 * begin given number of rows and writes to the
 * screen.
 *
 */

#include <LiquidCrystal.h>

#define LF 0x0A

const int D7_PIN = 12;
const int D6_PIN = 10;
const int D5_PIN = 8;
const int D4_PIN = 6;
const int ENABLE_PIN = 4;
const int RS_PIN = 2;

const int DELAY_IN_MS = 1000;
const int NO_OF_COLS = 16;
const int NO_OF_ROWS = 2;

char input[NO_OF_COLS];
char idx = 0;
int current_row = 0;

LiquidCrystal lcd(RS_PIN, ENABLE_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void lcd_clear_row(int row) {
    lcd.setCursor(0, row);
    for (int i = 0; i < NO_OF_COLS; ++i) {
        lcd.print(" ");
    }
}

void setup() {
    Serial.begin(9600);
    lcd.begin(NO_OF_COLS, NO_OF_ROWS);
    lcd.clear();
    lcd.setCursor(0, current_row);
}

void loop() {
    if (Serial.available() > 0) {
        input[idx] = Serial.read();
        if ((input[idx] == LF) || (idx == NO_OF_COLS - 1)) {
            if (idx != NO_OF_COLS - 1) {
                input[idx] = '\0';
            }
            idx = 0;
            current_row = current_row % NO_OF_ROWS;
            lcd_clear_row(current_row);
            lcd.setCursor(0, current_row);
            lcd.print(input);
            Serial.print("Wrote \"");
            Serial.print(input);
            Serial.println("\" to the screen.");
            ++current_row;
        } else {
            ++idx;
        }
    }
}
