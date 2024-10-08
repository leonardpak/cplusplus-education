/*===============================SOURCE========================================
                         Created by Leonard Pak
=============================================================================*/

#include <iostream>
#include <string>
using namespace std;

int main ()
{
   double checking = 5000;       // checking account balance
   double transaction = 0;       // number used for deposits/withdrawals
   string menu_input = "RESET";  // string used to start/return to main menu

   // introductory statement
   cout << "\n"    << "Welcome to Bailout Bank's ATM!"
        << "\n\n"  << "\"Where your money is ours no matter what -- "
        << "\n\t"  << "from your deposits OR from your taxes!\""
        << "\n\n"  << "Your current balance is: $" << checking;

   // menu system
   while (menu_input == "RESET")
   {
      cout << "\n\n"  << "Please choose from the following menu entries: "
           << "\n"    << "   - W (Withdrawal)"
           << "\n"    << "   - D (Deposit)"
           << "\n"    << "   - B (Show Balance)"
           << "\n"    << "   - Q (Quit)"
           << "\n\n"  << "Your choice: ";
      cin >> menu_input;
      menu_input = menu_input[0];

      // ERROR DETECTION
      if (menu_input != "w" && menu_input != "W" &&
          menu_input != "d" && menu_input != "D" &&
          menu_input != "b" && menu_input != "B" &&
          menu_input != "q" && menu_input != "Q" &&
          menu_input != "RESET")
      {
         cout << "\n" << "Invalid entry!";
         menu_input = "RESET";
      }

      // WITHDRAW
      else if (menu_input == "w" || menu_input == "W")
      {
         cout << "\n" << "How much would you like to withdraw?"
              << "\n" << "Please enter withdrawal amount: $";
         cin >> transaction;
         
         while (transaction <= 0 || transaction > checking)
         {
            cout << "\n" << "Invalid withdrawal amount."
                 << "\n" << "Your current balance is: $" << checking
                 << "\n" << "Please try again: $";
            cin >> transaction;
         }

         checking = checking - transaction;
         cout << "\n" << "You have withdrawn: $" << transaction
              << "\n" << "Your current balance is: $" << checking
              << "\n\n" << "Returning to main menu...";

         menu_input = "RESET";
      }

      // DEPOSIT
      else if (menu_input == "d" || menu_input == "D")
      {
         cout << "\n" << "How much would you like to deposit?"
              << "\n" << "Please enter deposit amount: $";
         cin >> transaction;
         
         while (transaction <= 0)
         {
            cout << "\n" << "Invalid deposit amount."
                 << "\n" << "Please try again: $";
            cin >> transaction;
         }

         checking = checking + transaction;
         cout << "\n" << "You have deposited: $" << transaction
              << "\n" << "Your current balance is: $" << checking
              << "\n\n" << "Returning to main menu...";

         menu_input = "RESET";
      }
      
      // BALANCE
      else if (menu_input == "b" || menu_input == "B")
      {
         cout << "\n" << "Your current balance is: $" << checking
              << "\n\n" << "Returning to main menu...";

         menu_input = "RESET";
      }

      // QUIT
      else if (menu_input == "q" || menu_input == "Q")
      {
         cout << "\n" << "Are you sure you would like to quit?"
              << "\n" << "   Enter Y (Yes) to quit"
              << "\n" << "   Enter anything else to return to the main menu"
              << "\n" << "Your choice: ";
         cin >> menu_input;
         menu_input = menu_input[0];

         if (menu_input == "y" || menu_input == "Y")
         {
            cout << "\n" << "Thanks for using Bailout Bank!"
                 << "\n\n";
            return 0;
         }
         else
         {
            cout << "\n\n" << "Returning to main menu...";
            menu_input = "RESET";
         }
      }

   } // end menu system
} // end method main

/*===============================OUTPUT========================================

Welcome to Bailout Bank's ATM!

"Where your money is ours no matter what --
        from your deposits OR from your taxes!"

Your current balance is: $5000

Please choose from the following menu entries:
   - W (Withdrawal)
   - D (Deposit)
   - B (Show Balance)
   - Q (Quit)

Your choice: 1

Invalid entry!

Please choose from the following menu entries:
   - W (Withdrawal)
   - D (Deposit)
   - B (Show Balance)
   - Q (Quit)

Your choice: w

How much would you like to withdraw?
Please enter withdrawal amount: $5001

Invalid withdrawal amount.
Your current balance is: $5000
Please try again: $0

Invalid withdrawal amount.
Your current balance is: $5000
Please try again: $5000

You have withdrawn: $5000
Your current balance is: $0

Returning to main menu...

Please choose from the following menu entries:
   - W (Withdrawal)
   - D (Deposit)
   - B (Show Balance)
   - Q (Quit)

Your choice: b

Your current balance is: $0

Returning to main menu...

Please choose from the following menu entries:
   - W (Withdrawal)
   - D (Deposit)
   - B (Show Balance)
   - Q (Quit)

Your choice: d

How much would you like to deposit?
Please enter deposit amount: $0

Invalid deposit amount.
Please try again: $10000

You have deposited: $10000
Your current balance is: $10000

Returning to main menu...

Please choose from the following menu entries:
   - W (Withdrawal)
   - D (Deposit)
   - B (Show Balance)
   - Q (Quit)

Your choice: b

Your current balance is: $10000

Returning to main menu...

Please choose from the following menu entries:
   - W (Withdrawal)
   - D (Deposit)
   - B (Show Balance)
   - Q (Quit)

Your choice: q

Are you sure you would like to quit?
   Enter Y (Yes) to quit
   Enter anything else to return to the main menu
Your choice: nosiree


Returning to main menu...

Please choose from the following menu entries:
   - W (Withdrawal)
   - D (Deposit)
   - B (Show Balance)
   - Q (Quit)

Your choice: withdrawwwzzzz

How much would you like to withdraw?
Please enter withdrawal amount: $5251

You have withdrawn: $5251
Your current balance is: $4749

Returning to main menu...

Please choose from the following menu entries:
   - W (Withdrawal)
   - D (Deposit)
   - B (Show Balance)
   - Q (Quit)

Your choice: Balancez

Your current balance is: $4749

Returning to main menu...

Please choose from the following menu entries:
   - W (Withdrawal)
   - D (Deposit)
   - B (Show Balance)
   - Q (Quit)

Your choice: D3p0s17s

How much would you like to deposit?
Please enter deposit amount: $100000

You have deposited: $100000
Your current balance is: $104749

Returning to main menu...

Please choose from the following menu entries:
   - W (Withdrawal)
   - D (Deposit)
   - B (Show Balance)
   - Q (Quit)

Your choice: q

Are you sure you would like to quit?
   Enter Y (Yes) to quit
   Enter anything else to return to the main menu
Your choice: y

Thanks for using Bailout Bank!

Press any key to continue . . .
=============================================================================*/
/*
There is no reason to have a huge logic statement for the test for invalid 
option input.  If you use if/else statements along the way, then a final else 
statement without a single test can be used to report invalid input. (-.5)

Good errror checking overall. It is also a good idea to put a cap on the 
deposit amount. Numbers (and strings) can be too large, so an upper limit 
should be defined to avoid this.

Error messages should be as specific as possible. Tell the user exactly what 
they did wrong. is the amount too high? Too low?

NIce Leo. I like the addition of the confirmation of quitting. Other than 
what I noted above, this is a well organized program. Your run is good - it 
shows what your program does with both valid and invalid input. Your output 
is clear and easy to read.
*/