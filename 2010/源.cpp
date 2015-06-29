#include <iostream>
using namespace std;
bool istrue(int num)
{
	int temp = num;
	int a1, a2, a3;
	a1 = temp % 10; temp /= 10;
	a2 = temp % 10; temp /= 10;
	a3 = temp;
	return num == a1*a1*a1 + a2*a2*a2 + a3*a3*a3;
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		bool flag = false;
		int a[1000],p=0;
		for (int i = m; i <= n; ++i)
		{
			if (istrue(i))
			{
				a[p++] = i;
				flag = true;
			}
		}
		if (!flag)
		{
			cout << "no" << endl;
		}
		else
		{
			for (int i = 0; i < p; ++i)
			{
				if (i == p - 1)
				{
					cout << a[i] << endl;
					break;
				}
				cout << a[i] << ' ';
			}
		}
	}
	return 0;
}