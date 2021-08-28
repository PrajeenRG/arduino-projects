/**
 * Serial Port Project
 * 
 * This is a simple LED toggle program which can be controlled with the serial monitor
 * provided by the Arduino IDE, giving 1 as input turns on the LED and giving
 * 0 turns off the same.
 * 
 */

const int LED_PIN = 8;

volatile char input;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        input = Serial.read();
        if (input == '1') {
            digitalWrite(LED_PIN, HIGH);
            Serial.println("LED is turned on.");
        } else if (input == '0') {
            digitalWrite(LED_PIN, LOW);
            Serial.println("LED is turned off.");
        }
    }
    delay(100);
}
