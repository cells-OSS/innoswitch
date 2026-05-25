const int switchPin1 = 2;
const int switchPin2 = 4;
const int switchPin3 = 7;
int lastState = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
}

void loop() {
  int currentState1 = digitalRead(switchPin1);
  int currentState2 = digitalRead(switchPin2);
  int currentState3 = digitalRead(switchPin3);

  if (currentState1 == LOW && lastState == HIGH) {
    Serial.println("PRESSED1");
    delay(50);
  }
  if (currentState2 == LOW && lastState == HIGH) {
    Serial.println("PRESSED2");
    delay(50);
  }
  if (currentState3 == LOW && lastState == HIGH) {
    Serial.println("PRESSED3");
    delay(50);
  }
  
  lastState = currentState1;
  delay(20);
  lastState = currentState2;
  delay(20);
  lastState = currentState3;
  delay(20);
}
