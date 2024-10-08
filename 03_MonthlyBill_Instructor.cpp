// CIS 15A - Assignment 3, Option A
// Instructor Solution
// Notes:
//   - The program was run three times to demonstrate the effect of different
//        user input, including illegal (negative) values
//   - Variables watts and hrs were reused several times, obviating
//        the need to have distinct variables for each appliance.
//   - Lines are shorter than 80 characters.
//   - Symbolic constants are used rather than literal values to make
//        updating the program easier and less error prone.

// ---------------- SOURCE -------------------------

#include <iostream>
#include <string>

using namespace std;

int main()
{             
   // declare some variables
   int watts, hrs, total_wh, wh_per_day;
   double monthly_charge;
   const double dollars_per_Wh = .00005;
   const int days_per_month = 30;
  
   // get the watts and time for the hot water heater
   cout << "How many Watts for the Water Heater? ";     
   cin >> watts;
   cout << "How many hours/day do you run the Water Heater? ";     
   cin >> hrs;

   // test for bad input
   if ( watts < 0 || hrs < 0 )   // see Module 4 for || operator
   {
      cout << "No negative values allowed. Program aborted.\n";
      return 1;
   }
   wh_per_day = hrs * watts;
 
   // get the watts and time for the computer equipment
   cout << "How many Watts for the Computer Equipment? ";     
   cin >> watts;
   cout << "How many hours/day do you run the Computer Equipment? ";     
   cin >> hrs;

   // test for bad input
   if ( watts < 0 || hrs < 0 )   // see Module 4 for || operator
   {
      cout << "No negative values allowed. Program aborted.\n";
      return 1;
   }
   wh_per_day += hrs * watts;

   // get the watts and time for the lights
   cout << "How many Watts for the Lights? ";     
   cin >> watts;
   cout << "How many hours/day do you run the Lights? ";     
   cin >> hrs;

   // test for bad input
   if ( watts < 0 || hrs < 0 )   // see Module 4 for || operator
   {
      cout << "No negative values allowed. Program aborted.\n";
      return 1;
   }
   wh_per_day += hrs * watts;

   // calculate totals for month
   total_wh = wh_per_day * days_per_month;
   monthly_charge = dollars_per_Wh * total_wh;

   // print bill
   cout << "\n\nYou have used " << total_wh << " Watt-Hours of electricity. " ;
   cout << "\nYour total bill this month is $" << monthly_charge 
      << endl << endl;

   return 0;
}

/*  ---------------------- Sample Run #1 -------------------

How many Watts for the Water Heater? 4000
How many hours/day do you run the Water Heater? 12
How many Watts for the Computer Equipment? 750
How many hours/day do you run the Computer Equipment? 24
How many Watts for the Lights? 900
How many hours/day do you run the Lights? 16


You have used 2412000 Watt-Hours of electricity.
Your total bill this month is $120.6

Press any key to continue . . .

--------------------------- Sample Run #2 ------------------

How many Watts for the Water Heater? 5500
How many hours/day do you run the Water Heater? 14
How many Watts for the Computer Equipment? 1200
How many hours/day do you run the Computer Equipment? 24
How many Watts for the Lights? 1775
How many hours/day do you run the Lights? 18


You have used 4132500 Watt-Hours of electricity.
Your total bill this month is $206.625

Press any key to continue . . .

--------------------------- Sample Run #3 ------------------

How many Watts for the Water Heater? -3
How many hours/day do you run the Water Heater? 12
No negative values allowed. Program aborted.
Press any key to continue . . .

 -------------------------- end of sample runs ------------ */