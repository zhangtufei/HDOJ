#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n)
	{
		int a[3] = { 0, 0, 0 };
		double temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			if (temp < 0)
				++a[0];
			else if (temp == 0)
				++a[1];
			else
				++a[2];
		}
		cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
	}
}