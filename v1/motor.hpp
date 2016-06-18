#ifndef MOTOR_HPP
#define MOTOR_HPP
#include "hwlib.hpp"
#include "servo.hpp"


class motor{
private:
    servo mot;
public:

motor(hwlib::target::pin_out & pin);
void turnto0();
void turnto90();
void turntodesire(int degree);

};
#endif 