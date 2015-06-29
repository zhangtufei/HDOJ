//卡塔兰数或者DP
//#include <iostream>
//using namespace std;
//卡塔兰数解法
//int main()
//{
//	long long h[36];
//	h[0] = h[1] = 1;
//	for (int i = 2; i <= 35; ++i)
//	{
//		h[i] = (4 * i - 2) / (1.0*(i + 1))*h[i - 1];
//	}
//	int n;
//	int a = 1;
//	while (cin >> n&&n != -1)
//	{
//		cout << a++ << ' ' << n << ' ' << h[n]*2 << endl;
//	}
//	return 0;
//}
//DP解法
//搜索超时
//long long sum ;
//int n;
//void dfs(int x,int y)
//{
//	if (x > n)
//		return;
//	if (x == n&&y == n)
//	{
//		++sum;
//		return;
//	}
//	if (x == y)
//		dfs(x + 1, y);
//	else
//	{
//		dfs(x + 1, y);
//		dfs(x, y + 1);
//	}
//}
//int main()
//{
//	while (cin >> n&&n != -1)
//	{
//		sum = 0;
//		dfs(1, 0);
//		cout << sum*2 << endl;
//	}
//}
//计算到达每个点的路径数
#include <iostream>
using namespace std;
int main()
{
	long long a[36][36];
	for (int x = 0; x < 36; ++x)
		a[0][x] = 1;
	a[1][1] = 1;
	for (int x = 2; x < 36; ++x)
	{
		for (int y = 1; y <= x; ++y)
		{
			if (x == y)
				a[y][x] = a[y - 1][x];
			else
				a[y][x] = a[y - 1][x] + a[y][x - 1];
		}
	}
	int n;
	int flag = 1;
	while (cin >> n&&n != -1)
	{
		cout << flag++ << ' ' << n << ' ' << a[n][n] * 2 << endl;
	}
	return 0;
}