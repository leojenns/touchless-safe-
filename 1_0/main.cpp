#include "hwlib.hpp"

#include "touchless_safe.hpp"
int main(void)
{
    
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    hwlib::cout << "run\n";
    namespace target = hwlib::target;
    bool meet = 0;
    bool w8woord = 0;
    bool lock = 0;
    auto adc0 = target::pin_adc( target::ad_pins::a0 );
    
whistle A(10000);
auto button  = target::pin_in( target::pins::d8);
auto button1  = target::pin_in( target::pins::d9);
auto button2  = target::pin_in( target::pins::d10);

auto col4 = target::pin_out( target::pins::d53);
auto col3  = target::pin_out( target::pins::d52);
auto col2  = target::pin_out( target::pins::d51);
auto col1  = target::pin_out( target::pins::d50);
auto row1  = target::pin_in( target::pins::d49);
auto row2  = target::pin_in( target::pins::d48);
auto row3  = target::pin_in( target::pins::d47);
auto row4  = target::pin_in( target::pins::d46);

keypad j(col1,col2,col3,col4,row1,row2,row3,row4);

while(1){
value 
    
if (button.get() == 0){
meet  = 1;
}
if(button1.get() == 0){
    w8woord = 1;
}
if (button2.get() == 0){
    lock = 1;
}
if (meet  ==1){
    A.measure(adc0);
    meet = 0;
}
else if (w8woord ==1){
    A.password();
    w8woord = 0;
}
else if (lock == 1){
    A.unlock();
    lock = 0;
}
}
}