#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#include "hwlib.hpp"
class keypad{
	/// the keypad class reads an 4x4 keyboard
	/// 
private: 
/// an matrix is aplied to see what every button means and to get the correct value 
   int pad[4][4] = {{1,2,3,'A'},{4,5,6,'B'},{7,8,9,'C'},{'*', 0,'#','D'}};
/// an list of 4 pins as input for the rows.
hwlib::target::pin_in * row[4] ;
/// an list of 4 pins as output for the colloms.
hwlib::target::pin_out * col[4];
public:
/// the constructor of the keypad class aplies 4 pins input and 4 pins output 
keypad(hwlib::target::pin_out & c1,hwlib::target::pin_out & c2,hwlib::target::pin_out & c3, hwlib::target::pin_out & c4 ,hwlib::target::pin_in & r1,hwlib::target::pin_in & r2,hwlib::target::pin_in & r3,hwlib::target::pin_in & r4);

/// input function: get is getting the value of the pressed button.
int input();
    
    
    
    
    
    
};



#endif 