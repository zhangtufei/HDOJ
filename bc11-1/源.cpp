#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int dp[100010][10];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		unsigned int a[100010];
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < M; ++i)
		{
			char c;
			cin >> c;
			if (c == 'Q')
			{
				int L, R, D, P,sum=0;
				cin >> L >> R >> D >> P;
				for (int j = L; j <= R; ++j)
				{

					if (dp[j][D]==-1)
					{
						int temp = a[j];
						int tt = pow((double)10, (double)D - 1);
						temp /= tt;
						/*for (int k = 1; k < D; ++k)
						{
						temp /= 10;
						if (temp == 0)
						break;
						}*/
						dp[j][D] = temp % 10;
					}
					if (dp[j][D]== P)
					{
						++sum;
					}
				}
				cout << sum << endl;
			}
			else if (c == 'S')
			{
				int x, y;
				cin >> x >> y;
				a[x] =y;

			}
		}
	}
	return 0;
}

//bc11-2
//bool Comp(int a, int b)
//{
//	return a > b;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int a[110],nz=0;
//		bool flag = false;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> a[i];
//			if (a[i])
//			{
//				++nz;
//				if (a[i] % 2 == 1)
//					flag = true;
//			}
//		}
//		if (!flag)
//		{
//			cout << -1 << endl;
//			continue;
//		}
//		if (nz <= 1&&n!=1)
//		{
//			cout << -1 << endl;
//			continue;
//		}
//		sort(a, a + n, Comp);
//		int temp;
//		for (int i = n - 1; i >= 0; --i)
//		{
//			if (a[i] % 2 == 1)
//			{
//				temp = a[i];
//				for (int j = i; j < n-1; ++j)
//				{
//					a[j] = a[j + 1];
//				}
//				break;
//			}
//		}
//		for (int i = 0; i < n-1; ++i)
//			cout << a[i];
//		cout <<temp <<endl;
//	}
//}

//bc11-1
//int main()
//{
//	int N, M, x, y;
//	while (cin >> N)
//	{
//		cin >>M >> x >> y;
//		if (x == N - x&&y == M - y)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}