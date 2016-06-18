#include "profile.hpp"

profile::profile(hwlib::target::pin_adc & adc,lock & l):
soundlock(adc,l)
{}
void profile::measure() {int samplesum=0;
    int counter_sample;
    int sample=0;
    int x=0;
    for (int ic = 0;ic<array_number;ic++){
        measurment[ic]=0;
        
    }
    array_number=0;
    while(x < 100000LL){  


sample = adc.get();  
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
   
   return;
   }
void profile::math_password(){
    
    if (set_p==0&&set_p_run==0){
    set_password();
    array_number = 0;
}
int array2[(array_number/2)];
int array3[(array_number/4)];
int array4[(array_number/18)];
int array5[(array_number/18)];
   
   for(int i =0;i<array_number;i+=2){
        array2[i/2]=(measurment[i]+measurment[i+1])/2;
    }
   
  
    for(int i =0;i<(array_number/2);i+=2){
        array3[i/2]=(array2[i]+array2[i+1])/2;
    }
      for(int i =0;i<(array_number/6);i+=3){
        array4[i/3]=(array3[i]+array3[i+1]+array3[i+2])/3;
    }
     
   
    
    
for(int i =0;i<(array_number/18);i++){
        if (array4[i]<3000){
            array4[i]=3000;
        }
    }
    for(int i =0;i<(array_number/18);i++){
        if (array4[i]==3000){
            array5[i]=0;
        }
        else if(array4[i]<3250){
            array5[i] = 1;
        }
          else if(array4[i]<3500){
            array5[i] = 2;
        }  else if(array4[i]<3750){
            array5[i] = 3;
        }  else if(array4[i]<4000){
            array5[i] = 4;
        }  else if(array4[i]<4250){
            array5[i] = 5;
        }  else if(array4[i]<4500){
            array5[i] = 6;
        }  else if(array4[i]<4750){
            array5[i] = 7;
        }
        else{
            array5[i] = 8;
        }
    }
    int arraypass[100];
    int k = 0;
    int c=0;
    int tel= 0;
    int telback=0;
    while (k==0){
      //  hwlib::cout<<"pass";
        if (array5[c] !=0){
            break;
        }
        else{
            tel++;
        }
        c++;
    }
c=2;
k = 0;

while (k==0){

    if (array5[(array_number/18)-c] !=0){
            break;
        }
        else{
            telback++;
        }
        c++;
    }

    
    for (int i = 0;i<( (array_number/18)-(tel+telback));i++){
        arraypass[i] = array5[i+tel];
    }
    int lengthof = (array_number/18)-(tel+telback);
    //hwlib::cout<< "length of pass"<< lengthof;
  //  hwlib::cout<<"pass2";

int tel876=0;
int tel54=0;
int tel32=0;
int tel10=0;

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



     for(int i =0;i<(array_number/18 - (tel+telback));i++){
        //hwlib::cout <<"-"<<arraypass[i];
    }
    
 
        temp = password(tel876,tel54,tel32,tel10);

        

    //hwlib::cout <<"\n"<<"wachtwoord = "<<tel876<<"-"<<tel54<<"-"<<tel32<<"-"<<tel10<<"\n";
}


void profile::compare_password(){
     if (set_p==0){
        hwlib::cout<<"you need to set password first";
        set_password();
return;
    }
    hwlib::cout <<"start measuring key\n";
    measure();
    hwlib::cout <<"calculating";
math_password();
    
    if (p==temp){
        hwlib::cout << "lock is opened by sound\n";
        l.open();
        hwlib::wait_ms(5000);
        l.close();
    }
    else{
        hwlib::cout<<"to many diffferents by sound\n"<<"temp is "<<
        temp;
    }
    
    
}

void profile::set_password(){
    
    
       // press button to start 10 times measurment/
 password sum(0,0,0,0);
set_p_run=1;
set_p=1;
for (int count=0; count<6 ;count++){
    hwlib::cout<< "\nset password "<< count+1<<"  of the 6 times >>   \n";
    measure();
    math_password();
    hwlib::cout<<"temp is "<<temp;
    sum+=temp;
    hwlib::cout<<"sum = "<<sum;
    //hwlib::cout << "\n passwordsum" << sum;
    temp  = password(0,0,0,0);
}
p = (sum/6);
hwlib::cout<<" password = "  <<  p  <<"\n";

}