#include "hwlib.hpp"
#include "touchless_safe.hpp"
#include "profile.hpp"
#include "lock.hpp"

int main(void)
{
    hwlib::cout << "welkom";
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    hwlib::cout << "run   \n";
    namespace target = hwlib::target;
 
    auto adc0 = target::pin_adc( target::ad_pins::a1 );
    	auto servoPin = hwlib::target::pin_out(hwlib::target::pins::d7);
        auto  pir = hwlib::target::pin_in(hwlib::target::pins::d6);
        auto col4 = target::pin_out( target::pins::d53);
        auto col3  = target::pin_out( target::pins::d52);
        auto col2  = target::pin_out( target::pins::d51);
        auto col1  = target::pin_out( target::pins::d50);
        auto row1  = target::pin_in( target::pins::d49);
        auto row2  = target::pin_in( target::pins::d48);
        auto row3  = target::pin_in( target::pins::d47);
        auto row4  = target::pin_in( target::pins::d46);

sound f (adc0);
lock l(servoPin,pir);
keypad j(col1,col2,col3,col4,row1,row2,row3,row4);
profile s(adc0,l,j);
movement p(pir);
hwlib::cout<< "testfile for library \n";
int x=0;
hwlib::cout << "press 1 \n";
  bool dd=0;
  bool bb=0;
  bool cc=0;
while (x<3){
    int value = j.input();
    if ( value == 1){
        hwlib::cout<< "one is pressed\n";

        hwlib::wait_ms(1000);
        hwlib::cout<<"press  D\n";
         if (bb==0)
        {
            x++;
            bb=1;
        }
    }
    else if (value == 'D')
    {
      
        hwlib::cout <<"D was pressed\n";
        
         hwlib::wait_ms(1000);
        hwlib::cout<<"press  *\n";
        if (dd==0)
        {
            x++;
            dd=1;
        }
    }
     else if (value == '*')
    {
        hwlib::cout <<"* was pressed\n";
        
         hwlib::wait_ms(1000);
           if (cc==0)
        {
            x++;
            cc=1;
        }
    }
    
}
 hwlib::cout<<"*keypad is working *\n";
 hwlib::wait_ms(1000);
 hwlib::cout<< "test for profile\n press A\n";
 
 x=0;
 while (x==0){
      int value = j.input();
      if (value == 'A'){
         
            hwlib::cout<<"A is pressed \n press 2 (command below doesn't need for test\n\n";
             s.compare_password();
             x=1;
      }
     
 }
hwlib::cout<<"\n\n\nprofile is working\n";
 hwlib::wait_ms(1000);
hwlib::cout<<"sound test\n";
    f.measure();
if (f.array_number==5000){
   hwlib::cout<<"\nsound is working\n"; 
}
else { 
    hwlib::cout<<"\nsound is  not working\n"; 
}

 hwlib::wait_ms(1000);
hwlib::cout<<"lock test \n";


    hwlib::cout<<"lock opens\n";
     hwlib::wait_ms(1000);   
l.open();
hwlib::cout<<"lock closes\n";
 hwlib::wait_ms(1000);   
l.close();


hwlib::cout << "if lock has open after that closed lock is working\n";


hwlib::wait_ms(1000);


hwlib::cout<<"pir test\n";
x=0;
while(x==0){
    if (p.get()==1)
    {

        x=1;
    }
}
hwlib::cout<<"pir working\n test completed";

}