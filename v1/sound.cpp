#include "sound.hpp"


whistle::whistle(hwlib::target::pin_adc & adc):
adc(adc){}


   void whistle::measure(){// measure is measuring the tones from the microphone and please the higer tones in beat[]
       
    for (int k = 0; k<beat_counter; k++){// clearing beat[] for new measurement
 beat[k] = 0;
        }
        
        
   beat_counter = 0;  // set beat_counter to 0 for new measurement
   
   
                int sam = 50000;
                int temp_h=0;
                int temp_l =0;
                bool h=0;
                bool l =0;
                int high[100];
                int low[100] ;
                int jezus[10000];
                int numbers[1000];
                int bb[10];
                int jezus_counter=0;
                jezus_counter=0;
                int low_counter=0;
                int high_counter=0;
               int x= 0;
     //          int sum = 0;
               //bool tone = 0;
  //             int tone_count = 0;
   //            int highest = 0;
   //            int lowest = 4096;
  //             int counthigh = 0;
   //            int countlow =0;
               int value=0;
               int sense =3100 ;// the sound value  limit for normal tones to higher tones
            hwlib::cout<< "measure\n";
    while(x < sam){
        
       hwlib::wait_us(1);
    
        value = adc.get();
        
        if (value > sense ){//high
            if((h ==0) && (l ==0)){
                h =1;
                temp_h = x;
            }
            else if( (h ==0)&& (l==1)){
                h =1;
                l = 0;
                 temp_h=x;
                low[low_counter] = (x - temp_l);
                low_counter++;
            }
            
            
            jezus[jezus_counter]=x;
            numbers[jezus_counter] = value;
            jezus_counter++;
            
            
        }
        
        if (value < sense){//low
            
            if ((h ==1)&&(l==0)){
                h =0;
                l=1;
                high[high_counter]=( x - temp_h);
                high_counter++;
                 temp_l = x;
            }
          
            
        }
      
        x++;
        
        
      

   }
   
   
   int sum1=0;
   int sum2=0;
    hwlib::cout<<"low = ";
        for(int i = 0; i<low_counter;i++){
          //  hwlib::cout<< low[i]<<"  ,   ";
            sum1+=low[i];
        }
        hwlib::cout<<"\n high  = ";
        for(int i =0;i<high_counter;i++){
            // hwlib::cout<< high[i]<<"  ,   ";
             sum2+=high[i];
        }
   hwlib::cout<<"\n sum of low "<<sum1<<"\n sum of high   "<< sum2<< "\n jezus run:  ";
  int numberof=0;
   //sumjez=0;
   for (int i=0;i < (jezus_counter-1);i++){
    //     hwlib::cout<<""<< jezus[i]<<"  ,   ";
    hwlib::cout << "  ,   " << numbers[i];
         if ((jezus[i+1]-jezus[i])> 1500){
bb[numberof] = (jezus[i+1]-jezus[i])            ;
 numberof++;

         }
       
   }
   hwlib::cout<<"number of tones = "<< numberof ;
   for (int i=0;i<numberof;i++){
       hwlib::cout << "\n  i = "<< bb[i];
   }

   
   return;
   }
   void whistle::password(){// making an password out of the numbers of the beat[]
       
     for (int k = 0; k<beat_counter; k++){
       pass[k] = 0;
   }
    

    for (int i = 0;i<(beat_counter-1); i++){
    if (beat[i]>1){
        int number = beat[i+1]-beat[i];
     pass_sum +=beat[i];
    if (number > 1){
    pass[i] = number;
   
    pass_counter++;
    
    hwlib::cout<<"password  nb"<<i<< " = "<< number<<"\n";
    }
    }
   }}
   
   
   
   void whistle::unlock(){
       
       
   }
   
    /*
   void whistle::unlock(){// unlocking the soundlock
        int beat_sum = 0;
    int out_of_range = 0;
    int good = 0;
    int bad = 0;
    int same = 0;
    int laps_pass[beat_counter] = {};
    int compare = 0;
    int skip_p[100];
    int skip_p_counter=0;
    int laps_passtest[test_4_size]={0};
    int passtest[test_4_size]={0};
    int test4correct=0;
    for (int k = 0; k<(beat_counter-1); k++){
       laps_pass[k] = 0;                                    }
    
for (int i  = 1; i< (beat_counter-1); i++){
    if (beat[i]>1){
beat_sum += beat[i];
    int laps =(beat[ i+1 ] - beat[i]);
    
    if (laps>1){
            
 laps_pass[i] = laps;
 
 // first test: compare pass[] with the beat[] to look how identical they are.
            if ((laps >= pass[i] -10) && (laps <= pass[i]+10)){
                        hwlib::cout << " confirmmed  with laps of :" << laps<<"        with differents of " << -1*(pass[i] - laps)<<"\n";
                        good++;
                        }
            else if (((pass[i]- laps) > 100000)          ||        ((pass[i] - laps) < -100000)){
                        out_of_range++;
                        hwlib::cout <<"out of range \n ";
                        }
            else{
                        hwlib::cout    << "failed with laps of "<< laps<<"        with differents of " <<-1*(pass[i] - laps)<<"\n";
                        bad++;
}                                            }  }}
                        
                        
                        
                        
                        
            if (bad==0){
             hwlib::cout<< "pass and beat identical twins you can come in ";
            }
            else if (bad  <2){
                
            hwlib::cout<<"nearly close \n"<<"good = "<<good<<"           bad =   "<< bad;
            }
// second test: comparing the sum of beat[] and pass[] 

 int comperising=  (beat_sum*200)/(pass_sum*2);
 hwlib::cout <<"\n"<<"comperising:"<< comperising<<"\n";
 





                                                                                                                                                                        if ((beat_sum<(pass_sum +100) ) &&(beat_sum>(pass_sum-100))  ){
                                                                                                                                                                            hwlib::cout << "second test is succesed\n"<<
                                                                                                                                                                            "pass >>" << pass_sum<< "     beat>>"<<beat_sum<<"\n";
                                                                                                                                                                            
                                                                                                                                                                        }
                                                                                                                                                                        else{
                                                                                                                                                                            hwlib::cout << "second test failed\n"
                                                                                                                                                                              "pass >>" << pass_sum<< "     beat>>"<<beat_sum<<"\n";
                                                                                                                                                                        }
                                                                                                                                                                                                              

// third test: comepare every element of the pass[] and beat[]
// 1. check in pass[] how many numbers are above 20;
// 2.  check how many high numbers are are sumilair(with an marge of 25 + and 25 - )
// 3. check is 1. and 2. are same.
 
//1.
for(int gg = 0;gg<pass_counter;gg++){
    if(pass[gg]>0){
        compare++;
    }
}

//2.
bool used=0;
for(int f=0;f<(beat_counter-1);f++){
for(int p = 0;p<(beat_counter-1);p++){
            if ((pass[p]>0) && (laps_pass[f]>0))
            if (laps_pass[f]>=(pass[p]-25)&&(laps_pass[f]<=(pass[p] +25))){
             for(int element :skip_p){
               if (element==p){
                     used =1;
                 }
                 if (used ==1){
                 
             break;
                same +=1;
                skip_p[skip_p_counter]=p;
                skip_p_counter++;
                f++;
                 }
            
}}}}
//3.
        if ((same >= (compare-1))&&(same<=(compare+1))){
            hwlib::cout<<"third test passed \n"<<"same : "<<same<<"         compare = "<<compare<<"\n";
        }
        else {
             hwlib::cout<<"third test failed \n"<<"same : "<<same<<"         compare = "<<compare<<"\n";
        }

       
       
// test 4
for(int & element:passtest){
    element = 0;
}
for(int & element2:laps_passtest){
    element2 = 0;
}

for (int a=0;a<pass_counter;a++){
    for(int b=0;b<test_4_size;b++){
        if (b<5){
            if((pass[a]>(0+(10*b)))&&(pass[a]<(10+(10*b)))){
                passtest[b]++;
                break;
            }
                }
                else{         
                if((pass[a]>(0+(50*(b-4))))&&(pass[a]<(50+(50*(b-4))))){
                passtest[b]++;
                break;
            }
                    
                }
                                                                }       
                                                            }
    
    for (int c=0;c<(beat_counter-1);c++){
    for(int d=0;d<test_4_size;d++){
        if(d<6){
            if((laps_pass[c]>(0+(10*(d)))&&(laps_pass[c]<(10+(10*d))))){
                laps_passtest[d]++;
                break;
                }
                else{
                       if((laps_pass[c]>(0+(50*(d-4))))&&(laps_pass[c]<(50+(50*(d-4))))){
                laps_passtest[d]++;
                break;
            }
                }
        }
        }
            }       
    
    
    for( int test4=0;test4<test_4_size;test4++){
       // if ((laps_passtest[test4]<(passtest[test4]+1))&&(laps_passtest[test4]>(passtest[test4]-1))){
           if (laps_passtest[test4]==(passtest[test4])){
                test4correct++;
        }
    }
    if (test4correct >=(test_4_size -1)){
        hwlib::cout << "welkome\n        "<<test4correct << "   over     " << test_4_size;
        
        
    }
    else 
       hwlib::cout << "to manny differents\n        "<<test4correct << "   over     " << test_4_size;
       
   }*/