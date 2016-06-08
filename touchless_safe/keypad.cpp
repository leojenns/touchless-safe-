#include "keypad.hpp"
#include "hwlib.hpp"


keypad::keypad(hwlib::target::pin_out & c1,hwlib::target::pin_out & c2,hwlib::target::pin_out & c3,hwlib::target::pin_out & c4,hwlib::target::pin_in & r1,hwlib::target::pin_in & r2,hwlib::target::pin_in & r3,hwlib::target::pin_in & r4):
row{&r4, &r3,&r2, &r1},col{&c1, &c2, &c3, &c4}{}

int  keypad::input(){
    bool value = 0;
for(;;){
for(int i =0; i<4;i++){
    col[i]->set(0);
    for(int j =0;j<4;j++){
        value  = row[j]->get();
        if (value == 0
        ){
            
            hwlib::cout << " pressed button = " << pad[j][i];
           return pad[j][i];
        }
value = 0;
    }
    col[i] ->set(1);
    
    
}
}
return 1;
}