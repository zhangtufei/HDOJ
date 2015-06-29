#include <iostream>
using namespace std;
int main()
{
	int  n;
	while (cin >> n&&n)
	{
		int temp, sum = 0;
		int x[6] = { 100, 50, 10, 5, 2, 1 };
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			for (int j = 0; j < 6; ++j)
			{
				sum += (temp / x[j]);
				temp %= x[j];
				if (temp == 0)
					break;
			}
		}
		cout << sum << endl;
	}
	return 0;
}