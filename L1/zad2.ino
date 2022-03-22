void setup() 
{
  pinMode(11, OUTPUT);
  pinMode(A3, OUTPUT);
}

unsigned long per0 = 100;
unsigned long per1 = 800;

unsigned long timer00, timer01, timer10, timer11;

void loop() 
{
  if (timer01 - timer00 > per0)
  {
    timer00 = millis();
    digitalWrite(11, !digitalRead(11));
  }
  timer01 = millis();

  if (timer11 - timer10 > per1)
  {
    timer10 = millis();
    digitalWrite(A3, !digitalRead(A3));
  }
  timer11 = millis();
}
