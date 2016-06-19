/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              profile.hpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#ifndef PROFILE_HPP
#define PROFILE_HPP

#include "keypad.hpp"
#include "sound_lock.hpp"
#include "sound.hpp"
#include "hwlib.hpp"
#include "password.hpp"
#include "lock.hpp"
#include "touchless_safe.hpp"
/// class profile 
//
/// this class is an decorator for the soundlock class so it is possible to have different passwords on the same lock 
class profile : public soundlock{
protected:
/// password p
//
/// the password that belongs to the profile
    password p;
    /// reference to keypad
    keypad & k;
/// bool set_p
//
/// ths bool is for the status if the password is already set or not 

    bool set_p=0;
/// bool set_p_run
//
/// this bool is for the status  if the password is beeing set at the moment .
    bool set_p_run=0;
/// function set_password 
//
///this function is the override for the virtual set_password function in soundlock
/// it set the password p by measuring 6x times and makingfrom tht the password.
    void set_password()override  ;
 /// funtion math_password
 //
 ///this function is the override for the virtual math _password function in soundlock
 /// the calculation makes from the 1000 measure numbers ( see measure function ) 
 /// an password
 /// and pleases it into the temporary password temp;
    void math_password()override ;
/// funcion measure
//
 ///this function is the override for the virtual measre function in sound
 /// 
 /// it measures 100.000 times and it amplifies the usable numbers and after that it transforms it into an 
 /// integer array measurment[] containing 1000 numbers 
    void measure()override;
public:
/// default constructor 
//
/// the constuctor gets an reference to an analog pin used for analog to digital conversion and anreference to an  lock needed for the soundlock function.

 profile(hwlib::target::pin_adc & adc,   lock & l,keypad & k);
 /// function compare_password 
 //
 ///this function is the override for the virtual compare _password function in soundlock
 //
 ///this function compares the temp password with the set password p.
 /// if there isn't set an password then it redirect to set_password function 
  void compare_password() override;
  
    
};


#endif