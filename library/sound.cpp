#include "sound.hpp"


sound::sound(hwlib::target::pin_adc & adc):
adc(adc){}


   void sound::measure(){// measure is measuring the tones from the microphone and please the higer tones in beat[]

    int x=0;
    for (int ic = 0;ic<array_number;ic++){
        measurment[ic]=0;
        
    }
    array_number=0;
    while(x < 5000){  



measurment[x] = adc.get();  
   x++;  
   }
   
   return;
   }
   