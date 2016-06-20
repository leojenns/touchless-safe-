/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              keypad.hpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#include "hwlib.hpp"
/// keypad class 
//
/// class for the reading of an 4x4 matrix keypad 
class keypad{
private: 
/// integer matrix with the values that ar equal on the keypad
   int pad[4][4] = {{1,2,3,'A'},{4,5,6,'B'},{7,8,9,'C'},{'*', 0,'#','D'}};
   /// list of four input pins that are for the rows of the keypad.
    hwlib::target::pin_in * row[4] ;
    /// list of four output pins that are the colloms of hte keypad.
    hwlib::target::pin_out * col[4];
public:
/// the default constructor
//
/// the constructor gets eigth pins in referrence four pins are input and four pins are output.
    keypad(hwlib::target::pin_out & c1,hwlib::target::pin_out & c2,hwlib::target::pin_out & c3, hwlib::target::pin_out & c4 ,hwlib::target::pin_in & r1,hwlib::target::pin_in & r2,hwlib::target::pin_in & r3,hwlib::target::pin_in & r4);

/// int input function.
//
/// gives the value back that the position contains out the matrix that is equal to the position that is pressed.
/// the colloms are set low one at the time .
/// the row that outputs low is the presssed key
    int input();
/// int input function.
//
/// gives the value back that the position contains out the matrix that is equal to the position that is pressed 
/// deferend with void input() is this function_waits until key is pressed.
/// the colloms are set low one at the time .
/// the row that outputs low is the presssed key
    int input_wait();
};



#endif //keypad.hpp