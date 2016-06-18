#ifndef PWM_HPP
#define PWM_HPP
#include "hwlib.hpp"

class pwm{
   private:  
    hwlib::target:: pin_out & pwmpin;
public:
    pwm(hwlib::target::pin_out & pwmpin);
    
    
    virtual void pulse(int width);
};

#endif