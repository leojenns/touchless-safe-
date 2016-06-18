#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP
#include "hwlib.hpp"
class movement {
private:

hwlib::target::pin_in & pir;
public:

movement(hwlib::target::pin_in & pir);
bool get();
};
#endif 