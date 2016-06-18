#ifndef SOUND_HPP
#define SOUND_HPP

#include "hwlib.hpp"
#include "sound.hpp"
class sound {
protected:
hwlib::target::pin_adc & adc;
int measurment[5000];
int array_number = 0;


public:
sound(hwlib::target::pin_adc & adc);


   virtual void measure();// measuring the sound 
   
};



#endif 