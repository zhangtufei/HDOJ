#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct moveline
{
	int bg;
	int ed;
};
int used[210],re,n;
moveline a[210];
bool Comp(moveline a, moveline b)
{
	return a.bg < b.bg;
}
void movest(int i, int ed)
{
	bool flag = true;
	for (int j = i+1; j < n; ++j)
	{
		if (!used[j] && (a[j].bg-1)/2 > (ed-1)/2)
		{
			used[j] = 1;
			movest(j, a[j].ed);
			flag = false;
			break;
		}
	}
	if (flag)
		++re;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		re = 0;
		memset(used, 0, sizeof(used));
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i].bg >> a[i].ed;
			if (a[i].bg > a[i].ed)
			{
				int temp = a[i].bg;
				a[i].bg = a[i].ed;
				a[i].ed = temp;
			}
		}
		sort(a, a + n, Comp);
		for (int i = 0; i < n; ++i)
		{
			if (!used[i])
			{
				used[i] = 1;
				movest(i, a[i].ed);
			}
		}
		cout << re * 10 << endl;
	}
	return 0;
}