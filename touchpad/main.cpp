#include "hwlib.hpp"
#include "touchless_safe.hpp"


int main(void)
{
     WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    hwlib::cout << "run\n";
    namespace target = hwlib::target;
auto col4 = target::pin_out( target::pins::d53);
auto col3  = target::pin_out( target::pins::d52);
auto col2  = target::pin_out( target::pins::d51);
auto col1  = target::pin_out( target::pins::d50);
auto row1  = target::pin_in( target::pins::d49);
auto row2  = target::pin_in( target::pins::d48);
auto row3  = target::pin_in( target::pins::d47);
auto row4  = target::pin_in( target::pins::d46);

keypad j(col1,col2,col3,col4,row1,row2,row3,row4);

j.input();

}



