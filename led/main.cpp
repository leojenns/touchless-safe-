
#include "hwlib.hpp"
#include "ostream"


int main(void)

{
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;   
   //auto adc0 = target::pin_adc( target::ad_pins::a0 );
   auto button = target::pin_in(target::pins::d8);


  
   for(;;)
    {
     
             if (button.get() ==0){
                 hwlib::cout<< "pussed button";
             }
       
   }

   }
   
  
