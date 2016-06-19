/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              system.cpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#include "system.hpp"

system::system(hwlib::target::pin_adc & adc,keypad & k,lock & l):
A(adc,l,k),B(adc,l,k),C(adc,l,k),D(adc,l,k),Q(l,k),k(k),l(l){}


void system::run(){
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
    B.compare_password();
}
else if(value == 'C'){
     hwlib::cout<< "profile C\n";
    C.compare_password();
}
else if(value == 'D'){
     hwlib::cout<< "profile D\n";
    D.compare_password();
}
else if (value == '*'){
     hwlib::cout<< "admin\n";
     Q.admin_menu();
}
    l.pir();
    
}
    
}