#include <iostream>
using namespace std;
int main()
{
	long long h[41];
	h[1] = 3;
	h[2] = 8;
	for (int i = 3; i <= 40; ++i)
		h[i] = 2 * h[i - 2] + 2 * h[i - 1];
	int n;
	while (cin >> n)
	{
		cout << h[n] << endl; 
	}
	return 0;
}
//long long dfs(bool is_o, int n)
//{
//	if (n == 1)
//	{
//		if (is_o)
//			return 2;
//		else
//			return 3;
//	}
//	if (is_o)
//		return 2*dfs(false, n - 1);
//	else
//		return (dfs(true, n - 1) + 2 * dfs(false, n - 1));
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		if (n == 1)
//		{
//			cout << 3 << endl;
//			continue;
//		}
//		long long sum = dfs(true, n - 1) + 2 * dfs(false, n - 1);
//		cout << sum << endl;
//	}
//}