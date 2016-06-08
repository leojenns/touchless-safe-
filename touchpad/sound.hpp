#ifndef SOUND_HPP
#define SOUND_HPP

#include "hwlib.hpp"
#include "sound.hpp"
class whistle {
protected:
int beat[100];
int beat_counter=0;
int sam;
int pass[100];
int pass_sum=0 ;


public:
whistle(int sam=100):
sam(sam){}

   void measure(hwlib::target::pin_adc & adc){// measure is measuring the tones from the microphone and please the higer tones in beat[]
       
    for (int k = 0; k<beat_counter; k++){// clearing beat[] for new measurement
 beat[k] = 0;
        }
   beat_counter = 0;  // set beat_counter to 0 for new measurement.
   
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
                                                    hwlib::cout<< "-";
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
   
   void password(){// making an password out of the numbers of the beat[]
       
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
   
   void unlock(){
        int beat_sum = 0;
    int out_of_range = 0;
    int good = 0;
    int bad = 0;
    
    
    
for (int i  = 1; i< (beat_counter-1); i++){

    int laps =(beat[ i+1 ] - beat[i]);
    beat_sum += laps;
 
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
            
}}
                                                        
if( (beat_sum <=(pass_sum +20))&&(beat_sum >=(pass_sum-20))){
    hwlib::cout<<"close enough";
}
hwlib::cout << pass_sum<<"-----"<<beat_sum;
if ( (good > (bad*3) )&&(out_of_range<20)){
hwlib::cout<< "welcome u are autorised to come in "<< "\n bad> "<< bad <<"\n good>"<< good<< "\n out of range"<< out_of_range ;

}
else {
  hwlib::cout<< "to many differents try again  \n differents   = "  << good <<"and bad->>"<<bad<<"with out of range of "<< out_of_range;
}


       
       
   }
   
};



#endif 