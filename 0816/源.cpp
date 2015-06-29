#include <iostream>
using namespace std;
//struct nodes
//{
//	int i;
//	nodes *
//};
int main()
{
	int n,k;
	cin >> n >> k;
	int a[22];
	for (int i = 1; i <= n; ++i)
	{
		a[i] = i;
	}
	int beg = 1,sum=0;
	for (int i = 1; i <= k; ++i)
	{
		int temp = beg + 1;
		if (temp > n)
			temp = 1;
		if (a[beg] < a[temp])
		{
			sum += a[temp];
			beg = temp;
			for (int j = temp; j <= n-1; ++j)
			{
				a[j] = a[j + 1];
			}
			--n;
			if (beg > n)
				beg = 1;
		}
		else if (a[beg] >= a[temp])
		{
			sum += a[beg];
			for (int j = beg; j <= n - 1; ++j)
			{
				a[beg] = a[beg + 1];
			}
			--n;
			if (beg > n)
				--beg;
		}
	}
	cout << sum << endl;
	system("pause");
}