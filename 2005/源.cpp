#include <iostream>
#include <string>
using namespace std;
int mon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int mon1[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main()
{
	string s;
	while (cin >> s)
	{
		int year, month, day;
		year = (s[0] - 0x30) * 1000 + (s[1] - 0x30) * 100 + (s[2] - 0x30) * 10 + (s[3] - 0x30);
		if (s[6] == '/')
			month = s[5] - 0x30;
		else if (s[7] == '/')
			month = (s[5] - 0x30) * 10 + (s[6] - 0x30);
		int len = s.length();
		if (s[len - 2] == '/')
			day = s[len - 1] - 0x30;
		else if (s[len - 3] == '/')
			day = s[len - 1] - 0x30 + (s[len - 2] - 0x30) * 10;
		int numOfDay = day;
		if (month <= 2)
		{
			for (int i = 1; i < month; ++i)
				numOfDay += mon[i];
		}
		else if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		{
			for (int i = 1; i < month; ++i)
				numOfDay += mon1[i];
		}
		else
			for (int i = 1; i < month; ++i)
				numOfDay += mon[i];
		cout << numOfDay << endl;
	}
	return 0;
}