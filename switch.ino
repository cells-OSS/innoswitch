const int switchPin1 = 2;
const int switchPin2 = 4;
const int switchPin3 = 7;

const int potPin = A0;

int lastState1 = HIGH;
int lastState2 = HIGH;
int lastState3 = HIGH;

int lastVolume = -1;

void setup() {
  Serial.begin(9600);

  // Using Arduino internal pull-up resistors
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  pinMode(switchPin3, INPUT_PULLUP);
}

void loop() {

  // =========================
  // BUTTONS
  // =========================

  int currentState1 = digitalRead(switchPin1);
  int currentState2 = digitalRead(switchPin2);
  int currentState3 = digitalRead(switchPin3);

  // Button 1
  if (currentState1 == LOW && lastState1 == HIGH) {
    Serial.println("PRESSED1");
    delay(50); // debounce
  }

  // Button 2
  if (currentState2 == LOW && lastState2 == HIGH) {
    Serial.println("PRESSED2");
    delay(50);
  }

  // Button 3
  if (currentState3 == LOW && lastState3 == HIGH) {
    Serial.println("PRESSED3");
    delay(50);
  }

  lastState1 = currentState1;
  lastState2 = currentState2;
  lastState3 = currentState3;

  // =========================
  // POTENTIOMETER
  // =========================

  // Read analog value (0-1023)
  int rawValue = analogRead(potPin);

  // Convert to 0-100 volume range
  int volume = map(rawValue, 0, 1023, 0, 100);

  if (abs(volume - lastVolume) >= 2) {
    Serial.print("VOL:");
    Serial.println(volume);

    lastVolume = volume;
  }

  delay(10);
}