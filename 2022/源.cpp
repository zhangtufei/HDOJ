#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int temp, max=0, p1, p2;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> temp;
				if (fabs((double)temp) > fabs((double)max))
				{
					max = temp;
					p1 = i; p2 = j;
				}
			}
		}
		cout << p1 + 1 << ' ' << p2 + 1 <<' '<< max << endl;
	}
	return 0;
}