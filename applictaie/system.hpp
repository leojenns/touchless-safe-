/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              system.hpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "profile.hpp"

#include "hwlib.hpp"

#include "touchless_safe.hpp"

/// system class
//
/// class that act as an application  that runs with use of this library
class system{
protected:
///three  profiles
//
profile A,A1,A2;
/// admin
admin AD;
/// reference to keyboard
keypad & k;
///reference to lock
lock & l;
public:
/// default constructor
//
/// this constructor gets an analog pin that is used for analog to digital conversion.
/// second it gets an reference to keypad that is installed .
/// third it gets an reference to lock that is installed
system(hwlib::target::pin_adc & adc, keypad & k, lock & l);
/// start function
//
/// this function starts the system and contains an basic menu
/// where the user can choise an profile or admin
/// also it includes the pir function from the lock 
/// that detects movement and closes the lockwhen there is detection.
void start();
    
    
    
};
#endif