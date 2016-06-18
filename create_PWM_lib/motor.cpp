#include "motor.hpp"

motor::motor(hwlib::target::pin_out & pin):
mot(pin)
{}


void motor::turnto0(){
    mot.turnDegrees(80);
}
 void motor::turnto90(){
     mot.turnDegrees(170);
 }
 
 void motor::turntodesire(int degree){
     int degreemath=degree +80;
     mot.turnDegrees(degreemath);
 }