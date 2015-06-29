#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		double a[60];
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		sort(a + 1, a + n+1);
		double dp[60];
		memset(dp, 0, sizeof(dp));
		for (int i = 2; i < n; ++i)
		{
			dp[i] = (a[i] - a[i - 1] > a[i+1] - a[i]) ? (a[i] - a[i - 1]) : (a[i+1] - a[i]);
		}
		double maxlen = dp[2];
		for (int i = 3; i < n; ++i)
		{
			if (maxlen>dp[i])
				maxlen = dp[i];
		}
		cout.precision(3);
		cout << fixed << maxlen << endl;
	}
	return 0;
}