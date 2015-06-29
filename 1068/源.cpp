#include <iostream>
#include <string>
using namespace std;
int used[1001], st[1001], map[1001][1001],n;
bool path(int a)
{
	for (int i = 0; i < n; ++i)
	{
		if (!used[i] && map[a][i]&&st[i])
		{
			used[i] = 1;
			if (st[i] == -1 || path(st[i]))
			{
				st[i] = a;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	/*int n;*/
	while (cin >> n)
	{
		char c;
		int a, b;
		memset(map, 0, sizeof(map));
		memset(st, -1, sizeof(st));
		for (int i = 0; i < n; ++i)
		{
			cin >> a >> c >> c >> b >> c;
			int jq;
			for (int j = 0; j < b; ++j)
			{
				cin >> jq;
				map[a][jq] =map[jq][a] =1;
			}
		}
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			memset(used, 0, sizeof(used));
			if (path(i))
				++sum;
		}
		if (sum % 2)//考虑输入0 1 2两两相关联，这时候能匹配的为3，应去掉两人
			++sum;
		cout << n - sum/2 << endl;
	}
	return 0;
}