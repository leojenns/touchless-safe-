/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              movement.hpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP
#include "hwlib.hpp"
/// class movement
//
/// reads pir sensor
class movement {
private:
/// reference to input_pin from the pir sensor
hwlib::target::pin_in & pir;
public:
/// the constructor
//
/// the constructor gets an reference from an input_pin .
movement(hwlib::target::pin_in & pir);
/// bool  get function;
//
/// function get  gives back an 1 if the pir sensor sees movement.
bool get();
};
#endif 