#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int a[1005];
		for (int i = 1; i <= n; ++i)
			a[i]=i;
		for (int i = 1; i < m; ++i)
			next_permutation(a + 1, a + n + 1);
		for (int i = 1; i < n; ++i)
			cout << a[i] << ' ';
		cout << a[n] << endl;
	}
	return 0;
}