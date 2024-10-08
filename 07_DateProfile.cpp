/*===============================SOURCE========================================
                         Created by Leonard Pak
=============================================================================*/

#include <iostream>
#include <string>
using namespace std;

// ---------------------------- CLASS PROTOTYPE ----------------------------
class DateProfile
{
public:
   // static constant variables
   static const int ROMANCE_MIN = 1;
   static const int ROMANCE_MAX = 10;
   static const int FINANCE_MIN = 1;
   static const int FINANCE_MAX = 10;
   static const int NAME_LENGTH_MIN = 3;
   static const int NAME_LENGTH_MAX = 40;
   // constructors
   DateProfile();
   DateProfile(char, char, int, int, string);
   // accessors
   char GetGender() { return gender; }
   char GetSearchGender() {return search_gender; }
   int GetRomance() { return romance; }
   int GetFinance() { return finance; }
   string GetName() { return name; }
   // mutators
   bool SetGender( char gender );
   bool SetSearchGender( char search_gender);
   bool SetRomance( int romance );
   bool SetFinance( int finance );
   bool SetName( string name );
   // instance methods
   void DisplayInfo();
   double FitValue(DateProfile partner);
private:
   // instance variables
   char gender;
   char search_gender;
   int romance;
   int finance;
   string name;
   // instance methods
   double DetermineGenderFit(DateProfile partner);
   double DetermineRomanceFit(DateProfile partner);
   double DetermineFinanceFit(DateProfile partner);
};

// --------------------------------- MAIN ---------------------------------
//                     ********** PROTOTYPES **********
bool CompatibilityConclusion(double fitvalue);
void CompareToOtherThree(DateProfile one, DateProfile two, 
                         DateProfile three, DateProfile four);
