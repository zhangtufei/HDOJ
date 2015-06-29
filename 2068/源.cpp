#include <iostream>
#include <string>
using namespace std;
int rpg[30];
int num;
int n;
void dfs(int x,int wr,int c)
{
	if (wr > n / 2)
		return;
	if (c >= (n / 2 + n % 2))
	{
		int temp = 1;
		for (int i = n - x + 1; i > 0; --i)
		{
			temp *= i;
		}
		num += temp;
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		bool flag = true;
		for (int j = 1; j < x; ++j)
		{
			if (rpg[j] == i)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			rpg[x] = i;
			if (x == i)
				dfs(x + 1, wr, c+1);
			else
				dfs(x + 1, wr+1, c);
		}
	}
}
int main()
{
	while (cin >> n&&n)
	{
		memset(rpg, 0, sizeof(int) * 30);
		num = 0;
		dfs(1,0, 0);
		cout << num << endl;
	}
	return 0;
}