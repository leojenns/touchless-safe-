/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              motor_g9.hpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*   
* this code is made with uses of servo.hpp (file included in the directory ) written by Tim IJntema 
* the code is however bit different to work better in this library  and to make it work with the hardware used (servo 9g analog) 
* 
*
*                                                                                                                                                                                                                                                
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#ifndef MOTOR_G9_HPP
#define MOTOR_G9_HPP
#include "hwlib.hpp"
#include "pwm.hpp"
#define MAX 360
#define MIN 0
/// class for control of 9g_servo
//
///this class is an decorator class to the pwm class 
/// in this class the pulse function is used to create  the  signal used for the servo( 9g analog)
class motor : public pwm{
public:
    ///default constructor
    //
    /// the constructor gets an reference to the ouput pin used for the pwm signal used for the servo 
    motor(hwlib::target::pin_out & pwmpin);
    /// turn the servo to an desired amount of degrees.
    //
    /// turn function gets an amount of degrees and calculates the correct value for the wait in the pulse function 
    void turn(int degrees);
    /// turnto0 function
    //
    /// this function uses the turn function and is pre set to turn the servo to 0 degrees in contrast to the turnto90 function
    void turnto0();
    /// turnto0 function
    //
    /// this function uses the turn function and is pre set  to turn the servo to 90 degree in contrast to the turnto0 function 
    void turnto90();
};

#endif