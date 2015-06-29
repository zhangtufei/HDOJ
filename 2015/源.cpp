#include <iostream>
using namespace std;
int main()
{
	int a[110];
	for (int i = 1; i <= 100; ++i)
	{
		a[i] = 2 * i;
	}
	int n, m;
	while (cin >> n >> m)
	{
		if (m == 0)
		{
			cout << 0 << endl;
			continue;
		}
		int temp = n%m;
		int sum ;
		int i;
		for (i = 1; i <= n-temp;)
		{
			sum = 0;
			for (int j = i; j< i + m; ++j)
			{
				sum += a[j];
			}
			i += m;
			if (i>n - temp&&temp == 0)
				cout << sum / m << endl;
			else
			{
				cout << sum / m << ' ';
			}	
		}
		if (temp != 0)
		{
			sum = 0;
			for (; i <= n; ++i)
				sum += a[i];
			cout << sum / temp << endl;
		}
	}
	return 0;
}