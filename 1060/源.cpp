#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int T;
	double h[10];
	for (int i = 1; i <= 9; ++i)
		h[i] = log10((double)i);
	cin >> T;
	while (T--)
	{
		long long N;
		cin >> N;
		long long n2 = (long long)N*log10((double)N);
		//cout << n2 << endl;
		double n1 = N*log10((double)N) - n2;
		//cout << n1 << endl;
		for (int i = 9; i >= 1; --i)
		{
			if (h[i] <= n1)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}