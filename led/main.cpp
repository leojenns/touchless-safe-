
#include "hwlib.hpp"
#include "ostream"


int main(void)

{
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;   
   //auto adc0 = target::pin_adc( target::ad_pins::a0 );

 auto led = target::pin_out(target::pins::dac0);
int l =0;
  int h=4000;
   while(l<3)
    {
     led.set(h);
     hwlib::wait_ms(25);
  
     hwlib::wait_ms(25);
     h+=-50;
      l++;
   }
   led.set(0);
   }
   
  
