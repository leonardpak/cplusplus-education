// 15a_assignment_6 Option A

#include <string>
#include <iostream>
using namespace std;

#define CHERRIES " cherries "
#define SEVEN " 7 "
#define BAR " BAR "
#define SPACE " (space) "
#define MAX_BET = 100;

// method prototypes ---------------------------
int GetBet();
string PullOne();
int GetPayMultiplier (string string_1, string string_2, string string_3);
void Display (string string_1, string string_2, string string_3, int multiplier );

// main ----------------------------------------
int main()
{
   int user_bet, multiplier, winnings;
   string string_1, string_2, string_3;
   
   for (user_bet = GetBet(); user_bet > 0; user_bet = GetBet() )
   {
      string_1 = PullOne();
      string_2 = PullOne();
      string_3 = PullOne();

      multiplier = GetPayMultiplier (string_1, string_2, string_3);
      winnings = multiplier * user_bet;

      Display( string_1, string_2, string_3, winnings);
   }

   cout << "Thanks for coming to Casino Loceff\n";
   return 0;
}

// method definitions --------------------------
int GetBet()
{
   int user_bet;
   do
   {
      cout << "How much would you like to bet (1 - 100) or 0 to quit? ";
      cin >> user_bet;
   } while (user_bet < 0 || user_bet > MAX_BET);
   return user_bet;
}

string PullOne()
{
   switch( rand()%4 )
   {
   case 0:
      return CHERRIES;
   case 1:
      return SEVEN;
   case 2:
      return BAR;
   case 3:
      return SPACE;
   }
}

int GetPayMultiplier (string string_1, string string_2, string string_3)
{
   // case 1:  start with "cherries"
   if (string_1 == CHERRIES)
   {
      if (string_2 != CHERRIES)
         return 3; // cherries|not cherries|any
      else if (string_3 != CHERRIES)
         return 10; //cherries|cherries|not cherries
      else
         return 20; // cherries|cherries|cherries
   }

   // case 2: start with "bar"
   if (string_1 == BAR & string_2 == BAR & string_3 == BAR)
      return 35;  // bar|bar|bar

   // case 3: start with "7"
   if (string_1 == SEVEN & string_2 == SEVEN & string_3 == SEVEN)
      return 50; // 7|7|7

   // all other cases return nothing
   return 0;
}

void Display (string string_1, string string_2, string string_3, int winnings )
{

   cout << "whirrrrrr .... and your pull is ... \n";
   cout << string_1 + string_2 + string_3 << endl;
   if (winnings > 0)
      cout << "congratulations, you win: " << winnings << endl;
   else
      cout << "sorry, you lose.\n";
}

/* ------------------- Sample Run ---------------------

How much would you like to bet (1 - 10) or 0 to quit? 3
whirrrrrr .... and your pull is ...
 7  (space)  BAR
sorry, you lose.
How much would you like to bet (1 - 10) or 0 to quit? 3
whirrrrrr .... and your pull is ...
 cherries  7  cherries
congratulations, you win: 9
How much would you like to bet (1 - 10) or 0 to quit? -1
How much would you like to bet (1 - 10) or 0 to quit? 1234
How much would you like to bet (1 - 10) or 0 to quit? 4
whirrrrrr .... and your pull is ...
 BAR  BAR  BAR
congratulations, you win: 140
How much would you like to bet (1 - 10) or 0 to quit? 1
whirrrrrr .... and your pull is ...
 cherries  7  7
congratulations, you win: 3
How much would you like to bet (1 - 10) or 0 to quit? 1
whirrrrrr .... and your pull is ...
 7  (space)  7
sorry, you lose.
How much would you like to bet (1 - 10) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 (space)  (space)  BAR
sorry, you lose.
How much would you like to bet (1 - 10) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 (space)  cherries  (space)
sorry, you lose.
How much would you like to bet (1 - 10) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 cherries  BAR  7
congratulations, you win: 6
How much would you like to bet (1 - 10) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 cherries  BAR  7
congratulations, you win: 6
How much would you like to bet (1 - 10) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 cherries  BAR  (space)
congratulations, you win: 6
How much would you like to bet (1 - 10) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 (space)  BAR  (space)
sorry, you lose.
How much would you like to bet (1 - 10) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 BAR  7  cherries
sorry, you lose.
How much would you like to bet (1 - 10) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 (space)  (space)  (space)
sorry, you lose.
How much would you like to bet (1 - 10) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 BAR  (space)  (space)
sorry, you lose.
How much would you like to bet (1 - 10) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 BAR  7  7
sorry, you lose.
How much would you like to bet (1 - 10) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 cherries  7  (space)
congratulations, you win: 6
How much would you like to bet (1 - 10) or 0 to quit? 0
Thanks for coming to Casino Loceff
Press any key to continue . . .

------------------------------------------------------ */