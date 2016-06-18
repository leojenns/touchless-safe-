#include "hwlib.hpp"
#include "lock.hpp"

int main(void)
{
    	auto servoPin = hwlib::target::pin_out(hwlib::target::pins::d7);
        auto  pir = hwlib::target::pin_in(hwlib::target::pins::d6);
lock l(servoPin,pir);
while(1){
    l.pir();

    l.open();

    
    
}
}
