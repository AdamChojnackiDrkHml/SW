/* 
 * prosta implementacja klasy obsługującej 
 * silniki pojazdu za pośrednictwem modułu L298
 *
 * Sterowanie odbywa się przez:
 * 1)  powiązanie odpowiednich pinów I/O Arduino metodą attach() 
 * 2)  ustalenie prędkości setSpeed*()
 * 3)  wywołanie funkcji ruchu
 *
 * TODO:
 *  - zabezpieczenie przed ruchem bez attach()
 *  - ustawienie domyślnej prędkości != 0
 */


#include <Arduino.h>


#ifndef Wheels_h
#define Wheels_h



class Wheels {
    public: 
        Wheels();
        /*
         *  pinForward - wejście "naprzód" L298
         *  pinBack    - wejście "wstecz" L298
         *  pinSpeed   - wejście "enable/PWM" L298
         */
        void attachRight(int pinForward, int pinBack, int pinSpeed);
        void attachLeft(int pinForward, int pinBack, int pinSpeed);
        void attach(int pinRightForward, int pinRightBack, int pinRightSpeed,
                    int pinLeftForward, int pinLeftBack, int pinLeftSpeed);
        void pause(uint16_t);
        /*
         *  funkcje ruchu
         */
        void forward();
        void forwardLeft();
        void forwardRight();
        void back();
        void backLeft();
        void backRight();
        void stop();
        void stopLeft();
        void stopRight();
         void goForward(uint8_t);
         void goBack(uint8_t);
         void moveForward(uint8_t);
         void moveBack(uint8_t);
         void turnLeft(uint8_t);
         void turnRight(uint8_t);
        void setSpeed(uint8_t);
        void setSpeedRight(uint8_t);
        void setSpeedLeft(uint8_t);
        void TimerUpdate();
        void TimerStop();
        static void doBeep();
        bool isAngleFree(int angle, int bonusTreshold);
        void resetSonarPosition();
        bool isFrontFree();
        void journey();
        void fun();

    private: 

        int pinsRight[3];
        int pinsLeft[3];
//        int cnt0;
//        int cnt1;
};



#endif
