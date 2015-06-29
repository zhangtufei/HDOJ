#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m&&!(n == 0 && m == 0))
	{
		if (n*n - 4 * m < 0)
		{
			cout << "No" << endl;
			continue;
		}
		double d1 = (n - sqrt((double)(n*n - 4 * m))) / 2;
		int temp = (int)d1;
		double d2 = temp;
		if (d2 == d1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}