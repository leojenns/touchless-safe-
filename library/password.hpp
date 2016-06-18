#ifndef PASSWORD_HPP
#define PASSWORD_HPP
#include "hwlib.hpp"

class password{
protected:

int tel876;
int tel54;
int tel32;
int tel10;
public:
password();
password(int tel876,int tel54,int tel32,int tel10);

void  operator=(const password & rhs);
password operator+(const password & rhs)const;
password operator/(const int rhs)const;
password operator*(const int rhs)const;
bool operator==(const password & rhs)const;
password & operator+=(const password & rhs);
friend  hwlib::ostream & operator<<( hwlib::ostream & lhs, const password & rhs );
} ;




#endif