#ifndef SOUND_HPP
#define SOUND_HPP
# define test_4_size  30
#include "hwlib.hpp"
#include "sound.hpp"
class whistle {
protected:
hwlib::target::pin_adc & adc;
int beat[1000];
int beat_counter=0;
int sam;
int pass[1000];
int pass_sum=0 ;
int pass_counter=0;

public:
whistle(hwlib::target::pin_adc & adc);


   void measure();// measure is measuring the tones from the microphone and please the higer tones in beat[]
   void password();// making an password out of the numbers of the beat[]
   void unlock(); // unlocking the lock by using of sound from beat[]
   
};



#endif 