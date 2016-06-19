/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              sound.hpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#ifndef SOUND_HPP
#define SOUND_HPP

#include "hwlib.hpp"
#include "sound.hpp"
/// microphone measure class
//
/// This class is for measuring the output of an 3pin ( vcc-gnd - a0)  microphone
class sound {
protected:
/// reference to analoge pin used for analoge to digital conversion
hwlib::target::pin_adc & adc;
///  integer array where the measurment are put in 
int measurment[5000];



public:
/// default constructor
//
/// this constructor gets and reference of the analoge pin where the microphone is plugged in.
sound(hwlib::target::pin_adc & adc);
/// measure function
//
/// default it will measure 5000 times and place the values into the array measerment[]
   virtual void measure();
   /// counter that has the length of the measurment[] array after an measurment
int array_number = 0;
   
};



#endif // sound.hpp