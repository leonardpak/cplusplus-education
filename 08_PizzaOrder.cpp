/*===============================SOURCE========================================
                         Created by Leonard Pak
=============================================================================*/
#include <iostream>
#include <string>
using namespace std;
// ---------------------------- CLASS PROTOTYPE -------------------------------
class PizzaOrder
{
public:
   // static constant variables
   const static string TOPPINGS_OFFERED[];
   const static double TOPPING_BASE_PRICE;
   const static double PIZZA_BASE_PRICE;
   const static int MAXIMUM_TOPPINGS_ON_PIZZA = 5;
   const static int NUMBER_OF_TOPPINGS_OFFERED;
   // constructors
   PizzaOrder();
   PizzaOrder(int size);
   // accessors
   int GetSize() {return size;}
   // mutators
   bool SetSize(int size);
   bool AddTopping(string topping);
   bool AddTopping(int position);
   // instance methods
   void DisplayPizzaInfo();
   string StringizeSize(int size);
   string GetToppings();
private:
   // instance variables
   int size;
   string toppings_added[MAXIMUM_TOPPINGS_ON_PIZZA];
   int topping_amount;
   // instance methods
   double GetPrice(int size, int topping_amount);
};
//                ********** STATIC INITIALIZATION **********
const string PizzaOrder::TOPPINGS_OFFERED[] = {"Sausage","Pepperoni",
   "Ham","Mushroom","Onion","Bell Peppers","Extra Cheese"};
const double PizzaOrder::TOPPING_BASE_PRICE = 1.50;
const double PizzaOrder::PIZZA_BASE_PRICE = 10.00;
const int PizzaOrder::NUMBER_OF_TOPPINGS_OFFERED = // computes based on array
                              sizeof(PizzaOrder::TOPPINGS_OFFERED) /
                              sizeof(PizzaOrder::TOPPINGS_OFFERED[0]);
