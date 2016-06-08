
#include "hwlib.hpp"
#include "ostream"


int main(void)

{
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;   
   //auto adc0 = target::pin_adc( target::ad_pins::a0 );

 auto led = target::pin_out(target::pins::dac0);

  int h=200;
   for(;;)
    {
     led.set(h);
     hwlib::wait_ms(100);
     led.set(0);
     hwlib::wait_ms(100);
     h+=-50;
      
   }

   }
   
  
