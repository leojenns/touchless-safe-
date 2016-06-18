#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include "hwlib.hpp"
#include "touchless_safe.hpp"
class system{
private:
    lock p;
    keypad k;  
    whistle s;
  
public: 
        system(hwlib::target::pin_in & pir,hwlib::target::pin_out & mot,hwlib::target::pin_out & c1,hwlib::target::pin_out & c2,hwlib::target::pin_out & c3,hwlib::target::pin_out & c4,hwlib::target::pin_in & r1,hwlib::target::pin_in & r2,hwlib::target::pin_in & r3,hwlib::target::pin_in & r4, hwlib::target::pin_adc & adcj);
    
};



#endif 