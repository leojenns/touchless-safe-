/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              admin.cpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#include "admin.hpp"

admin::admin(lock & l,keypad & k):
l(l),k(k)
{}


void admin::admin_wait(){
hwlib::cout<< "please enter password:"; 
while(1){
   hwlib::wait_ms(500);
    int p = k.input_wait();
        hwlib::wait_ms(500);
    int q=  k.input_wait();
       hwlib::wait_ms(500);
    int r = k.input_wait();
       hwlib::wait_ms(500);
    int s = k.input_wait();
    
    password af(p,q,r,s);
    
    if (admin_login(af)==1){
        hwlib::cout<< "correct password\n";
        admin_menu();
    }
    else{
        hwlib::cout<< "wrong password try again\n";
    }

    }

}

void admin::admin_menu(){
    hwlib::cout<< "welkom to admin\n please enter password:\n";
    int a = k.input_wait();
    hwlib::wait_ms(500);
    int b=  k.input_wait();
       hwlib::wait_ms(500);
    int c = k.input_wait();
       hwlib::wait_ms(500);
    int d = k.input_wait();
      
    password ad(a,b,c,d);
    
    if (admin_login(ad)==1){
        hwlib::cout<< "welkom admin\n\npress 1 for open lock\n press 2 for close lock\n press 3 for locking system until admin password is pressed \n press 4 to return to home\n enter choice\n";
    }
    else {
        hwlib::cout<<"wrong password";
        return;
    }

while (1){
    
    int choice = k.input();
    if (choice== 1){
        l.open();
    }
    else if (choice == 2){
        l.close();
    }
    else if (choice ==3){
        l.close();
        admin_wait();
    }
    else if (choice == 4){
        return;
    }


  
    }

    
}



bool admin::admin_login(password & t){
    if ( p>=t){
        return 1;
    }
    else {
        return 0;
    }
    
}