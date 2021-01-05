#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
using namespace std;
#include <iostream>
#include <conio.h>
#include <string>

int len_str(string &str) // функция определения длины строки заданных чисел
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

int frchtoint(string str, int Count)  // frchtoint - from char to int
{
	int k = Count - 1;
	int helper = 0;
	for (int i = 0 ; i < Count; i++)
	{
		if (str[i] != '\0')
		{
			if (str[i] == '+' || str[i] == '-')
			{
				k--;
				continue;
			}
			helper += (str[i] - '0') * pow(10,k);
			k--;
		}
	}
	return helper;
}

void fr10topr(int int10, string &str, char symbol) // fr10topr - перевод из 10-й системы счисления в прямой код
{
	int k = 0, j = 0;
	while (true)
	{
		if (int10 % 2 == 0)
		{
			int10 = int10 / 2;
			char help = k + 48;
			str[j] = help;
			k = 0;
			if (int10 < 2)
			{
				str[j+1] = int10 + 48;
				str[j+2] = '\0';
				break;
			}
			j++;
		}
		else
		{
			int10 = int10 - 1;
			k++;
		}
	}
}

int quality(int size1, int size2)  // проверяет сколько необходимо выделить разрядов для выполнения суммы чтобы избежать переполнения
{
	int N = 8;
	while (abs(size1) + abs(size2) > pow(2, N))
	{
		N++;
	}
	return N;
}


void perevod(string &str, int N, int strCount, char symbol) //perevod - записывает в строки str1 и str2 числа в прямом коде вместо естественной формы
{
	for (int i = 0; i < N; i++)
	{
		str[i] = '0';
	}
	str[N] = '\0';
	string helper;
	fr10topr(strCount, helper, symbol);
	int Count = len_str(helper);
	int j = Count - 1;
	for (int i = N - Count; i < N; i++)
	{
		str[i] = helper[j];
		j--;
	}
}

void backcode(string &str) // функция использует доступ к массиву по ссылке, выполняет перевод из прямого в обратный код
{
	int Count = len_str(str);
	for (int i = 0; i < Count; i++)
	{
		if (str[i] == '0')
		{
			str[i] = '1';
		}
		else
		{
			str[i] = '0';
		}
	}
}

void sum(string &str1, string &str2, int num1, int num2, char symbol_1, char symbol_2, int N) // функция выполнения суммы, подробное описание в README файле
{
	bool helper = false;
	bool compar = false;
	if (symbol_1 == '+' && symbol_2 == '-')
	{
		if (abs(num2) > num1)
		{
			compar = false;
		}
	}
	else
	{
		if (symbol_1 == '+' && symbol_2 == '+')
		{
			compar = false;
		}
	}

	if (symbol_1 == '+' && symbol_2 == '-')
	{
		if (abs(num2) < num1)
		{
			compar = true;
		}
	}
	else
	{
		if (symbol_1 == '-' && symbol_2 == '-')
		{
			compar = true;
		}
	}
	int i = N;
	while (true)
	{
		i--;
		if (str1[i] == '1' &&  str2[i] == '1')
		{
			if (helper == true)
			{
				str1[i] = '1';
				continue;
			}
			else
			{
				str1[i] = '0';
				helper = true;
				continue;
			}
		}
		else
		{
			if (str1[i] == '0' && str2[i] == '0')
			{
				if (helper == true)
				{
					str1[i] = '1';
					helper = false;
					continue;
				}
				else
				{
					str1[i] = '0';
					continue;
				}
			}
		}
		if (str1[i] == '1' && str2[i] == '0')
		{
			if (helper == true)
			{
				str1[i] = '0';
				continue;
			}
			else
			{
				str1[i] = '1';
				continue;
			}
		}
		else
		{
			if (str1[i] == '0' && str2[i] == '1')
			{
				if (helper == true)
				{
					str1[i] = '0';
					continue;
				}
				else
				{
					str1[i] = '1';
					continue;
				}
			}
		}
		if (i == - 1 && compar == true && helper == true && str1[N-1] == '1')
		{
			int j = N - 1;
			while (str1[j] != '0')
			{
				str1[j] = '0';
				j--;
			}
			str1[j] = '1';
			break;
		}
		else
		{
			if (i == -1 && compar == true && str1[N-1] == '0')
			{
				str1[N-1] = '1';
				break;
			}
		}
		if (i == - 1 && compar == false)
		{
			break;
		}
	}
}

int main()
{
	string s1;
	string s2;
	char symbol_1;
	char symbol_2;
	cout << "Enter symbol of 1-st number: ";
	cin >> symbol_1;
	cout << "Enter 1-st number: ";
	cin >> s1;
	cout << "Enter symbol of 2-nd number: ";
	cin >> symbol_2;
	cout << "Enter 2-nd number: ";
	cin >> s2;
	int Count_s1 = len_str(s1);
	int Count_s2 = len_str(s2);
	int strint_s1 = frchtoint(s1, Count_s1);
	int strint_s2 = frchtoint(s2, Count_s2);
	int N = quality(strint_s1, strint_s2);
	perevod(s1, N, strint_s1, symbol_1);
	perevod(s2, N, strint_s2, symbol_2);
	if (symbol_1 == '-' )
	{
		backcode(s1);
	}
	if (symbol_2 == '-')
	{
		backcode(s2);
	}
	sum(s1,s2,strint_s1, strint_s2, symbol_1, symbol_2, N);
	if (s1[0] == '1')
	{
		backcode(s1);
	}
	for (int i = 0; i < N; i++)
	{
		cout << s1[i];
	}
	getch();
	return 0;
}
