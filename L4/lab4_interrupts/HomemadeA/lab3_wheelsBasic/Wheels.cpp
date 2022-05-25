#include <Arduino.h>
#include <Servo.h>

#include "Wheels.h"
#include "PinChangeInterrupt.h"
#include "TimerOne.h"

#define INTINPUT0 A0
#define INTINPUT1 A1

#define BEEPER 13


// piny dla sonaru (HC-SR04)
#define TRIG A4
#define ECHO A5

// pin kontroli serwo (musi być PWM)
#define SERVO 9
int MIN_DISTANCE = 15;

Servo serwo;

//size_t cnt0;
//size_t cnt1;
int cnt0;
int cnt1;





long int intPeriod = 300000;


#define SET_MOVEMENT(side,f,b) digitalWrite( side[0], f);\
                               digitalWrite( side[1], b)



Wheels::Wheels() 
{ 
  cnt0=0;
  cnt1=0;
  Serial.begin(9500);
}


void increment() {
  if(digitalRead(INTINPUT1))
    cnt1++;
  if(digitalRead(INTINPUT0))
    cnt0++;
//  Serial.print(cnt0);
//  Serial.print(":");
//  Serial.println(cnt1);
}

void Wheels::attachRight(int pF, int pB, int pS)
{
    pinMode(pF, OUTPUT);
    pinMode(pB, OUTPUT);
    pinMode(pS, OUTPUT);
    this->pinsRight[0] = pF;
    this->pinsRight[1] = pB;
    this->pinsRight[2] = pS;
}


void Wheels::attachLeft(int pF, int pB, int pS)
{
    pinMode(pF, OUTPUT);
    pinMode(pB, OUTPUT);
    pinMode(pS, OUTPUT);
    this->pinsLeft[0] = pF;
    this->pinsLeft[1] = pB;
    this->pinsLeft[2] = pS;
}

void Wheels::setSpeedRight(uint8_t s)
{
    analogWrite(this->pinsRight[2], s);
}

void Wheels::setSpeedLeft(uint8_t s)
{
    analogWrite(this->pinsLeft[2], s);
}

void Wheels::setSpeed(uint8_t s)
{
    setSpeedLeft(s);
    setSpeedRight(s);
}

void Wheels::attach(int pRF, int pRB, int pRS, int pLF, int pLB, int pLS)
{
    this->attachRight(pRF, pRB, pRS);
    this->attachLeft(pLF, pLB, pLS);
    Serial.begin(9600);
    pinMode(INTINPUT0, INPUT);
    pinMode(INTINPUT1, INPUT);
    attachPCINT(digitalPinToPCINT(INTINPUT0), increment, CHANGE);
    attachPCINT(digitalPinToPCINT(INTINPUT1), increment, CHANGE);
    pinMode(BEEPER, OUTPUT);

    pinMode(TRIG, OUTPUT);    // TRIG startuje sonar
    pinMode(ECHO, INPUT);     // ECHO odbiera powracający impuls
    serwo.attach(SERVO);
      serwo.write(0);
      delay(1000);
    /* patrz przed siebie */
    resetSonarPosition();
    setSpeed(100);
}

void Wheels::forwardLeft() 
{
    SET_MOVEMENT(pinsLeft, HIGH, LOW);
}

void Wheels::forwardRight() 
{
    SET_MOVEMENT(pinsRight, HIGH, LOW);
}

void Wheels::backLeft()
{
    SET_MOVEMENT(pinsLeft, LOW, HIGH);
}

void Wheels::backRight()
{
    SET_MOVEMENT(pinsRight, LOW, HIGH);
}

void Wheels::forward()
{
    Serial.println("GOING");

    this->forwardLeft();
    this->forwardRight();
}

void Wheels::back()
{
  Serial.println("BACKING");

    this->backLeft();
    this->backRight();
    
}

void Wheels::stopLeft()
{
    SET_MOVEMENT(pinsLeft, LOW, LOW);
}

void Wheels::stopRight()
{
    SET_MOVEMENT(pinsRight, LOW, LOW);
}

void Wheels::stop()
{

    this->stopLeft();
    this->stopRight();
}

