#ifndef PROFILE_HPP
#define PROFILE_HPP


#include "sound_lock.hpp"
#include "sound.hpp"
#include "hwlib.hpp"
#include "password.hpp"
#include "lock.hpp"
#include "touchless_safe.hpp"

class profile : public soundlock{
protected:
    password p;
bool set_p=0;
bool set_p_run=0;
 void set_password()override  ;
void math_password()override ;// calculating the password from the set 
void measure()override;
public:
 profile(hwlib::target::pin_adc & adc,   lock & l);
  void compare_password() override;// comparing the measured sound with the pre_set password
  
    
};


#endif