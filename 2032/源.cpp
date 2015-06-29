#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int a[35][35];
		memset(a, 0, sizeof(a));
		a[1][1] = 1;
		//a[2][1] = a[2][2] = 1;
		for (int i = 2; i <= n; ++i)
		{
			a[i][1] = a[i][i] = 1;
			for (int j = 2; j < i; ++j)
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				if (j!=i)
					cout << a[i][j]<<' ';
				else
					cout << a[i][j];
			}
			cout << endl ;
		}
		cout << endl;
	}
	return 0;
}