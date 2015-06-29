#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	bool first = true;
	while (cin >> n)
	{
		char a, b;
		cin >> a >> b;
		if (first)
			first = false;
		else
			cout << endl;
		int temp = (n - 1) / 2;
		if (temp % 2 != 0)
		{
			char t = a;
			a = b;
			b = t;
		}
		string s[80];
		s[0] = " ";
		for (int i = 1; i <= n - 2; ++i)
			s[0] += a;
		s[0] += " ";
		for (int i = 1,  flag = 1; i < n / 2; i += 2,++flag)
		{
			for (int j = 0; j < flag; ++j)
			{
				s[i] += a ;
				s[i] += b;
				s[i+1] += a;
				s[i+1] += b;
			}
			for (int j = flag * 2; j < n - flag * 2; ++j)
			{
				s[i] +=b;
				s[i + 1] += a;
			}
			for (int j = 0; j < flag; ++j)
			{
				s[i] += b;
				s[i] += a;
				s[i + 1] += b;
				s[i + 1] += a;
			}
		}
		s[n / 2] = "";
		for (int i = 0; i < n; ++i)
		{
			if (i % 2 == 0)
				s[n / 2] += a;
			else
				s[n / 2] += b;
		}
		for (int i = 0; i < n / 2; ++i)
		{
			s[n - 1 - i] = s[i];
		}
		for (int i = 0; i < n; ++i)
			cout << s[i] << endl;
	}
	return 0;
}