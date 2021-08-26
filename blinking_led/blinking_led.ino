/**
 * Blinking LED Program
 * 
 * This is the Hello World equivalent of Arduino world. The code 
 * is written to turn the LED on for 1s or 1000ms, and then turn 
 * it off for another 1s or 1000ms, thus simulating blinking.
 * 
 * The constant LED_PIN is declared to set the pin to which LED
 * is connected, currently its set to 8, but can be changed to
 * any other digital pin on the board
 * 
 */

int LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
