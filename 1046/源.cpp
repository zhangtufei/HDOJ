#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	int flag = 1;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		double sum = 0.0;
		if (n % 2 != 0 && m % 2 != 0)
		{
			sum = sqrt((double)2.0) + n*m - 1;
		}
		else
			sum = n*m;
		cout << "Scenario #" << flag++ << ":" << endl;
		cout << setprecision(2) << fixed << sum << endl << endl;
	}
	system("pause");
	return 0;
}