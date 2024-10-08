// 15a_assignment_7a Instructor's solution.


#include <iostream>
#include <string>
using namespace std;

// DateProfile Class Prototype
class DateProfile
{
  private:
   char gender;
   char search_gender;
   int romance;
   int finance;
   string name;
  public:
   // int static consts can be initialized in-line like so:
   static const int MIN_VAL = 1;
   static const int MAX_VAL = 10;
   static const int MAX_NAME_LENGTH = 100;
   static const int MIN_NAME_LENGTH = 3;

   // constructors
   DateProfile();
   DateProfile(char gen, char srch_gen, int rom, int fin, string nm);

   // mutators
   bool SetGender(char gen);
   bool SetSearchGender(char gen);
   bool SetRomance(int rom);
   bool SetFinance(int fin);
   bool SetName(string nm);

   // accessors
   char GetGender() { return gender; }
   char GetSearchGender() { return search_gender; }
   int GetRomance() { return romance; }
   int GetFinance() { return finance; }
   string GetName() { return name; }

   // computational
   double FitValue(DateProfile partner);

  private:
   // helpers
   bool ValidGender(char gen);
   void SetAll(char gen, char srch_gen, int rom, int fin, string nm);
   double DetermineGenderFit(DateProfile partner);
   double DetermineRomanceFit(DateProfile partner);
   double DetermineFinanceFit(DateProfile partner);
};

// Main Program (Client)
int main()
{
   DateProfile app1('m', 'f', 2, 8, "Joe Somebody"),
      app2('m', 'f', 5, 5, "Steve Nobody"),
      app3('f', 'm', 1, 7, "Jane Peabody"),
      app4('f', 'm', 4, 9, "Helen Anybody");

   // compare everyone to Helen
   cout << app1.GetName() << endl;
   cout << "    " << app1.GetName() << " fit: " << app1.FitValue(app1) << endl;
   cout << "    " << app2.GetName() << " fit: " << app1.FitValue(app2) << endl;
   cout << "    " << app3.GetName() << " fit: " << app1.FitValue(app3) << endl;
   cout << "    " << app4.GetName() << " fit: " << app1.FitValue(app4) << endl;

   // compare everyone to Joe
   cout << app2.GetName() << endl;
   cout << "    " << app1.GetName() << " fit: " << app2.FitValue(app1) << endl;
   cout << "    " << app2.GetName() << " fit: " << app2.FitValue(app2) << endl;
   cout << "    " << app3.GetName() << " fit: " << app2.FitValue(app3) << endl;
   cout << "    " << app4.GetName() << " fit: " << app2.FitValue(app4) << endl;

   // compare everyone to Steve
   cout << app3.GetName() << endl;
   cout << "    " << app1.GetName() << " fit: " << app3.FitValue(app1) << endl;
   cout << "    " << app2.GetName() << " fit: " << app3.FitValue(app2) << endl;
   cout << "    " << app3.GetName() << " fit: " << app3.FitValue(app3) << endl;
   cout << "    " << app4.GetName() << " fit: " << app3.FitValue(app4) << endl;

   // compare everyone to Jane
   cout << app4.GetName() << endl;
   cout << "    " << app1.GetName() << " fit: " << app4.FitValue(app1) << endl;
   cout << "    " << app2.GetName() << " fit: " << app4.FitValue(app2) << endl;
   cout << "    " << app3.GetName() << " fit: " << app4.FitValue(app3) << endl;
   cout << "    " << app4.GetName() << " fit: " << app4.FitValue(app4) << endl;

   return 0;
}

// DateProfile Method Definitions

DateProfile::DateProfile()
{
   SetAll('F', 'M', 0, 0, "undefined applicant");
}

DateProfile::DateProfile(char gen, char srch_gen, int rom, int fin, string nm)
{
   SetAll(gen, srch_gen, rom, fin, nm);
}

void DateProfile::SetAll(char gen, char srch_gen, int rom, int fin, string nm)
{
   if (!SetGender(gen))
      SetGender('F');
   if (!SetSearchGender(srch_gen))
      SetSearchGender('M');
   if (!SetRomance(rom))
      SetRomance(0);
   if (!SetFinance(fin))
      SetFinance(0);
   if (!SetName(nm))
      SetName("applicant undefined");
}

bool DateProfile::SetGender(char gen)
{
   if ( !ValidGender(gen) )
      return false;
   gender = toupper(gen);
   return true;
}

bool DateProfile::SetSearchGender(char gen)
{
   if ( !ValidGender(gen) )
      return false;
   search_gender = toupper(gen);
   return true;
} 

bool DateProfile::SetRomance(int val)
{
   if ( val < MIN_VAL || val > MAX_VAL )
      return false;
   romance = val;
   return true;
}

bool DateProfile::SetFinance(int val)
{
   if ( val < MIN_VAL || val > MAX_VAL )
      return false;
   finance = val;
   return true;
}

bool DateProfile::SetName(string nm)
{
   if (nm.length() < MIN_NAME_LENGTH || nm.length() > MAX_NAME_LENGTH )
      return false;
   name = nm;
   return true;
}

bool DateProfile::ValidGender(char gen)
{
  char new_gender = tolower(gen);

   if ( new_gender != 'm' && new_gender != 'f' )
      return false;
   else
      return true;
}

double DateProfile::DetermineFinanceFit(DateProfile partner)
{
   int my_val, partners_val, diff;
   double fit;

   my_val = finance;
   partners_val = partner.finance;
   diff = abs(my_val - partners_val);
   fit =  MAX_VAL - 1 - diff; // 9 is largest and 0 is the smallest
   fit = fit / (double)(MAX_VAL-1);  // now goes from 0.0 to 1.0

   return fit;
}

double DateProfile::DetermineRomanceFit(DateProfile partner)
{
   int my_val, partners_val, diff;
   double fit;

   my_val = romance;
   partners_val = partner.romance;
   diff = abs(my_val - partners_val);
   fit = MAX_VAL - 1 - diff; // 9 is largest and 0 is the smallest
   fit = fit / (double)(MAX_VAL-1);  // now goes from 0.0 to 1.0

   return fit;
}

double DateProfile::DetermineGenderFit(DateProfile partner)
{
   if (search_gender != partner.gender)
      return 0.0;
    if (partner.search_gender != gender)
      return 0.0;
    return 1.0;
}

double DateProfile::FitValue(DateProfile partner)
{
   return DetermineGenderFit(partner) * DetermineRomanceFit(partner)
      * DetermineFinanceFit(partner);
}

/* ------------------ Output of Above ------------------------------

Joe Somebody
    Joe Somebody fit: 0
    Steve Nobody fit: 0
    Jane Peabody fit: 0.790123
    Helen Anybody fit: 0.691358
Steve Nobody
    Joe Somebody fit: 0
    Steve Nobody fit: 0
    Jane Peabody fit: 0.432099
    Helen Anybody fit: 0.493827
Jane Peabody
    Joe Somebody fit: 0.790123
    Steve Nobody fit: 0.432099
    Jane Peabody fit: 0
    Helen Anybody fit: 0
Helen Anybody
    Joe Somebody fit: 0.691358
    Steve Nobody fit: 0.493827
    Jane Peabody fit: 0
    Helen Anybody fit: 0
Press any key to continue . . .

------------------------------------------------------------------- */