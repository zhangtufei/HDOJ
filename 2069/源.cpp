#include <iostream>
#include <string>
using namespace std;
struct coins
{
	int x;
	int ct;
};
coins c1[300], c2[300];
int a[6] = { 0,1, 5, 10, 25, 50 };
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < 300; ++i)
		{
			c1[i].x = 0;
			c1[i].ct = 0;
			c2[i].x = 0;
			c2[i].ct = 0;
		}
		int temp = (n > 100) ? 100 : n;
		for (int i = 0; i <= 100; ++i)
		{
			c1[i].x = 1;
			c1[i].ct = 1;
		}
		c1[0].ct = 0;
		int ct = 0;
		for (int i = 2; i <= 5; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				for (int k = 0; j + k <= n; k += a[i])
				{
					c2[k + j].ct =k+c1[j].ct;
					if (c2[k+j].ct<=100)
						c2[k + j].x += c1[j].x;
				}
			}
			for (int j = 0; j <= n; ++j)
			{
				c1[j].x = c2[j].x;
				c1[j].ct = c2[j].ct;
				c2[j].x = 0;
				c2[j].ct = 0;
			}
			c1[0].ct = 0;
		}
		cout << c1[n].x << endl;
	}
	return 0;
}