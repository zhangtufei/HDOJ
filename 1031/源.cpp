#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
double a[10000];
int b[10000];
bool Comp(double a, double b)
{
	return a > b;
}
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		memset(a, 0, sizeof(a));
		double temp;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> temp;
				a[j] += temp;
			}
		}
		for (int i = 0; i < k; ++i)
		{
			double max = a[0];int  p = 0;
			for (int j = 1; j < m; ++j)
			{
				if (a[j] == -1)
					continue;
				if (a[j]>max)
				{
					max = a[j];
					p = j;
				}
			}
			b[i] = p+1;
			a[p] = -1;
		}
		sort(b, b + k, Comp);
		for (int i = 0; i < k; ++i)
		{
			cout << b[i];
			if (i == k - 1)
				cout << endl;
			else
				cout << ' ' ;
		}
	}
	return 0;
}
