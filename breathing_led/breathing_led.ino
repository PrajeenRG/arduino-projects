/**
 * Breathing LED Project
 * 
 * A simple LED breathing effect generation program which uses one of
 * the PWM pins present on the board to generate the breathing effect
 * of the LED connected to it.
 * 
 */

const int LED_PIN = 9;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    for (int i = 10; i < 250; i += 10) {
        analogWrite(LED_PIN, i);
        delay(100);
    }
    for (int i = 250; i > 10; i -= 10) {
        analogWrite(LED_PIN, i);
        delay(100);
    }
}
