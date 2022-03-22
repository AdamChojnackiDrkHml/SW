uint8_t count = 0;
volatile bool go = true;
volatile bool press = false;
long lastDebounceTime;
int changer = 1;

void buttonPress() {
  press = true;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), buttonPress, FALLING);

  Serial.begin(9600);
}

void loop() {
  if (press)
  { 
    press = false;
    lastDebounceTime = millis();
    while (millis() - lastDebounceTime  < 500);
    go = !go;
    press = false;
  }
  
  if(!go) {
    digitalWrite(7, HIGH);
    return;
  }
  digitalWrite(7, LOW);
  // put your main code here, to run repeatedly:
  analogWrite(6, count);
  analogWrite(5, (255 - count));
  
  if((count == 255 && changer == 1) || (count == 0 && changer == -1)) 
  {
    changer = -changer;
  }
  
  count += changer;
  Serial.print(count);
  Serial.print(" ");
  Serial.println(changer);

}
