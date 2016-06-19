/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              pwm.hpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*   
* this code is made with uses of PWM_signal.hpp(file included in the directory ) written by Tim IJntema 
* the code is however bit different to work better in this library  
*
*                                                                                                                                                                                                                                                
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/

#ifndef PWM_HPP
#define PWM_HPP
#include "hwlib.hpp"
/// class for pwm signal
//
/// this class is for  pwm signals 
class pwm{
private:  
   /// reference to output pin 
    hwlib::target:: pin_out & pwmpin;
public:
/// default constructor
//
/// the cosnstructor sets an pin_out for the pwm signal used in this class
/// for this the reference to pin_out
    pwm(hwlib::target::pin_out & pwmpin);
    /// function for the pwm pulse
    //
    /// this function is for sending the pwm signal.
    virtual void pulse(int width);
};

#endif