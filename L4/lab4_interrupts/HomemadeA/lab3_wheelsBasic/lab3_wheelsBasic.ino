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
//  w.turnRight(90);
//  w.turnLeft(90);

   
}

void loop() {
w.journey();  
}
