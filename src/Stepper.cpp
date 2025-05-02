#include "Stepper.h"
#include <cmath>

Stepper::Stepper(GPIO_TypeDef* stepPort, uint16_t stepPin, GPIO_TypeDef* dirPort, 
    uint16_t dirPin, uint16_t stepPerRev = 200)
    {
        _stepPort = stepPort;
        _stepPin = stepPin;
        _dirPort = dirPort;
        _dirPin = dirPin;
        _stepPerRev = stepPerRev;
        _stepdelayMs = 10;
    }

void Stepper::step(int steps)
{   
    //dirpin conditionals sets the direction if + it goes forward if - it goes backwards therfore uses dir
    if(steps == 0)
    {
        return
    }
    if(steps > 0 )
    {
        HAL_GPIO_WritePin(dirPort, dirPin, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(dirPort, dirPin, GPIO_PIN_RESET);
    }
    steps = std::abs(steps);
    for(size_t i = 0; i < steps; ++i)
    {
        HAL_GPIO_WritePin(stepPort, stepPin, GPIO_PIN_SET);
        HAL_Delay(_stepDelayMs / 2);
        HAL_GPIO_WritePin(stepPort, stepPin, GPIO_PIN_SET);
        HAL_Delay(_stepDelayMs / 2);

    }
}
void Stepper::setSpeedRPM(uint16_t rpm)
{

}
void Stepper::stepAngle(double angle)
{

}

