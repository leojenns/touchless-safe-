#include "keypad.hpp"
#include "hwlib.hpp"

/// constructor of keypad the the first four pins C1 to C4
/// are output pins and will be eddit to the col outputlist 
/// the last four pins R1 to R4 are input pins and these will be eddit
/// to the row input list 
keypad::keypad(hwlib::target::pin_out & c1,hwlib::target::pin_out & c2,hwlib::target::pin_out & c3,hwlib::target::pin_out & c4,hwlib::target::pin_in & r1,hwlib::target::pin_in & r2,hwlib::target::pin_in & r3,hwlib::target::pin_in & r4):
row{&r4, &r3,&r2, &r1},col{&c1, &c2, &c3, &c4}{}

int  keypad::input(){
	///input function: this function sets all of the colloms on high and one at the time 
	/// the colloms will be put to low  then when an button is pressed the input will see an zero ad the row
	/// where the button is pressed. 
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