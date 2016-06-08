#ifndef SOUND_HPP
#define SOUND_HPP

#include "hwlib.hpp"
#include "sound.hpp"
class whistle {
protected:
hwlib::target::pin_adc & adc;
int beat[100];
int beat_counter=0;
int sam;
int pass[100];
int pass_sum=0 ;


public:
whistle(hwlib::target::pin_adc & adc,int sam=1000);


   void measure();// measure is measuring the tones from the microphone and please the higer tones in beat[]
      
   
   void password();// making an password out of the numbers of the beat[]
    

   
   void unlock();
   
};



#endif 