/*	1) Скопировать в файл F2 только те строки из F1, которые начинаются и заканчиваются на одну и ту же букву.
	2) Подсчитать количество символов в F2.*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	string row;
	ifstream F1("File1.txt");
	ofstream F2("File2.txt");

	if (F1.is_open())
	{
		while (!F1.eof())
		{
			getline(F1, row);
			if (row[0] == row[row.length() - 1])
				F2 << row << '\n';
		}
		F1.close();
		F2.close();
	}
	else cout << "Не удалось открыть F1.txt";

	int letters = 0;
	
	ifstream F3("File2.txt");
	
	if (F3.is_open())
	{
		while (!F3.eof())
		{
			getline(F3, row);
			letters += row.length();
		}
		F3.close();
	}
	else cout << "Не удалось открыть F2.txt";
	
	cout << "Строки с одинаковым началом и концом скопированы в File2.txt" << endl;
	cout << "Кол-во сиволов в File2: " << letters << endl;
}