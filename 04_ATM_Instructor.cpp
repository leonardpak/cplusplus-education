// CIS 15A - Assignment 4, Option A
// Instructor Solution
// Notes:
//   - Loops and if statements are correctly indented.
//   - Logical operators, ||, are used to simplify if statments
//   - Lines are shorter than 80 characters.
//   - Program run contains enough input to demonstrate all functionality.
//   - Error messages are clear.
//   - Tests for excessive withdrawal or illegal (negative) deposits included.
//   - getline() used everywhere -- we did not mix cin with getline().

// ---------------- SOURCE -------------------------

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
   string user_choice;
   char letter;
   int length, amount;
   int balance = 5000;
  
   // Get menu choices from the user until s/he says "quit".
   while (true)
   {
      // get the menu choice from user
      cout << "Menu: \n  W (Withdrawal) \n  D (Deposit)"
            << "\n  B (Show Balance) \n  Q (Quit) \n\n  Your Choice: "; 
      getline(cin, user_choice);
      
      length = user_choice.length();
      if (length < 1)
      {
         cout << "No choice made, try again.\n";
         continue;   // string is empty, so go again
      }

      // store in letter for reuse
      letter = user_choice[0];

      // test for quit first
      if (letter == 'q'  || letter == 'Q')
      {
         cout << "Thank you for using the Bank of Loceff\n";
         break;  // from loop
      }
      else if (letter == 'W' || letter == 'w')
      {
         // we do a withdrawal
         cout << "\n  Amount of Withdrawal (whole dollars only): ";
         getline(cin, user_choice);
         istringstream(user_choice) >> amount;
         if (amount > balance || amount <= 0 )
            cout << "Sorry, amounts must be between 0 and $" 
               << balance << endl;
         else
         {
            balance-=amount;
         }
      }
      else if (letter == 'D' || letter == 'd')
      {
         // we do a deposit
         cout << "\n  Amount of Deposit (whole dollars only): ";
         getline(cin, user_choice);
         istringstream(user_choice) >> amount;
         if (amount <= 0 )
            cout << "Sorry, amount must be > 0\n";
         else
         {
            balance+=amount;
         }
      }
      else if (letter == 'B' || letter == 'b')
      {
         // we do a balance
         // nothing to do, since we print balance anyway, below
      }
      else
      {
         // this letter is not one of the three legal types
         cout << "Use W, D, B or Q, please.\n";
         continue;   // the main loop 
      }
      // in all cases, print balance
      cout << "\n  Your current balance is $" << balance << endl;
   }
   
   cout << "\nGood bye.\n";

   return 0;
}

/* ----------------------- SAMPLE RUN ----------------------------

Menu:
  W (Withdrawal)
  D (Deposit)
  B (Show Balance)
  Q (Quit)

  Your Choice: joke
Use W, D, B or Q, please.
Menu:
  W (Withdrawal)
  D (Deposit)
  B (Show Balance)
  Q (Quit)

  Your Choice: depositspelledworng

  Amount of Deposit (whole dollars only): 250

  Your current balance is $5250
Menu:
  W (Withdrawal)
  D (Deposit)
  B (Show Balance)
  Q (Quit)

  Your Choice: d

  Amount of Deposit (whole dollars only): -199
Sorry, amount must be > 0

  Your current balance is $5250
Menu:
  W (Withdrawal)
  D (Deposit)
  B (Show Balance)
  Q (Quit)

  Your Choice: d

  Amount of Deposit (whole dollars only): 500

  Your current balance is $5750
Menu:
  W (Withdrawal)
  D (Deposit)
  B (Show Balance)
  Q (Quit)

  Your Choice: b

  Your current balance is $5750
Menu:
  W (Withdrawal)
  D (Deposit)
  B (Show Balance)
  Q (Quit)

  Your Choice: W

  Amount of Withdrawal (whole dollars only): 99999
Sorry, amounts must be between 0 and $5750

  Your current balance is $5750
Menu:
  W (Withdrawal)
  D (Deposit)
  B (Show Balance)
  Q (Quit)

  Your Choice: W

  Amount of Withdrawal (whole dollars only): 999

  Your current balance is $4751
Menu:
  W (Withdrawal)
  D (Deposit)
  B (Show Balance)
  Q (Quit)

  Your Choice: With

  Amount of Withdrawal (whole dollars only): 123

  Your current balance is $4628
Menu:
  W (Withdrawal)
  D (Deposit)
  B (Show Balance)
  Q (Quit)

  Your Choice: d

  Amount of Deposit (whole dollars only): 123

  Your current balance is $4751
Menu:
  W (Withdrawal)
  D (Deposit)
  B (Show Balance)
  Q (Quit)

  Your Choice: QUIT!!
Thank you for using the Bank of Loceff

Good bye.
Press any key to continue . . .

------------------------- END SAMPLE RUN ----------------------- */

