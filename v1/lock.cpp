#include "lock.hpp"


lock::lock(hwlib::target::pin_out & pinout, hwlib::target::pin_in & pinin ):
see(pinin),move(pinout){}

void lock::open(){
    if (status==0){
    move.turnto0();
    status =1;
    
    }
}
void lock::close(){
    if (status==1){
    move.turnto90();
    status = 0;
    }
    }


void lock::pir(){
    if(see.get() ==1){
        close();
        hwlib::cout<< "person detected\n";
        status =0;
        hwlib::wait_ms(2000);
    }
    
}

