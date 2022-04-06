#include "Wheels.h"

#include "PinChangeInterrupt.h"

#define INTINPUT0 A0
#define INTINPUT1 A1

Wheels w;
volatile int cnt0, cnt1;

void setup() {
  w.attach(13,12,11,7,8,6);
  w.setSpeed(120);



  Serial.begin(9600);

  pinMode(INTINPUT0, INPUT);
  pinMode(INTINPUT1, INPUT);

  w.cnt0=0;
  w.cnt1=0;

  PCICR  = 0x02;  // włącz pin change interrupt dla 1 grupy (A0..A5)
  PCMSK1 = 0x03;  // włącz przerwanie dla A0, A1
  w.goForward(60);
}

void loop() {
  Serial.print(w.cnt0/2);
  Serial.print(" ");
  Serial.println(w.cnt1/2);
  delay(250);
}

ISR(PCINT1_vect) {
  if(digitalRead(INTINPUT0))
    w.cnt0++;
  if(digitalRead(INTINPUT1))
    w.cnt1++;
}
