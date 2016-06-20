/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              motor_g9.cpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*   
* this code is made with uses of servo.cpp(file included in the directory ) written by Tim IJntema 
* the code is however bit different to work better in this library  and to make it work with the hardware used (servo 9g analog) 
*
*                                                                                                                                                                                                                                                
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#include "motor_g9.hpp"

motor::motor(hwlib::target::pin_out & pwmpin):
pwm(pwmpin){}

void motor::turn(int degrees){
    if (degrees< MIN || degrees > MAX ){
        return;
    }
    int width = ((degrees * 2100)/180);
    
    for (int i = 0; i<20;i++){
        pulse(width);
    }
}

void motor::turnto0(){
    turn(80);
    //wait for 0.5 second
    hwlib::wait_ms(500);
}
void motor::turnto90(){
    turn(170);
    //wait for 0.5 second
    hwlib::wait_ms(500);
}