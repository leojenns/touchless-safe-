#include "hwlib.hpp"

int main(void)
{
	 WDT->WDT_MR = WDT_MR_WDDIS;
auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl1);
auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda1);
auto i2c = hwlib::i2c_bus_bit_banged_scl_sda ( scl,sda);



 const byte   l = 0x0E;
 for(;;){
i2c.write(0x03,&l,5);
    
    
 }
        
        
        
        
    }

