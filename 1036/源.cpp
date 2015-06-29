#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;
int main()
{
	int n;
	double len;
	cin >> n >> len;
	int num;
	string temp = "-:--:--";
	while (cin >> num )
	{
		int h=0, m=0, sec=0;
		char s1[10];
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			cin >> s1;
			if (s1==temp&&flag)
			{
				cout.width(3);
				cout << setfill(' ')<<num << ": -" << endl;
				flag = false;
			}
		/*	if (s1 == temp)
			{
				cout.width(3);
				cout << setfill(' ') << num << ": -" << endl;
				flag = false;
			}*/
			else if (flag)
			{
				int j = 0;
				while (s1[j] != ':')
					++j;
				if (j == 1)
				{
					h += (s1[0] - 0x30);
					m += (s1[3] - 0x30 + (s1[2] - 0x30) * 10);
					sec += (s1[6] - 0x30 + (s1[5] - 0x30) * 10);
				}
				else if (j == 2)
				{
					h += ((s1[1] - 0x30) + (s1[0] - 0x30) * 10);
					m += (s1[4] - 0x30 + (s1[3] - 0x30) * 10);
					sec += (s1[7] - 0x30 + (s1[6] - 0x30) * 10);
				}
			}
		}
		if (flag)
		{
			sec = h * 3600 + m * 60 + sec;
			sec = (int)((double)sec/ len + 0.5);
			m = sec / 60;
			sec %= 60;
			cout.width(3);
			cout << setfill(' ') << num << ": ";
			cout << m << ':';
			cout.width(2);
			cout << setfill('0') << sec << " min/km" << endl;
		}
	}
	return 0;
}