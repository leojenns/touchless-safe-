
/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              password.cpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#include "password.hpp"


password::password(int tel876,int tel54,int tel32,int tel10):
tel876(tel876),tel54(tel54),tel32(tel32),tel10(tel10){}

password::password():
tel876(0),tel54(0),tel32(0),tel10(0){}


void password::operator =(const password & rhs){
    tel876 = rhs.tel876;
    tel54 = rhs.tel54;
    tel32 = rhs.tel32;
    tel10 = rhs.tel10;
}

bool password::operator>=(const password & rhs) const{
    return(((tel876==rhs.tel876)&&(tel54 == rhs.tel54)) && (  (tel32==rhs.tel32)   &&   (tel10==rhs.tel10)  ) );
}


bool password::operator==(const password & rhs) const{
    bool a=0;
    bool b=0;
    bool c=0;
    bool d=0;
    if ((tel876<=(rhs.tel876+2))&&(tel876>=(rhs.tel876-1))){
        a=1;
    }
     if ((tel54<=(rhs.tel54+2))&&(tel54>=(rhs.tel54-1))){
        b=1;
    }
     if ((tel32<=(rhs.tel32+2))&&(tel32>=(rhs.tel32-1))){
        c=1;
    }
     if ((tel10<=(rhs.tel10+3))&&(tel10>=(rhs.tel10-2))){
        d=1;
    }
    int summ =tel876 + tel54 + tel32 + tel10;
    int sumrhs = rhs.tel876 + rhs.tel54 + rhs.tel32 + rhs.tel10;
    
    if ((summ <= sumrhs+5)&&( summ >= sumrhs - 5)){
        if (((a==1) && (b==1))&&(( c==1)&& (d==1))){
        
            return 1;
        }
        else{
            hwlib::cout << "sum correct comparising not";
        }
    }
    else {
        hwlib::cout<<"sum not correct";
    }
    
    return 0;
}


password password::operator+(const password & rhs)const{
    return password(
    tel876+rhs.tel876
    ,tel54+rhs.tel54
    ,tel32+rhs.tel32
    ,tel10+rhs.tel10
                                    );
}    

password password::operator/(const int rhs)const{
    return password(tel876/rhs,tel54/rhs,tel32/rhs,tel10/rhs);
}

password password::operator*(const int rhs)const{
     return password(tel876*rhs,tel54*rhs,tel32*rhs,tel10*rhs);
}

password & password::operator+=(const password & rhs){
    tel876 = tel876+rhs.tel876;
    tel54 = tel54+rhs.tel54;
    tel32 = tel32+rhs.tel32;
    tel10 = tel10+rhs.tel10;
    return *this;
}

 hwlib::ostream & operator<<( hwlib::ostream & lhs, const password & rhs ){
      return lhs 
         << " " 
         << rhs.tel876 
         << "-" 
         << rhs.tel54
            << " -" 
         << rhs.tel32
         << "-" 
         << rhs.tel10
         << " ";
   }   