#include <iostream>
#include <string>
#include <vector>
using namespace std;
//struct node
//{
//	char c;
//	int x;
//	int y;
//};
char map[15][15];
int dp[15][15],steps,loops;
int n, m, p;
void findway(int i,int j,int num)
{
	if (dp[i][j]!=0)
	{
		loops = dp[i][j];
		steps = num;
		return ;
	}
	if (i < 0 || j < 0 || i >= n || j >= m)
	{
		steps = num ;
		return;
	}
	dp[i][j] = num + 1;
	switch (map[i][j])
	{
	case 'N':findway(i - 1, j, num + 1); break;
	case 'S':findway(i + 1, j, num + 1); break;
	case 'W':findway(i, j - 1, num + 1); break;
	case 'E':findway(i, j + 1, num + 1); break;
	default:break;
	}
	return;
}
int main()
{
	while (cin >> n >> m >> p&&n&&m&&p)
	{
		memset(dp, 0, sizeof(dp));
		steps = 0;
		loops = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> map[i][j];
			}
		}
		findway(0, p-1,0);
		if (!loops)
		{
			cout << steps << " step(s) to exit" << endl;
		}
		else
		{
			cout << loops - 1 << " step(s) before a loop of " << steps - loops+1 << " step(s)" << endl;
		}
	}
	return 0;
}