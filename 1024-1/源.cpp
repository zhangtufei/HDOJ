#include <iostream>
using namespace std;
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int *pre_max = new int[n+1];
		int *cur_max = new int[n+1];
		int *a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n + 1; ++i)
		{
			pre_max[i] = 0;
		}
		cur_max[0] = 0;
		int sum_max;
		for (int i = 1; i <= m; ++i)
		{
			sum_max = INT_MIN;
			int j = i;
			for (; j <= n; ++j)
			{
				cur_max[j] = (cur_max[j - 1] > pre_max[j - 1]) ? (cur_max[j - 1] + a[j - 1]) : (pre_max[j - 1] + a[j - 1]);
				pre_max[j - 1] = sum_max;
				if (sum_max < cur_max[j])
					sum_max = cur_max[j];
			}
			pre_max[j - 1] = sum_max;
		}
		delete[] cur_max;
		delete[] a;
		delete[] pre_max;
		cout << sum_max << endl;
	}
	return 0;
}