// --------------------------------- MAIN -------------------------------------
//                     ********** PROTOTYPES **********
void ToppingSelectionMenu(int size_input);
//                        ********** MAIN **********
int main()
{
   cout.setf(ios::fixed);  
   cout.precision(2);      // to force proper dollar amount
   
   int size_input;
      
   while(true)
   {
      cout << "Hello! What size pizza would you like to order?" << endl
           << "  1. Small" << endl
           << "  2. Medium" << endl
           << "  3. Large" << endl
           << "  0. Exit Order" << endl
           << "Please enter an option: ";
      cin >> size_input;

      if( size_input >= 1 && size_input <= 3 )
      {
         ToppingSelectionMenu(size_input); // moves to submenu method
      }

      if ( size_input == 0 )
      {
         cout << endl << "\tCome again!" << endl << endl;
         return 0;
      }

      if ( size_input < 0 || size_input > 3 )
      {
         cout << endl << "\tInvalid option!" << endl << endl;
         continue;
      }
   }
}
//                        ********** OTHER **********
void ToppingSelectionMenu(int size_input) // used to keep submenu separate
{                                         // to increase main readability
   int topping_input;

   PizzaOrder order(size_input - 1); // subtraction to align to menu choices
   
   while(true)
   {
      cout << endl << "Currently, your pizza is "
           << order.StringizeSize(order.GetSize()) << " size and has "
           << "these toppings:" << endl
           << order.GetToppings() << endl
           << "Would you like to add more toppings?" << endl;
      for ( int k = 0; k < PizzaOrder::NUMBER_OF_TOPPINGS_OFFERED; k++)
         // for loop used to output topping options based on array contents
      {
         cout << "  " << k+1 << ". " + PizzaOrder::TOPPINGS_OFFERED[k] 
              << endl;
      }
      cout << "  0. Finish Order" << endl
           << "Please enter an option: "; // line always printed after toppings

      cin >> topping_input;

      if (topping_input >= 1 && 
          topping_input <= PizzaOrder::NUMBER_OF_TOPPINGS_OFFERED)
      {
         order.AddTopping(topping_input - 1); // subtraction to align to array
      }

      if ( topping_input == 0 )
      {
         cout << endl << "Thanks for your order!" << endl
              << "Here is your order information: " << endl << endl;
         order.DisplayPizzaInfo();
         return; // returns to main because "submenu" is finished
      }

      if (topping_input < 0 || 
          topping_input > PizzaOrder::NUMBER_OF_TOPPINGS_OFFERED)
      {
         cout << endl << "\tInvalid option!" << endl;
      }
   }
}
// ---------------------------- CLASS FUNCTIONS -------------------------------
//                     ********** CONSTRUCTORS **********
PizzaOrder::PizzaOrder()
{
   SetSize(0);
   topping_amount = 0; // returns garbage if not set
}
PizzaOrder::PizzaOrder( int size )
{
   if(!SetSize(size))
      SetSize(0); // if client chooses bad size, defaults to small
   topping_amount = 0; // returns garbage if not set
}
//                      ********** MUTATORS **********
bool PizzaOrder::SetSize( int size )
{
   if ( size < 0 || size > 2)
      return false;
   this->size = size;
   return true;
}
bool PizzaOrder::AddTopping( string topping )
{
   if ( topping_amount == MAXIMUM_TOPPINGS_ON_PIZZA )
   {
      // aborts if user is attempting to go past maximum toppings
      cout << endl << "You have reached the maximum amount of pizza toppings!"
           << endl;
      return true;
   }

   for (int k = 0; k < NUMBER_OF_TOPPINGS_OFFERED; k++)
   {
      if ( TOPPINGS_OFFERED[k] == topping )
      {
         toppings_added[topping_amount] = topping;
         topping_amount++;
         return true;
      }
   }
   // following executed if client uses string not in 'toppings offered' array
   cout << endl << "Error: Invalid topping entered." << endl;
   return false;
}
bool PizzaOrder::AddTopping( int position )
{
   if ( topping_amount == MAXIMUM_TOPPINGS_ON_PIZZA )
   {
      // aborts if user is attempting to go past maximum toppings
      cout << endl << "You have reached the maximum amount of pizza toppings!"
           << endl;
      return true;
   }

   if ( position < 0 || position > ( NUMBER_OF_TOPPINGS_OFFERED - 1 ) )
   {
      // executed if client enters invalid array element number
      cout << endl << "Error: Invalid array position for topping." << endl;
      return false;
   }
   toppings_added[topping_amount] = TOPPINGS_OFFERED[position];
   topping_amount++;
   return true;
}
//                        ********** OTHER **********
void PizzaOrder::DisplayPizzaInfo()
{
   cout << "\tSize: " << StringizeSize(size) << endl
        << "\tToppings: " << GetToppings() << endl
        << "\tPrice: $" << GetPrice(size,topping_amount) << endl << endl;
}
string PizzaOrder::StringizeSize( int size )
{
   switch (size)
   {
      case 0: 
         return "small";
      case 1: 
         return "medium";
      case 2: 
         return "large";
      default:
         return "ERROR"; // notifies client if method somehow receives bad int
   }
}
string PizzaOrder::GetToppings()
{
   string toppings_list;
   
   for (int k = 0; k < topping_amount; k++)
   {
      toppings_list += "    " + toppings_added[k];
   }
   return toppings_list;
}
double PizzaOrder::GetPrice( int size, int topping_amount )
{
   double multiplier;

   switch(size)
   {
      case 0: 
         multiplier = 1.00;
         break;
      case 1: 
         multiplier = 1.15;
         break;
      case 2: 
         multiplier = 1.25;
         break;
      default:
         multiplier = 0.00; // to indicate error
   }
   return ( (PIZZA_BASE_PRICE + (topping_amount * TOPPING_BASE_PRICE))
               * multiplier );
}
/*===============================OUTPUT========================================
Hello! What size pizza would you like to order?
  1. Small
  2. Medium
  3. Large
  0. Exit Order
Please enter an option: -1

        Invalid option!

Hello! What size pizza would you like to order?
  1. Small
  2. Medium
  3. Large
  0. Exit Order
Please enter an option: 4

        Invalid option!

Hello! What size pizza would you like to order?
  1. Small
  2. Medium
  3. Large
  0. Exit Order
Please enter an option: 1

Currently, your pizza is small size and has these toppings:

Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 2

Currently, your pizza is small size and has these toppings:
    Pepperoni
Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 4

Currently, your pizza is small size and has these toppings:
    Pepperoni    Mushroom
Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 0

Thanks for your order!
Here is your order information:

        Size: small
        Toppings:     Pepperoni    Mushroom
        Price: $13.00

Hello! What size pizza would you like to order?
  1. Small
  2. Medium
  3. Large
  0. Exit Order
Please enter an option: 2

Currently, your pizza is medium size and has these toppings:

Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 1

Currently, your pizza is medium size and has these toppings:
    Sausage
Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 5

Currently, your pizza is medium size and has these toppings:
    Sausage    Onion
Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 7

Currently, your pizza is medium size and has these toppings:
    Sausage    Onion    Extra Cheese
Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 0

Thanks for your order!
Here is your order information:

        Size: medium
        Toppings:     Sausage    Onion    Extra Cheese
        Price: $16.67

Hello! What size pizza would you like to order?
  1. Small
  2. Medium
  3. Large
  0. Exit Order
Please enter an option: 3

Currently, your pizza is large size and has these toppings:

Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 6

Currently, your pizza is large size and has these toppings:
    Bell Peppers
Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 3

Currently, your pizza is large size and has these toppings:
    Bell Peppers    Ham
Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 2

Currently, your pizza is large size and has these toppings:
    Bell Peppers    Ham    Pepperoni
Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 2

Currently, your pizza is large size and has these toppings:
    Bell Peppers    Ham    Pepperoni    Pepperoni
Would you like to add more toppings?
  1. Sausage
  2. Pepperoni
  3. Ham
  4. Mushroom
  5. Onion
  6. Bell Peppers
  7. Extra Cheese
  0. Finish Order
Please enter an option: 0

Thanks for your order!
Here is your order information:

        Size: large
        Toppings:     Bell Peppers    Ham    Pepperoni    Pepperoni
        Price: $20.00

Hello! What size pizza would you like to order?
  1. Small
  2. Medium
  3. Large
  0. Exit Order
Please enter an option: 0

        Come again!

Press any key to continue . . .
=============================================================================*/
/*
An if/else if is the correct choice for mutually exclusive options rather than
successive if statements. (-.5)

If the current pizza has no toppings, you should not output "Your Pizza has 
these toppings:".

You should not use constants like 0 or 2 in programs.   Use symbolic constants 
like MAX_SIZE as #define or as static const int. This makes your code more 
readable, less error prone and easier to update.(-.5)

You are not using the provided variable names in some cases. Following a 
program specification is extremely important. Since most programming is done
in teams, it is imperative that each programmer write his/her code to the 
spec so that the code of the different programmers will work together.

Mutators like AddTopping() should not do output or call a function that does
output. (-1.5)
*/