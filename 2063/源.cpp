//–Ÿ—¿¿˚À„∑®
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int k, m, n;
const int MAX_NUM = 1001;
int map[MAX_NUM][MAX_NUM], used[MAX_NUM], boys[MAX_NUM];
bool path(int a)
{
	for (int i = 1; i <= n; ++i)
	{
		if (!used[i] && map[a][i])
		{
			used[i] = 1;
			if (!boys[i] || path(boys[i]))
			{
				boys[i] = a;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	while (cin >> k&&k)
	{
		cin >> m >> n;
		memset(map, 0, sizeof(int)*MAX_NUM*MAX_NUM);
		memset(boys, 0, sizeof(int)*MAX_NUM); 
		int a, b;
		for (int i = 1; i <= k; ++i)
		{
			cin >> a >> b;
			map[a][b] = 1;
		}
		int sum = 0;
		for (int i = 1; i <= m; ++i)
		{
			memset(used, 0, sizeof(int)*MAX_NUM);
			if (path(i))
				++sum;
		}
		cout << sum << endl;
	}
	return 0;
}