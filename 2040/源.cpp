#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		long long a, b;
		cin >> a >> b;
		//if (a > b)
		//{
		//	int temp = a;
		//	a = b;
		//	b = temp;
		//}
		long long sum = 1;
		for (int i = 2; i <= sqrt((double)a); ++i)
		{
			if (a%i == 0)
			{
				sum += i;
				sum += a / i;
			}
		}
		if (sum == b)
		{
			sum = 1;
			for (int i = 2; i <= sqrt((double)b); ++i)
			{
				if (b%i == 0)
				{
					sum += i;
					sum += b / i;
				}
			}
			if (sum == a)
			{
				cout << "YES" << endl;
				continue;
			}
		}
		cout << "NO" << endl;
	}
	return 0;
}