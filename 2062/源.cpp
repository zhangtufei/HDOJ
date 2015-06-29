#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long fn[30];
int  a[30],A[30],n;
void dfs(int num,long long m,int x)
{
	if (x > n)
		return;
	if (num == 1)
		a[x] = 1;
	if (num == 2)
	{
		switch (m)
		{
		case 1:a[x] = A[1]; break;
		case 2:a[x] = A[1]; a[x + 1] = A[2]; break;
		case 3:a[x] = A[2]; break;
		case 4:a[x] = A[2]; a[x + 1] = A[1]; break;
		default:break;
		}
		return;
	}
	long long t = fn[num]/num;
	int temp = (m-1)/t+1;
	a[x] = A[temp];
	for (int i = temp; i <= num; ++i)
	{
		A[i] = A[i + 1];
	}
	while (m > t)
		m -= t;
	if (m == 1)
	{
		return;
	}
	dfs(num - 1, m-1, x + 1);
}
int main()
{
	fn[1] = 1;
	for (int i = 2; i <= 20;++i)
	{
		fn[i] = i + i*fn[i - 1];
	}
	long long  m;
	while (cin >> n)
	{
		cin >> m;
		memset(A, 0, sizeof(int) * 30);
		for (int i = 1; i <= n; ++i)
			A[i] = i;
		memset(a, 0, sizeof(int) * 30);
		dfs(n, m, 1);
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] != 0)
			{
				if (a[i + 1] == 0)
					cout << a[i] << endl;
				else
					cout << a[i] << ' ';
			}	
			else break;
		}
	}
}