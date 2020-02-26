/*
The Distance class will represent a distance in some number of feet and inches. 
This Distance object must always be positive and never contain an inch value greater than or equal to 12 (12 inches equals 1 foot). 
It is your job, as the engineer/designer of this Distance class to make sure this is always true.
*/



------
#include <iostream>

using namespace std;

#include "Distance.h"

int main() {
   Distance d1;
   cout << "d1: " << d1 << endl;
   
   Distance d2 = Distance(2, 5.9);
   Distance d3 = Distance(3.75);
   cout << "d2: " << d2 << endl;
   cout << "d3: " << d3 << endl;
   
   //test init helper function
   Distance d4 = Distance(5, 19.34);
   Distance d5 = Distance(100);
   cout << "d4: " << d4 << endl;
   cout << "d5: " << d5 << endl;
   
   //test add (<12 inches)
   cout << "d4 + d5: " << (d4 + d5) << endl;
   //test add (>12 inches)
   cout << "d2 + d4: " << (d2 + d4) << endl;
   
   //test sub (0 ft)
   cout << "d3 - d1: " << (d3 - d1) << endl;
   //test sub (0 ft, negative conversion)
   cout << "d1 - d3: " << (d1 - d3) << endl;
   
   //test sub (positive ft & inch)
   cout << "d4 - d2: " << (d4 - d2) << endl;
   //test sub (negative ft & inch)
   cout << "d2 - d4: " << (d2 - d4) << endl;
   
   //test sub (negative ft, positive inch)
   cout << "d4 - d5: " << (d4 - d5) << endl;
   //test sub (positive ft, negative inch)
   cout << "d5 - d2: " << (d5 - d2) << endl;
   
   return 0;
}
