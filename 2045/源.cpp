#include <iostream>
using namespace std;
int main()
{
	long long h[55];
	h[1] = 3; h[2] = h[3] = 6;
	for (int i = 4; i <= 50; ++i)
	{
		h[i] = 2 * h[i - 2] + h[i - 1];
	}
	int n;
	while (cin >> n)
	{
		cout << h[n] << endl;
	}
	return 0;
}