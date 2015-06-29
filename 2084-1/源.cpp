#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int max;
struct tuf
{
	int num;
	int max;
}a[110][110];

int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				scanf("%d", &a[i][j].num);
				a[i][j].max = a[i][j].num;
			}
		}
		for (int i = n - 1; i >= 1; --i)
		{
			for (int j = 1; j <= i; ++j)
				a[i][j].max = a[i + 1][j].max > a[i + 1][j + 1].max ? (a[i][j].num + a[i + 1][j].max) : (a[i][j].num + a[i + 1][j + 1].max);
		}
		cout << a[1][1].max << endl;
	}
	return 0;
}