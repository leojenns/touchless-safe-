#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#include "hwlib.hpp"
class keypad{
private: 
   int pad[4][4] = {{1,2,3,'A'},{4,5,6,'B'},{7,8,9,'C'},{'*', 0,'#','D'}};
hwlib::target::pin_in * row[4] ;
hwlib::target::pin_out * col[4];
public:

keypad(hwlib::target::pin_out & c1,hwlib::target::pin_out & c2,hwlib::target::pin_out & c3, hwlib::target::pin_out & c4 ,hwlib::target::pin_in & r1,hwlib::target::pin_in & r2,hwlib::target::pin_in & r3,hwlib::target::pin_in & r4);
int input();

};



#endif 