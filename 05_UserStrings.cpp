/*===============================SOURCE========================================
                         Created by Leonard Pak
=============================================================================*/

#include <iostream>
#include <string>
using namespace std;

string UserInput();
string DisplayAllCaps(string);
string DisplayAllLower(string);
int NumberOfVowels(string);
int NumberOfConsonants(string);
string ReverseString(string);

int main()
{
   string input;
   
   cout << "\n" << "Hello! Please enter a phrase, sentence, or paragraph!"
        << "\n" << "Type here: ";
   input = UserInput(); // receives string to be used as argument for methods

   cout << "\n" << "1. All uppercase version: " << DisplayAllCaps(input);
   cout << "\n" << "2. All lowercase version: " << DisplayAllLower(input);
   cout << "\n" << "3. Number of vowels: "      << NumberOfVowels(input);
   cout << "\n" << "4. Number of consonants: "  << NumberOfConsonants(input);
   cout << "\n" << "5. Reversed version: "      << ReverseString(input);

   cout << "\n";
	return 0;
}

string UserInput()
{
   string inputted_data;
   getline(cin, inputted_data);
   return inputted_data;
}

string DisplayAllCaps(string uppercase)
{
   int length = uppercase.length();

   for (int i = 0; i < length; i++)
   {
      char letter = uppercase[i];
      if (letter >= 'a' && letter <= 'z');
         uppercase[i] = toupper(uppercase[i]);
   }
   return uppercase;
}

string DisplayAllLower(string lowercase)
{
   int length = lowercase.length();

   for (int i = 0; i < length; i++)
   {
      char letter = lowercase[i];
      if (letter >= 'A' && letter <= 'Z');
         lowercase[i] = tolower(lowercase[i]);
   }
   return lowercase;
}

int NumberOfVowels(string vowels)
{
   int length = vowels.length();
   int number_of_vowels = 0;

   for (int i = 0; i < length; i++)
   {
      char letter = vowels[i];
      if (letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' ||
          letter == 'i' || letter == 'I' || letter == 'o' || letter == 'O' ||
          letter == 'u' || letter == 'U')
          number_of_vowels++;
   }

   return number_of_vowels;
}

int NumberOfConsonants(string consonants)
{
   int length = consonants.length();
   int number_of_consonants = 0;

   for (int i = 0; i < length; i++)
   {
      char letter = consonants[i];
      if ( (letter != 'a' && letter != 'A' && letter != 'e' && letter != 'E' &&
            letter != 'i' && letter != 'I' && letter != 'o' && letter != 'O' &&
            letter != 'u' && letter != 'U' )
                              &&
           ( (letter >= 'A' && letter <= 'Z') || // prevent symbols and numbers
             (letter >= 'a' && letter <= 'z') ))
          number_of_consonants++;
   }

   return number_of_consonants;
}

string ReverseString(string reverse)
{
   int length = reverse.length();
   string duplicate = reverse;

   for (int i = 0; i < length; i++)
   {
      char letter = duplicate[length - i - 1];
      reverse[i] = letter;
   }

   return reverse;
}

/*===============================OUTPUT========================================

-------------------------------TEST RUN #1-------------------------------

Hello! Please enter a phrase, sentence, or paragraph!
Type here: I am the greatest of all time!

1. All uppercase version: I AM THE GREATEST OF ALL TIME!
2. All lowercase version: i am the greatest of all time!
3. Number of vowels: 10
4. Number of consonants: 13
5. Reversed version: !emit lla fo tsetaerg eht ma I
Press any key to continue . . .

-------------------------------TEST RUN #2-------------------------------

Hello! Please enter a phrase, sentence, or paragraph!
Type here: AaEeBbCc##$$

1. All uppercase version: AAEEBBCC##$$
2. All lowercase version: aaeebbcc##$$
3. Number of vowels: 4
4. Number of consonants: 4
5. Reversed version: $$##cCbBeEaA
Press any key to continue . . .

=============================================================================*/
/*
It was good, but you should look for ways to shorten it.  The simplest way to
immediately make this code shorter is to first upcase or downcase the 
character you are testing and then you only have to test for HALF the number
of vowels.

isAlpha() would have also saved you some work in the consontant function.
*/