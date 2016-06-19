#include "pwm.hpp"


pwm::pwm( hwlib::target::pin_out & pwmpin):
pwmpin(pwmpin){}

void pwm::pulse(int width){
    pwmpin.set(1);
	hwlib::wait_us(width);
	pwmpin.set(0);
	hwlib::wait_ms(19);
    
}