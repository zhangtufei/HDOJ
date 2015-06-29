//dijkstra算法
//
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
const int MAX_SIZE = 1010;
const int intmax = 0x7f7f7f7f;
int T, S, D,cityNum,minTime;
int map[MAX_SIZE][MAX_SIZE], d[MAX_SIZE], dp[MAX_SIZE], used[MAX_SIZE];
void dijkstra()
{
	int minPath, iminPath;
	//used表示某个节点是否遍历过
	memset(used, 0, sizeof(int)*MAX_SIZE);
	//保存每个节点的值
	for (int i = 1; i <= cityNum; ++i)
		dp[i] = map[0][i];
	//遍历所有节点
	for (int i = 1; i <= cityNum; ++i)
	{
		minPath = intmax;
		for (int j = 1; j <= cityNum; ++j)
		{
			//找到当前S（路径最短（dp[j]）的一条，并标记为已遍历，下次循环时就会跳过该节点）
			if (!used[j] && dp[j] < minPath)
			{
				iminPath = j;
				minPath = dp[j];
			}
		}
		used[iminPath] = 1;
		for (int j = 1; j <= cityNum; ++j)
		{
			//计算节点J的最小值：当前S的值+S到节点J的路径
			if (!used[j] && dp[iminPath] + map[iminPath][j] < dp[j])
				dp[j] = dp[iminPath] + map[iminPath][j];
		}
	}
	minTime = dp[d[1]];
	for (int i = 2; i <= D; ++i)
	{
		if (dp[d[i]] < minTime)
			minTime = dp[d[i]];
	}
}
int main()
{
	while (cin >> T >> S >> D)
	{
		memset(map, intmax, sizeof(int) * 1010 * 1010);
		cityNum = 0;
		int a, b, c;
		for (int i = 1; i <= T; ++i)
		{
			scanf("%d %d %d", &a, &b, &c);
			map[a][b] = map[b][a] = (map[a][b] > c) ? c : map[a][b];
			if (a > b)
			{
				cityNum = cityNum > a ? cityNum : a;
			}
			else
				cityNum = cityNum > b ? cityNum : b;
		}
		for (int i = 1; i <= S; ++i)
		{
			scanf("%d", &a);
			map[0][a] = map[a][0] = 0;
		}
		for (int i = 1; i <= D; ++i)
		{
			scanf("%d", &d[i]);
		}
		dijkstra();
		cout << minTime << endl;
	}
	return 0;
}