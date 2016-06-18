#ifndef SOUND_LOCK_HPP
#define SOUND_LOCK_HPP
#include "sound.hpp"
#include "hwlib.hpp"
#include "password.hpp"
#include "lock.hpp"
#include "touchless_safe.hpp"
class soundlock :public sound{
protected:
//password p;
password temp;
//bool set_p=0;
//bool set_p_run=0;
 lock & l;
  
public:
  soundlock(hwlib::target::pin_adc & adc,   lock & l);
 virtual void math_password();// calculating the password from the set 
   virtual void set_password();
   virtual void compare_password();// comparing the measured sound with the pre_set password
   
   

    
};





#endif