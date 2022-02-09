#pragma once
#include<iostream>
#include <string>
#include<utility>
#include <iostream>
#include<math.h>


class NumberSequence
{
	std::string nazwa;
public:
	virtual double calc_nth(int n)const = 0;
	std::string to_String() const
	{
		std::string wartosc;
		wartosc += nazwa;
		for (int i = 1 ; i <= 10; i++)
		{
			wartosc += " " + std::to_string(calc_nth(i));
		}
		return(wartosc);
	};

	NumberSequence(const std::string& znak) : nazwa(znak) {};
	NumberSequence(const NumberSequence& ref) : nazwa(ref.nazwa) {};
	NumberSequence(NumberSequence&& rhs) : nazwa(move(rhs.nazwa)) {};
		

	

	virtual ~NumberSequence() {};

};


class ArithmeticSequence : public NumberSequence
{
protected:

	double a;
	double r;
public:

	double calc_nth(int n) const override { return a+(n-1)*r; };

	ArithmeticSequence( double w1,const double w2) : a(w1), r(w2), NumberSequence("Arithmetic") {};
	ArithmeticSequence(const ArithmeticSequence& zm) : a(zm.a), r(zm.r), NumberSequence(zm) {};
	ArithmeticSequence(ArithmeticSequence&& zg) : a(std::move(zg.a)), r(std::move(zg.r)), NumberSequence(std::move(zg)) {};

		
};


class GeometricSequence : public NumberSequence
{
protected:
	double a;
	double q;

public : 

	double calc_nth(int n) const override { double x= (a * pow(q,(n-1))); return x; };
	

	GeometricSequence( double w1, const double w2) : a(w1), q(w2), NumberSequence("geometric") {};
	GeometricSequence(const GeometricSequence& zm) : a(zm.a), q(zm.q),NumberSequence(zm) {};
	GeometricSequence(GeometricSequence&& zg) : a((zg.a)), q(zg.q), NumberSequence(std::move(zg)) {};


};