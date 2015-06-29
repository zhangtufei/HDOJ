#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	int T;
	string st = "0";
	cin >> T;
	while (T--)
	{
		//cout << endl;
		string s1;
		cin >> s1;
		if (s1 != st)
		{
			int a[150];
			memset(a, 0, sizeof(a));
			int j = 0;
			for (int i = s1.size() - 1; i >= 0; --i)
			{
				a[j++] = s1[i] - 0x30;
			}
			while (cin >> s1)
			{
				if (s1 == st)
				{
					int k = 149;
					//很走运，这里把一串0的情况也正确处理了
					while (a[k] == 0)
					{
						k--;
						if (k < 0)
							break;
					}
					if (k < 0)
					{
						cout << 0 ;
					}
					else
					{
						for (int i = k; i >= 0; --i)
						{
							cout << a[i];
						}
					}
					cout << endl;
					break;
				}
				int temp = 0,j=0;
				for (int i = s1.size() - 1; i >= 0; --i,++j)
				{
					a[j] += (s1[i] - 0x30) + temp;
					temp = a[j] / 10;
					a[j] %= 10;
				}
				if (temp)
				{
					a[j] += temp;
				}
			}
		}
		else
		{
			cout << 0 << endl ;
		}
		if (T)
			cout << endl;
	}
}