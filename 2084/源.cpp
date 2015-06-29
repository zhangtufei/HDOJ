#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int maxi;
int a[110][110];
int n;
void dfs(int x,int y,int sum)
{
	if (x > n)
		return;
	sum += a[x][y];
	if (sum > maxi)
		maxi = sum;
	dfs(x + 1, y, sum);
	dfs(x + 1, y + 1, sum);
}
int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		memset(a, 0, sizeof(int)*12100);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
				scanf("%d", &a[i][j]);
		}
		maxi = a[1][1];
		dfs(2,1,a[1][1]);
		dfs(2, 2, a[1][1]);
		cout << maxi << endl;
	}
	return 0;
}