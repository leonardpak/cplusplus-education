/*===============================SOURCE========================================
                         Created by Leonard Pak
=============================================================================*/

#include <iostream>
#include <string>
using namespace std;

int GetBet(); 
string PullOne();
int GetPayMultiplier(string s1, string s2, string s3);
void Display(string s1, string s2, string s3, int winnings);

int main()
{
   while(true)
   {
      int bet = GetBet();

      if ( bet == 0 )   // test to see if user wants to quit
      {
         cout << "Thanks for playing!" << endl;
         return 0;
      }

      string slot1 = PullOne();
      string slot2 = PullOne();
      string slot3 = PullOne();
      
      int winnings = bet * GetPayMultiplier(slot1, slot2, slot3);

      Display(slot1, slot2, slot3, winnings);
   }
}

int GetBet()
{
   int bet;
   
   while(true)
   {
      cout << "\n" << "Please place a bet for the slot machine!"
           << "\n" << "   Bets between $1 and $100 are acceptable."
           << "\n" << "   If you want to quit, please enter '$0' for your bet."
           << "\n\n" << "Please enter your bet: $";
      cin >> bet;

      if ( bet >= 0 && bet <= 100 )
      {
         cout << endl;
         return bet;
      }
      else
      {
         cout << "\n" << "Invalid amount: Must be between $0 and $100!"
              << endl;
         continue;
      }
   }
}

string PullOne()
{
   string possibility0 = "BAR";
   string possibility1 = "7";
   string possibility2 = "cherries";
   string possibility3 = "(space)";
   
   switch ( rand() % 4 )
   {
      case 0: return possibility0;
      case 1: return possibility1;
      case 2: return possibility2;
      case 3: return possibility3;
   }
}

int GetPayMultiplier(string s1, string s2, string s3)
{
   if ( s1 == "cherries" && s2 != "cherries" )
      return 3;
   else if ( s1 == "cherries" && s2 == "cherries" && s3 != "cherries" )
      return 10;
   else if ( s1 == "cherries" && s2 == "cherries" && s3 == "cherries" )
      return 20;
   else if ( s1 == "BAR" && s2 == "BAR" && s3 == "BAR" )
      return 35;
   else if ( s1 == "7" && s2 == "7" && s3 == "7" )
      return 50;
   else
      return 0;
}

void Display(string s1, string s2, string s3, int winnings)
{
   cout << "The slot machine results were: " << endl
        << "\n\t" << s1 << "\t\t" << s2 << "\t\t" << s3 << endl;
   if ( winnings == 0 )
   {
      cout << "\n" << "Sorry, you lose." << endl;
   }
   else
   {
      cout << "\n" << "Your earnings were: $" << winnings << endl;
   }
}

/*===============================OUTPUT========================================

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $1

The slot machine results were:

        7               (space)         cherries

Sorry, you lose.

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $5

The slot machine results were:

        BAR             7               BAR

Sorry, you lose.

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $10

The slot machine results were:

        cherries                cherries                cherries

Your earnings were: $200

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $20

The slot machine results were:

        BAR             7               7

Sorry, you lose.

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $30

The slot machine results were:

        7               (space)         7

Sorry, you lose.

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $40

The slot machine results were:

        (space)         (space)         cherries

Sorry, you lose.

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $50

The slot machine results were:

        (space)         BAR             (space)

Sorry, you lose.

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $60

The slot machine results were:

        BAR             cherries                7

Sorry, you lose.

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $70

The slot machine results were:

        BAR             cherries                7

Sorry, you lose.

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $80

The slot machine results were:

        BAR             cherries                (space)

Sorry, you lose.

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $90

The slot machine results were:

        (space)         cherries                (space)

Sorry, you lose.

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $100

The slot machine results were:

        cherries                7               BAR

Your earnings were: $300

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $101

Invalid amount: Must be between $0 and $100!

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $-1

Invalid amount: Must be between $0 and $100!

Please place a bet for the slot machine!
   Bets between $1 and $100 are acceptable.
   If you want to quit, please enter '$0' for your bet.

Please enter your bet: $0

Thanks for playing!
Press any key to continue . . .
=============================================================================*/
/*
Use words for variable names not things like s1, s2, etc. This makes your 
code more readable. In such a short program, it doesn't seem like much of an
issue, but you want to create good programming habits now so that when  you
are working with larger projects,  your code is great. Since these names 
were in the spec, there is no deduction this week.

Variables should be declared at the top of each method. Here, you are
declaring variables within a loop. When we only want to do something once,
as with variable declaration, it needs to go outside of the loop.(-1)

The switch statement should have the bodies on separate lines from the 
case keyword. (-.5)

It is also better form to have a default case even when you expect that it 
can never be reached.
*/