#include <iostream>
using namespace std;
int main()
{
	double h[301];
	h[1] = 0.5;
	for (int i = 2; i <= 300; ++i)
	{
		h[i] = h[i - 1] +1.0/ (i + 1);
	}
	double n;
	while (cin >> n&&n)
	{
		int i = 1;
		while (h[i++] < n);
		cout << i - 1<<" card(s)" << endl;
	}
	return 0;
}