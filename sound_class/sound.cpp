#include "sound.hpp"


whistle::whistle(hwlib::target::pin_adc & adc,int sam ):
adc(adc),sam(sam){}


   void whistle::measure(){// measure is measuring the tones from the microphone and please the higer tones in beat[]
       
    for (int k = 0; k<beat_counter; k++){// clearing beat[] for new measurement
 beat[k] = 0;
        }
   beat_counter = 0;  // set beat_counter to 0 for new measurement
                
               int x= 0;
               int sum = 0;
               bool tone = 0;
               int tone_count = 0;
               int highest = 0;
               int lowest = 4096;
               int counthigh = 0;
               int countlow =0;
               int value=0;
               int sense =2700 ;// the sound value  limit for normal tones to higher tones
            hwlib::cout<< "measure\n";
    while(x < sam){
        hwlib::wait_ms(1);
        value = adc.get();// use the ad converter and please into value
        sum += value;
        
                                   if (value> highest)// determine if value is highest measured yet
                                    {
                                             highest = value;
                                    }
                                    if (value< lowest)//determine if value is lowest measured yet
                                    {
                                             lowest = value;
                                    }
                                                        
                                    if(value >=sense)//measure the number of high tones 
                                    {
                                                counthigh+=1;
                                                beat[beat_counter] = x;
                                                beat_counter++;
                                                
                        
                                    }
                                    if(value <=2000)//measure the number of low tones measured 
                                    {
                                                countlow +=1;
                                    }
                                                   
                                    if ((value >= sense) && (tone == 0))// tone start test
                                    {
                                                tone  =1 ;
                                    }
                                    if ((tone==1 )&&( value< sense))// tone end test 
                                    {
                                                tone  = 0;
                                                tone_count++;
                                                int flow = 0;
                                                while(flow< tone_count ){
                                                hwlib::cout<< "-";
                                                flow++;
                                                }  hwlib::cout<<"\n";
                                                while(flow>0){
                               //                     hwlib::cout<< "-";
                                                    flow--;
                                                }
                                                flow = 0;
                                                
                                              
                                    }
                                
                                x++;
                            }
                                 //   for (int i = 0;i<beat_counter;i++)
                              //      {
                              //                  hwlib::cout << "beat counter is :"<<beat[i]<<"\n";
                              //      }
          hwlib::cout<< "\n"<< "optel "<< sum;
                  
            sum/= sam;
            // printing basic info about measurement
          hwlib::cout<< "\n"<<hwlib::setw(8)<< "    het gemiddelde"<< sum  <<  "\n"
        << "het hoogst gemeten"<<highest<<"\n" 
          << "het laagste gemeten"<<lowest<<"\n"
          <<"het aantal highs is"<<counthigh<<"\n"
          <<"het aantal low is "<< countlow<<"\n"
          <<"het aantal tones is " << tone_count<<"\n"
          << "meting volbracht\n";
return;
   }
   
   
   void whistle::password(){// making an password out of the numbers of the beat[]
       
     for (int k = 0; k<beat_counter; k++){
       pass[k] = 0;
   }
    

    for (int i = 0;i<(beat_counter-1); i++){
    int number = beat[i+1]-beat[i];
    pass[i] = number;
    pass_sum +=number;
    hwlib::cout<<"password  nb"<<i<< " = "<< number<<"\n";
    }
       
   }
   
   
   
    
   void whistle::unlock(){// unlocking the soundlock
        int beat_sum = 0;
    int out_of_range = 0;
    int good = 0;
    int bad = 0;
    int same = 0;
    int laps_pass[beat_counter];
    int compare = 0;
    for (int k = 0; k<(beat_counter-1); k++){
       laps_pass[k] = 0;
                                                                }
    
for (int i  = 1; i< (beat_counter-1); i++){

    int laps =(beat[ i+1 ] - beat[i]);
    beat_sum += laps;
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
                        }                                              }
            if (bad==0){
             hwlib::cout<< "pass and beat identical twins you can come in ";
            }
// second test: comparing the sum of beat[] and pass[] 
            if ((beat_sum<(pass_sum +40) ) &&(beat_sum>(pass_sum-40))  ){
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
for(int q=0;q<(beat_counter-1);q++){
    if(pass[q]>20){
        compare++;
    }
}

//2.
for(int f=0;f<(beat_counter-1);f++){
for(int p = 0;p<(beat_counter-1);p++){
            if ((pass[p]>20) && (laps_pass[f]>20))
            if (laps_pass[f]>=(pass[p]-5)&&(laps_pass[f]<=(pass[p] +5))){
                same +=1;
                p++;
                f++;
            }
                                                                }}
//3.
        if ((same >= (compare-1))&&(same<=(compare+1))){
            hwlib::cout<<"third test passed \n"<<"same : "<<same<<"         compare = "<<compare<<"\n";
        }
        else {
             hwlib::cout<<"third test failed \n"<<"same : "<<same<<"         compare = "<<compare<<"\n";
        }

       
       
   }