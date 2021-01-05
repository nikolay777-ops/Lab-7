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

int len_str(string str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

int frchtoint(string str, int Count) // frchtoint - from char to int
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

string fr10to2(int int10)  // функция перевода из 10-й системы в двоичную, алгоритм работы в README файле
{
	string str;
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
	return str;
}

int main()
{
	string s1;
	cin >> s1;
	int Count = len_str(s1);
	int strint = frchtoint(s1, Count);
	string str = fr10to2(strint);
	int newCount = 0;
	while (str[newCount] != 0)
	{
		newCount++;
	}
	if (s1[0] == '+')
	{
		cout << "0";
	}
	else
	{
		cout << "1";
	}
	for (int i = newCount - 1; i >= 0; i--)
	{
		cout << str[i];
	}
	getch();
	return 0;
}
