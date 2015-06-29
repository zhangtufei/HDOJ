#include <iostream>
#include <string>
#include <queue>
#include <ctype.h>
using namespace std;
int dp[60][60], newmap[15][15], value[15], usedbfs[60][60], useddfs[15];
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 }, maxvalue, revalue;
int W, H, L, M;
char map[60][60];
struct node
{
	int y;
	int x;
};
void bfs(int y, int x, int p)
{
	queue<node> que;
	node cur;
	cur.x = x;
	cur.y = y;
	usedbfs[y][x] = 1;
	dp[y][x] = 0;
	que.push(cur);
	while (!que.empty())
	{
		cur = que.front();
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			node next;
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if (next.x >= 0 && next.x < W&&next.y >= 0 && next.y < H&&!usedbfs[next.y][next.x] && map[next.y][next.x] != '*')
			{
				usedbfs[next.y][next.x] = 1;
				dp[next.y][next.x] = dp[cur.y][cur.x] + 1;
				if (map[next.y][next.x] == '@')
				{
					newmap[p][0] = dp[next.y][next.x];
				}
				if (isalpha(map[next.y][next.x]))
				{
					newmap[p][map[next.y][next.x] - 'A'+1] = dp[next.y][next.x];
				}
				if (map[next.y][next.x] == '<')
				{
					newmap[p][M + 1] = dp[next.y][next.x];
				}
				que.push(next);
			}
		}
	}
}
void dfs(int p, int v, int tm)
{
	if (tm > L || revalue == maxvalue)
	{
		return;
	}
	if (p > M)
	{
		if (v > revalue)
			revalue = v;
		return;
	}
	for (int i = 0; i <= M + 1; ++i)
	{
		if (newmap[p][i] == 0 || useddfs[i])
			continue;
		useddfs[i] = 1;
		dfs(i, v + value[i], tm + newmap[p][i]);
		useddfs[i] = 0;
	}
}
int main()
{
	int T;
	cin >> T;
	int temp = T;
	while (T--)
	{
		memset(newmap, 0, sizeof(newmap));
		memset(value, 0, sizeof(value));
		maxvalue = 0;
		cin >> W >> H >> L >> M;
		for (int i = 1; i <= M; ++i)
		{
			cin >> value[i];
			maxvalue += value[i];
		}
		for (int i = 0; i < H; ++i)
		{
			cin >> map[i];
		}
		for (int i = 0;i < H; ++i)
		{
			for (int j = 0; j < W; ++j)
			{
				memset(usedbfs, 0, sizeof(usedbfs));
				memset(dp, 0, sizeof(dp));
				if (map[i][j] == '@')
				{
					bfs(i, j, 0);
				}
				if (isalpha(map[i][j]))
				{
					bfs(i, j, map[i][j] - 'A'+1);
				}
				if (map[i][j] == '<')
				{
					bfs(i, j, M + 1);
				}
			}
		}
		memset(useddfs, 0, sizeof(useddfs));
		revalue = -1;
		useddfs[0] = 1;
		dfs(0, 0, 0);
		if (revalue >= 0)
		{
			cout << "Case " << temp - T << ":" << endl << "The best score is " << revalue << "." << endl;
		}
		else
		{
			cout << "Case " << temp - T << ":" << endl << "Impossible" << endl;
		}
		if (T)
		{
			cout << endl;
		}
	}
	return 0;
}