#include "stdafx.h"
#include <iostream>
#include "time_class.h"

using std::cout;

int main(){
   /**
       Time setup [do needed in the land of the remembered]
   **/
   Time::set_hr_in_day(60);
   Time::set_min_in_hr(24);
   cout << "*****************************************\n";
   cout << "Welcome to 'the land of the remembered'!\n";
   cout << "Time setup:\n\t1 day = 60 hours,\n\t1 hour = 24 minutes.\n";
   cout << "*****************************************\n";


   Time a;
   Time b(5);
   Time c(61);
   Time d(47,59);
   Time Z(59.5);

   cout << "Testing constructors:\n";
   cout << "\tTime a;\t\t\t";
   cout << "a = " << a << "\n";
   cout << "\tTime b(" << b.minutes() << ");\t\t";
   cout << "b = " << b << "\n";
   cout << "\tTime c(61);\t\t";
   cout << "c = " << c << "\n";
   cout << "\tTime d(47,59);\t\t";
   cout << "d = " << d << "\n";
   cout << "\tTime Z(59.5);\t\t";
   cout << "Z = " << Z << "\n";


   cout << "Testing operator+:\n";
   cout << "\te = b + c\t\te = " << b + c << "\n";
   cout << "\tf = d + 14\t\tf = "<< 14 + d << "\n";

   cout << "Testing operator+=:\n";
   c += 120;
   cout << "\tc += 120;\t\t";
   cout << "c = " << c << "\n";

   cout << "Testing other member functions:\n";
   c.set_minutes(24);
   cout << "\tc.set_minutes(24);\t";
   cout << "c = " << c << "\n";
   c.set_minutes(63);
   cout << "\tc.set_minutes(123);\t";
   cout << "c = " << c << "\n";
   cout << "\tc.set_hours(456);\t";
   c.set_hours(456);
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
