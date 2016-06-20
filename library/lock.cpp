/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              lock.cpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#include "lock.hpp"


lock::lock(hwlib::target::pin_out & pinout, hwlib::target::pin_in & pinin ):
motor(pinout),movement(pinin){}

void lock::open(){
    if (status==0){
        turnto0();
        status =1;
   }
}

void lock::close(){
    if (status==1){
        turnto90();
        status = 0;
    }
}


void lock::pir(){
    if(get() ==1){
        close();
        // wait for 1,5 second
        hwlib::wait_ms(1500);
    }
    
}

