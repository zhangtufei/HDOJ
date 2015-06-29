#include <iostream>
#include <math.h>
using namespace std;
long long a[100001];
int main()
{
	int n, m;
	long long temp = 1, i = 2;
	a[1] = 1;
	for (; i <= 100000; i++)
	{
		if (i & 1)
			temp = (temp * 2 + 1) % 1000000000;
		else temp = temp * 2 % 1000000000;
		a[i] = temp;
		//if (temp != 1)
		//{
		//	a[i] = temp;
		//}
		//else
		//	break;
	}
	while (cin >> n >> m)
	{
		if (n <= 100000)
			cout << a[n] << endl;
		//else
		//{
		//	for (i = 1; i <= 10000;++i)
		//}
		long long temp=1,i=2;
		a[1] = 1;
		for (; i <= 1000; i++)
		{
			if (i & 1)
				temp = (temp * 2 + 1) % m;
			else temp = temp * 2 % m;
			if (temp!=1)
			{
				a[i] = temp;
			}
			else
				break;
		}
		if (i == n + 1)
			cout << a[n] << endl;
		else
			cout << a[n%i] << endl;
	}
	return 0;
}
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#include <cstdio>
//#include<iostream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include<vector>
//using namespace std;
//const int MAX = 100000 * 2;
//const int INF = 1e9;
//
//int main()
//{
//	int n, m, ans, i;
//	while (cin>>n>>m)
//	{
//		ans = 0;
//		for (i = 1; i <= n; i++)
//		{
//			if (i & 1)ans = (ans * 2 + 1) % m;
//			else ans = ans * 2 % m;
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}