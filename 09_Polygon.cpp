/*===============================SOURCE========================================
                         Created by Leonard Pak
=============================================================================*/
#include <iostream>
using namespace std;
// --------------------------- CLASS PROTOTYPES -------------------------------
class Point
{
public:
   // constructors
   Point();
   Point(int x, int y);
   // accessors
   int GetX() {return x;}
   int GetY() {return y;}
   // mutators
   bool Set(int x, int y);
   // instance methods
   void DisplayPoint();
private:
   // instance variables
   int x, y;
};

class Polygon
{
public:
   // static constant variables
   const static int MAX_POINTS = 8;
   // constructors
   Polygon();
   Polygon(int num_points, int x_array[], int y_array[]);
   // accessors
   Point GetPoint(int element) {return points[element];}
   // mutators
   bool SetPoints(int num_points, int x_values[], int y_values[]);
   bool AddPoint(int x, int y);
   bool AddPoint(Point p);
   // instance methods
   void ShowPolygon();
private:
   // instance variables
   int num_points;
   Point points[MAX_POINTS];
};
// --------------------------------- MAIN -------------------------------------
int main()
{
   int poly1points = 7;
   int poly1array1[] = {0,1,2,3,4,5,6,7};
   int poly1array2[] = {0,1,2,3,4,5,6,7};

   Polygon poly1(poly1points, poly1array1, poly1array2);
   Polygon poly2;

   Point added_point1; 
   Point added_point2(222,222);
   
   poly2.AddPoint(added_point1);
   poly2.AddPoint(11,11);
   poly2.AddPoint(added_point2);
   poly2.AddPoint(1337,1337);

   cout << "Polygon 1 contents: ";
   poly1.ShowPolygon();
   cout << "\n";

   cout << "Polygon 2 contents: ";
   poly2.ShowPolygon();
   cout << "\n";

   return 0;
}
// ------------------------- POINT CLASS FUNCTIONS ----------------------------
//                     ********** CONSTRUCTORS **********
Point::Point()
{
   Set(0,0);
}
Point::Point(int x, int y)
{
   if(!Set(x,y))
      Set(0,0);
}
//                       ********** MUTATORS **********
bool Point::Set(int x, int y)
{
   if ( x < 0 || y < 0)
      return false;
   this->x = x;
   this->y = y;
   return true;
}
//                        ********** OTHER **********
void Point::DisplayPoint()
{
   cout << "(" << x << ", " << y << ")";
}
// ------------------------ POLYGON CLASS FUNCTIONS ---------------------------
//                     ********** CONSTRUCTORS **********
Polygon::Polygon()
{
   SetPoints(0,0,0);
}
Polygon::Polygon(int num_points, int x_array[], int y_array[])
{
   if(! (SetPoints(num_points, x_array, y_array)) )
      SetPoints(0,0,0);
}
//                       ********** MUTATORS **********
bool Polygon::SetPoints(int num_points, int x_values[], int y_values[])
{
   if (num_points < 0 || num_points > MAX_POINTS)
      return false;
   this->num_points = num_points;
   
   for (int k = 0; k < num_points; k++)
   {
      Point temp(x_values[k], y_values[k]);
      points[k] = temp;
   }

   if ( (sizeof(points) / sizeof(points[0])) < num_points )
      return false;

   return true;  
}
bool Polygon::AddPoint(int x, int y)
{
   Point p(x,y);
   
   if(num_points == MAX_POINTS)
      return false;
   points[num_points++] = p;
   return true;
}
bool Polygon::AddPoint(Point p)
{
   if(num_points == MAX_POINTS)
      return false;
   points[num_points++] = p;
   return true;
}
//                        ********** OTHER **********
void Polygon::ShowPolygon()
{
   for (int k = 0; k < (num_points-1); k++) // displays all points besides last
   {                                        // with a comma
      points[k].DisplayPoint();
      cout << ", ";
   }
   points[num_points-1].DisplayPoint();     // displays last point, no comma
}
/*===============================OUTPUT========================================
Polygon 1 contents: (0, 0), (1, 1), (2, 2), (3, 3), (4, 4), (5, 5), (6, 6)
Polygon 2 contents: (0, 0), (11, 11), (222, 222), (1337, 1337)
Press any key to continue . . .
=============================================================================*/
/*
Having a public method that returns the Point array is not a good idea because
it allows the client to directly manipulate the data. (-.5)

You were supposed to display two polygons, then modify them and display them 
each again, after the modification. You never modified your Polygons.(-1.5)

There is no need to use accessor methods (or the this keyword) for accessing 
class data(or methods). You should access it directly.

Testing the size of the points array against num_points is not useful. You
are already testing num_points and besides the size will always be MAX_POINTS,
so why not use this variable instead of doing the math?(-.5)

Instead of creating a new Point everytime you add one in AddPoint(int, int),
it is more efficient to set the Point in the array directly. (-.5)
*/