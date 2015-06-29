#include <iostream>
using namespace std;
int main()
{
	int n, r;
	while (cin >> n >> r)
	{
		if (n < 0)
		{
			n = -n;
			cout << '-';
		}
		int a[35];
		int i;
		for (i=0; i <= 31; ++i)
		{
			a[i] = n%r ;
			n /= r;
			if (n == 0)
				break;
		}
		for (int j = i; j >= 0; --j)
		{
			char c;
			if (a[j] >= 10)
			{
				c = a[j] - 10 + 'A';
			}
			else
				c = a[j] + '0';
			cout << c;
		}
		cout << endl;
	}
	return 0;
}