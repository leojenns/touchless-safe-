/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              profile.cpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#include "profile.hpp"

profile::profile(hwlib::target::pin_adc & adc,lock & l,keypad & k):
soundlock(adc,l),k(k)
{}


void profile::measure() {
    int samplesum=0;
    int counter_sample;
    int sample=0;
    int x=0;
    /// clean measurment
    for (int ic = 0;ic<array_number;ic++){
        measurment[ic]=0;
    }
    /// set array_number on 0 for new measurement
    array_number=0;
    
    while(x < 100000LL){  
        sample = adc.get();  
        /// amplify signal 
        if (counter_sample<100&& sample >2800){
             samplesum += 3*sample;
            counter_sample ++;
        }
        else if (counter_sample<100){
            samplesum += sample;
            counter_sample ++;
        }
        else{
            measurment[array_number] = (samplesum/100);
            array_number++;
            samplesum = 0;
            counter_sample = 0;
        }
        x++;  
   }
   
   
   }
   
   
void profile::math_password(){
    /// check if password is set
    if (set_p==0&&set_p_run==0){
        set_password();
        array_number = 0;
    }
    /// needed variables
    
    /// integer array needed for algorithm
    int array2[(array_number/2)];
    /// integer array needed for algorithm
    int array3[(array_number/4)];
    /// integer array needed for algorithm
    int array4[(array_number/18)];
    /// integer array needed for algorithm
    int array5[(array_number/18)];
    /// integer array needed for algorithm
    int arraypass[100];
    /// integer variable  used as counter to eliminate useless zeros
    int c=0;
    /// counter for useless zeros  before tone
    int tel_zero= 0;
       /// counter for useless zeros  after tone
    int telback_zero=0;
    /// password integer
     int tel876=0;
         /// password integer
    int tel54=0;
        /// password integer
    int tel32=0;
        /// password integer
    int tel10=0;
    /// step one  algorithm (sum two numbers divide with 2 )
   for(int i =0;i<array_number;i+=2){
        array2[i/2]=(measurment[i]+measurment[i+1])/2;
    }
   
  /// step two  algorithm (sum two numbers divide with 2  again )
    for(int i =0;i<(array_number/2);i+=2){
        array3[i/2]=(array2[i]+array2[i+1])/2;
    }
    /// step three  algorithm (sum three numbers divide with 3  again )
      for(int i =0;i<(array_number/6);i+=3){
        array4[i/3]=(array3[i]+array3[i+1]+array3[i+2])/3;
    }
     
   
    
    /// step four algorithm( all the numbers lower then 3000 make 3000)
    for(int i =0;i<(array_number/18);i++){
        if (array4[i]<3000){
            array4[i]=3000;
        }
    }
    /// step five algorithm
    //
    /// make from 3000>
    /// numbers between 0 and 8 
    /// 3000 = 0   -   3250 = 1  -  3500 = 2 etc.
    for(int i =0;i<(array_number/18);i++){
        if (array4[i]==3000){
                array5[i]=0;
        }
        else if(array4[i]<3250){
                array5[i] = 1;
        }
        else if(array4[i]<3500){
                array5[i] = 2;
        }
        else if(array4[i]<3750){
                array5[i] = 3;
        }  
        else if(array4[i]<4000){
                array5[i] = 4;
        }  
        else if(array4[i]<4250){
                array5[i] = 5;
        }  
        else if(array4[i]<4500){
                array5[i] = 6;
        }  
        else if(array4[i]<4750){
                array5[i] = 7;
        }
        else{
                array5[i] = 8;
        }
    }
/// step six algorithm  part 1
/// count useless zero created  during measurment  before tone
    while (1){

        if (array5[c] !=0){
            break;
        }
        else{
            tel_zero++;
        }
        c++;
    }
    c=2;
   /// step six algorithm  part 2
/// count useless zero created  during measurment after tone
    while (1){

        if (array5[(array_number/18)-c] !=0){
            break;
        }
        else{
            telback_zero++;
        }
        c++;
    }
    
  int lengthof = (array_number/18)-(tel_zero+telback_zero);
    /// step seven algorithm
    /// eliminate useless zero's
    for (int i = 0;i<( lengthof);i++){
        arraypass[i] = array5[i+tel_zero];
    }
    
  



/// step eigth algorith (determine password)
    for(int i = 0 ; i<lengthof;i++){
    
    if(arraypass[i]==8||arraypass[i] == 7 || arraypass[i]==6){
            tel876 ++;
    }
    else if ( arraypass[ i]==5||arraypass[i]==4){
            tel54 ++;
    }
    else if (arraypass[i]==3||arraypass[i]==2){
            tel32 ++;
    }
    else if (arraypass[i] ==1||arraypass[i]==0){
            tel10 ++;
    }
    }
        temp = password(tel876,tel54,tel32,tel10);
}


void profile::compare_password(){
     if (set_p==0){
        hwlib::cout<<"you need to set password first";
        set_password();
        return;
    }
    hwlib::cout <<"start measuring key\n";
    measure();
    math_password();
    
    if (p==temp){
        hwlib::cout << "lock is opened by sound\n";
        l.open();
        hwlib::wait_ms(2000);
    }
    else{
        hwlib::cout<<"to many diffferents by sound\n"<<"temp is "<<
        temp;
    }
    
    
}




void profile::set_password(){
    password sum(0,0,0,0);
    bool st_x=1;
    hwlib::cout<< "\npress 1 to start set \n press 2 to stop\n";
    while (st_x==1){
        int v = k.input();
        if (v==1){
            set_p_run=1;
    set_p=1;
    for (int count=0; count<6 ;count++){
        hwlib::cout<< "\n set password "<< count+1<<"  of the 6 times >>   \n";
        measure();
        math_password();
        hwlib::cout<<"temp is    "<<temp;
        sum+=temp;
        hwlib::cout<<"  sum = "<<sum;
        temp  = password(0,0,0,0);
    }
    p = (sum/6);
    hwlib::cout<<" password = "  <<  p  <<"\n";
 st_x=0;
  }
  else if (v==2){
      hwlib::cout << "stopping set";
     st_x=0;
  }
    }
}