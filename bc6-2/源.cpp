#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int t = sqrt(double(n));
		if (t*t == n)
			t -= 1;
		bool flag = false;
		for (int i = t; i >= 1; --i)
		{
			int temp = n - t*t;
			int sum = 0,j=1;
			for (int m = 1; m <= k - 1; ++j)
			{
				if (j == temp)
					continue;
				sum += j;
				++m;
			}
			if (sum <= t*t)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}