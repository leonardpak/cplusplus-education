// CIS 15A - Assignment 2, Option A
// Instructor Solution
// Notes:
//   - Blank lines are placed between distinct sections of code (blocks).
//   - After a blank line, the next block starts with a comment
//        that explains the purpose of that block.
//   - Other than separating commented blocks of code, there are
//        no other blank lines.
//   - Continuation lines are indented.
//   - There is no indentation unless specified by style rules.  In this
//        case, that means only indentation for the main block, and
//        an extra level of indentation for continuation lines.
//   - I coded tabs, \t, in the output.  This is okay.  Tabs are not allowed
//        in source code, but fine in the output of a console application.
//        However, the output may look bad on this web page becaue they are
//        expanded differently than in the actual run.  (Another reason why
//        tabs are of dubious value, in general.) If you run the program,
//        you will see that tabs are correctly expanded in the console output.

// ---------------- SOURCE -------------------------

#include <iostream>
using namespace std;

int main()
{
   int n, result;

   // print header
   cout << "\nn\t1+2+...+n\t(n*(n+1))/2\t3+...+(2n-1)\tn-squared - 1\n";
   cout << " -------------------------------------------------"
      "---------------------\n";

   // case n = 6
   n = 6;
   result = n;
   cout << result;
   result = 1 + 2 + 3 + 4 + 5 + 6;
   cout << " \t " << result;
   result = (n*(n+1))/2;
   cout << " \t\t " << result;
   result = 3 + 5 + 7 + 9 + 11;
   cout << " \t\t " << result;
   result = n*n - 1;
   cout << " \t\t " << result << endl;

   // case n = 9
   n = 9;
   result = n;
   cout << result;
   result = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;
   cout << " \t " << result;
   result = (n*(n+1))/2;
   cout << " \t\t " << result;
   result = 3 + 5 + 7 + 9 + 11 + 13 + 15 + 17;
   cout << " \t\t " << result;
   result = n*n - 1;
   cout << " \t\t " << result << endl;

   // case n = 16
   n = 16;
   result = n;
   cout << result;
   result = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
      + 11 + 12 + 13 + 14 + 15 + 16;
   cout << " \t " << result;
   result = (n*(n+1))/2;
   cout << " \t\t " << result;
   result = 3 + 5 + 7 + 9 + 11 + 13 + 15 + 17 + 19 + 21
      + 23 + 25 + 27 + 29 + 31;
   cout << " \t\t " << result;
   result = n*n - 1;
   cout << " \t\t " << result << endl;

   cout << endl;
   return 0;
}


/* ------------- RUN (OUTPUT) ----------------------

n       1+2+...+n       (n*(n+1))/2     3+...+(2n-1)    n-squared - 1
 ----------------------------------------------------------------------
6        21              21              35              35
9        45              45              80              80
16       136             136             255             255

Press any key to continue . . .

--------------- END OF RUN ------------------------- */