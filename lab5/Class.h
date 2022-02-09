#pragma once
#include <sstream>
#include<iostream>
#include <string>


class NumberSequence
{
	std::string nazwa;
public: 
	virtual float calc_nth(int n)const = 0;
	std::string to_String() const
	{
		std::string wartosc;
		wartosc += nazwa;
		wartosc += " ";
		for (int i = 1 : i <= 10; i++)
		{
			std::string s = std::to_string(calc_nth(i));
			wartosc += s+" ";
			
		}
		
		return(wartosc);
		
	};

	 virtual ~NumberSequence() {};

};