#include "hwlib.hpp"
#include "mirror.hpp"

int main( void ){	
    hwlib::wait_ms(1000);
    

   WDT->WDT_MR = WDT_MR_WDDIS;
   hwlib::cout<<"run";
   namespace target = hwlib::target;   
   auto adc0 = target::pin_adc( target::ad_pins::a1 );

int sample=0;
int array[5000];
int array2[5000];
int array3[1000];
int array4[1000];
int array5[1000];
int array_number = 0;
int samplesum = 0;
int counter_sample  =0;
int x=0;
   while(x < 100000LL){  

x++;  
sample = adc0.get();  
if (counter_sample<100&& sample >2800){
     samplesum += 3*sample;
    counter_sample ++;
}
else if (counter_sample<100){
    samplesum += sample;
    counter_sample ++;
}
else{
array[array_number] = (samplesum/100);
array_number++;
samplesum = 0;
counter_sample = 0;
}
   
   }
   
   
    for(int i =0;i<array_number;i+=2){
        array2[i/2]=(array[i]+array[i+1])/2;
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
   // hwlib::cout << "pass3\n";
    if (array5[(array_number/18)-c] !=0){
            break;
        }
        else{
            telback++;
        }
        c++;
    }
    hwlib::cout<<"telback is "<<telback;
    

    for (int i = 0;i<( (array_number/18)-(tel+telback));i++){
        arraypass[i] = array5[i+tel];
    }
    int lengthof = (array_number/18)-(tel+telback);
    hwlib::cout<< "length of pass"<< lengthof;
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


/*
    for(int i =0;i<(array_number);i++){
        hwlib::cout <<"\n"<<array[i];
    }hwlib::cout<<"..............................................................................................................\n\n\n\n\n\n\n\n";
        for(int i =0;i<(array_number/2);i++){
        hwlib::cout <<"\n"<<array2[i];
    }     hwlib::cout<<"..............................................................................................................\n\n\n\n\n\n\n\n";
     for(int i =0;i<(array_number/4);i++){
        hwlib::cout <<"\n"<<array3[i];
    }*/
     // hwlib::cout<<"..............................................................................................................\n\n\n\n\n\n\n\n\n";
     for(int i =0;i<(array_number/18);i++){
       // hwlib::cout <<"\n"<<array4[i];
    }
    
     //hwlib::cout<<"..............................................................................................................\n\n\n\n\n\n\n\n\n";
     for(int i =0;i<(array_number/18);i++){
       // hwlib::cout <<"\n"<<array5[i];
    }
     //hwlib::cout<<"..............................................................................................................\n\n\n\n\n\n\n\n\n";
     for(int i =0;i<(array_number/18 - (tel+telback));i++){
        hwlib::cout <<"-"<<arraypass[i];
    }
    
    
    hwlib::cout <<"\n"<<"wachtwoord = "<<tel876<<"-"<<tel54<<"-"<<tel32<<"-"<<tel10<<"\n";
    
        hwlib::cout<<"\n done\n";
    
    
    
    
    
    /// to do maak bij het verijderen van de 0 aan het begin het zelfde aan het eind dat elimineerd de 00
    
    

}
