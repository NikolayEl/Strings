#include <iostream>
#include <Windows.h>

using namespace std;


int StringLenght(const char str[]);
char To_Lower(char str[]);
char To_Upper(char str[]);
char Shrink(char str[], int &size);
bool Is_Palindrome(char str[]);
bool Is_Int_Number(char str[]);
int To_Int_Number(char str[]);

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
	str[size] = To_Lower(str);
	cout << str << endl << endl;

	cout << "Переводим всю строку в верхний регистр" << endl;
	str[size] = To_Upper(str);
	cout << str << endl << endl;

	cout << "Удаляем из строки все лишние пробелы" << endl;
	str[size] = Shrink(str, size);
	cout << str << endl << endl;	

	cout << "Определяем является ли строка полиндромом" << endl;
	if (Is_Palindrome(str)) cout << "Строка является полиндромом" << endl << endl;
	else cout << "Строка не полиндром" << endl << endl;

	cout << "Определяем является ли строка целым числом" << endl;
	if (Is_Int_Number(str)) cout << "Строка является целым числом" << endl << endl;
	else cout << "Строка не целое число" << endl << endl;
	
	cout << "Если строка является целым числом, то возвращаем его значение" << endl;
	if (Is_Int_Number(str)) cout << "Возвращаемое число - " << To_Int_Number(str) << ", показываем тип числа - " << typeid(To_Int_Number(str)).name() << endl << endl;
	else cout << "Строка не целое число и мы не можем вывести его значение в int" << endl << endl;


	//cout << int(str[0]);
	//cout << str[size + 1];
	//cout << size % 2;

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

char To_Upper(char str[])
{
	int size = StringLenght(str);
	for (int i = 0; i < size; i++)
	{
		if (((int)str[i] >= 97 && (int)str[i] <= 122) || ((int)str[i] >= -32 && (int)str[i] <= -1)) str[i] -= 32; // Работает ENG/RUS в действующих кодировках
	}
	return str[size];
}

char To_Lower(char str[])
{
	int size = StringLenght(str);
	for (int i = 0; i < size; i++)
	{
		if (((int)str[i] >= 65 && (int)str[i] <= 92) || ((int)str[i] >= -64 && (int)str[i] <= -33)) str[i] += 32;// Работает ENG/RUS в действующих кодировках
	}
	return str[size];
}

char Shrink(char str[], int& size) // Пробел  32 в таблице
{
	char buffer[256]{};
	for (int i = 0; i < size; i++)buffer[i] = str[i];
	bool temp = false;
	int j = 0;
	for (int i = 0; i < size; i++, j++)
	{
		if (temp) if ((int)buffer[i] == 32) j--;
		str[j] = buffer[i];
		if ((int)buffer[i] == 32) temp = true;
		else temp = false;
	}
	for (int i = j; i <= size; i++) str[i] = {};
	size = j;
	return str[size];
}

bool Is_Palindrome(char str[])
{
	int size = StringLenght(str);
	if (size % 2 != 0) return false;
	for (int i = 0, j = size - 1; i < size / 2; i++, j--) if (str[i] != str[j]) return false;
	return true;
}

bool Is_Int_Number(char str[])
{
	int size = StringLenght(str);
	for (int i = 0; i < size; i++) if ((int)str[i] < 48 || (int)str[i] > 57) return false;
	return true;
}

int To_Int_Number(char str[])
{
	int size = StringLenght(str);
	int number = 0;
	for (int i = 0; i < size; i++)
	{
		if ((int)str[i] == 48) number *= 10;
		if ((int)str[i] == 49) number = number * 10 + 1;
		if ((int)str[i] == 50) number = number * 10 + 2;
		if ((int)str[i] == 51) number = number * 10 + 3;
		if ((int)str[i] == 52) number = number * 10 + 4;
		if ((int)str[i] == 53) number = number * 10 + 5;
		if ((int)str[i] == 54) number = number * 10 + 6;
		if ((int)str[i] == 55) number = number * 10 + 7;
		if ((int)str[i] == 56) number = number * 10 + 8;
		if ((int)str[i] == 57) number = number * 10 + 9;
	}
	return number;
}
