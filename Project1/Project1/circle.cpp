#include <iostream>
#include "circle.h"

using namespace std;


Circle::Circle(double x, double y, double promien) : p1(x, y), promien(promien) {};// konstruktor z lista inicjalizacyjna

Circle::Circle(const Circle& a) : p1(a.p1), promien(a.promien) { // konstruktor kopiuj¹cy
};


//double Circle::Area()
//{
// double r = getProm();
// double pole = r*r * 3.14;
// return pole;
//}
//
//double  Circle::perimeter()
//{
// double r = getProm();
// double obwod = 2 * 3.14*r;
// return obwod;
//}
//
//void Circle::print()
//{
// cout << "wspolrzedne: x" << p1.x << "y: " << p1.y << "promien : " << promien << endl;
//}

double distance()
{

}