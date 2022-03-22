void setup() 
{
  pinMode(11, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop() 
{
  digitalWrite(A3, LOW);
  a();
  d();
  a();
  m();
  digitalWrite(A3, HIGH);
  space();
}

void a()
{
  dot();
  wait();
  dash();
  pause();
}

void d()
{
  dash();
  wait();
  dot();
  wait();
  dot();
  pause();
}

void m()
{
  dash();
  wait();
  dash();
  pause();
}

void dot() 
{
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(11, LOW);
}

void dash()
{
  digitalWrite(11, HIGH);
  delay(600);
  digitalWrite(11, LOW);
}

void wait()
{
  delay(200);
}

void pause()
{
  delay(600);
}

void space()
{
  delay(1400);
}