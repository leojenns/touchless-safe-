#include "hwlib.hpp"
#include "servo.hpp"
#include "motor.hpp"

int main()
{
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	auto servoPin = hwlib::target::pin_out(hwlib::target::pins::d2);

	
	motor d(servoPin);
	while(1) {
	d.turnto0();
    hwlib::wait_ms(1000);
    d.turnto90();
	}
	
	return 0;
}
