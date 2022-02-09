#pragma once


template <class T, class Comp>
class BinaryHeap
{
public:
	std::vector<T> Wektor;
	Comp comparator;
	
	BinaryHeap(std::vector<T>&& Data,  Comp Comparator) : Wektor(std::move(Data)), comparator(Comparator)
	{
		std::make_heap(Wektor.begin(), Wektor.end(), Comparator);
	}


};