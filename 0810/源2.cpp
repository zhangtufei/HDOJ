#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int map[1000][1000],frt,lst,mintime,dp[1000];
int maxn(int a, int b)
{
	return (a > b) ? a : b;
}
void dfs(int p,int T)
{
	for (int i = frt + 1; i <= lst; ++i)
	{
		if (dp[])
	}
}
int main()
{
	string s;
	cin >> s;
	if (s == "Sender")
	{
		cin >> frt;
	}
	cin >> s;
	memset(map, 0, sizeof(map));
	lst = 0;
	if (s == "Relationship")
	{
		int a, b;
		char c;
		while (cin >> a >>c>> b)
		{
			lst = maxn(lst, maxn(a, b));
			map[a][b] = 1;
		}
	}
	mintime = 0xfffffff;
	dfs(frt,0);
}