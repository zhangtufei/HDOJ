#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	long long h[25],mul[25];
	h[1] = 0; h[2] = 1; h[3] = 2;
	for (int i = 4; i <= 20; ++i)
		h[i] = (i - 1)*(h[i - 2] + h[i - 1]);
	mul[0] = 1;
	for (int i = 1; i <= 20; ++i)
		mul[i] = i*mul[i - 1];
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		double re = (h[n] * 1.0 / mul[n]) * 100;
		cout.precision(2);
		cout << fixed << re << '%' << endl;
	}
	return 0;
}