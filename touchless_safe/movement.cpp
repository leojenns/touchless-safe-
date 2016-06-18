#include "movement.hpp"
/// movement constructor needs one input pin used for the pir sensor
movement::movement(hwlib::target::pin_in & pir):
pir(pir){}
///  get function returns the value the pir sensor is giving
bool movement::get(){
    bool value = pir.get();
    return value;
    
}