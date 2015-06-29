#include <iostream>
#include <string>
using namespace std;
int c1[10000], c2[10000];
int main()
{
	int num_1, num_2, num_5;
	while (cin >> num_1 >> num_2 >> num_5&&!(num_1 == 0 && num_2 == 0 && num_5 == 0))
	{
		memset(c1, 0, sizeof(int) * 10000);
		memset(c2, 0, sizeof(int) * 10000);
		for (int i = 0; i <= num_1; ++i)
			c1[i] = 1;
		int i = 2;
		for (int j = 0; j <= num_1; ++j)
		{
			for (int k = 0, x = 0; x <= num_2; k += i, ++x)
				c2[j + k] += c1[j];
		}
		for (int j = 0; j <= num_1+num_2*i; ++j)
		{
			c1[j] = c2[j];
			c2[j] = 0;
		}
		i = 5;
		for (int j = 0; j <= num_1+num_2*2; ++j)
		{
			for (int k = 0, x = 0; x <= num_5; k += i, ++x)
				c2[j + k] += c1[j];
		}
		for (int j = 0; j <= 10000; ++j)
		{
			c1[j] = c2[j];
		}
		for (int i = 1; i <= 10000; ++i)
		{
			if (c1[i] == 0)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}