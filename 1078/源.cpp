#include <iostream>
#include <string>
using namespace std;
#define maxi(a,b) a>b?a:b
int map[110][110], dp[110][110], re,n, k;
int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
//³¬Ê±
//void dfs(int i, int j, int sum)
//{
//	if (dp[i][j] != -1)
//	{
//		if (sum < dp[i][j])
//			return;
//	}
//	if (sum > re)
//		re = sum;
//	dp[i][j] = sum;
//	for (int x = 1; x<= k; ++x)
//	{
//		for (int y = 0; y < 4; ++y)
//		{
//			int nx = i + x*dir[y][0], ny = j + x*dir[y][1];
//			if (nx >= 0 && nx < n&&ny >= 0 && ny < n&&map[i][j]<map[nx][ny])
//			{
//				dfs(nx, ny, sum + map[nx][ny]);
//			}
//		}
//	}
//}
//¼ÇÒä»¯ËÑË÷
int dfs(int i, int j)
{
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	//if (sum > re)
	//	re = sum;
	//dp[i][j] = sum;
	int sum = 0;
	for (int x = 1; x<= k; ++x)
	{
		for (int y = 0; y < 4; ++y)
		{
			int nx = i + x*dir[y][0], ny = j + x*dir[y][1];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < n&&map[i][j]<map[nx][ny])
			{
				sum = maxi(sum, dfs(nx, ny));
			}
		}
	}
	return dp[i][j] = sum + map[i][j];
}
int main()
{
	while (cin >> n >> k&&n != -1 && k != -1)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				cin >> map[i][j];
		}
		memset(dp, -1, sizeof(dp));
		cout << dfs(0, 0) << endl;
	}
	return 0;
}