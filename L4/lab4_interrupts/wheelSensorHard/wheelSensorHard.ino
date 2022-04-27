#include "Wheels.h"

#include "PinChangeInterrupt.h"

#define INTINPUT0 A0
#define INTINPUT1 A1

Wheels w;

void setup() {
  w.attach(13,12,11,7,8,6);
  w.setSpeed(250);



  Serial.begin(9600);

  pinMode(INTINPUT0, INPUT);
  pinMode(INTINPUT1, INPUT);

  w.cnt0=0;
  w.cnt1=0;

  PCICR  = 0x02;  // włącz pin change interrupt dla 1 grupy (A0..A5)
  PCMSK1 = 0x03;  // włącz przerwanie dla A0, A1
//  w.goForward(50);
//  delay(200);
//  w.goBack(50);
  w.turnLeft();
  Serial.println("a");
  delay(500);
  w.turnRight();
  Serial.println("a");
  delay(500);

}

void loop() {

}

ISR(PCINT1_vect) {
  
  if(digitalRead(INTINPUT0))
    w.cnt0++;
   
  if(digitalRead(INTINPUT1))
    w.cnt1++;
}
