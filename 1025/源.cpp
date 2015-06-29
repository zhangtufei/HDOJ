#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct road
{
	int p;
	int r;
}r[500010];
int len[500010];
//这里其实不需要判断相等，如果数据给出一对二的情况，本题输出会出现错误
bool Comp(road a,road b)
{
	if (a.p < b.p)
		return true;
	else if (a.p == b.p&&a.r < b.r)
	{
		return true;
	}
	else
		return false;
}
//nlogn算法，求最大上升子序列
int nlogn(int s, int m,int num)
{
	while (s < m)
	{
		int mid = (s + m) / 2;
		if (num>len[mid])
		{
			s = mid +1;
		}
		else
		{
			m=mid;
		}
	}
	return s;
}
int main()
{
	int n;
	int k = 1;
	while (cin >> n)
	{
		for (int i = 0; i <n; ++i)
		{
			cin >> r[i].p >> r[i].r;
		}
		sort(r, r + n,Comp);
		int x=0;
		len[0] = r[0].r;
		for (int i = 1; i < n; ++i)
		{
			if (r[i].r>len[x])
				len[++x] = r[i].r;
			else
			{
				len[nlogn(0, x,r[i].r)] = r[i].r;
			}
		}
		cout << "Case " << k++ << ":" << endl;
		if (n == 0)
		{
			cout << "My king, at most " << 0 << " road can be built." << endl;
			continue;
		}
		if (x < 1)
		{
			cout << "My king, at most " << x+1 << " road can be built." << endl;
		}
		else
		{
			cout << "My king, at most " << x+1 << " roads can be built." << endl;
		}
		cout << endl;
	}
	return 0;
}