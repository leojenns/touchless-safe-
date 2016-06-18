#ifndef MOTOR_G9_HPP
#define MOTOR_G9_HPP
#include "hwlib.hpp"
#include "pwm.hpp"
#define MAX 360
#define MIN 0

class motor : public pwm{
public:
    
    
    motor(hwlib::target::pin_out & pwmpin);
    void turn(int degrees);
    void turnto0();
    void turnto90();
};

#endif