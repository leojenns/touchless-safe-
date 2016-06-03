#include "mirror.hpp"

window_mirror::window_mirror( hwlib::window & w ): 
   window( hwlib::location( w.size.x / 2, w.size.y ), hwlib::black, hwlib::white ),
   w( w )
{}

void window_mirror::write_implementation( hwlib::location pos, hwlib::color col ){
   w.write( pos, col );
   w.write( hwlib::location( ( w.size.x - 1 ) - pos.x, pos.y ), col );
}



