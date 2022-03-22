//zad. 4.
volatile bool go = true;
uint8_t count = 1;
int changer = 1;

void buttonPress() 
{
  go = !go;
}

void setup() 
{
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  analogWrite(6, LOW);
  analogWrite(5, 256);
  
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), buttonPress, FALLING);

  Serial.begin(9600);
}

void loop() 
{
  if (!go) 
  {
    digitalWrite(7, HIGH);
    return;
  }
  digitalWrite(7, LOW);



  analogWrite(6, count);
  analogWrite(5, (256 - count));
  
  if(count == 255) 
  {
    changer = -changer;
  }
  
  count += changer;
  Serial.print(count);
  Serial.print(" ");
  Serial.println(changer);
}
