#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	long long h[1010][100];
	memset(h, 0, sizeof(h));
	h[2][0] = 1;
	int flag = 1;
	for (int i = 3; i <= 1000; ++i)
	{
		long long temp=0;
		int j;
		for (j = 0; h[i-1][j]!=0; ++j)
		{
			if (i % 2 == 0)
			{
				h[i][j] += (h[i - 1][j] * 2 + (j == 0 ? 1 : temp));
				temp = h[i][j] / 10000000;
				h[i][j] %= 10000000;
			}
			else
			{
				h[i][j] += (h[i - 1][j] * 2 + (j == 0 ? -1 : temp));
				temp = h[i][j] / 10000000;
				h[i][j] %= 10000000;
			}
		}
		if (temp)
		{
			h[i][j] += temp;
		}
	}
	int n;
	while (cin >> n)
	{
		int i =0;
		while (h[n][i + 1] != 0)
		{
			++i;
		}
		cout << h[n][i];
		for (int j = i - 1; j >= 0; --j)
		{
			cout.width(7);
			cout << setfill('0') << h[n][j];
		}
		cout << endl;
	}
	return 0;
}