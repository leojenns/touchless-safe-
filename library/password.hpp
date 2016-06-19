/****************************************************************************************************************************
*  auther ::       Leo Jenneskens                                                                                                                                                                                                  
* File ::              password.hpp                                                                                                                                                                                                            
* Date::           18 - june - 2016                                                                                                                                                                                                   
* copyright:    Leo Jenneskens 2016
*                                                                                                                                                                                                                                                    
*  Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at 
* http://www.boost.org/LICENSE_1_0.txt)
*******************************************************************************************************************************/
#ifndef PASSWORD_HPP
#define PASSWORD_HPP
#include "hwlib.hpp"
///  password ADT
//
/// this is an ADT that saves the  passwords.
/// this ADT contains four integers.
///that are beeing used in this library.

class password{
protected:
///integer tel876
//
/// this integer is  first of the four numbers of an password .
/// it is determinate in the math_password function.
/// 
int tel876;
/// integer tel54
//
/// this integer is  second of the four numbers of an password .
/// it is determinate in the math_password function.
/// 
int tel54;
///integer tel32
//
/// this integer is  third of the four numbers of an password .
/// it is determinate in the math_password function.
/// 
int tel32;
/// integer tel10
//
/// this integer is  first of the four numbers of an password .
/// it is determinate in the math_password function.
/// 
int tel10;
public:
/// default constructor
//
/// this constructor gets 4 integers that are stalled as password
password(int tel876,int tel54,int tel32,int tel10);
/// empty constructor
//
/// when an password has to be still calculated and/or determend 
/// the values will stay empty (used in profile class)
password();
/// = operator
//
/// this operator makes it possile to give an password the values of an other password.
/// for example when an password  is empty and the calculation is done it can e put in the correct please (used in set_pasword function in profile class)
void  operator=(const password & rhs);
/// + operator
//
/// this operator sum two passwords
password operator+(const password & rhs)const;
/// / operator
//
///  this oprator divide an password with an integer.
password operator/(const int rhs)const;
/// * operator
//
///this operator multiplies an password with an integer
password operator*(const int rhs)const;
/// bool == operator
//
/// this bool operator compares two passwords with an certain marge 
bool operator==(const password & rhs)const;
/// bool == operator
//
/// this bool operator compares two passwords without marge.
bool operator>=(const password & rhs)const;
/// += operator
//
/// this operator adds an password to an other password 
password & operator+=(const password & rhs);
/// hwlib::ostream << operator
//
/// makes it possible to print out an password  to the terminal
friend  hwlib::ostream & operator<<( hwlib::ostream & lhs, const password & rhs );
} ;




#endif