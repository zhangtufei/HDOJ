#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long x, y, k;
		cin >> x >> y >> k;
		long long t1 = x, t2 = y;
		long long temp;
		if (t1 < t2)
		{
			temp = t1;
			t1 = t2;
			t2 = temp;
		}
		temp = t1%t2;
		while (temp)
		{
			t1 = t2;
			t2 = temp;
			temp = t1%t2;
		}
		temp = t2;
		long long l = 1,re;
		long long a[500];
		a[0] = 1;
		long long sq = sqrt((double)temp);
		for (int i = 2; i <= sq&&l<k; ++i)
		{
			if (temp%i == 0)
			{
				a[l++] = i;
			}
		}
		if (l < k)
		{
			long long len;
			if (a[l - 1] * a[l - 1] == temp)
				len= l * 2 - 1;
			else
				len =l* 2;
			if (k > len)
			{
				cout << -1 << endl;
			}
			else
				cout << a[len - k] << endl;
		}
		else
		{
			cout <<temp/a[k-1] << endl;
		}
	}
	return 0;
}