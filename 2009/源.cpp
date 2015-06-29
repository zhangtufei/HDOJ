#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		double temp = n,sum=n;
		for (int i = 1; i < m; ++i)
		{
			temp = sqrt(double(temp));
			sum += temp;
		}
		cout.precision(2);
		cout << fixed << sum << endl;
	}
	return 0;
}