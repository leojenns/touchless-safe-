/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              pwm.cpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*   
* this code is made with uses of PWM_signal.cpp(file included in the directory ) written by Tim IJntema 
* the code is however bit different to work better in this library  
*
*                                                                                                                                                                                                                                                
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#include "pwm.hpp"


pwm::pwm( hwlib::target::pin_out & pwmpin):
pwmpin(pwmpin){}

void pwm::pulse(int width){
    pwmpin.set(1);
	hwlib::wait_us(width);
	pwmpin.set(0);
	hwlib::wait_ms(19);
    
}