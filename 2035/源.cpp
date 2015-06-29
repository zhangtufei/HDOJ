#include <iostream>
using namespace std;
int main()
{
	int a, b;
	b = 100;
	while (cin >> a >> b&&a&&b)
	{
		int temp= 1;
		if (b >= 100)
		{
			b %= 100;
			if (a % 2 == 0)
				temp = 376;
			else if (a%5==0)
				temp = 625;
			else
				temp = 1;
		}
		if (b != 0)
		{
			while (b--)
			{
				temp *= a;
				temp %= 1000;
			}
		}
		cout << temp << endl;
	}
}
//¿ìËÙÃÝ
//#include<stdio.h>
//int pow_mod(int a, int b, int c)
//{
//	int res = 1;
//	a = a % c;
//	while (b)
//	{
//		if (b & 1)
//			res = (res * a) % c;
//		a = a * a % c;
//		b >>= 1;
//	}
//	return res;
//}
//
//int main()
//{
//	int a, b, n;
//	while (scanf("%d %d", &a, &b) != EOF)
//	{
//		if (!a && !b)
//			break;
//		printf("%d\n", pow_mod(a, b, 1000));
//	}
//	return 0;
//}