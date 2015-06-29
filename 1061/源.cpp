#include <iostream>
using namespace std;
long long mod_pow(long long a, int mod)
{
	int res = 1;
	long long x = a;
	while (a > 0)
	{
		if (a & 1)
			res = res*x%mod;
		x = x*x%mod;
		a >>= 1;
	}
	return res;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << mod_pow(n, 10) << endl;;
	}
	return 0;
}