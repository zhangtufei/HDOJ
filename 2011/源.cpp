#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		int n;
		cin >> n;
		double sum = 0.0;
		bool flag = true;
		for (int i = 1; i <= n; ++i)
		{
			if (flag)
			{
				sum += 1.0 / i;
				flag = false;
			}
			else
			{
				sum -= 1.0 / i;
				flag = true;
			}
		}
		cout.precision(2);
		cout << fixed << sum << endl;
	}
	return 0;
}