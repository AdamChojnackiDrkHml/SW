#include "Wheels.h"
// https://playground.arduino.cc/code/timer1
// Jeśli nie masz tej biblioteki, wybierz:
// Narzędzia->Zarządzaj bibliotekami, w oknie wyszukaj 
// bibliotekę TimerOne i zanistaluj.
//


Wheels w;

void setup() {
  // put your setup code here, to run once:
  w.attach(10,12,11,7,8,6);
  w.setSpeed(150);

  w.back();
  delay(5000);
  w.forward();
}

void loop() {

}
