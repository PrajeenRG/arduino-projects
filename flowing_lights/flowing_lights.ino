/**
 * Flowing lights using LED
 * 
 * A simple program where a series of lights will turn on one by one
 * and will turn off one by one from the last.
 * 
 */

const int DELAY_IN_MS = 1000;
const int LED_PIN_START = 2;
const int LED_PIN_END = 7;

void setup() {
    for (int i = LED_PIN_START; i <= LED_PIN_END; ++i) {
        pinMode(i, OUTPUT);
    }
}

void loop() {
    for (int i = LED_PIN_START; i <= LED_PIN_END; ++i) {
        digitalWrite(i, HIGH);
        delay(DELAY_IN_MS);
    }
    for (int i = LED_PIN_END; i >= LED_PIN_START; --i) {
        digitalWrite(i, LOW);
        delay(DELAY_IN_MS);
    }
}
