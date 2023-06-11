#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <Windows.h>

using namespace std;


int StringLenght(const char str[]);
char* To_Lower(char str[]);
char To_Upper(char str[]);
char* Shrink(char str[], int &size);
bool Is_Palindrome(const char str[]);
bool Is_Int_Number(char str[]);
int To_Int_Number(char str[]);
char* remove_symbol(char str[], char symbol);
bool Is_BIn_Number(const char str[]);

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
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	int size = StringLenght(str);
	cout << str << endl;
	cout << "Размер введенной строки - " << StringLenght(str) << endl << endl;
	//---------------------------------------------------------------------------------------
	cout << "Переводим всю строку в нижний регистр" << endl;
	cout << To_Lower(str) << endl << endl;

	cout << "Переводим всю строку в верхний регистр" << endl;
	str[size] = To_Upper(str);
	cout << str << endl << endl;

	cout << "Удаляем из строки все лишние пробелы" << endl;
	cout << Shrink(str, size) << endl << endl;

	//cout << "Определяем является ли строка полиндромом" << endl;
	//if (Is_Palindrome(str)) cout << "Строка является полиндромом" << endl << endl;
	//else cout << "Строка не полиндром" << endl << endl;

	cout << "Строка " << (Is_Palindrome(str) ? "" : "НЕ ") << "является палиндромом" << endl << endl;

	cout << "Определяем является ли строка целым числом" << endl;
	if (Is_Int_Number(str)) cout << "Строка является целым числом" << endl << endl;
	else cout << "Строка не целое число" << endl << endl;
	
	cout << "Если строка является целым числом, то возвращаем его значение" << endl;
	if (Is_Int_Number(str)) cout << "Возвращаемое число - " << To_Int_Number(str) << ", показываем тип числа - " << typeid(To_Int_Number(str)).name() << endl << endl;
	else cout << "Строка не целое число и мы не можем перевести его значение в int" << endl << endl;

	cout << "Проверяем является ли число двоичным числом" << endl;
	cout << "Строка " << (Is_BIn_Number(str) ? "" : "НЕ ") << "является двоичным числом" << endl << endl;

	cout << str << endl;
}


int StringLenght(const char str[])
{
	//int count = 0; //my code
	//while (count != 0); count++;
	//return count;

	int i = 0; //code of Oleg Anatolyevich
	for (; str[i]; i++);
	return i;
}

char To_Upper(char str[])
{
	int size = StringLenght(str); //my code
	for (int i = 0; i < size; i++)
	{
		if (((int)str[i] >= 97 && (int)str[i] <= 122) || ((int)str[i] >= -32 && (int)str[i] <= -1)) str[i] -= 32; // Работает ENG/RUS в действующих кодировках
	}
	return str[size];
}

char* To_Lower(char str[])
{
	int size = StringLenght(str);
	for (int i = 0; i < size; i++) //my code
	{
		if (((int)str[i] >= 65 && (int)str[i] <= 92) || ((int)str[i] >= -64 && (int)str[i] <= -33)) str[i] += 32;// Работает ENG/RUS в действующих кодировках
	}
	return str;
}

char* Shrink(char str[], int& size) // Пробел  32 в таблице
{
	//char buffer[256]{}; //my code
	//for (int i = 0; i < size; i++)buffer[i] = str[i];
	//bool temp = false;
	//int j = 0;
	//for (int i = 0; i < size; i++, j++)
	//{
	//	if (temp) if ((int)buffer[i] == 32) j--;
	//	str[j] = buffer[i];
	//	if ((int)buffer[i] == 32) temp = true;
	//	else temp = false;
	//}
	//for (int i = j; i <= size; i++) str[i] = {};
	//size = j;
	//return str[size];

	for (int i = 0; str[i]; i++) //code of Oleg Anatolyevich
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)str[j] = str[j + 1];
		}
	}
	while (str[0] == ' ') for (int i = 0; str[i]; i++) str[i] = str[i + 1];
	return str;
}

bool Is_Palindrome(const char str[])
{
	/*int size = StringLenght(str); //my code
	str[size] = To_Lower(str);
	char buffer[256] = {};
	buffer[size] = str[size];
	for (int i = 0, j = 0; j < size; i++, j++)
	{
		if (buffer[j] == ' ')
		{
			i--;
			continue;
		}
		str[i] = buffer[j];
	}
	if (size % 2 != 0) return false;
	for (int i = 0, j = size - 1; i < size / 2; i++, j--) if (str[i] != str[j]) return false;
	return true;*/

	int n = strlen(str); //code of Oleg Anatolyevich
	char* buffer = new char[n + 1] {};
	strcpy(buffer, str);
	str = To_Lower(buffer);
	str = remove_symbol(buffer, ' ');
	n = StringLenght(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - i - 1])
		{
			delete buffer;
			return false;
		}
	}
	delete buffer;
	return true;
}

bool Is_Int_Number(char str[])
{
	int size = StringLenght(str); //my code
	for (int i = 0; i < size; i++) if ((int)str[i] < 48 || (int)str[i] > 57) return false;
	return true;
}

int To_Int_Number(char str[])
{
	int number = 0; //my code
	for (int i = 0; str[i]; i++)
	{
		if ((int)str[i] >= 48 && str[i] <= 57) number = number * 10 + (int)str[i] - 48;
	}
	return number;
}

char* remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++) //code of Oleg Anatolyevich
	{
		while (str[i] == symbol)for (int j = i; str[j]; j++)str[j] = str[j + 1];
	}
	return str;
}

bool Is_BIn_Number(const char str[]) //Делаем константой ибо функция вовзащает true or false и не видет опрерация над строкой
{
	for (int i = 0; str[i]; i++) if (str[i] != '0' && str[i] != '1') return false;
	return true;
}
