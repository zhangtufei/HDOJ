#include <iostream>
using namespace std;
int main()
{
	long long h[55];
	h[0] = 0; h[1] = 1; h[2] = 2;
	for (int i = 3; i <= 50; ++i)
	{
		h[i] = h[i - 1] + h[i - 2];
	}
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << h[b - a] << endl;
	}
	return 0;
}