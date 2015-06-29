#include <iostream>
using namespace std;
int a[6] = { 0, 1, 5, 10, 25, 50 };
int main()
{
	int n;
	while (cin >> n)
	{
		int num[6];
		for (int i = 1; i <= 5; ++i)
			num[i] = n / a[i];
		int sum = 0;
		for (int i = 0; i <= num[5]; ++i)
		{
			for (int j = 0; j <= num[4]; ++j)
			{
				for (int k = 0; k <= num[3]; ++k)
				{
					for (int x = 0; x <= num[2]; ++x)
					{
						for (int y = 0; y <= num[1]; ++y)
						{
							if (i * 50 + j * 25 + k * 10 + x * 5 + y == n&&i + j+ k + x + y <= 100)
								++sum;
						}
					}
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}