#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		double a, b, c;
		cin >> a >> b >> c;
		if (a + b > c&&fabs(a - b) < c&&a&&b&&c)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}