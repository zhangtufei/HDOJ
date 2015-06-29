#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n)
	{
		int map[110][110];
		int dp[110];
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		int bg, ed;
		int citynum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> bg >> ed;
			if (ed > citynum)
				citynum = ed;
			map[bg][ed] = 1;
		}
		int maxtime = 0;
		for (int i = 0; i <= citynum; ++i)
		{
			for (int k = 0; k <i; ++k)
			{
				if (dp[k] > maxtime)
					maxtime = dp[k];
			}
			if (dp[i] < maxtime)
				dp[i] = maxtime;
			for (int j = i + 1; j <= citynum; ++j)
			{
				if (map[i][j])
				{
					dp[j] = (dp[j] > dp[i] + 1) ? dp[j] : dp[i] + 1;
				}
			}
		}
		for (int i = 0; i <= citynum; ++i)
		{
			if (dp[i] > maxtime)
				maxtime = dp[i];
		}
		cout << maxtime << endl;
	}
	return 0;
}