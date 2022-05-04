#include <Arduino.h>

#include "Wheels.h"
//
//#define SET_MOVEMENT(side,f,b) ( digitalWrite( side[0], f ) ); digitalWrite( side[1], b ) )

#define SET_MOVEMENT(side,f,b) digitalWrite( side[0], f);\
                               digitalWrite( side[1], b)
//#define HIGH 1
//#define LOW 0

//#define SET_MOVEMENT(s,f,b) delay(10);

Wheels::Wheels() 
{ }

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
    this->forwardLeft();
    this->forwardRight();
}

void Wheels::back()
{
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

void Wheels::goForward(int cm)
{
    this->cnt1 = 0;
    this->cnt0 = 0;
    //odległość na dziurkę 2*pi*r / 20
    int toGo = (int)(cm * 0.9) * 2;
    Serial.print("Forward holes");
    Serial.println(toGo);
    this->forward();
    while((this->cnt1+this->cnt0)/2 <= toGo) {
      
    }
    Serial.print("Forward after");
    Serial.println(this->cnt1);
    this->stop();
    this->cnt1 = 0;
    this->cnt0 = 0;
}

void Wheels::goBack(int cm)
{
    this->cnt1 = 0;
    this->cnt0 = 0;
    //odległość na dziurkę 2*pi*r / 20
    int toGo = (int)(cm * 0.9) * 2;

    this->back();
    while((this->cnt1+this->cnt0)/2 <= toGo) {
    }

    this->stop();
    this->cnt1 = 0;
    this->cnt0 = 0;
}

int Wheels::turnLeft(int angle)
{
    this->cnt1 = 0;
    this->cnt0 = 0;
  int toGo = (int)(this->holesPerAngle * (float)angle);
  Serial.print("Left before ");
  Serial.println(this->cnt0);
  this->backLeft();
  this->forwardRight();  

  while(this->cnt0 < toGo) {
  }

  this->stop();
  Serial.print("Left after ");
  Serial.println(this->cnt0);
    this->cnt1 = 0;
    this->cnt0 = 0;

  return toGo;
}

int Wheels::turnRight(int angle)
{
  //40 to 90
  //czyli mamy 4/9 obrót/stopień
    this->cnt1 = 0;
    this->cnt0 = 0;
  int toGo = (int)(this->holesPerAngle * (float)angle);
  Serial.print("Right before ");
  Serial.println(this->cnt1);
  this->backRight();
  this->forwardLeft();  

  while(this->cnt1 < toGo) {
  }

  this->stop();
  Serial.print("Right after ");
  Serial.println(this->cnt1);
  this->cnt1 = 0;

   return toGo;
}
