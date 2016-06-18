#include "hwlib.hpp"
#include "movement.hpp"
int main(void)
{
	 WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    
   auto  pir = hwlib::target::pin_in(hwlib::target::pins::d7);
  // auto led =  hwlib::target::pin_out(hwlib::target::pins::d8);
    movement a(pir);
    
    
    for(;;){
         if (a.get() == 1){
             //led.set(1);
        //    hwlib::wait_ms(100);
             hwlib::cout<<"criminal\n";
         //    led.set(0);
         }
    }
}
