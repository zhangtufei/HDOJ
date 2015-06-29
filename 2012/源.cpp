#include <iostream>
using namespace std;
int main()
{
	int x, y;
	while (cin >> x >> y&&!(x == 0 && y == 0))
	{
		long long num = 0;
		bool flag = true;
		for (int i = x; i <= y; ++i)
		{
			num= i*i + i + 41;
			for (int j = 2; j*j <= num; ++j)
			{
				if (num%j == 0)
				{
					flag = false;
					break;
				}
			}
		if (!flag)
				break;
		}
		if (flag)
			cout << "OK" << endl;
		else
			cout << "Sorry" << endl;
	}
	return 0;
}