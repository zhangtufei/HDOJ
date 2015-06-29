#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;
int ti;
int T,S, D;
int t[1100][3];
int s[1010];
int d[1010];
void dfs(int tm,int sr)
{
	for (int i = 0; i < D; ++i)
	{
		if (t[sr][1] == d[i])
		{
			if (tm +t[sr][2]< ti)
				ti = tm+t[sr][2];
			return;
		}
	}
	for (int i = 0; i < T; ++i)
	{
		if (t[i][0] == t[sr][1])
			dfs(tm + t[sr][2], i);
	}

}
int main()
{
	while (cin >> T)
	{
		ti = INT_MAX;
		cin >> S >> D;
		for (int i = 0; i < T; ++i)
		{
			scanf("%d %d %d", &t[i][0], &t[i][1], &t[i][2]);
		}

		for (int i = 0; i < S; ++i)
		{
			scanf("%d", &s[i]);
		}
		for (int i = 0; i < D; ++i)
		{
			scanf("%d", &d[i]);
		}
		bool flag = false;
		for (int i = 0; i < S; ++i)
		{
			for (int j = 0; j < D; ++j)
			{
				if (s[i] == d[j])
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				ti = 0;
				break;
			}
			for (int j = 0; j < T; ++j)
			{
				if (t[j][0] == s[i])
					dfs(0,j);
			}
		}
		cout << ti << endl;
	}
	return 0;
}