#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n != -1)
	{
		long long f0 = 0, f1 = 1;
		long long sum;
		if (n == 0||n==1)
		{
			sum = n;
		}
		else
		{
			for (int i = 2; i <= n; ++i)
			{
				sum = f0 + f1;
				f0 = f1;
				f1 = sum;
			}
		}
		cout << sum << endl;
	}
	return 0;
}