#pragma once
namespace data_structures
{
	template<class T>
	class Element
	{
		T dana;
		Element<T>* wsk_nast;
	public:
		Element(const T& info, Element<T>* wsk_nast) : dana(info), wsk_nast(wsk_nast) {}



		void setWskNast(Element<T>* wsk_nast)
		{
			this->wsk_nast = wsk_nast;
		}

		Element<T>* getWskNast()const {

			return wsk_nast;
		}

		T& operator *()
		{
			return dana;
		}
	};

	template<class T>
	class List
	{

		Element<T>* wsk_pocz;
		Element<T>* wsk_koniec;

		int liczba_el;

	public:

		List() : wsk_pocz(nullptr), wsk_koniec(nullptr), liczba_el(0) {}

		List(const List& inny)
		{
			Element<T>* zmienna = new Element < T >(nowawart, nullptr);




		}


		~List()
		{
			for (int i = 0; i < liczba_el; i++)
			{
				Element<T>* wsk_pomo;

				wsk_pomo = wsk_pocz;

				wsk_pocz = wsk_pomo->getWskNast();
				delete wsk_pomo;
			}

		}
		Element<T>* head()
		{
			return wsk_pocz;
		}

		Element<T>* tail()
		{
			return wsk_koniec;
		}

		int count()const
		{
			return liczba_el;
		}



		void add(const T& nowawart)
		{

			Element<T>* zmienna = new Element < T >(nowawart, nullptr);

			if (wsk_pocz == nullptr)
			{
				wsk_koniec = zmienna;
				wsk_pocz = zmienna;

			}
			else
			{
				wsk_koniec->setWskNast(zmienna);
				wsk_koniec = zmienna;

			}
			liczba_el++;
		}

	};


}