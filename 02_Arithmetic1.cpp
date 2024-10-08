/*===============================SOURCE========================================
                         Created by Leonard Pak
=============================================================================*/

#include <iostream>
using namespace std;



int main()
{
   int first_n = 6;
   int second_n = 9;
   int third_n = 16;

   cout << "\n" << "Homework Assignment 2, Option A - Some Easy Arithmetic";
   cout << "\n" << "Compute the following equations when n = 6, 9, 16";
   cout << "\n" << "   #1: 1 + 2 + 3 + ... + n";
   cout << "\n" << "   #2: ( n * (n + 1) ) / 2";
   cout << "\n" << "   #3: 3 + 5 + ... + (2n - 1)";
   cout << "\n" << "   #4: n^2 - 1";
   cout << "\n";

   cout << "\n" << "   n = " << first_n;
   cout << "\n" << "      #1: " << 1 + 2 + 3 + 4 + 5 + first_n;
   cout << "\n" << "      #2: " << (first_n * (first_n + 1)) / 2;
   cout << "\n" << "      #3: " << 3 + 5 + 7 + 9 + ((2 * first_n) - 1);
   cout << "\n" << "      #4: " << (first_n * first_n) - 1;
   cout << "\n";

   cout << "\n" << "   n = " << second_n;
   cout << "\n" << "      #1: " << 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + second_n;
   cout << "\n" << "      #2: " << (second_n * (second_n + 1)) / 2;
   cout << "\n" << "      #3: " << 3 + 5 + 7 + 9 + 11 + 13 + 15 
                                      + ((2 * second_n) - 1);
   cout << "\n" << "      #4: " << (second_n * second_n) - 1;
   cout << "\n";

   cout << "\n" << "   n = " << third_n;
   cout << "\n" << "      #1: " << 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11
                                     + 12 + 13 + 14 + 15 + third_n;
   cout << "\n" << "      #2: " << (third_n * (third_n + 1)) / 2;
   cout << "\n" << "      #3: " << 3 + 5 + 7 + 9 + 11 + 13 + 15 + 17 + 19 + 21
                                     + 23 + 25 + 27 + 29 + ((2 * third_n) - 1);
   cout << "\n" << "      #4: " << (third_n * third_n) - 1;
   cout << "\n";

   cout << "\n";
   return 0;
} // end main

/*===============================OUTPUT========================================

Homework Assignment 2, Option A - Some Easy Arithmetic
Compute the following equations when n = 6, 9, 16
   #1: 1 + 2 + 3 + ... + n
   #2: ( n * (n + 1) ) / 2
   #3: 3 + 5 + ... + (2n - 1)
   #4: n^2 - 1

   n = 6
      #1: 21
      #2: 21
      #3: 35
      #4: 35

   n = 9
      #1: 45
      #2: 45
      #3: 80
      #4: 80

   n = 16
      #1: 136
      #2: 136
      #3: 255
      #4: 255

Press any key to continue . . .
=============================================================================*/
/*
Only one variable should be used to represent the n value. The point of a 
variable is that it can be reassigned to hold a different value. Using a 
different variable for each value makes it more like using constants which 
cannot change value within the program. (-1)

Another error here is doing calculations in output instead of assigning the 
result to a variable and printing the variable. Mixing calculations and output
like this is not allowed in this class. Module D addresses this as well. 
(This is one of the most important and far reaching rules in all modern 
programming). (-2)
*/