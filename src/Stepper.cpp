#include "Stepper.h"
#include <cmath>

Stepper::Stepper(GPIO_TypeDef* stepPort, uint16_t stepPin, GPIO_TypeDef* dirPort, uint16_t dirPin, uint16_t stepPerRev = 200);

void Stepper::step(int steps); 
void Stepper::setSpeedRPM(uint16_t rpm);
void Stepper::stepAngle(double angle);

