#include "Timer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

//Task 1

template<class T>

void Swap(T* f, T* s)
{
	T temp = *f;
	*f = *s;
	*s = temp;
}

//task 2

template<class T>
void SortPointers(vector<T*>& integer)
{
	sort(integer.begin(), integer.end(), [](T* a, T* b) {return *a < *b; });
}

int main()
{
	//task 1
	
	setlocale(LC_ALL, "Russian");
	int a{ 2 };
	int* Aptr{ &a };
	int b = 4;
	int* Bptr{ &b };
	cout << "Первоначальное значение a = " << *Aptr << ". Первоначальное значение b = " << *Bptr << endl;
	Swap(Aptr, Bptr);
	cout << "После обмена: a = " << *Aptr << ", b = " << *Bptr << endl;

	//task 2
	int c{ 22 };
	int* Cptr{ &c };
	int d{ 57 };
	int* Dptr{ &d };
	int e{ 24 };
	int* Eptr{ &e };
	int f{ 45 };
	int* Fptr{ &f };
	int g{ 11 };
	int* Gptr{ &g };
	cout << "Vector до сортировки: ";
	vector<int*> integer = { Cptr, Dptr, Eptr, Fptr, Gptr };
	for (const auto& i : integer)
	{
		cout << *i << " ";
	}
	cout << endl;
	SortPointers(integer);
	cout << "Vector после сортировки: ";
	for (const auto& i : integer)
	{
		cout << *i << " ";
	}

	return 0;
}