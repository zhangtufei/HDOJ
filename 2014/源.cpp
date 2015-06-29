#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int a, ma, mi;
		double sum = 0.0;
		cin >> a;
		sum += a;
		ma = mi = a;
		for (int i = 1; i < n; ++i)
		{
			cin >> a;
			sum += a;
			if (a>ma)
			{
				ma = a;
			}
			if (a< mi)
			{
				mi = a;
			}
		}
		cout.precision(2);
		cout <<fixed <<(sum - ma - mi)/(n-2) << endl;
	}
	return 0;
}