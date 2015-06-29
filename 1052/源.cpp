#include <iostream>
#include <algorithm>
using namespace std;
bool Comp(int x, int y)
{
	return x > y;
}
//void dfs(int i,int j, int num)
//{
//	for (int k = j; k < n; ++k)
//	{
//		if (!used[k])
//		{
//			if (a[i]>b[k])
//			{
//				used[k] = 1;
//				dfs(i + 1, ,num + 1);
//			}
//			else if (a[i] == b[k])
//			{
//				dfs(i,num)
//			}
//		}
//	}
//}
int main()
{
	int n;
	while (cin >> n&&n)
	{
		int a[1010], b[1010], re;
		re = 0;
		//memset(used, 0, sizeof(used));
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> b[i];
		}
		sort(a, a + n, Comp);
		sort(b, b + n, Comp);
		int abeg, bbeg, aend, bend;
		abeg = bbeg = 0;
		aend = bend = n-1;
		for (int i = 0; i < n; ++i)
		{
			if (a[abeg]>b[bbeg])
			{
				re += 200;
				++abeg;
				++bbeg;
			}
			else if (a[abeg]==b[bbeg])
			{
				if (a[aend]>b[bend])
				{
					re += 200;
					--aend;
					--bend;
				}
				else 
				{
					if (a[aend] < b[bbeg])
					{
						re -= 200;
					}
					--aend;
					++bbeg;
				}
			}
			else
			{
				re -= 200;
				--aend;
				++bbeg;
			}
		}
		cout << re << endl;
	}
	return 0;
}