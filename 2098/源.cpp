#include <iostream>
#include <math.h>
using namespace std;
bool Isprime(int a)
{
	for (int i = (int)sqrt((double)a); i > 1; --i)
	{
		if (a%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n&&n)
	{
		int count = 0;
		for (int i = 2; i < n / 2; ++i)
		{
			if (Isprime(i))
				if (Isprime(n - i))
					++count;
		}
		cout << count << endl;
	}
	return 0;
}
//ÇóËØÊýËã·¨
//#include <stdio.h>
//#define N 10000
//void func(bool a[10001])
//{
//	int i, j;
//	a[1] = 1;
//	for (i = 2; i*i <= N; i++)
//	{
//		if (a[i] == 0)
//		{
//			for (j = i; j*i <= N;)
//			{
//				a[i*j] = 1;
//				if (i == 2){ j++; }
//				else { j = j + 2; }
//			}
//		}
//	}
//}
//
//int main()
//{
//	bool a[10001] = { 0 };
//	func(a);
//	int n, i, j, count;
//	scanf("%d", &n);
//	while (n)
//	{
//		count = 0;
//		for (i = 2; i<n / 2; i++)
//		{
//			j = n - i;
//			if (a[j] == 0 && a[i] == 0){ count++; }
//		}
//		printf("%d\n", count);
//		scanf("%d", &n);
//	}
//	return 0;
//}