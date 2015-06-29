#include <iostream>
using namespace std;
int main()
{
	int a,b;
	while (cin >> a >> b)
	{
		int re = 1;
		a %= 10;
		while (b)
		{
			if (b & 1)
				re = re*a % 10;
			a = a*a % 10;
			b >>= 1;
		}
		cout << re << endl;
	}
	return 0;
}