#include <iostream>

using namespace std;
int main()
{
	int n;
	while (cin >> n&&n != -1)
	{
		long long H = 1, L = 0;
		while (n--)
		{
			long long temp = H;
			H = temp * 3 + L * 2;
			L = temp + L;
		}
		cout << H << ", " << L << endl;
	}
	return 0;
}