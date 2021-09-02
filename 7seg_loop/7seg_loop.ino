/**
 * 7 segment display basics
 *
 * A sample program where the 7-segment display
 * is looped through all of its possible displayable
 * characters.
 *
 * Pin Connections:
 * A -> 7, B ->  2, C ->  4, D -> 6
 * E -> 8, F -> 10, G -> 12
 *
 */

int characters[][7] = {
    // { A,    B,    C,    D,    E,    F,    G }
    { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH,  LOW }, // 0
    {  LOW, HIGH, HIGH,  LOW,  LOW,  LOW,  LOW }, // 1
    { HIGH, HIGH,  LOW, HIGH, HIGH,  LOW, HIGH }, // 2
    { HIGH, HIGH, HIGH, HIGH,  LOW,  LOW, HIGH }, // 3
    {  LOW, HIGH, HIGH,  LOW,  LOW, HIGH, HIGH }, // 4
    { HIGH,  LOW, HIGH, HIGH,  LOW, HIGH, HIGH }, // 5
    { HIGH,  LOW, HIGH, HIGH, HIGH, HIGH, HIGH }, // 6
    { HIGH, HIGH, HIGH,  LOW,  LOW,  LOW,  LOW }, // 7
    { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH }, // 8
    { HIGH, HIGH, HIGH, HIGH,  LOW, HIGH, HIGH }, // 9
    { HIGH, HIGH, HIGH,  LOW, HIGH, HIGH, HIGH }, // A
    {  LOW,  LOW, HIGH, HIGH, HIGH, HIGH, HIGH }, // B
    { HIGH,  LOW,  LOW, HIGH, HIGH, HIGH,  LOW }, // C
    {  LOW, HIGH, HIGH, HIGH, HIGH,  LOW, HIGH }, // D
    { HIGH,  LOW,  LOW, HIGH, HIGH, HIGH, HIGH }, // E
    { HIGH,  LOW,  LOW,  LOW, HIGH, HIGH, HIGH }  // F
};

const int DELAY_IN_MS = 1000;

int idx = 0; // denotes the letter to display

void display_character() {
    digitalWrite(7, characters[idx][0]);
    for (int i = 1; i < 7; ++i) {
        digitalWrite(2 * i, characters[idx][i]);
    }
}

void setup() {
    pinMode(7, OUTPUT);
    for (int i = 2; i < 13; i += 2) {
        pinMode(i, OUTPUT);
    }
}

void loop() {
    idx = idx % 16;
    display_character();
    ++idx;
    delay(DELAY_IN_MS);
}
