void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(A3, OUTPUT);
}

unsigned long time1, time2;
int diff = 1000;
void loop() {
  // put your main code here, to run repeatedly:
  if (time2 - time1 >= diff)
  {
    time1 = millis();
    digitalWrite(A3, !digitalRead(A3));
    digitalWrite(11, !digitalRead(11));
  }
  time2 = millis();
}
