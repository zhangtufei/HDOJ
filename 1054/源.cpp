#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;
struct nodes
{
	int i;
	int num;
	int next[1510];
	bool isRoot;
};
int dp[1510][2];
nodes node[1510];
int Compmin(int x, int y)
{
	return x < y ? x : y;
}
int dfs(int i, int flag)//flag为0表示该节点不放士兵，并且此
{						//时下一个节点必须放士兵，为1表示该节点放士兵，下个节点可放可不放
	//这里用动态规划是可以节约时间,比如第一次搜错dfs(i,0)，第二次搜索i,1，第二次中出现第一次相同的情况
	if (dp[i][flag] != -1)
		return dp[i][flag];
	int sum = flag;
	for (int j = 0; j < node[i].num; ++j)
	{
		if (flag)
		{
			sum += Compmin(dfs(node[i].next[j], 0), dfs(node[i].next[j], 1));
		}
		else
		{
			sum += dfs(node[i].next[j], 1);
		}
	}
	dp[i][flag] = sum;
	return sum;
}
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			node[i].i = i;
			node[i].isRoot = true;
			node[i].num = 0;
			dp[i][0] = dp[i][1] = -1;
		}
		/*memset(dp, false, sizeof(dp));*/
		int a, b;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d:(%d)", &a, &b);
			node[a].num = b;
			int temp;
			for (int j = 0; j < b; ++j)
			{
				cin >> temp;
				node[a].next[j] = temp;
				node[temp].isRoot = false;
			}
		}
		int i = 0;
		while (!node[i].isRoot)
			++i;
		int re = Compmin(dfs(i, 0), dfs(i, 1));
		cout << re << endl;
	}
}
//#include <iostream>  
//#include <cstdio>  
//#include <cstring>  
//
//#define MaxN 1505  
//
//using namespace std;
//
//struct Node {
//	int no;
//	int sons;
//	int son_no[MaxN];
//	bool isRoot;
//}node[MaxN];
//int dp[MaxN][2];
//int n;
//int min(int x, int y)
//{
//	return x < y ? x : y;
//}
//int solve(int i, int flag)
//{
//	if (dp[i][flag] != -1)
//		return dp[i][flag];
//
//	int sum = flag;
//	for (int j = 0; j < node[i].sons; j++) {
//		if (flag == 0) {
//			sum += solve(node[i].son_no[j], 1);
//		}
//		else {
//			sum += min(solve(node[i].son_no[j], 0), solve(node[i].son_no[j], 1));
//		}
//	}
//	dp[i][flag] = sum;
//
//	return sum;
//}
//
//int main()
//{
//	//freopen("data.in", "rb", stdin);  
//	while (scanf("%d", &n) != EOF) {
//		for (int i = 0; i < n; i++) {
//			node[i].no = i;
//			node[i].isRoot = true;
//			node[i].sons = 0;
//			dp[i][0] = dp[i][1] = -1;
//		}
//		for (int i = 0; i < n; i++) {
//			int a, b;
//			scanf("%d:(%d)", &a, &b);
//			node[a].sons = b;
//			for (int j = 0; j < b; j++) {
//				int tmp;
//				scanf("%d", &tmp);
//				node[a].son_no[j] = tmp;
//				node[tmp].isRoot = false;
//			}
//		}
//
//		int i = 0;
//		while (!node[i].isRoot)
//			i++;
//
//		printf("%d\n", min(solve(i, 0), solve(i, 1)));
//	}
//
//	return 0;
//}