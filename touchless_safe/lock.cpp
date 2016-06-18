#include "lock.hpp"

/// lock constructor needs one input pin and one output pin
lock::lock(hwlib::target::pin_out & pinout, hwlib::target::pin_in & pinin ):
/// the input pin will be send to see and the output pin will be send to move.
see(pinin),move(pinout){}
/// the open function opens the lock by first looking if the lock is actually closed and if that is true
/// the lock will start turnto0 function this will open the lock.
void lock::open(){
    if (status==0){
    move.turnto0();
    status =1;
    
    }
}
/// the close function closes the lock if the status of the lock is true by using the turnto90 function 
void lock::close(){
    if (status==1){
    move.turnto90();
    status = 0;
    }
    }

/// the pir function is an function that uses the pir sensor to look for movement and if their is movement then the lock will be closed.
void lock::pir(){
    if(see.get() ==1){
        close();
        hwlib::cout<< "person detected\n";
        status =0;
        hwlib::wait_ms(1000);
    }
    
}

