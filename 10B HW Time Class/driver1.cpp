#include "stdafx.h"
#include <iostream>
#include "time_class.h"

using std::cout;

int main(){

//       Time setup [not needed in San Angel]
       Time::set_hr_in_day(24);
       Time::set_min_in_hr(60);


   cout << "*****************************************\n";
   cout << "Welcome to 'San Angel'!\n";
   cout << "Time setup:\n\t1 day = 24 hours,\n\t1 hour = 60 minutes.\n";
   cout << "*****************************************\n";

   Time a;
   Time b(5);
   Time c(61);
   Time d(47,59);
   Time X(5.0);
   Time Y(1.5);
   Time Z(25.1);

   cout << "Testing constructors:\n";
   cout << "\tTime a;\t\t\t";
   cout << "a = " << a << "\n";
   cout << "\tTime b(" << b.minutes() << ");\t\t";
   cout << "b = " << b << "\n";
   cout << "\tTime c(61);\t\t";
   cout << "c = " << c << "\n";
   cout << "\tTime d(47,59);\t\t";
   cout << "d = " << d << "\n";
   cout << "\tTime X(5.0);\t\t";
   cout << "X = " << X << "\n";
   cout << "\tTime Y(1.5);\t\t";
   cout << "Y = " << Y << "\n";
   cout << "\tTime Z(25.1);\t\t";
   cout << "Z = " << Z << "\n";

   cout << "Testing operator+:\n";
   cout << "\te = b + c;\t\te = " << b + c << "\n";
   cout << "\tf = d + 2;\t\tf = "<< 2 + d << "\n";
   cout << "\tg = c + 2.75;\t\tf = "<< 2.75 + c << "\n";

   cout << "Testing operator+=:\n";
   c += 120;
   cout << "\tc += 120;\t\t";
   cout << "c = " << c << "\n";
   c += 1.99166666;
   cout << "\tc += 1.99166666;\t";
   cout << "c = " << c << "\n";
   c += 1.99166667;
   cout << "\tc += 1.99166667;\t";
   cout << "c = " << c << "\n";

   cout << "Testing other member functions:\n";
   c.set_minutes(60);
   cout << "\tc.set_minutes(60);\t";
   cout << "c = " << c << "\n";
   c.set_minutes(123.45);
   cout << "\tc.set_minutes(123.45);\t";
   cout << "c = " << c << "\n";
   c.set_minutes(67.89);
   cout << "\tc.set_minutes(67.89);\t";
   cout << "c = " << c << "\n";
   cout << "\tc.set_hours(45);\t";
   c.set_hours(45);
   cout << "c = " << c << "\n";
   cout << "\tc.set_hours(1.9);\t";
   c.set_hours(1.9);
   cout << "c = " << c << "\n";
   cout << "\tc.set_hours(1.9999);\t";
   c.set_hours(1.9999);
   cout << "c = " << c << "\n";

   cout << "Testing comparison operators:\n";
   if ( b < c )
      cout << b << " occurs earlier in the day than " << c << ", ";

   if ( !(b == c) )
      cout << "hence b != c.\n";

   if ( c >= b )  
      cout << c << " occurs later in the day than " << b << ", ";

   if ( b != c )
      cout << "hence c != b.\n";

   return 0;
}
