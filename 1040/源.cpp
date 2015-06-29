#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int a[1010];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = 0; i < n - 1; ++i)
			cout << a[i] << ' ';
		cout << a[n - 1] << endl;
	}
	return 0;
}