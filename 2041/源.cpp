#include <iostream>
using namespace std;
int main()
{
	long long h[45];
	h[0] = 0;
	h[1] = 1;
	h[2] = 2;
	for (int i = 3; i <= 40; ++i)
	{
		h[i] = h[i - 1] + h[i - 2];
	}
	int n;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		cout << h[m - 1] << endl;
	}
	return 0;
}