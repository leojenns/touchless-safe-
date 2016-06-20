/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              lock.hpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/

#ifndef LOCK_HPP
#define LOCK_HPP
#include "motor_g9.hpp"
#include "movement.hpp"
#include "hwlib.hpp"
/// lock class 
//
/// lock class combine motor class (servo) with movement class(pir)
class lock:public motor ,movement {
private:
/// movement see
//
///movement see is for the pir sensor used in this class 
//movement see;
/// motor move 
//
/// motor move  is  the servo used in this class to open and close.
//motor move;
/// bool status
//
/// this bool indicates the status of the  lock (open or close).
bool status=0;
public:
/// default constructor
//
/// the constructor gets a pin_out reference for the motor (move)  and 
///  a pin_in reference for the movement (see).
lock(hwlib::target::pin_out & pinout, hwlib::target::pin_in & pinin );
///  open function
//

/// this function  opens the lock if the lock is closed .
///  it turns the motor to 0 degrees by using the turnto0 function.
/// the function is virtual so it is possible to have an different  set up with the lock 

 void open();
///   close function
//

///default : this function closes the lock if the lock is open . 
///  it turns the motor to 90 degrees by using the turnto90 function.
/// the function is virtual so it is possible to have an different  set up with the lock 
 void close();
///   pir function
//
/// this function closes the lock when someone is moving by and  if the lock is open at that moment 
 void pir();
    
};

#endif 