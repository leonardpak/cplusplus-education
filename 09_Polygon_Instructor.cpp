// 15a Assignment 9 Option A

#include <iostream>
#include <string>
using namespace std;

// class Point prototype --------------------------------------
class Point
{
  private:
   int x;
   int y;
  public:
   Point(int x = 0, int y = 0);
   void Set(int x, int y);
   int GetX() { return x; }
   int GetY() { return y; }
   void DisplayPoint();
};

// class Polygon prototype ------------------------------------
class Polygon
{
  private:
   static const int MAX_POINTS = 100;
   int num_points;
   Point points[MAX_POINTS];
  public:
   Polygon(int num = 0);
   Polygon(int num, int x_vals[], int y_vals[]);
   bool SetPoints(int num, int x_vals[] = NULL, int y_vals[] = NULL);
   void ShowPolygon();
   bool AddPoint(int x, int y);
   bool AddPoint(Point p);
};

// client -----------------------------------------------------
int main()
{
   int x_array[] = {3, 6, 1, 7, 4, 12, 4, 11, 2, 0, 2};
   int y_array[] = {13, 5, 2, 9, 9, 13, 2, 3, 7, 14, 5};
   Polygon poly1(11, x_array, y_array );
   int NUM_VERTS_IN_POLY2 = sizeof(x_array)/sizeof(x_array[0]);
   Polygon poly2;
   int k;

   for (k = 0; k < NUM_VERTS_IN_POLY2; k++)
      poly2.AddPoint(2*k, -3*k);

   cout << "--- Polygon 1 ---";
   poly1.ShowPolygon();
   cout << "--- Polygon 2 ---";
   poly2.ShowPolygon();

   for (k = 0; k < 5; k++)
      poly2.AddPoint(k, k - 3);

   cout << "--- Polygon 1 ---";
   poly1.ShowPolygon();
   cout << "--- Polygon 2 ---";
   poly2.ShowPolygon();
   return 0;
}

// Point method definitions -----------------------------------

// constructors
Point::Point(int x, int y)
{
   Set(x, y);
}

// mutators
void Point::Set(int x, int y)
{
   // we allow full range of ints
   this->x = x;
   this->y = y;
}

// others
void Point::DisplayPoint()
{
   cout << " (" << x << ", " << y << ") ";
}

// Polygon method definitions --------------------------------

// constructors
Polygon::Polygon(int num )
{
   SetPoints(num);
}

Polygon::Polygon(int num, int x_vals[], int y_vals[])
{
   SetPoints(num, x_vals, y_vals);
}

// mutators
bool Polygon::SetPoints(int num, int x_vals[], int y_vals[])
{
   if (num < 0 || num > MAX_POINTS)
   {
      num_points = 0;
      return false;
   }
   num_points = num;
   if (x_vals == NULL)
      return true;

   for (int k = 0; k < num; k++)
      points[k].Set(x_vals[k], y_vals[k]);
   return true;
}

// others
void Polygon::ShowPolygon()
{
   cout << "\nPolygon: ";
   for (int k = 0; k < num_points; k++)
   {
      if (k%6 == 0)
         cout << endl;
      points[k].DisplayPoint();
   }
   cout << endl;
}

bool Polygon::AddPoint(int x, int y)
{
   if (num_points >= MAX_POINTS)
      return false;
   points[num_points++].Set(x, y);
   return true;
}

bool Polygon::AddPoint(Point p)
{
   return AddPoint(p.GetX(), p.GetY());
}

/* ---------------------- Output ------------------------------
--- Polygon 1 ---
Polygon:
 (3, 13)  (6, 5)  (1, 2)  (7, 9)  (4, 9)  (12, 13)
 (4, 2)  (11, 3)  (2, 7)  (0, 14)  (2, 5)
--- Polygon 2 ---
Polygon:
 (0, 0)  (2, -3)  (4, -6)  (6, -9)  (8, -12)  (10, -15)
 (12, -18)  (14, -21)  (16, -24)  (18, -27)  (20, -30)
--- Polygon 1 ---
Polygon:
 (3, 13)  (6, 5)  (1, 2)  (7, 9)  (4, 9)  (12, 13)
 (4, 2)  (11, 3)  (2, 7)  (0, 14)  (2, 5)
--- Polygon 2 ---
Polygon:
 (0, 0)  (2, -3)  (4, -6)  (6, -9)  (8, -12)  (10, -15)
 (12, -18)  (14, -21)  (16, -24)  (18, -27)  (20, -30)  (0, -3)
 (1, -2)  (2, -1)  (3, 0)  (4, 1)
Press any key to continue . . .
-------------------------------------------------------------- */