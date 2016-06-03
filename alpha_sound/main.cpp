#include "hwlib.hpp"

#include "mirror.hpp"


void password( int beat[], int beat_counter,int password[])
{
    for (int i = 0;i<(beat_counter-1); i++){
    int number = beat[i+1]-beat[i];
    password[i] = number;
   // hwlib::cout<<"password  nb"<<i<< " = "<< number<<"\n";
    }
}

void unlock(int password[] ,int beat[] , int beat_size )
{
    bool welcome = 1;
    int good = 0;
    int bad = 0;
for (int i  = 1; i< beat_size; i++){
    
int laps =(beat[ i+1 ] - beat[i]);
if (i < (beat_size-1)){
if ((laps >= password[i] -10) && (laps <= password[i]+10))
    
{
//hwlib::cout << " confirmmed  with laps of :" << laps<<"        with differents of " << -1*(password[i] - laps)<<"\n";
good+=1
}
else 
{
//hwlib::cout    << "failed with laps of "<< laps<<"        with differents of " <<-1*(password[i] - laps)<<"\n";
bad +=1;
}

}
}
if ( good >  ( bad *10)){
hwlib::cout<< "welcome u are autorised to come in ";
}

}
    
    
void measure(hwlib::target::pin_adc & adc, int row[], int row_count, int beat[], int beat_counter, int sample){
    int x= 0;
    int sum = 0;
    bool tone = 0;
    int tone_count = 0;
    int highest = 0;
    int lowest = 4096;
    int counthigh = 0;
    int countlow =0;
  
    while(x < sample){
        row[x] = adc.get();
        sum += row[x];
        
        
                                   if (row[x]> highest)//hoogste
                                    {
                                             highest = row[x];
                                    }
                                    if (row[x]< lowest)//laagste
                                    {
                                             lowest = row[x];
                                    }
                                                        
                                    if(row[x] >=2700)//aantal hoogte
                                    {
                                                counthigh+=1;
                                                beat[beat_counter] = x;
                                                beat_counter ++;
                                                hwlib::cout<< "---------                                      high count voor waarde  = " << row[x]<<"\n"; 
                                    }
                                    if(row[x] <=2600)//aantal low
                                    {
                                                countlow +=1;
                                    }
                                                   
                                    if ((row[x] >= 2700) && (tone == 0))
                                    {
                                                tone  =1 ;
                                    }
                                    if ((tone==1 )&&( row[ x] < 2700))
                                    {
                                                tone  = 0;
                                                tone_count++;
                                    }
                                
                                x++;
                            }
                                   // for (int i = 0;i<beat_counter;i++)
                               //     {
                              //                  hwlib::cout << "beat counter is :"<<beat[i]<<"\n";
                                //    }
          hwlib::cout<< "\n"<< "optel "<< sum;
                  
            sum/= sample;
          hwlib::cout<< "\n"<<hwlib::setw(8)<< "    het gemiddelde"<< sum  <<  "\n"
          << "het hoogst gemeten"<<highest<<"\n" 
          << "het laagste gemeten"<<lowest<<"\n"
          <<"het aantal highs is"<<counthigh<<"\n"
          <<"het aantal low is "<< countlow<<"\n"
          <<"het aantal tones is " << tone_count<<"\n";
    
}
int main(void)
{
    
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    hwlib::cout << "run";
    namespace target = hwlib::target;
    auto adc0 = target::pin_adc( target::ad_pins::a0 );
int meter[10000];
int beat[10000];
int row_count = 0;
int beat_count = 0;
int sample  = 100;
//auto button  = target::pin_in( target::pins::a0);
while(1){
//if (button.get() ==0){
    measure(adc0,meter,row_count,beat,beat_count,sample);
//}
}}
