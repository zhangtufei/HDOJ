#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define INTMAX  1000001
long long map[1010][1010], N, M, dp[1010];
int res[1010];

void dijkstra()
{
	int used[1010];
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= N; ++i)
	{
		dp[i] = map[2][i];
	}
	used[2] = 1;
	dp[2] = 0;
	
	for (int i = 2; i <= N; ++i)
	{
		long long minpath = INTMAX;
		int cur = 0;//cur未初始化放在for循环外面时会导致RE，如N=2，M=0.。。。cur不会被初始化
		for (int j = 1;j<= N; ++j)
		{
			if (!used[j] && dp[j] < minpath)
			{
				cur = j;
				minpath = dp[j];
			}
		}
		used[cur] = 1;
		for (int j = 1; j <= N; ++j)
		{
			if (!used[j] && minpath + map[cur][j] < dp[j])
				dp[j] = minpath + map[cur][j];			
		}
	}
}

int dfs(int node)
{
	//if (node == 2 )
	//{
	//	++re;
	//	return;
	//}
	//for (int i = 1; i <= N; ++i)
	//{
	//	if (i != node&&dp[node] + map[node][i] == dp[i])
	//		dfs(i);
	//}
	if (res[node] != -1)
		return res[node];
	if (node == 2)
		return 1;
	res[node] = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (map[node][i] != INTMAX&&dp[node] > dp[i])
			res[node] += dfs(i);
	}
	return res[node];
}
int main()
{
	while (cin >> N&&N)
	{
		cin >> M;
		for (int i = 0; i <= N; ++i)
		{
			dp[i] = -1;
			for (int j = 0; j <= N; ++j)
				map[i][j] = INTMAX;
		}
		int a, b, c;
		for (int i = 0; i < M; ++i)
		{
			cin >> a >> b >> c;
			map[a][b] = map[b][a] = c;
		}
		dijkstra();
		memset(res, -1, sizeof(res));
		cout << dfs(1) << endl;
	}
	return 0;
}