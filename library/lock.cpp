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
see(pinin),move(pinout){}

void lock::open(){
    if (status==0){
        move.turnto0();
        status =1;
   }
}

void lock::close(){
    if (status==1){
        move.turnto90();
        status = 0;
    }
}


void lock::pir(){
    if(see.get() ==1){
        close();
        hwlib::cout<< "person detected\n";
        hwlib::wait_ms(1500);
    }
    
}

