#include "motor_g9.hpp"

motor::motor(hwlib::target::pin_out & pwmpin):
pwm(pwmpin){}

void motor::turn(int degrees){
    if (degrees< MIN || degrees > MAX ){
        return;
    }
    int width = ((degrees * 2170)/180);
    
    for (int i = 0; i<20;i++){
        pulse(width);
    }
}

void motor::turnto0(){
    turn(80);
    hwlib::wait_ms(500);
}
void motor::turnto90(){
    turn(170);
    hwlib::wait_ms(500);
}