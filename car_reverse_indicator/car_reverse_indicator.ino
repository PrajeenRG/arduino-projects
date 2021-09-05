/**
 * Car reverse indicator
 *
 * Simple project which can be used as a car reverse
 * indicator. The principle being that when the distance
 * is less the buzzer alarms at higher frequencies and
 * vice-versa for the lower ones.
 *
 */

const int DELAY_IN_MS = 250;
const int MAX_DISTANCE = 2; // max distance detectable by sensor in metres
const int SPEED_OF_SOUND = 343; // speed of sound in cm/us
const int BUZZER_PIN = 10;
const int ECHO_PIN = 11;
const int TRIGGER_PIN = 12;
const int TIMEOUT = MAX_DISTANCE * 6000; // timeout in microseconds (approx to max distance * 6000)

float get_distance() {
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10); // 10us is the duration of trigger
    digitalWrite(TRIGGER_PIN, LOW);
    float duration = pulseIn(ECHO_PIN, HIGH, TIMEOUT);
    return (int) (duration * SPEED_OF_SOUND / 20000);
}

void setup() {
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(TRIGGER_PIN, OUTPUT);
}

void loop() {
    delay(DELAY_IN_MS);
    float distance = get_distance();
    if (distance == 0) {
        // indicates that the car in this case is far from other object
        analogWrite(BUZZER_PIN, 0);
    } else {
        // as our sensor is capped at 200cm, dont use for higher distances
        analogWrite(BUZZER_PIN, 255 - distance);
    }
}
