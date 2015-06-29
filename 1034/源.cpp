#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int a[100010];
bool finish(int n)
{
	int temp = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] != temp)
			return false;
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n&&n)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			//if (a[i] % 2 != 0)
			//	++a[i];
		}
		int flag = 0;
		while (!finish(n))
		{
			//int temp = a[0]/2;
			//a[0] = a[n - 1] / 2 + temp;
			//if (a[0]%2!=0)
			int t1, t2;
			t1 = a[n - 1] / 2;
			for (int i = 0; i < n; ++i)
			{
				t2 = a[i]/2;
				a[i] = t1 + t2;
				t1 = t2;
				if (a[i] % 2 != 0)
					++a[i];
			}
			++flag;
		}
		cout << flag << ' ' << a[0] << endl;
	}
	return 0;
}