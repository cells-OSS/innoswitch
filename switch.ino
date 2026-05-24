const int switchPin = 2;
int lastState = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
}

void loop() {
  int currentState = digitalRead(switchPin);
  
  if (currentState == LOW && lastState == HIGH) {
    Serial.println("PRESSED");
    delay(50);
  }
  
  lastState = currentState;
  delay(20);
}
