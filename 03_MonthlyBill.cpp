/*===============================SOURCE========================================
                         Created by Leonard Pak
=============================================================================*/

#include <iostream>
#include <string>
using namespace std;

int main ()
{
   double dollars_per_wh = 0.00012;    // $0.12/kWh is national average rate
   string device1, device2, device3;   // user inputted devices
   int watts1, watts2, watts3;         // user inputted devices' wattage
   int hours1, hours2, hours3;         // user inputted devices' hour usage
   double result;                      // for result calculations

   // ask for devices
   cout << "What is one device that uses power in your household?    ";
   getline(cin, device1);
   cout << "What is another device that uses power in your household?    ";
   getline(cin, device2);
   cout << "What about a third device that uses power in your household?    ";
   getline(cin, device3);
   cout << endl;

   // ask for devices' watt usage
   cout << "What is the watt rating for the " + device1 + "?    ";
   cin >> watts1;
   cout << "What is the watt rating for the " + device2 + "?    ";
   cin >> watts2;
   cout << "What is the watt rating for the " + device3 + "?    ";
   cin >> watts3;
   cout << endl;

   // perform negative number check for watts
   if ( (watts1 < 0) || (watts2 < 0) || (watts3 < 0) )
   {
      cout << "Error: A negative number was inputted for wattage.\n";
      return 1;
   }

   // ask for devices' hours usage
   cout << "How many hours per day do you use the " + device1 + "?    ";
   cin >> hours1;
   cout << "How many hours per day do you use the " + device2 + "?    ";
   cin >> hours2;
   cout << "How many hours per day do you use the " + device3 + "?    ";
   cin >> hours3;
   cout << endl;

   // perform negative number check for hours
   if ( (hours1 < 0) || (hours2 < 0) || (hours3 < 0) )
   {
      cout << "Error: A negative number was inputted for hours.\n";
      return 1;
   }

   // perform calculations for ONE DAY's use
   result = ( (watts1 * hours1) + (watts2 * hours2) + (watts3 * hours3) );

   // print a "bill" for the user: monthly watt hour usage and cost
   cout << "For the three devices you listed (at the national average rate"
           " of $0.12/KWH):\n";

   result = result * 30;
   cout << "\tYou approximately use: \t" << result << " WH / month.\n";

   result = result * dollars_per_wh;
   cout << "\tYou would pay: \t\t$" << result << " / month.\n\n";

   return 0;
}

/*    Average watt usage of some devices:
         medium-sized window AC/electric space heater:   900
         small-sized window AC/electric space heater:    400
         48" ceiling fan at high:                         75
         21st century refridgerator:                      57
         typical laptop:                                  45
         17" LCD monitor:                                 40
         50" plasma television:                          340
         50" LCD television:                             260
         50" DLP television:                             170    */

/*===============================OUTPUT========================================


                        RUN #1
What is one device that uses power in your household?    ceiling fan
What is another device that uses power in your household?    50" plasma TV
What about a third device that uses power in your household?    fridge

What is the watt rating for the ceiling fan?    75
What is the watt rating for the 50" plasma TV?    340
What is the watt rating for the fridge?    57

How many hours per day do you use the ceiling fan?    5
How many hours per day do you use the 50" plasma TV?    3
How many hours per day do you use the fridge?    24

For the three devices you listed (at the national average rate of $0.12/KWH):
        You approximately use:  82890 WH / month.
        You would pay:          $9.9468 / month.

Press any key to continue . . .



                        RUN #2
What is one device that uses power in your household?    17" LCD monitor
What is another device that uses power in your household?    laptop
What about a third device that uses power in your household?    5.1 speakers

What is the watt rating for the 17" LCD monitor?    40
What is the watt rating for the laptop?    45
What is the watt rating for the 5.1 speakers?    150

How many hours per day do you use the 17" LCD monitor?    6
How many hours per day do you use the laptop?    6
How many hours per day do you use the 5.1 speakers?    6

For the three devices you listed (at the national average rate of $0.12/KWH):
        You approximately use:  42300 WH / month.
        You would pay:          $5.076 / month.

Press any key to continue . . .



                        RUN #3
What is one device that uses power in your household?    spaceship
What is another device that uses power in your household?    nuclear silo
What about a third device that uses power in your household?    Robocop

What is the watt rating for the spaceship?    -500000
What is the watt rating for the nuclear silo?    123456789
What is the watt rating for the Robocop?    1

Error: A negative number was inputted for wattage.
Press any key to continue . . .


=============================================================================*/
/*
This looks good, Leo. You have used decision statements(if) perfectly. You 
give good user prompts and error messages. Your output is well described and 
your calculations are correct. You have descriptive variable names and your 
program is well-organized and easy to follow.

Do take a look at my solution to see how I dealt with variables to avoid 
using so many separate variables. Minimizing variables isn't necessary for 
this assignment, but beginning next week you will be expected to reuse 
variables where appropriate.
*/