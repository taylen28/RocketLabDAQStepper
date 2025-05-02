#ifndef __STEPPER_H
#define __STEPPER_H
#include <cstdint>
extern "C" {
    #include "stm32f3xx_hal.h"
    
    }
class Stepper
{
    public:
    //constructor   
    Stepper(GPIO_TypeDef* stepPort, uint16_t stepPin, GPIO_TypeDef* dirPort, uint16_t dirPin, uint16_t stepPerRev = 200);

    void step(int steps); 
    void setSpeedRPM(uint16_t rpm);
    void stepAngle(double angle);

    
    private:
        GPIO_TypeDef* _stepPort;
        uint16_t _stepPin;

        GPIO_TypeDef* _dirPort;
        uint16_t _dirPin;

        int16_t _stepsPerRev;
        uint32_t _stepDelayMs;

};

#endif