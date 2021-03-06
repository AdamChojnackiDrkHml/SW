#include "Wheels.h"

#include "PinChangeInterrupt.h"

#define INTINPUT0 A0
#define INTINPUT1 A1

Wheels w;
volatile int cnt0, cnt1;

void setup() {
  w.attach(13,12,11,7,8,9);
  w.setSpeed(80);

  w.forward();

  Serial.begin(9600);

  pinMode(INTINPUT0, INPUT);
  pinMode(INTINPUT1, INPUT);

  cnt0=0;
  cnt1=0;

 attachPCINT(digitalPinToPCINT(INTINPUT0), incrementC0, RISING);
 attachPCINT(digitalPinToPCINT(INTINPUT1), incrementC1, RISING);
}

void loop() {
  Serial.print(cnt0);
  Serial.print(" ");
  Serial.println(cnt1);
  delay(250);
}

void incrementC0() 
{
  cnt0++;
}

void incrementC1()
{
  cnt1++;
}
