#include <iostream>
using namespace std;
int main()
{
	int n, u, d;
	while (cin >> n >> u >> d&&!(n == 0 && u == 0 && d == 0))
	{
		int sum = 0;
		while (n - u > 0)
		{
			n -= (u - d);
			sum += 2;
		}
		cout << sum+1<< endl;
	}
	return 0;
}