//  PAUSE
void Wheels::pause(uint16_t ms) {
  unsigned long begin, end;
  begin = millis();
  do {
    end = millis();
  } while (end - begin < ms);
}

void Wheels::goForward(uint8_t cm)
{
    setSpeed(150);
    forward();
    pause(13*cm);
    stop();
}

void Wheels::goBack(uint8_t cm)
{
    setSpeed(150);
    back();
    pause(13*cm);
    stop();
    //delay
}

void Wheels::moveForward(uint8_t cm)
{
  setSpeed(150);
  forward();
  cnt0=0;
  cnt1=0;
  uint16_t time = (100*cm)/45;
  while(cnt0 <= time) {
//    if (cnt0 > 50) break;
    Serial.println(cnt0);
//    Serial.println(cnt0);
  }
  stop();
}

void Wheels::moveBack(uint8_t cm)
{
  setSpeed(150);
  back();
  cnt0=0;
  cnt1=0;
  uint16_t time = (100*cm)/45;
  while(cnt0 <= time) {
//    if (cnt0 > 50) break;
    Serial.print("");
//    Serial.println(cnt0);
  }
  stop();
}

void Wheels::turnLeft(uint8_t degree)
{
  setSpeed(220);
  forwardRight();
  backLeft();
  cnt0=0;
  cnt1=0;
  uint16_t time = degree/3;
  while(cnt1 <= time) {
//    if (cnt0 > 50) break;
    Serial.print("");
//    Serial.print(cnt0);
//    Serial.print("-");
//    Serial.println(cnt1);
  }
  stop();
  setSpeed(100);
}

void Wheels::turnRight(uint8_t degree)
{
  setSpeed(220);
  forwardLeft();
  backRight();
  cnt0=0;
  cnt1=0;
  uint16_t time = degree/3;
  while(cnt1 <= time) {
//    if (cnt0 > 50) break;
    Serial.print("");
//    Serial.print(cnt0);
//    Serial.print("-");
//    Serial.println(cnt1);
  }
  stop();
  setSpeed(100);
}

// zmienia wartość pinu BEEPER



bool Wheels::isAngleFree(int angle, int bonusTreshold) {
  unsigned long tot;      // czas powrotu (time-of-travel)
  unsigned int distance;
  Serial.println(angle);
  serwo.write(angle);
  delay(500);
/* uruchamia sonar (puls 10 ms na `TRIGGER')
 * oczekuje na powrotny sygnał i aktualizuje
 */
  digitalWrite(TRIG, HIGH);
  delay(10);
  digitalWrite(TRIG, LOW);
  tot = pulseIn(ECHO, HIGH);

/* prędkość dźwięku = 340m/s => 1 cm w 29 mikrosekund
 * droga tam i z powrotem, zatem:
 */
  distance = tot/58;
  Serial.println(distance);
  if (distance != 0 && distance < MIN_DISTANCE + bonusTreshold) return false;
  return true;
}

void Wheels::resetSonarPosition() {
  Serial.println("RESETING");
  serwo.write(90);
  delay(500);
}


void Wheels::journey() {
  bool freeAngles[3] = {false};
 
  resetSonarPosition();
  forward();
  while (isAngleFree(90, 0)) {
    pause(10);
  }

  Serial.println("Przeszkoda");
  stop();


  for (int i = 0; i < 3; i++) {
   freeAngles[i] = isAngleFree(i*90, 0);

   Serial.print("Angle");
   Serial.print(i);
   Serial.print(": ");
   Serial.println(freeAngles[i]);
   
  }

  int counter = 0;
  resetSonarPosition();
  if (freeAngles[0])
  {
    counter = 0;
    turnRight(90);
  }
  else if (freeAngles[2])
  {
    counter = 2;
     turnLeft(90);
  }
  else if (!freeAngles[1])
  {
    moveBack(20);
    counter = 1;
  }

  forward();
  while (!isAngleFree(90 * counter, 10)) {
    pause(20);
  }

  if(counter == 0)
  {
    turnLeft(90);
  }
  else if(counter == 2)
  {
    turnRight(90);
  }

 
  Serial.println("Rozwiazano");
}
