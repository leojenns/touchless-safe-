#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP
#include "hwlib.hpp"
/// class for the pir sensor
class movement {
private:
/// one input pin for the pir sensor
hwlib::target::pin_in & pir;
public:
/// the construtor of the movement class needs one input pin for the pir 

movement(hwlib::target::pin_in & pir);
/// function getis for getting the value of the pir sensor. 
bool get();
};
#endif 