//                        ********** MAIN **********
int main()
{
   // object creation
   DateProfile applicant1('M', 'F', 6, 4, "Joe Average");
   DateProfile applicant2('M', 'F', 3, 3, "Aidunn Caremuch");
   DateProfile applicant3('F', 'M', 1, 10, "Goldee Digga");
   DateProfile applicant4('F', 'M', 4, 6, "Jane Ordinary");
   // display object information
   applicant1.DisplayInfo();
   applicant2.DisplayInfo();
   applicant3.DisplayInfo();
   applicant4.DisplayInfo();
   // display comparisions
   CompareToOtherThree(applicant1, applicant2, applicant3, applicant4);
   CompareToOtherThree(applicant2, applicant1, applicant3, applicant4);
   CompareToOtherThree(applicant3, applicant1, applicant2, applicant4);
   CompareToOtherThree(applicant4, applicant1, applicant2, applicant3);
}
//                        ********** OTHER **********
bool CompatibilityConclusion(double fitvalue)
{
   const double COMPATIBILITY_THRESHOLD = 0.35;

   if (fitvalue > COMPATIBILITY_THRESHOLD)
      return true;
   else
      return false;
}
void CompareToOtherThree(DateProfile one, DateProfile two, 
                         DateProfile three, DateProfile four)
{
   cout << one.GetName();
   // compare first parameter to second parameter
   cout << "\n   " << two.GetName() << " - Rating: " << one.FitValue(two);
   if ( CompatibilityConclusion(one.FitValue(two)) ) // concludes suitability
      cout << "   <--- This person is a good match!";
   // compare first parameter to third parameter
   cout << "\n   " << three.GetName() << " - Rating: " << one.FitValue(three);
   if ( CompatibilityConclusion(one.FitValue(three)) ) // concludes suitability
      cout << "   <--- This person is a good match!";
   // compare first parameter to fourth parameter
   cout << "\n   " << four.GetName() << " - Rating: " << one.FitValue(four);
   if ( CompatibilityConclusion(one.FitValue(four)) ) // concludes suitability
      cout << "   <--- This person is a good match!";
   // compare first parameter with itself
   cout << "\n   " << one.GetName() << " - Rating: " << one.FitValue(one)
      << endl;
}
// ---------------------------- CLASS FUNCTIONS ----------------------------
//                     ********** CONSTRUCTORS **********
DateProfile::DateProfile()
{
   SetGender('M');
   SetSearchGender('F');
   SetRomance(5);
   SetFinance(5);
   SetName("John Doe");
}
DateProfile::DateProfile(char gender, char search_gender, int romance,
                         int finance, string name)
{
   SetGender(gender);
   SetSearchGender(search_gender);
   SetRomance(romance);
   SetFinance(finance);
   SetName(name);
}
//                      ********** MUTATORS **********
bool DateProfile::SetGender( char gender )
{
   if ( gender == 'm' || gender == 'f' ) // force standardized capital letter
      gender = toupper(gender);
   if ( gender != 'M' && gender != 'F')
      return false;
   this->gender = gender;
      return true;
}
bool DateProfile::SetSearchGender( char search_gender )
{
   if ( search_gender == 'm' || search_gender == 'f' ) // force standardized
      gender = toupper(search_gender);                 //   capital letter
   if ( search_gender != 'M' && search_gender != 'F')
      return false;
   this->search_gender = search_gender;
      return true;
}
bool DateProfile::SetRomance( int romance )
{
   if ( romance < ROMANCE_MIN || romance > ROMANCE_MAX )
      return false;
   this->romance = romance;
      return true;
}
bool DateProfile::SetFinance( int finance )
{
   if ( finance < FINANCE_MIN || finance > FINANCE_MAX )
      return false;
   this->finance = finance;
      return true;
}
bool DateProfile::SetName( string name )
{
   if ( name.length() < NAME_LENGTH_MIN || name.length() > NAME_LENGTH_MAX )
      return false;
   this->name = name;
      return true;
}
//                        ********** OTHER **********
void DateProfile::DisplayInfo()
{
   cout << "Date Profile: "
      << endl << " Name: " << name
      << endl << " Gender:   " << gender << "\tDesired:  " << search_gender
      << endl << " Romance:  " << romance << "\tFinance:  " << finance
      << endl << endl;
}
double DateProfile::FitValue(DateProfile partner)
{
   return ( DetermineGenderFit(partner) * 
            DetermineRomanceFit(partner) *
            DetermineFinanceFit(partner) );
}
double DateProfile::DetermineGenderFit(DateProfile partner)
{
   if ( this->search_gender == partner.GetGender() )
      return 1.0;
   else
      return 0.0;
}
double DateProfile::DetermineRomanceFit(DateProfile partner)
{
   double lower, higher; // for comparison calculation

   if ( this->romance == partner.GetRomance() )
   {
      return 1.0;
   }
   else if ( this->romance > partner.GetRomance() )
   {
      higher = this->romance;
      lower = partner.GetRomance();
   }
   else
   {
      higher = partner.GetRomance();
      lower = this->romance;
   }
   return (lower / higher);
}
double DateProfile::DetermineFinanceFit(DateProfile partner)
{
   double lower, higher; // for comparison calculation

   if ( this->finance == partner.GetFinance() )
   {
      return 1.0;
   }
   else if ( this->finance > partner.GetFinance() )
   {
      higher = this->finance;
      lower = partner.GetFinance();
   }
   else
   {
      higher = partner.GetFinance();
      lower = this->finance;
   }
   return (lower / higher);
}
/*===============================OUTPUT========================================
Date Profile:
 Name: Joe Average
 Gender:   M    Desired:  F
 Romance:  6    Finance:  4

Date Profile:
 Name: Aidunn Caremuch
 Gender:   M    Desired:  F
 Romance:  3    Finance:  3

Date Profile:
 Name: Goldee Digga
 Gender:   F    Desired:  M
 Romance:  1    Finance:  10

Date Profile:
 Name: Jane Ordinary
 Gender:   F    Desired:  M
 Romance:  4    Finance:  6

Joe Average
   Aidunn Caremuch - Rating: 0
   Goldee Digga - Rating: 0.0666667
   Jane Ordinary - Rating: 0.444444   <--- This person is a good match!
   Joe Average - Rating: 0
Aidunn Caremuch
   Joe Average - Rating: 0
   Goldee Digga - Rating: 0.1
   Jane Ordinary - Rating: 0.375   <--- This person is a good match!
   Aidunn Caremuch - Rating: 0
Goldee Digga
   Joe Average - Rating: 0.0666667
   Aidunn Caremuch - Rating: 0.1
   Jane Ordinary - Rating: 0
   Goldee Digga - Rating: 0
Jane Ordinary
   Joe Average - Rating: 0.444444   <--- This person is a good match!
   Aidunn Caremuch - Rating: 0.375   <--- This person is a good match!
   Goldee Digga - Rating: 0
   Jane Ordinary - Rating: 0
Press any key to continue . . .
=============================================================================*/
/*
Methods should not mix computation with display except for main(). Your 
method that displays the matches is also calling FitValue() which does 
computation so this is a violation of the rule.  Sometimes this is okay, but 
you have to name the function accordingly.  CompareToOtherTwo() sounds like a
computational method, not an output method.  (-.5)

In your mutator methods, you allowed the client to possibly leave the 
variables undefined, and thus "garbage" by not assigning a default.  This 
would have been okay if your constructor was guaranteed to make a correct 
assignment but your constructor calls this and does nothing if the value 
passed to the constructor was invalid.(-.5)

It is not a good idea to alter the parameter in a method. Either create a 
local variable or return the value directly.

Your DetermineGenderFit() was not correct.  You needed to compare the 
SearchGender of A with the Gender of B and the SearchGender of B with the 
Gender of A. You only make one comparison.(-1)

Your DetermineRomanceFit() and DetermineFinanceFit() are not correct. If the 
values are 2 and 4, the FitValue should be higher than if they are 5 and 
10.(-1.5)

There is no need for a special case in Determining Romance and Finance.
*/