#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long y, n;
		cin >> y >> n;
		while (1)
		{
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			{
				break;
			}
			else
				y += 1;
		}
		if (y == 0)
			y += 4;
		n -= 1;
		y = y + (n / 97) * 400;
		n %= 97;
		for (int i = 1; i <= n; ++i)
		{
			y += 4;
			if (y % 100 == 0 && y % 400 != 0)
				y += 4;
		}
		cout << y << endl;
	}
	return 0;
}