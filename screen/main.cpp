#include "hwlib.hpp"



int main(void)
{
    hwlib::wait_ms(1000);
	 WDT->WDT_MR = WDT_MR_WDDIS;
auto rs =  hwlib::target::pin_out(hwlib::target::pins::d12);
auto e =  hwlib::target::pin_out(hwlib::target::pins::d12);
auto d4 = hwlib::target::pin_out(hwlib::target::pins::d5);
auto d5 = hwlib::target::pin_out(hwlib::target::pins::d4);
auto d6 = hwlib::target::pin_out(hwlib::target::pins::d3);
auto d7 = hwlib::target::pin_out(hwlib::target::pins::d2);
auto port = hwlib::port_out_from_pins(d4,d5,d6,d7);
auto screen = hwlib::hd44780(rs,e,port,4,20);
for(;;){
screen.clear();
hwlib::wait_ms(1000);
screen.data('k');

}
    }

