#include "system.hpp"

system::system(hwlib::target::pin_in & pir,hwlib::target::pin_out & mot,hwlib::target::pin_out & c1,hwlib::target::pin_out & c2,hwlib::target::pin_out & c3,hwlib::target::pin_out & c4,hwlib::target::pin_in & r1,hwlib::target::pin_in & r2,hwlib::target::pin_in & r3,hwlib::target::pin_in & r4, hwlib::target::pin_adc & adcj ):
p(mot,pir),
k(c1,c2,c3,c4,r1,r2,r3,r4), 
s(adcj)
{}

