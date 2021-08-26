/**
 * Traffic Lights Program
 * 
 * This is a simple Arduino program which recreates a
 * traffic signals like LED glowing with the use of 
 * LEDs and multiple output ports on the Arduino board.
 * 
 * The LEDs are connect to the pins specified below.
 * These can be changed according to the usage. Each of
 * these LEDs are attached to a delay element which is a
 * multiple of 250ms or 0.25s and the multiple of each LED
 * can be changed to simulate different frequency of traffic
 * signals.
 * 
 */

// LED pins
const int LED_GREEN = 8;
const int LED_ORANGE = 9;
const int LED_RED = 10;

// Delay multipliers 
const int ORANGE_MULTIPLIER = 4;
const int GREEN_MULTIPLIER = 2;
const int RED_MULTIPLIER = 1;

void blink_led(int ledpin, int multiplier) {
	digitalWrite(ledpin, HIGH);
	delay(multiplier * 250);
	digitalWrite(ledpin, LOW);
}

void setup() {
	pinMode(LED_RED, OUTPUT);
	pinMode(LED_ORANGE, OUTPUT);
	pinMode(LED_GREEN, OUTPUT);
}

void loop() {
	blink_led(LED_RED, RED_MULTIPLIER);
	blink_led(LED_ORANGE, ORANGE_MULTIPLIER);
	blink_led(LED_GREEN, GREEN_MULTIPLIER);
}
