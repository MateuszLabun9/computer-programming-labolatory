#pragma once
#include <iostream>

#include "point.h"

using namespace std;

class Circle
{

	Point p1;
	double promien;


public:

	double getProm()const { return promien; }
	void setProm(double promien) { this->promien = promien; }

	Point getPoint()const { return p1; }
	void setPoint(const Point& p1) { this->p1 = p1; }

	//Circle(double x, double y, double promien) : p1(x, y),  promien(promien) {};


	Circle(double x, double y, double promien);

	Circle(const Circle& a);
	//double Area();
	double Area()const
	{

		/*double r = getProm();
		double pole = r*r * 3.14;
		return pole;*/

		return promien * promien*3.14;
	}

	double  perimeter()const
	{
		/*double r = getProm();
		double obwod = 2 * 3.14*r;
		return obwod;*/

		return promien * 2 * 3.13;
	}

	//double  perimeter();
	//void print();

	void print()const
	{
		cout << "wspolrzedne: x" << p1.x << "y: " << p1.y << "promien : " << promien << endl;
	}


};

enum wzajemne_polozenie_okregow
{
	rozlaczne_zewnetrznie,
	styczne_zewnetrznie,
	przecinajace_sie,
	styczne_wewnetrznie,
	rozlaczne_wew,
	wspolsrodkowe
};
