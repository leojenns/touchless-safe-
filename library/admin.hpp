/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              admin.hpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "keypad.hpp"
#include "sound.hpp"
#include "hwlib.hpp"
#include "password.hpp"
#include "lock.hpp"

/// class admin
//
/// this class is an decorator for the soundlock class so it is possible to have different passwords on the same lock 
class admin {
protected:
/// password p
//
/// the password that belongs to the admin
    password p = password(1,2,3,4);
/// reference to lock

     lock & l;
     /// reference to keypad
    keypad & k;
/// bool function for admin login
   
    
bool  admin_login(password & t);

public:

 admin(lock & l,keypad & k);
/// admin_menu function
//
/// this function is the menu for admin
  void admin_menu();  
  /// admin_wait function 
  //
  /// keep lock closed until password is put in 
  void admin_wait();
};


#endif