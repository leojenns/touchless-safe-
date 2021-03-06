/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              sound.cpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#include "sound.hpp"

sound::sound(hwlib::target::pin_adc & adc):
adc(adc){}


void sound::measure(){
    /// counter 
    int x=0;
    ///clean measurment 
    for (int ic = 0;ic<array_number;ic++){
        measurment[ic]=0;
    }
    
    array_number=0;
    
    while(x < 5000){  
        measurment[x] = adc.get();  
        x++;  
        array_number++;
   }

}
   