
#include "hwlib.hpp"

void password( int beat[], int beat_counter,int password[], int & pass_sum)
{
     for (int k = 0; k<beat_counter; k++){
       password[k] = 0;
   }
    

    for (int i = 0;i<(beat_counter-1); i++){
    int number = beat[i+1]-beat[i];
    password[i] = number;
    pass_sum +=number;
    hwlib::cout<<"password  nb"<<i<< " = "<< number<<"\n";
    }
}

void unlock(int password[] ,int beat[] , int beat_size ,int &pass_sum)
{
    
    int beat_sum = 0;
    int out_of_range = 0;
    int good = 0;
    int bad = 0;
for (int i  = 1; i< beat_size; i++){

int laps =(beat[ i+1 ] - beat[i]);
beat_sum += laps;
if (i < (beat_size-1)){
if ((laps >= password[i] -10) && (laps <= password[i]+10))
    
{
hwlib::cout << " confirmmed  with laps of :" << laps<<"        with differents of " << -1*(password[i] - laps)<<"\n";
good++;
}
else 
{
    if (((password[i]- laps) > 100000)          ||        ((password[i] - laps) < -100000)){
    out_of_range++;
    hwlib::cout <<"out of range \n ";
        }
        else{
hwlib::cout    << "failed with laps of "<< laps<<"        with differents of " <<-1*(password[i] - laps)<<"\n";
    
bad++;
}}}}
if ( (beat_sum <=(pass_sum +20))&&(beat_sum >=(pass_sum-20))){
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
    
    
void measure(hwlib::target::pin_adc & adc, int beat[], int & beat_counter, int sample){
   for (int k = 0; k<beat_counter; k++){
       beat[k] = 0;
   }
   beat_counter = 0;
    int x= 0;
    int sum = 0;
    bool tone = 0;
    int tone_count = 0;
    int highest = 0;
    int lowest = 4096;
    int counthigh = 0;
    int countlow =0;
  int value=0;
  int sense =2720 ;
  hwlib::cout<< "measure\n";
    while(x < sample){
        hwlib::wait_ms(1);
        value = adc.get();
        sum += value;
       // hwlib::cout<< " check"<< x<<"\n";
        
                                   if (value> highest)//hoogste
                                    {
                                             highest = value;
                                    }
                                    if (value< lowest)//laagste
                                    {
                                             lowest = value;
                                    }
                                                        
                                    if(value >=sense)//aantal hoogte
                                    {
                                                counthigh+=1;
                                                beat[beat_counter] = x;
                                                beat_counter++;
                                              // hwlib::cout<<  x<<"---------                                      high count voor waarde  = " << value<<"\n"; 
                                    }
                                    if(value <=2000)//aantal low
                                    {
                                                countlow +=1;
                                    }
                                                   
                                    if ((value >= sense) && (tone == 0))
                                    {
                                                tone  =1 ;
                                    }
                                    if ((tone==1 )&&( value< sense))
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
                  
            sum/= sample;
          hwlib::cout<< "\n"<<hwlib::setw(8)<< "    het gemiddelde"<< sum  <<  "\n"
          << "het hoogst gemeten"<<highest<<"\n" 
          << "het laagste gemeten"<<lowest<<"\n"
          <<"het aantal highs is"<<counthigh<<"\n"
          <<"het aantal low is "<< countlow<<"\n"
          <<"het aantal tones is " << tone_count<<"\n"
          << "meting volbracht\n";
    
}
int main(void)
{
    
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    hwlib::cout << "run\n";
    namespace target = hwlib::target;
    auto adc0 = target::pin_adc( target::ad_pins::a0 );
    int pass[100];
    int pass_sum = 0;
//int meter[3000];

int beat[1000];
//int row_count = 0;
int beat_count = 0;
int sample = 2000 ;
bool meet = 0;
bool w8woord = 0;
bool lock =0;
auto button  = target::pin_in( target::pins::d8);
auto button1  = target::pin_in( target::pins::d9);
auto button2  = target::pin_in( target::pins::d10);
while(1){
if (button.get() == 0){
meet  = 1;
}
if(button1.get() == 0){
    w8woord = 1;
}
if (button2.get() == 0){
    lock = 1;
}
if (meet  ==1){
    measure(adc0,beat,beat_count,sample);
    meet = 0;
}
else if (w8woord ==1){
    password(beat,beat_count,pass,pass_sum);
    w8woord = 0;
}
else if (lock == 1){
    unlock(pass,beat,beat_count,pass_sum);
    lock = 0;
}
}
}

