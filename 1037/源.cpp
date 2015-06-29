#include <iostream>
using namespace std;
int main()
{
	double a[3];
	double temp = 168;
	while (cin >> a[0] >> a[1] >> a[2])
	{
		bool flag = true;
		for (int i = 0; i < 3; ++i)
		{
			if (a[i] <= temp)
			{
				cout << "CRASH " << a[i] << endl;
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "NO CRASH" << endl;
	}
	return 0;
}