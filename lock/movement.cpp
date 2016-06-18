#include "movement.hpp"

movement::movement(hwlib::target::pin_in & pir):
pir(pir){}

bool movement::get(){
    if (pir.get() == 1){
        return 1;
    }
    else{
        return 0;
    }
    
    
    
    
}