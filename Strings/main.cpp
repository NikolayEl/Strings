#include <iostream>
#include <Windows.h>

using namespace std;

int StringLenght(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
	////char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//char str[] = "Hello";
	//cout << str << endl;

	//const char* str2 = "World";
	//cout << str2 << endl;

	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Enter string: "; 
	//cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	//SetConsoleOutputCP(866);
	SetConsoleCP(866);
	cout << str << endl;
	cout << "Размер введенной строки - " << StringLenght(str) << endl;
}

int StringLenght(const char str[])
{
	//int count = 0;
	//while (count != 0); count++;
	//return count;

	int i = 0;
	for (; str[i]; i++);
	return i;
}
