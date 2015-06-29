#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct blk
{
	int w;
	int l;
	int h;
};
blk a[1000];
int dp[1000],sum,n;
bool Comp(blk a,blk b)
{
	return a.w*a.l > b.w*b.l;
}
void dfs(int i,int high)
{
	if (dp[i] >= high)
		return;
	else
	{
		dp[i] = high;
	}
	if (high > sum)
	{
		sum = high;
	}
	for (int j = i + 1; j < 3 * n; ++j)
	{
		if (a[i].w>a[j].w&&a[i].l>a[j].l)
			dfs(j, high + a[j].h);
	}
	return;
}
int main()
{
	int ca = 1;
	while (cin >> n&&n)
	{
		int d[3];
		for (int i = 0; i < n; ++i)
		{
			cin >> d[0]>> d[1] >> d[2];
			sort(d, d + 3);
			a[i * 3].w = d[1];
			a[i * 3].l = d[2];
			a[i * 3].h = d[0];
			a[i * 3+1].w = d[0];
			a[i * 3+1].l = d[2];
			a[i * 3+1].h = d[1];
			a[i * 3+2].w = d[0];
			a[i * 3+2].l = d[1];
			a[i * 3+2].h = d[2];
		}
		sort(a, a + 3*n, Comp);
		memset(dp, 0, sizeof(dp));
		sum = 0;
		for (int i = 0; i < 3 * n; ++i)
		{
				dfs(i, a[i].h);
		}
		cout << "Case " << ca++ << ": maximum height = " << sum << endl;
	}
	return 0;
}