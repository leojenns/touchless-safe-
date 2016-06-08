#include "hwlib.hpp"
#include "servo.hpp"

//make decorator?

//between 180 and 110 for the lock 

int main()
{
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	auto servoPin = hwlib::target::pin_out(hwlib::target::pins::d2);
	//auto checkerPin = hwlib::target::pin_in(hwlib::target::pins::d3);
	
	servo servo1(servoPin);
	while(1) {
		servo1.turnDegrees(70);
		hwlib::wait_ms(1000);
		servo1.turnDegrees(180);
		hwlib::wait_ms(1000);
	}
	
	return 0;
}