#include <iostream>
#include <string>
using namespace std;
int c1[1000], c2[1000];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, line;
		cin >> n >> line;
		int a[10];
		memset(a, 0, sizeof(int) * 10);
		int temp;
		for (int i = 1; i <= line; ++i)
		{
			cin >> temp;
			cin >> a[temp];
		}
		memset(c1, 0, sizeof(int) * 1000);
		memset(c2, 0, sizeof(int) * 1000);
		for (int i = 0; i <= a[1]; ++i)
			c1[i] = 1;
		for (int i = 2; i <= line; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				for (int k = 0, x = 0; k + j <= n && x <= a[i]; k += i, ++x)
				{
					c2[k + j] += c1[j];
				}
			}
			for (int j = 0; j <= n; ++j)
			{
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		cout << c1[n] << endl;
	}
	return 0;
}