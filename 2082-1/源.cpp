//Å£±ÆµÄÄ¸º¯Êý
#include <iostream>
#include <string>
using namespace std;
int c1[10001], c2[10001];
int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		int a[27];
		for (int i = 1; i <= 26; ++i)
			cin >> a[i];
		memset(c2, 0, sizeof(int) * 10001);
		memset(c1, 0, sizeof(int) * 10001);
		for (int i = 0; i <= a[1]; ++i)
			c1[i] = 1;
		for (int i = 2; i <= 26; ++i)
		{
			for (int j = 0; j <= 50; ++j)
			{
				for (int k = 0, x = 0; k <= 50&&x<=a[i]; k += i,++x)
					c2[k + j] += c1[j];
			}
			for (int j = 0; j <= 50; ++j)
			{
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		int sum = 0;
		for (int i = 1; i <= 50; ++i)
			sum += c1[i];
		cout << sum << endl;
	}
	return 0;
}