#include <iostream>
using namespace std;
int main()
{
	int i, j;
	while (cin >> i >> j)
	{
		long long max = 0, temp = 0;
		int x1=i, x2=j;
		if (i > j)
		{
			x1 = j; x2 = i;
		}
		for (int x = x1; x <= x2; ++x)
		{
			int n = x;
			++temp;
			while (n != 1)
			{
				if (n % 2 == 0)
					n /= 2;
				else
					n = 3 * n + 1;
				++temp;
			}
			if (temp > max)
					max = temp;
			temp = 0;
		}
		cout << i<<' '<<j<<' '<<max<<endl;
	}
}