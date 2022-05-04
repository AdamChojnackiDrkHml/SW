#include <Arduino.h>


#ifndef Wheels_h
#define Wheels_h



class Wheels {
    public: 
        Wheels();
        void attachRight(int pinForward, int pinBack, int pinSpeed);
        void attachLeft(int pinForward, int pinBack, int pinSpeed);
        void attach(int pinRightForward, int pinRightBack, int pinRightSpeed,
                    int pinLeftForward, int pinLeftBack, int pinLeftSpeed);
        void forward();
        void forwardLeft();
        void forwardRight();
        void back();
        void backLeft();
        void backRight();
        void stop();
        void stopLeft();
        void stopRight();
        void setSpeed(uint8_t);
        void setSpeedRight(uint8_t);
        void setSpeedLeft(uint8_t);
        void goForward(int cm);
        void goBack(int cm);
        float diameter = 6.1;
        float perHole = 3.14 * diameter / 20.0;
        float holesPerAngle = 4.0 / 9.0;
        volatile int cnt0, cnt1;
        int turnLeft(int angle);
        int turnRight(int angle);

    private: 
        int pinsRight[3];
        int pinsLeft[3];

        
};



#endif
