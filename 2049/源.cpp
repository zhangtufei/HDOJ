#include <iostream>
using namespace std;
long long multi(int n,int m)
{
	long long temp = 1;
	for (int i = 2; i <= m; ++i)
		temp *= i;
	long long temp1 = 1;
	for (int i = n; i >n-m; --i)
		temp1 *= i;
	return temp1 / temp;
}
long long wsort(long long num)
{
	if (num == 1)
	{
		return 0;
	}
	else if (num == 2)
	{
		return 1;
	}
	else
		return (num - 1)*(wsort(num - 2) + wsort(num - 1));
}
int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		long long n, m;
		cin >> n >> m;
		cout << multi(n, n - m)*wsort(m) << endl;
	}
	return 0;
}
//#include <stdio.h>
//
//int main()
//{
//	int n, a, b, i, j;
//	__int64 s[22], h[22];
//	s[1] = 0;
//	s[2] = 1;
//	s[3] = 2;
//	for (i = 4; i<21; i++)
//	{
//		s[i] = (i - 1)*(s[i - 1] + s[i - 2]);
//	}
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%d%d", &a, &b);
//		h[0] = 1;
//		for (j = 1; j<22; j++){
//			h[j] = j*h[j - 1];
//		}
//		printf("%I64d\n", h[a] / (h[a - b] * h[b])*s[b]);
//	}
//	return 0;
//}