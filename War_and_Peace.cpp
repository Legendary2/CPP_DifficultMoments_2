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
		t.start("������ ���������� #1");
		size_t count = count_if(istreambuf_iterator<char>(book1), istreambuf_iterator<char>(), [=](char s)
			{return vowels.find(s) != string::npos; });
		t.print();
		cout << "���������� �������: " << count << endl;
	}
	else
	{
		cout << "�� ������� ������� ��������� ����";
	}
	book1.close();
	ifstream book2("E:\phone\War and peace.txt");
	if (book2.is_open())
	{
		t.start("������ ���������� #2");
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
		cout << "���������� �������: " << count << endl;
	}
	else
	{
		cout << "�� ������� ������� ��������� ����";
	}
	book2.close();
	ifstream book3("E:\phone\War and peace.txt");
	if (book3.is_open())
	{
		size_t counter = 0;
		string str;
		t.start("������ ���������� #3");
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
		cout << "���������� �������: " << counter << endl;
	}
	else
	{
		cout << "�� ������� ������� ��������� ����";
	}
	book3.close();
	ifstream book4("E:\phone\War and peace.txt");
	if (book4.is_open())
	{
		size_t counter = 0;
		string str;
		t.start("������ ���������� #4");
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
		cout << "���������� �������: " << counter << endl;
	}
	else
	{
		cout << "�� ������� ������� ��������� ����";
	}
	book4.close();

	return 0;
}