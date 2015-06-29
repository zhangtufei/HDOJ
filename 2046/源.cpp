#include <iostream>
using namespace std;
int main()
{
	long long h[55];
	h[1] = 1; h[2] = 2; h[3] = 3;
	for (int i = 4; i <= 50; ++i)
		h[i] = h[i - 1] + h[i - 2];
	int n;
	while (cin >> n)
		cout << h[n] << endl;
	return 0;
}