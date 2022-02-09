#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<sstream>
#include <queue>
#include <vector>
#include <map>
#include<iterator>

using namespace std;


struct BusTime
{

	int godzina;
	int minuta;

	BusTime(string czas) {

		string first_half = czas.substr(0, 2);
		string second_half = czas.substr(3, 5);
		godzina = stoi(first_half);
		minuta = stoi(second_half);

	}



	string ToString()// ma zamieniac godz na stringa
	{
		string godz;
		string min;

		ostringstream oss;
		oss << setw(2) << setfill('0') << godzina << ":" << setw(2) << setfill('0') << minuta;


		return oss.str();

	}
};


struct CompBusTime
{

	bool operator()(const BusTime& B1, const BusTime& B2)
	{
		if (B1.godzina == B2.godzina)
		{
			return B1.minuta > B2.minuta;
		}
		else
			return B1.godzina > B2.godzina;
	}

};


struct BusLine
{

	priority_queue<BusTime, vector<BusTime>, CompBusTime>kolejka;

	void dodaj(const BusTime& wartosc)
	{
		kolejka.push(wartosc);
	}

	void wypisz() {
		while (!kolejka.empty())
		{
			BusTime pomocniczy = kolejka.top();

			cout << pomocniczy.godzina << ' ' << pomocniczy.minuta << ' ' << endl;
			kolejka.pop();
		}
	}



};

struct BusStop
{
	map<int, BusLine>mapa;


	/*void dodaj(const BusLine& wartosc, int liczba)
	{
	mapa.insert(std::pair<BusLine, int>(wartosc, liczba));
	}

	void dodaj(const BusTime& wartosc)
	{
	kolejka.push(wartosc);
	}*/
};

void PrepareBusBoard(const std::string& file_name)
{

	fstream plik(file_name);


}

int main()
{
	//BusTime przyklad("08:08");
	//cout << przyklad.ToString() << endl;



	BusLine line;
	line.dodaj(BusTime("10:32"));
	line.dodaj(BusTime("17:32"));
	line.dodaj(BusTime("12:12"));
	line.dodaj(BusTime("9:32"));

	line.wypisz();






	system("pause");
}