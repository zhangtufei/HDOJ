#include <iostream>
#include <iomanip>
using namespace std;
long long h[100000];
int main()
{
	int n;
	while (cin >> n)
	{
		memset(h, -1, sizeof(h));
		h[0]=1;
		if (n <= 1)
		{
			cout << 1 << endl;
			continue;
		}
		for (int i = 2; i <= n; ++i)
		{
			long long temp = 0;
			int j;
			for (j = 0; h[j] != -1; ++j)
			{
				h[j] *= i ;
				h[j] += temp;
				temp = h[j] /100000000;
				h[j] %= 100000000;
			}
			while(temp)
			{
				h[j] = temp%100000000;
				temp /= 100000000;
			}
		}
		int i = 0;
		while (h[i] != -1)
		{
			++i;
		}
		cout << h[--i];
		for (int j = i - 1; j >= 0; --j)
		{
			cout.width(8);
			cout << setfill('0') << h[j];
		}
		cout << endl;

	}
	system("pause");
}