#include "Wheels.h"
// https://playground.arduino.cc/code/timer1
// Jeśli nie masz tej biblioteki, wybierz:
// Narzędzia->Zarządzaj bibliotekami, w oknie wyszukaj 
// bibliotekę TimerOne i zanistaluj.
//

Wheels w;

void setup() {
  // put your setup code here, to run once:
  w.attach(10,9,11,4,5,3);
  w.setSpeed(150);
}

void loop() {

}


