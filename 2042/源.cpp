#include <iostream>
using namespace std;
int main()
{
	long long h[40];
	h[0] = 3;
	for (int i = 1; i <= 30; ++i)
	{
		h[i] = (h[i-1] - 1) * 2;
	}
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		cout << h[a] << endl;
	}
	return 0;
}