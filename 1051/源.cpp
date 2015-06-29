#include <iostream>
#include <algorithm>
using namespace std;
struct wood
{
	int l;
	int w;
};
bool Comp(wood a, wood b)
{
	if (a.l < b.l)
	{
		return true;
	}
	else if (a.l == b.l)
	{
		return a.w < b.w;
	}
	return false;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		wood a[5010];
		int used[5010];
		memset(used, 0, sizeof(used));
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i].l >> a[i].w;
		}
		sort(a, a + n, Comp);
		//搞不明白，为什么这样不行
		//int w, re = 1;
		//w = a[0].w;
		//for (int i = 1; i < n; ++i)
		//{
		//	if (a[i].w < w)
		//	{
		//		++re;
		//	}
		//	w = a[i].w;
		//}
		int re = 0;
		for (int i = 0; i < n; ++i)
		{
			if (!used[i])
			{
				int w = a[i].w;
				for (int j = i + 1; j < n; ++j)
				{
					if (!used[j] && w <= a[j].w)
					{
						w = a[j].w;
						used[j] = 1;
					}
				}
				++re;
			}
		}
		cout << re << endl;
	}
	return 0;
}