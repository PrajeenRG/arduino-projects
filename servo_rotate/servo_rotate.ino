/**
 * Rotating servo motor in finite steps
 *
 * rotates the servo motor from 0 to 180 deg in
 * predefined step size and again comes to 0 deg from 
 * 180 deg.
 *
 */

#include <Servo.h>

const int DELAY_IN_MS = 1000; // amount of delay between each rotation
const int SERVO_PIN = 11;  // pin thats attached to servo
const int STEP_SIZE = 10;  // amount of rotation (in deg) to rotate

Servo servo;

void setup() {
    servo.attach(SERVO_PIN);
    servo.write(0);
}

void loop() {
    for (int i = 0; i < 180; i += STEP_SIZE) {
        servo.write(i);
        delay(DELAY_IN_MS);
    }

    for (int i = 180; i > 0; i -= STEP_SIZE) {
        servo.write(i);
        delay(DELAY_IN_MS);
    }
}
