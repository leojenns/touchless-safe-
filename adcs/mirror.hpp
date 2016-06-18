#ifndef _MIRROR_HPP
#define MIRROR_HPP

#include "hwlib.hpp"

class window_mirror : public hwlib::window {
private:
   hwlib::window & w;
   
public:
   window_mirror( hwlib::window & w ); 
   
private:   
   void write_implementation( hwlib::location pos, hwlib::color col ) override;

};

#endif


