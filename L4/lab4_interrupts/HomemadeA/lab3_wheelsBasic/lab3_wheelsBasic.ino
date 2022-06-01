#include "Wheels.h"
#include <IRremote.h>
// https://playground.arduino.cc/code/timer1
// Jeśli nie masz tej biblioteki, wybierz:
// Narzędzia->Zarządzaj bibliotekami, w oknie wyszukaj 
// bibliotekę TimerOne i zanistaluj.
//
int input_pin = 3; // wpisujemy nazwę pinu, po którym nastepuje komunikacja
IRrecv irrecv(input_pin);
decode_results signals;
enum Direction {up, down, left, right, no};
Direction currentDir = no;

Wheels w;

void setup() {
  // put your setup code here, to run once:
  w.attach(10,12,5,7,8,6);
    Serial.begin(9600);
    irrecv.enableIRIn(); // włączenie odbierania danych

   
}

void loop() {
    if (irrecv.decode(&signals)) {
        Serial.println(signals.decode_type); // typ nadajnika
        Serial.print(F("wynik = 0x"));
        Serial.println(signals.value, HEX); // wynik w systemie szesnatkowym
        Serial.println(signals.bits); // ilość przesłanych danych
        irrecv.blink13(true); // mrugamy diodami w arduino
        
        // Przykładowe porównanie:
//        if (signals.value == 0xFFFFFFFF)
//        {
//          Serial.println("INHERE");
//          unsigned int timer = millis(); 
//          while(signals.value == 0xFFFFFFFF)
//          {
//            Serial.println(currentDir);
//            switch(currentDir) {
//              case up: w.forward(); Serial.println("jazda w górę"); break;
//              case down: w.back(); Serial.println("jazda w dół"); break;
//              case left: w.left(); Serial.println("jazdaw w lewo"); break;
//              case right: w.right(); Serial.println("jazda w prawo"); break;
//              case no: break;
//            }
//            irrecv.resume();
//            if(irrecv.decode(&signals))
//            {
//              Serial.println("in decode if");
//              if (signals.value != 0xFFFFFFFF)
//              {
//                irrecv.resume();
//                currentDir = no;
//                break;
//              }
//              timer = millis();
//            }
//            if(millis() - timer >= 1000)
//            {
//              break;
//            }
//            signals.value = 0xFFFFFFFF;
//          }
//          currentDir = no;
//          w.stop();
//          irrecv.resume();
//        }
        if (signals.value == 0xFF18E7)
        {
          w.forwardWithStop();
          Serial.println("Wcisnieto klawisz góra");
        }
        if (signals.value == 0xFF4AB5)
        {
          w.back();
          Serial.println("Wcisnieto klawisz dół");
        }
        if (signals.value == 0xFF10EF)
        {
          w.left();
          Serial.println("Wcisnieto klawisz lewo");
        }
        if (signals.value == 0xFF5AA5)
        {
          w.right();
          Serial.println("Wcisnieto klawisz prawo");
        }
        if(signals.value == 0xFF38C7)
        {
          w.stop();
          Serial.println("Stop");
        }
        
        
        // ... i tak dalej
        
        irrecv.resume(); // nasłuchujemy na następne nadanie     
    } 

}
