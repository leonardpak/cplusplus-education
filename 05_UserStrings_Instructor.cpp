// CIS 15A - Assignment 5, Option A
// Instructor Solution
// Notes:
//   - This file contains two possible solutions to Assignment 5.  The first
//        does not make use of methods (functions).  The second does.
//        You should study both versions and understand them, completely.
//   - Program run contains enough input to demonstrate all functionality.
//   - One sample run used a short input string which made the output 
//        easy to check for correctness.  The other run's input was more
//        complex.
//   - The first source was commented out so the file would run if pasted
//        without modification. You can switch the comments to try the second
//        version.

// ---------------- SOURCE -------------------------

/*  Version without methods  (commented out) -----

#include <iostream>
#include <string>
using namespace std;

int main()
{
   string user_string, result_string;
   int k, vowels, consonants, len;

   // get the string from the user
   cout << "Please enter a phrase or sentence: ";
   getline(cin, user_string);

   // length used many places so store into variable:
   len = user_string.length();

   // up-case
   result_string = user_string; // work on a copy, not original
   for (k = 0; k < len; k++)
      result_string[k]  = toupper( result_string[k] );
   cout << "UPPER CASED: " << result_string << endl;

   // down-case
   result_string = user_string; // work on a copy, not original
   for (k = 0; k < len; k++)
      result_string[k]  = tolower( result_string[k] );
   cout << "lower cased: " << result_string << endl;

   // vowels/consonants (use lower-cased result - assume result is all lower)
   vowels = consonants = 0;
   for (k = 0; k < len; k++)
   {
      switch ( result_string[k] )
      {
         case 'a': case 'e': case 'i': case 'o': case 'u':
            vowels ++;
            break;
         case 'b': case 'c': case 'd':  case 'f': case 'g': case 'h':
         case 'j': case 'k': case 'l':  case 'm': case 'n': case 'p':
         case 'q': case 'r': case 's':  case 't': case 'v': case 'w':
         case 'x': case 'y': case 'z':
            consonants ++;
            break;
      }
   }
   cout << "Number of Vowels: " << vowels << endl;
   cout << "Number of Consonants: " << consonants << endl;

   // reverse order
   result_string = user_string; // create a result of correct length first
   for (k = 0; k < len; k++)
      result_string[k]  = user_string[len - k - 1];
   cout << "In reverse: " << result_string << endl;

   return 0;
}
  --- end version without methods (commented out) ----- */

// Version using methods

#include <iostream>
#include <string>
using namespace std;

#define VOWELS 0
#define CONSONANTS 1

// method prototypes
string GetInput();
string ConvertToUpper(string s);
string ConvertToLower(string s);
int CountVowelsOrConsonants( string the_string, int which );
string ReverseChars( string s);

int main()
{
   string user_string;

   // get the string from the user
   user_string = GetInput();

   cout << "UPPER CASED: " << ConvertToUpper(user_string) << endl;
   cout << "lower cased: " << ConvertToLower(user_string) << endl;
   cout << "Number of Vowels: " 
      << CountVowelsOrConsonants( user_string,  VOWELS ) << endl;
   cout << "Number of Consontants: " 
      << CountVowelsOrConsonants( user_string, CONSONANTS ) << endl;
   cout << "and, in reverse: " << ReverseChars(user_string) << endl;

   return 0;
}

// method definitions:
string GetInput()
{
   string the_string;
   cout << "Please enter a phrase or sentence: ";
   getline(cin, the_string);
   return the_string;
}

string ConvertToUpper( string the_string )
{
   string result_string;

   result_string = the_string; // work on a copy, not original
   for (int k = 0; k < the_string.length(); k++)
      result_string[k]  = toupper( result_string[k] );
   return result_string;
}

string ConvertToLower( string the_string )
{
   string result_string;

   result_string = the_string; // work on a copy, not original
   for (int k = 0; k < the_string.length(); k++)
      result_string[k]  = tolower( result_string[k] );
   return result_string;
}

int CountVowelsOrConsonants( string the_string, int which )
{
   the_string = ConvertToLower(the_string);   // must first convert to lower
   int count = 0;
   if (which == VOWELS)
   {
      for (int k = 0; k < the_string.length(); k++)
      {
         switch ( the_string[k] )
         {
            case 'a': case 'e': case 'i': case 'o': case 'u':
               count ++;
               break;
         }
      }
   }
   else
   {
      for (int k = 0; k < the_string.length(); k++)
      {
         switch ( the_string[k] )
         {
            case 'b': case 'c': case 'd':  case 'f': case 'g': case 'h':
            case 'j': case 'k': case 'l':  case 'm': case 'n': case 'p':
            case 'q': case 'r': case 's':  case 't': case 'v': case 'w':
            case 'x': case 'y': case 'z':
               count ++;
               break;
         }
      }
   }
   return count;
}

string ReverseChars( string the_string)
{
   // length used many places so store into variable:
   int len = the_string.length();

   // reverse order
   string result_string = the_string; // create a result of correct length first
   for (int k = 0; k < len; k++)
      result_string[k]  = the_string[len - k - 1];
   return result_string;
}

/* ------------------- Sample Run 1 ------------------------------

Please enter a phrase or sentence: aei XYZ
UPPER CASED: AEI XYZ
lower cased: aei xyz
Number of Vowels: 3
Number of Consontants: 3
and, in reverse: ZYX iea
Press any key to continue . . .

   ------------------- Sample Run 2 ------------------------------

Please enter a phrase or sentence: Here is more complexity *&^!!
UPPER CASED: HERE IS MORE COMPLEXITY *&^!!
lower cased: here is more complexity *&^!!
Number of Vowels: 8
Number of Consontants: 12
and, in reverse: !!^&* ytixelpmoc erom si ereH
Press any key to continue . . .
--------------------------------------------------------------- */