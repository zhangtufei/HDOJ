#include <iostream>
using namespace std;
int main()
{
	long long h[35];
	h[1] = 1;
	for (int i = 2; i <= 30; ++i)
	{
		h[i] = (h[i-1] + 1) * 2;
	}
	int n;
	while (cin >> n)
	{
		cout << h[n] << endl;
	}
	return 0;
}