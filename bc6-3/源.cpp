#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		if (k == 2)
		{
			cout << 1 << endl;
			continue;
		}
		else
		{
			int cnt = 1;
			for (int i = 2; i <= n; ++i)
			{
				if (n%i == 0)
				{
					++cnt;
				}
				else//没那么简单。。。。
				{
					int t1 = n, t2 = i;
					int temp =t1%t2;
					while (temp)
					{
						t1 = t2;
						t2 = temp;
						temp = t1%t2;
					}
					if (t2 == 1)
						cnt+=2;
				}
			}
			cout << cnt << endl;
		}
	}
	return 0;
}