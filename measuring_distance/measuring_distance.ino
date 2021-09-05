/**
 * Measuring distance using ultrasonic sensor
 *
 * measures the distance of the object and prints
 * the same on the serial monitor after the given interval
 * of time.
 *
 */

const int INTERVAL_IN_MS = 1000;
const int MAX_DISTANCE = 2; // max distance detectable by sensor in metres
const int SPEED_OF_SOUND = 343; // speed of sound in cm/us
const int ECHO_PIN = 11;
const int TRIGGER_PIN = 12;
const int TIMEOUT = MAX_DISTANCE * 6000; // timeout in microseconds (approx to max distance * 6000)

float get_distance() {
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10); // 10us is the duration of trigger
    digitalWrite(TRIGGER_PIN, LOW);
    float duration = pulseIn(ECHO_PIN, HIGH, TIMEOUT);
    return (duration * SPEED_OF_SOUND) / 20000;
}

void setup() {
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIGGER_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    delay(INTERVAL_IN_MS);
    float distance = get_distance();
    if (distance > 0) {
        Serial.print("The object is ");
        Serial.print(distance);
        Serial.println(" cms away.");
    } else {
        Serial.println("The object is out of tracking distance.");
    }
}
