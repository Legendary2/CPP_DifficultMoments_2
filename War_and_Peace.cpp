#include "Timer.h"
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	//task 3
	Timer t;
	string vowels = "aeiouyAEIOUY";
	ifstream book1("E:\phone\War and peace.txt");
	if (book1.is_open())
	{
		t.start("Способ сортировки #1");
		size_t count = count_if(istreambuf_iterator<char>(book1), istreambuf_iterator<char>(), [=](char s)
			{return vowels.find(s) != string::npos; });
		t.print();
		cout << "Количество гласных: " << count << endl;
	}
	else
	{
		cout << "Не удается открыть текстовый файл";
	}
	book1.close();
	ifstream book2("E:\phone\War and peace.txt");
	if (book2.is_open())
	{
		t.start("Способ сортировки #2");
		size_t count = count_if(istreambuf_iterator<char>(book2), istreambuf_iterator<char>(), [vowels](char s)
			{for (const auto& v : vowels)
		{
			if (v == s)
			{
				return true;
			}
		}
		return false;
			});
		t.print();
		cout << "Количество гласных: " << count << endl;
	}
	else
	{
		cout << "Не удается открыть текстовый файл";
	}
	book2.close();
	ifstream book3("E:\phone\War and peace.txt");
	if (book3.is_open())
	{
		size_t counter = 0;
		string str;
		t.start("Способ сортировки #3");
		while (getline(book3, str))
		{
			for (size_t i = 0; i < str.size(); i++)
			{
				if (vowels.find(str[i]) != string::npos)
				{
					counter++;
				}
			}
		}
		t.print();
		cout << "Количество гласных: " << counter << endl;
	}
	else
	{
		cout << "Не удается открыть текстовый файл";
	}
	book3.close();
	ifstream book4("E:\phone\War and peace.txt");
	if (book4.is_open())
	{
		size_t counter = 0;
		string str;
		t.start("Способ сортировки #4");
		while (getline(book4, str))
		{
			for (size_t i = 0; i < str.size(); i++)
			{
				for (size_t j = 0; j < vowels.size(); j++)
				{
					if (str[i] == vowels[j])
					{
						counter++;
					}
				}
			}
		}
		t.print();
		cout << "Количество гласных: " << counter << endl;
	}
	else
	{
		cout << "Не удается открыть текстовый файл";
	}
	book4.close();

	return 0;
}