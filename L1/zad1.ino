void setup() {
  // put your setup code here, to run once:
    pinMode(11, OUTPUT);
    pinMode(A3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  digitalWrite(A3, !digitalRead(A3));
  digitalWrite(11, !digitalRead(11));
}
