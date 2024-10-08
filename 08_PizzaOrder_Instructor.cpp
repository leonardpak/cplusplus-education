// CIS 15A Assignment 8 Option A, Instructor's Solution
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// global define --------------------------------------
#define MAX_TOPPINGS 20
enum size {small = 0, medium, large};

// ordinary method prototypes
void DisplayMainMenu();

// class prototype ------------------------------------
class PizzaOrder
{
public:
   static const string toppings_offered[];
   static const double topping_base_cost;
   static const double base_price;
   static const double medium_conv_factor;
   static const double large_conv_factor;

   PizzaOrder( int size = small);
   bool SetSize( int size = small);
   bool SetSizeAsChar( char sz );
   int GetSize() { return size; }
   bool AddTopping(string topping);
   bool AddTopping(int n_topping);
   double GetPrice();
   string StringizeSize();
   void GetToppings(string &list_of_toppings);
   void DisplayPizza();
   void DisplayPizzaWithoutPrice();
   void ResetToppings() { num_toppings = 0; }


private:
   int size;
   string toppings[MAX_TOPPINGS];
   bool IsLegalTopping(string test);
   int num_toppings;
   int num_legal_toppings;
};

const double PizzaOrder::medium_conv_factor = 1.15;
const double PizzaOrder::large_conv_factor = 1.25;
const double PizzaOrder::topping_base_cost = 2.50;
const double PizzaOrder::base_price = 12.95;
const string PizzaOrder::toppings_offered[] = { "onions", "bell peppers", "olives", "pepperoni", "end_of_toppings" };

// main program ----------------------------------------
int main()
{
   PizzaOrder pizza;
   string response;
   char letter;
   bool done;
   int n_choice;

   while (true)
   {
      cout << "\nSize of pizza ('s', 'm', 'l') or 'q' to quit: ";
      getline(cin, response);
      letter = response[0];
      if (letter == 'q' || letter == 'Q')
      {
         cout << "Loceff's Pizzaria is now closed.  Thanks.\n";
         break;
      }
      pizza.SetSizeAsChar(letter);
      pizza.ResetToppings();

      // loop for this pizza, getting toppings
      for (done = false; !done; )
      {
         // show what they have ordered so far
         cout << "\nCurrent Pizza: ";
         pizza.DisplayPizzaWithoutPrice();

         // get a new topping or 0
         DisplayMainMenu();
         cout << "Selection: ";
         // accept numbers as strings; don't mix cin>> with getline()
         getline(cin, response);
         istringstream(response) >> n_choice;

         if (n_choice == 0)
         {
            done = true;
            pizza.DisplayPizza();
            continue;
         }

         pizza.AddTopping(n_choice);
      }

   }
	return 0;
}

// print menu ordinary non-member method
void DisplayMainMenu()
{
   cout << "Select an item by number (0 when done):\n";
   for (int k = 0; 
      PizzaOrder::toppings_offered[k] != "end_of_toppings" && k < MAX_TOPPINGS; 
      k++)
      cout << "  " << k+1 << ". " << PizzaOrder::toppings_offered[k] << endl; 
}

// PizzeOrder method definitions  ----------------------
PizzaOrder::PizzaOrder( int size )
{
   SetSize(size);
   num_toppings = 0;
   int k;

   // determing the number of legal toppings for other methods
   for (k = 0; 
      toppings_offered[k] != "end_of_toppings" && k < MAX_TOPPINGS; 
      k++)
      ;  // empty loop body.  nothing to do.
   num_legal_toppings = k;
}

bool PizzaOrder::SetSize( int size )
{
   if (size >=small && size <= large)
      this->size = size;
   else
   {
      this->size = small; 
      return false;
   }
   return true;
}

bool PizzaOrder::SetSizeAsChar( char sz )
{
   if (sz == 's' || sz == 'S')
      size = small;
   else if (sz == 'm' || sz == 'M')
      size = medium;
   else if (sz == 'l' || sz == 'L')
     size = large;
   else
   {
      size = small;
      return false;
   }
   return true;
   // if bad param, don't change anything 
}

// version that takes actual string
bool PizzaOrder::AddTopping(string topping)
{
   if (num_toppings >= MAX_TOPPINGS)
      return false; // silently
   if (IsLegalTopping( topping ) )
   {
      toppings[num_toppings++] = topping;
      return true;
   }
   else
      // if not legal, silently return
      return false;
}

// version that takes int from 1 to legal_toppings
bool PizzaOrder::AddTopping(int n_topping)
{
   n_topping--; // the menu went from 1 to num_legal_toppings
   if (n_topping >= 0 && n_topping < num_legal_toppings )
   {
      AddTopping(toppings_offered[n_topping]);
      return true;
   }
   else
      // if not legal, silently return
      return false;
}

bool PizzaOrder::IsLegalTopping(string test)
{
   for (int k = 0; 
      toppings_offered[k] != "end_of_toppings" && k < MAX_TOPPINGS; 
      k++)
   {
      if (toppings_offered[k] == test)
         return true;
   }
   return false;
}

double PizzaOrder::GetPrice()
{
   double total;
   total = base_price + num_toppings * topping_base_cost;
   if (size == medium)
      total = total * medium_conv_factor;
   else if (size == large)
      total = total * large_conv_factor;
   return total;
}

string PizzaOrder::StringizeSize()
{
   if (size == small )
      return "small";
   else if (size == medium)
      return "medium";
   else if (size == large)
      return "large";
   else
      return "mal-formed pizza size";
}

void PizzaOrder::GetToppings(string &list_of_toppings)
{
   list_of_toppings = "";
   for (int k = 0; k < num_toppings; k++)
      list_of_toppings = list_of_toppings + " + " + toppings[k];
}

void PizzaOrder::DisplayPizza()
{
   DisplayPizzaWithoutPrice();
   cout.setf(ios::fixed);
   cout.precision(2);
   cout << "Total Price: $" << GetPrice() << endl << endl;
}

void PizzaOrder::DisplayPizzaWithoutPrice()
{
   string list_of_toppings;

   GetToppings(list_of_toppings);
   cout << StringizeSize() << " " 
      << list_of_toppings << endl;
}

/* ----------------------- SAMPLE RUN ----------------------

Size of pizza ('s', 'm', 'l') or 'q' to quit: m

Current Pizza: medium
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection: 1

Current Pizza: medium  + onions
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection: 3

Current Pizza: medium  + onions + olives
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection: 3

Current Pizza: medium  + onions + olives + olives
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection: 0
medium  + onions + olives + olives
Total Price: $23.52


Size of pizza ('s', 'm', 'l') or 'q' to quit: l

Current Pizza: large
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection: 2

Current Pizza: large  + bell peppers
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection: 0
large  + bell peppers
Total Price: $19.31


Size of pizza ('s', 'm', 'l') or 'q' to quit: s

Current Pizza: small
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection: 1

Current Pizza: small  + onions
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection: 2

Current Pizza: small  + onions + bell peppers
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection: 3

Current Pizza: small  + onions + bell peppers + olives
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection: 4

Current Pizza: small  + onions + bell peppers + olives + pepperoni
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection:

Current Pizza: small  + onions + bell peppers + olives + pepperoni + pepperoni
Select an item by number (0 when done):
  1. onions
  2. bell peppers
  3. olives
  4. pepperoni
Selection: 0
small  + onions + bell peppers + olives + pepperoni + pepperoni
Total Price: $25.45


Size of pizza ('s', 'm', 'l') or 'q' to quit: q
Loceff's Pizzaria is now closed.  Thanks.
Press any key to continue . . .

---------------------- END SAMPLE RUN ------------------------- */