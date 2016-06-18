#include "movement.hpp"

movement::movement(hwlib::target::pin_in & pir):
pir(pir){}

bool movement::get(){
    bool value = pir.get();
    return value;
    
}