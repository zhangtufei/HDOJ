#include <iostream>
#include <algorithm>
using namespace std;
int a[1010];
int main()
{
	int n;
	while (cin >> n&&n)
	{
		long long avr=0, k,mid;
		k= (n + 1) / 2;
		int temp;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			avr += a[i];
		}
		sort(a+1, a + n+1);
		mid = a[k];
		avr /= n;
		cout << (mid > avr ? "YES" : "NO") << endl;
	}
	return 0;
}