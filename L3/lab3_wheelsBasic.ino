#include "Wheels.h"


Wheels w;
volatile char cmd;

void setup() {
  // put your setup code here, to run once:
  w.attach(13,12,11,7,8,9);
  
  Serial.begin(9600);
  Serial.println("Forward: WAD");
  Serial.println("Back: ZXC");
  Serial.println("Stop: S");
  w.goForward(50);
  delay(100);
  w.goBack(50);
}

void loop() {
//  while(Serial.available())
//  {
//    cmd = Serial.read();
//    switch(cmd)
//    {
//      case 'w': w.forward(); break;
//      case 'x': w.back(); break;
//      case 'a': w.forwardLeft(); break;
//      case 'd': w.forwardRight(); break;
//      case 'z': w.backLeft(); break;
//      case 'c': w.backRight(); break;
//      case 's': w.stop(); break;
//      case '1': w.setSpeedLeft(75); break;
//      case '2': w.setSpeedLeft(200); break;
//      case '9': w.setSpeedRight(75); break;
//      case '0': w.setSpeedRight(200); break;
//      case '5': w.setSpeed(100); break;
//      case 'f': w.goForward(50); break;
//      case 'b': w.goBack(50); break;
//    }
//  }
}
