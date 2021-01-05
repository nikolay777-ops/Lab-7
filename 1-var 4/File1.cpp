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

int len_str(string &number)
{
	int i = 0;
	while (number[i] != '\0')
	{
		i++;
	}
	return i;
}

int fr11to10(string num11, int Count)
{
	long int num10 = 0;
	int k = Count - 1;
	for (int i = 0; i < Count; i++)
	{
		if (num11[i] == 'A')
		{
			num10 += 10 * pow(11,k);
			k--;
			continue;
		}
		num10 += (num11[i] - '0') * pow(11,k);
		k--;
	}
	return num10;
}

string fr10to7(int num10)
{
	string num7;
	int j = 0, k = 0;
	while (true)
	{
		if (num10 % 7 == 0)
		{
			num10 = num10 / 7;
			char help = k + 48;
			num7[j] = help;
			k = 0;
			if (num10 < 10)
			{
				num7[j+1] = num10 + 48;
				num7[j+2] = '\0';
				break;
			}
			j++;
		}
		else
		{
			num10 = num10 - 1;
			k++;
		}
	}
	return num7;
}

int main()
{
	string num_11;
	cout << "Enter number in 11-th system of counting ";
	cin >> num_11;
	int Count = len_str(num_11);
	int num_10 = fr11to10(num_11, Count);
	string num_7 = fr10to7(num_10);
    int Count_7 = len_str(num_7);
	for (int i = Count_7 - 1; i >= 0; i--)
	{
		cout << num_7[i];
	}
	getch();
	return 0;
}
