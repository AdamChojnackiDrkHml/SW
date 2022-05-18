#include "Wheels.h"
// https://playground.arduino.cc/code/timer1
// Jeśli nie masz tej biblioteki, wybierz:
// Narzędzia->Zarządzaj bibliotekami, w oknie wyszukaj 
// bibliotekę TimerOne i zanistaluj.
//


Wheels w;

void setup() {
  // put your setup code here, to run once:
  w.attach(10,12,5,7,8,6);
  w.setSpeed(100);

    w.journey(); 
}

void loop() {

}
