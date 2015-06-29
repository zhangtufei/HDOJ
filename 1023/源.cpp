#include <iostream>
using namespace std;
int n;
long long num;
void dfs(int x, int a, int b)
{
	if (x == n&&a==0&&b==0)
		++num;
	else
	{
		if (a > 0)
			dfs(x + 1, a - 1, b);
		if (b>0)
		{ 
			for (int i = 1; i <= b; ++i)
				dfs(x + 1, a + i-1, b - i);
		}
	}
	return;
}
int main()
{
	while (cin >> n)
	{
		num = 0;
		for (int i = 1; i <= n; ++i)
			dfs(1, i - 1, n - i);
		cout << num << endl;
		
	}
	return 0;
}