#include <iostream>
#include <string>
using namespace std;
int c1[1000], c2[1000];
int main()
{
	int n;
	while (cin >> n)
	{
		memset(c1, 0, sizeof(int) * 1000);
		memset(c2, 0, sizeof(int) * 1000);
		for (int i = 0; i <= n; ++i)
			c1[i] = 1;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				for (int k = 0; k + j <= n; k += i)
					c2[k + j] += c1[j];
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