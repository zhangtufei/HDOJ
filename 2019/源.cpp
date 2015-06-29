#include <iostream>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m&&!(n == 0 && m == 0))
	{
		int a[110];
		int temp;
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			if (temp >= m&&flag)
			{
				a[i++] = m;
				a[i] = temp;
				flag = false;
				++n;
			}
			//else if (temp == m)
			//{
			//	a[i] = temp;
			//	flag = false;
			//}
			else
				a[i] = temp;
		}
		if (flag)
			a[n++] = m;
		for (int i = 0; i < n-1; ++i)
		{
			cout << a[i] << ' ';
		}
		cout << a[n-1] << endl;
	}
	return 0;
}