#include "hwlib.hpp"

int main(int argc, char **argv)
{
	 WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    
   auto  pir = hwlib::target::pin_in(hwlib::target::pins::d7);
   auto led =  hwlib::target::pin_out(hwlib::target::pins::d8);
    
    
    
    for(;;){
         if (pir.get() == 1){
             led.set(1);
           //  hwlib::wait_ms(100);
             hwlib::cout<<"criminal\n";
             led.set(0);
         }
        
        
        
        
    }
}
