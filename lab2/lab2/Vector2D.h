#pragma once
#include "ProjectileCollection.h"

class Vector2D
{
public:

	double x;
	double y;

	Vector2D(double x, double y) : x(x), y(x) {};
	Vector2D& operator=(const Vector2D& wartosc)
	{
		x = wartosc.x;
		y = wartosc.y;

		return *this;

	}

	Vector2D& operator--() {
		x -= 1.0;
		y -= 1.0;
		return *this;
	}

	Vector2D operator--(int) {
		Vector2D copy(*this);
		x -= 1.0;
		y -= 1.0;
		return copy;
	}


	double& operator[](int i)
	{
		if (i == 0) { return x; }
		else {
			return y;
		}
	}

	Vector2D& operator+=(const Vector2D& wartosc) {
		this->x += wartosc.x;
		this->y += wartosc.y;
		return*this;
	}

	Vector2D operator*(const double& wartosc) {
		return Vector2D(x * wartosc, y * wartosc);
	}

	void normalize()
	{
		float d = sqrt(x * x + y * y);
		x = x / d;
		y = y / d;

	}

	void show() {


		std::cout << "wartosc x: " << x << "wartosc y: " << y;

	}

}; #pragma once
