/**
 * Controlling a LED with button project
 * 
 * A simple Arduino program to control state of a LED using
 * a button. This program employs dual safety procedure
 * to check about the button before toggling the state of LED,
 * this is because of the jitter in voltage that is generated when the
 * button is pressed.
 * 
 */
 
const int BUTTON_PIN = 2;
const int LED_PIN = 8;

volatile int state = LOW;

void toggle_led() {
    state = !state;
    digitalWrite(LED_PIN, state);
}

void setup() {
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    if (digitalRead(BUTTON_PIN) == LOW) {
        delay(10);
        if (digitalRead(BUTTON_PIN) == LOW) {
            while (digitalRead(BUTTON_PIN) == LOW);
            delay(10);
	          while (digitalRead(BUTTON_PIN) == LOW);
	          toggle_led();
	      }
    }
}
