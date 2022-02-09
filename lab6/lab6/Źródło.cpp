#include<iostream>
#include<algorithm>
#include<random>
#include<vector>
#include "BinaryHeap.h"


void wypisz(int x)
{
	std::cout << x << " ";
}

int main()
{
	std::default_random_engine gen;
	std::uniform_int_distribution<int> distr(1, 10);
	std::vector<int> wektor(100);

	std::generate(wektor.begin(), wektor.end(), [&]()->int {return distr(gen); });
	

	for (int i : wektor)
	{
		std::cout << i << " ";
	}
	//std::for_each(wektor.begin(), wektor.end(), wypisz);

	auto pom = unique(wektor.begin(), wektor.end());
	wektor.erase(pom, wektor.end());
	std::cout << std::endl<< "\npo uzyciu funkcji unique\n" << std::endl;
	int i = 0;
	for (int i:wektor)
	{
		std::cout << i << " ";
	}
	// funkcja unique usuwa tylko pierwszy element powtarzaj¹cy siê, aby to w pe³ni dzia³a³o trzeba najpierw posortowaæ wektor rosn¹co


	std::sort(wektor.begin(), wektor.end());
	std::cout << std::endl << "\npo posortowaniu\n" << std::endl;
	for (int i : wektor)
	{
		std::cout << i << " ";
	}
	//std::for_each(wektor.begin(), wektor.end(), wypisz);


	auto pom2 = unique(wektor.begin(), wektor.end());
	wektor.erase(pom2, wektor.end());
	std::cout << std::endl << "\npo posortowaniu i erase\n" << std::endl;
	for (int i : wektor)
	{
		std::cout << i << " ";
	}
	//std::for_each(wektor.begin(), wektor.end(), wypisz);


	//---------------------ZADANIE 2


	std::reverse(wektor.begin(), wektor.end());
	std::cout << std::endl << "\npo odwroceniu: \n" << std::endl;
	for (int i : wektor)
	{
		std::cout << i << " ";
	}
	auto zm=std::find(wektor.begin(), wektor.end(), 2);
	if (zm==wektor.end())
	{
		std::cout <<std::endl<< "\n nie znaleziono\n";
	}
	else
	{
		std::cout << std::endl << "\n znaleziono\n";
	}

	auto zm2 = std::binary_search(wektor.begin(), wektor.end(), 2);
	if (zm2)
	{
		std::cout << std::endl << "\n znaleziono\n";
	}
	else
	{
		std::cout << std::endl << "\n  nie znaleziono\n";
	}
	
	
	std::cout << std::endl << "\npo odwroceniu i zmianie w binary search \n" << std::endl;
	auto zm3 = std::binary_search(wektor.begin(), wektor.end(), 2,std::greater<int>());
	if (zm3)
	{
		std::cout << std::endl << "\n znaleziono\n";
	}
	else
	{
		std::cout << std::endl << "\n  nie znaleziono\n";
	}

	// --------------------------------zad 3 

	std::default_random_engine gen2;
	std::poisson_distribution<int> distr2(5.0);
	std::vector<std::pair<int, int>> pair(100);

	std::generate(pair.begin(), pair.end(), [&]()->std::pair<int, int> { return std::make_pair(distr2(gen2), distr2(gen2)); });
	
	for (auto p:pair)
	{
		std::cout << p.first << " " << p.second << " " << std::endl;
	}

	std::sort(pair.begin(), pair.end(), [](std::pair<int, int> x, std::pair<int, int> y) {return x.second > y.second; });
	std::cout << std::endl << "\npary po uporzadkowaniu wedlug drugiego malejaco  \n" << std::endl;
	for (auto p : pair)
	{
		std::cout << p.first << " " << p.second << " " << std::endl;
	}
	

	
	std::vector<std::pair<int, int>> pair2 = pair;
	
	std::sort(pair.begin(), pair.end(), [](std::pair<int, int> x, std::pair<int, int> y) {return x.first < y.first; });
	std::cout << std::endl << "\npary po uporzadkowaniu wedlug pierwszego rosnaco \n" << std::endl;
	for (auto p : pair)
	{
		std::cout << p.first << " " << p.second << " " << std::endl;
	}

	//std::vector<std::pair<int, int>> pair2 = pair;
	
	std::stable_sort(pair2.begin(), pair2.end(), [](std::pair<int, int> x, std::pair<int, int> y) {return x.first < y.first; });
	std::cout << std::endl << "\npary po zamianie na stable_sort \n" << std::endl;
	for (auto k : pair2)
	{
		std::cout << k.first << " " << k.second << " " << std::endl;
	}


	//---------------------------------zad 4

	std::vector<int>vec;
	auto komparator = [](auto a, auto b)->bool {return abs(a) < abs(b); };
	BinaryHeap<int, decltype(komparator)> Kopiec(std::move(vec), komparator); //tworzenie kopca
	




	return 0;
}