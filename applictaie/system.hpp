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
#include "hwlib.hpp"
#include "admin.hpp"
#include "lock.hpp"
#include "keypad.hpp"
#include "profile.hpp"
#include "sound.hpp"
 class system{
private:
    profile &A;
    profile & B;
    profile &C;
    profile & D;
    admin & Q;
    keypad & k;
    lock & l;
    

public: 
system(hwlib::target::pin_adc & adc,keypad & k,lock & l);


void run();

 
 };

#endif