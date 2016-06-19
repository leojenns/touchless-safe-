
/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              soundlock.hpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#ifndef SOUND_LOCK_HPP
#define SOUND_LOCK_HPP

#include "sound.hpp"
#include "hwlib.hpp"
#include "password.hpp"
#include "lock.hpp"
#include "touchless_safe.hpp"
/// soundlock class 
//
///  decorator class to the sound class 
/// for controllling an lock
class soundlock :public sound{
protected:
/// temparary  password for comparing an setting password.
password temp;
/// reference to an lock that is needed for controlling 
 lock & l;

public:
/// default constructor
//
/// theconstructor gets an reference to an analog port that is used for the analog to digital  conversion .
/// and a reference to an lock that is used to control.
  soundlock(hwlib::target::pin_adc & adc,   lock & l);
  /// vitual fuction  math_password
  //
  /// default doing nothing can be set for calculating password for lock 
 virtual void math_password()=0;
///virtual fuction  set_passsword
//
/// default doing nothing can be set for setting te password for the lock 
   virtual void set_password()=0;
/// virtual function compare_password
//
///default doing nothing can be set for comparing password with input
   virtual void compare_password()=0;// comparing the measured sound with the pre_set password
   
   

    
};





#endif