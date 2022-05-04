#include "Wheels.h"

#include "PinChangeInterrupt.h"

#define INTINPUT0 A0
#define INTINPUT1 A1
int lastInput0 = 0;
int lastInput1 = 0;
Wheels w;
void setup() {
  w.attach(13,12,11,7,8,6);
  w.setSpeed(250);



  Serial.begin(9600);

  pinMode(INTINPUT0, INPUT);
  pinMode(INTINPUT1, INPUT);

  w.cnt0=0;
  w.cnt1=0;
 attachPCINT(digitalPinToPCINT(INTINPUT0), increment, CHANGE);
 attachPCINT(digitalPinToPCINT(INTINPUT1), increment, CHANGE);
//  w.goForward(50);
//  delay(200);
//  w.goBack(50);
  w.goForward(75);
  delay(1000);
  w.goBack(25);
  delay(1000);
//  Serial.println(w.turnLeft(90));
//  delay(500);
//  w.goForward(20);
//  delay(500);
//  Serial.println(w.turnRight(90));
//  delay(500);
//  w.goForward(20);
//  delay(500);
//   Serial.println(w.turnRight(90));
//  delay(500);
//  w.goForward(20);
//  delay(500);
//  Serial.println(w.turnLeft(90));
//  delay(500);
//  w.goForward(50);
//  delay(500);  
}

void loop() {
  Serial.print("ctn0 = ");
  Serial.println(w.cnt0);
  
  Serial.print("ctn1 = ");
  Serial.println(w.cnt1);
  delay(100);
}

void increment() {
  int input0 = digitalRead(INTINPUT0);
  int input1 = digitalRead(INTINPUT1);
  if(input0 != lastInput0)
  {
    lastInput0 = input0;
    w.cnt0++;
  }
  if(input1 != lastInput1)
  {
    lastInput1 = input1;
    w.cnt1++;
  }
}
