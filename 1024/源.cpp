//#include <iostream>
//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//int imax;
//int m;
//int n;
//void dfs(int *num,int i,int mth,int sum)
//{
//	for (int x = i; x < n; ++x)
//	{
//		if (num[x] <= 0)
//			continue;
//		for (int y = x; y < n; ++y)
//		{
//			if (num[y] <= 0)
//				continue;
//			int temp=0;
//			for (int z = x; z <= y; ++z)
//				temp += num[z];
//			if (temp <= 0)
//				break;
//			if (mth == m)
//			{
//				if (sum + temp > imax)
//					imax = sum + temp;
//			}
//			else
//			{
//				if (y < n - 1)
//					dfs(num, y + 1, mth + 1, sum + temp);
//			}
//		}
//	}
//}
//int main()
//{
//	while (cin >> m >> n)
//	{
//		imax = 0;
//		int *num = new int[n];
//		for (int i = 0; i < n; ++i)
//			scanf("%d", num + i);
//		dfs(num, 0, 1, 0);
//		cout << imax << endl;
//		delete[] num;
//	}
//	return 0;
//}
#include<iostream>
#include<climits>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int max(int *a, int m, int n)
{
	int *c;
	int *p;
	int max, i, j;
	c = new int[n + 1];
	p = new int[n + 1];
	for (i = 0; i<n + 1; i++)
		p[i] = 0;
	c[0] = 0;
	for (i = 1; i <= m; ++i)
	{
		max = INT_MIN;
		for (j = i; j <= n; ++j)
		{
			if (c[j - 1]< p[j - 1])
				c[j] = p[j - 1] + a[j - 1];
			else
				c[j] = c[j - 1] + a[j - 1];
			p[j - 1] = max;
			if (max<c[j])
				max = c[j];
		}
		p[j - 1] = max;
	}
	delete[]p;
	delete[]c;
	return max;
}
int main()
{
	int n, m, i, *d;
	while (cin >> m >> n)
	{
		d = new int[n];
		for (i = 0; i<n; ++i)
			cin >> d[i];
		cout << max(d, m, n) << endl;
		delete[] d;
	}
	return 0;
}