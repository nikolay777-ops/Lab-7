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

int len_str(string &str)  // ������� �������� ����� ������
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

int chint(char num) // ������� chint - char to int ��������� ������ ������ ����� �� ���� char � ��� int
{
	int helper = 0;
	if (num == 'A' || num == 'a')
	{
		helper = 10;
	}
	else
	{
		helper = num - '0';
	}
	return helper;
}

void checker(string &str1, string &str2) // ������� checker ������ ������� �������� 1-� � 2-� ������ ���� 2-� ������� (��� ������� �������)
{
	int len1 = len_str(str1);
	int len2 = len_str(str2);
	if (len2 > len1)
	{
		int i = 0;
		while (str2[i] != '\0')
		{
			char helper = str1[i];
			str1[i] = str2[i];
			str2[i] = helper;
            i++;
		}
        str1[i] = '\0';
	}
}

void wider(string &str) // ������� wider ������ ������ ���� �� 1 ������� � ������ ���� � �������� ���������� ������������
{
	int len = len_str(str);
	for (int i = len ; i > 0; i--)
	{
		str[i] = str[i-1];
	}
}

void sum(string &str1, string &str2)   // ������� ����� - ����� ��������� �������� � README �����
{
	int len1 = len_str(str1);
	int len2 = len_str(str2);
	int num1 = 0;
	int num2 = 0;
	int helper = 0;
	for (int i = len1 - 1, j = len2 - 1; i >= 0; i--, j--)
	{
		num1 = chint(str1[i]);
		num2 = chint(str2[j]);
		if (num2 < 0)
		{
			num2 = 0;
		}
		if (num1 < 0)
		{
			num1 = 0;
		}
		num1 += num2 + helper;
		if (num1 == 10)
		{
			str1[i] = 'A';
			continue;
		}
		if (helper == 1)
		{
			helper--;
		}
		if (num1 >= 11)
		{
			num1 -= 11;
			if (num1 == 10)
			{
				str1[i] = 'A';
				helper++;
				continue;
			}
			else
			{
				str1[i] = num1 + '0';
			}
			helper++;
		}
		else
		{
			if (str1[i] == '+' || str1[i] == '-')
			{
				wider(str1);
				str1[i+1] = num1 + '0';
			}
			else
			{
				if (true)
				{
                    str1[i] = num1 + '0';
				}
			}
		}
	}
}

void ext(string &str1, string &str2) // ������� �������� - ����� ��������� �������� � README �����
{
	int len1 = len_str(str1);
	int len2 = len_str(str2);
	int num1 = 0;
	int num2 = 0;
	bool helper = false;
	for (int i = len1 - 1, j = len2 - 1; i > 0; i--, j--)
	{
		num1 = chint(str1[i]);
		num2 = chint(str2[j]);
		if (helper == true)
		{
			num1--;
			helper = false;
		}
		if (num2 < 0)
		{
            num2 = 0;
		}
		if (num1 < num2)
		{
			num1 += 11;
			helper = true;
		}
		num1 -= num2;
		if (num1 == 10)
		{
			str1[i] = 'A';
		}
		else
		{
			str1[i] = num1 + '0';
		}
	}
}

int _tmain()
{
	string str1;
	string str2;
	char symbol;
	cout << "Enter 1-st number with '+' or '-': ";
	cin >> str1;
	cout << "Enter symbol of operation: ";
	cin >> symbol;
	cout << "Enter 2-nd number with '+' or '-': ";
	cin >> str2;
	if (str1[0] == '+' && symbol == '+' && str2[0] == '+')
	{
		checker(str1, str2); // ������� checker ������ ������� �������� 1-� � 2-� ������ ���� 2-� ������� (��� ������� �������)
		int Count = len_str(str1);
		sum(str1, str2);
		for (int i = 0; i <= Count ; i++)
		{
			cout << str1[i];
		}
		str1[0] = '0'; // ��� ���� ����� �� ����������� ��������� ������� � ����� ��������� ���������� � ���� �����
	}
	if (str1[0] == '-' && symbol == '+' && str2[0] == '+')
	{
		checker(str1, str2);
		int Count = len_str(str1);
		ext(str1, str2);
		for (int i = 0; i < Count; i++)
		{
			cout << str1[i];
		}
		str1[0] = '0';
	}
	if (str1[0] == '-' && symbol == '-' && str2[0] == '+')
	{
		checker(str1, str2);
		int Count = len_str(str1);
		sum(str1,str2);
		for (int i = 0; i <= Count; i++)
		{
			cout << str1[i];
		}
		str1[0] = '0';
	}
	if (str1[0] == '-' && symbol == '-' && str2[0] == '-')
	{
		if (len_str(str1) < len_str(str2)) // ��� ��� ������ ������� ������� ��������� ����� �� ����� �������� ���� � - �� +
		{                                  // ����� � ������ ���� ��� ������
			str2[0] = '+';
		}
		checker(str1, str2);
		int Count = len_str(str1);
		ext(str1,str2);
		for (int i = 0; i < Count; i++)
		{
			cout << str1[i];
		}
		str1[0] = '0';
	}
	if (str1[0] == '+' && symbol == '-' && str2[0] == '-')
	{
		checker(str1, str2);
		if (str1[0] == '-')
		{
			str1[0] = '+';
		}
		int Count = len_str(str1);
		sum(str1,str2);
		for (int i = 0; i <= Count; i++)
		{
			cout << str1[i];
		}
		str1[0] = '0';
	}
	if (str1[0] == '+' && symbol == '+' && str2[0] == '-')
	{
		checker(str1, str2);
		int Count = len_str(str1);
		ext(str1,str2);
		for (int i = 0; i < Count; i++)
		{
			cout << str1[i];
		}
		str1[0] = '0';
	}
	if (str1[0] == '+' && symbol == '-' && str2[0] == '+')
	{
		if (len_str(str1) < len_str(str2))
		{
			str2[0] = '-';
		}
		checker(str1, str2);
		int Count = len_str(str1);
		ext(str1,str2);
		for (int i = 0; i < Count; i++)
		{
			cout << str1[i];
		}
		str1[0] = '0';
	}
	if (str1[0] == '-' && symbol == '+' && str2[0] == '-')
	{
		checker(str1, str2);
		int Count = len_str(str1);
		sum(str1, str2);
		for (int i = 0; i <= Count; i++)
		{
			cout << str1[i];
		}
		str1[0] = '0';
	}
	getch();
	return 0;
}
