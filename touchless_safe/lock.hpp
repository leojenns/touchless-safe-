#ifndef LOCK_HPP
#define LOCK_HPP
#include "motor.hpp"
#include "movement.hpp"
#include "hwlib.hpp"
  
class lock {
	/// the lock class is for usig an servo and pir sensor in an combination to have an lock 
	
private:
/// needed for the class is an object form the movement class and we have called it see 
movement see;
/// also needed is an object from the motor class
motor move;
/// the bool status is needed to know what the status of the lock is (open or closed)
bool status;
public:
/// the constructor of the lock class needs two pins one output and one input. 
lock(hwlib::target::pin_out & pinout, hwlib::target::pin_in & pinin );
/// the function open : opens the lock
void open();
/// the function close: closes the lock 
void close();
/// the function pir : is een function that looks if their is movement and then will the functionn close the lock.
void pir();
    
};

#endif 