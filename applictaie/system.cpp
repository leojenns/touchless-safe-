#include "system.hpp"

system::system(hwlib::target::pin_adc & adc,keypad & k,lock & l):
A(adc,l,k),
A1(adc,l,k),
A2(adc,l,k),
AD(l,k),
k(k),
l(l)
{}


void system::start(){
    
    hwlib::cout<<"welcome to touchless safe \n";
    hwlib::cout <<"choose an profile or admin \n";

while(1){
    int value = k.input();
    
if (value == 'A'){
    hwlib::cout<< "profile A\n";
    A.compare_password();

}
else if(value == 'B'){
     hwlib::cout<< "profile B\n";
    A1.compare_password();
}
else if(value == 'C'){
     hwlib::cout<< "profile C\n";
    A2.compare_password();
}

else if (value == 'D'){
     hwlib::cout<< "admin\n";
     hwlib::wait_ms(500);
     AD.admin_menu();
}
    l.pir();
    
}
    
}