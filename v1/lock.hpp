#ifndef LOCK_HPP
#define LOCK_HPP
#include "motor.hpp"
#include "movement.hpp"
#include "hwlib.hpp"
class lock {
private:
movement see;
motor move;
bool status;
public:
lock(hwlib::target::pin_out & pinout, hwlib::target::pin_in & pinin );
void open();
void close();
void pir();
    
};

#endif 