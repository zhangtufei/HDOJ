#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int map[10][10], N, M, dp[10][10][2],cnt;
int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
bool success ;
void dfs(int i, int j,int t)
{
	
	if (dp[i][j][0] >= cnt)
		return;
	if (!t)
		return;
	if (map[i][j] == 3)
	{
		if (dp[i][j][0] < cnt)
			cnt = dp[i][j][0];
		success = true;
		return;
	}
	if (map[i][j] == 4)
		t = 6;
	dp[i][j][1] = t;
	for (int k = 0; k < 4; ++k)
	{
		int nx = dir[k][0] + i;
		int ny = dir[k][1] + j;
		if (nx >= 1 && nx <= N&&ny >= 1 && ny <= M&&map[nx][ny] && (dp[nx][ny][0] == -1 || dp[i][j][0] + 1 <= dp[nx][ny][0]||dp[i][j][1]-1>dp[nx][ny][1]))
		{
			dp[nx][ny][0] = dp[i][j][0] + 1;
			dp[nx][ny][1] = dp[i][j][1] - 1;
			dfs(nx, ny, t - 1);
		}
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int wall = 0, rst = 0;
		int stx, sty, edx, edy;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				cin >> map[i][j];
				if (map[i][j] == 2)
				{
					stx = i; sty = j;
				}
				else if (map[i][j] == 0)
				{
					++wall;
				}
				else if (map[i][j] == 4)
				{
					++rst;
				}
				else if (map[i][j] == 3)
				{
					edx = i; edy = j;
				}
			}
		}
		int nn = edx + edy - stx - sty;
		if (N*M - wall < nn - 1)
		{
			return -1;
		}
		if (5 + 5 * rst < nn)
			return -1;
		cnt = INT_MAX;
		memset(dp, -1, sizeof(dp));
		dp[stx][sty][0] = 0;
		dp[stx][sty][1] = 6;
		success = false;
		dfs(stx, sty,6);
		if (success)
			cout << cnt << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}