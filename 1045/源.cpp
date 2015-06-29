#include <iostream>
#include <string>
using namespace std;
char map[10][10];
//int used[10][10];
int re,n;
//int maxc[4] = { 1, 2, 5, 8 };
//int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
//bool bemax;
bool isConfig(int i,int j)
{
	bool flagr = true, flagc = true;
	if (map[i][j] == 'X')
		return false;
	for (int k = i-1; k >=0; --k)
	{
		if (map[k][j] == '1')
		{
			flagr = false;
			break;
		}
		if (map[k][j] == 'X')
			break;
	}
	if (flagr&&flagc)
	{
		for (int k = i+1; k<n; ++k)
		{
			if (map[k][j] == '1')
			{
				flagr = false;
				break;
			}
			if (map[k][j] == 'X')
				break;
		}
	}
	if (flagr&&flagc)
	{
		for (int k = j + 1; k<n; ++k)
		{
			if (map[i][k] == '1')
			{
				flagc = false;
				break;
			}
			if (map[i][k] == 'X')
				break;
		}
	}
	if (flagr&&flagc)
	{
		for (int k = j-1; k>=0; --k)
		{
			if (map[i][k] == '1')
			{
				flagc = false;
				break;
			}
			if (map[i][k] == 'X')
				break;
		}
	}
	return flagr&&flagc;
}
//void dfs(int i, int j, int num)
//{
//	if (num == maxc[n])
//	{
//		bemax = true;
//		re = num;
//		return;
//	}
//	if (bemax)
//		return;
//	if (num > re)
//	{
//		re = num;
//	}
//	used[i][j] = 1;
//	if (isConfig(i, j))
//	{
//		int ntx, nty;
//		for (int k = 0; k < 4; ++k)
//		{
//			ntx = i + dir[k][0];
//			nty = j + dir[k][1];
//			map[i][j] = '1';
//			if (ntx >= 0 && ntx < n&&nty >= 0 && nty < n&&!used[ntx][nty]&&map[ntx][nty]=='.')
//			{
//				dfs(ntx, nty, num+1);
//				map[i][j] = '.';
//				dfs(ntx, nty, num);
//
//			}
//		}
//		//map[i][j] = '.';
//		//for (int k = 0; k < 4; ++k)
//		//{
//		//	ntx = i + dir[k][0];
//		//	nty = j + dir[k][1];
//		//	if (ntx >= 0 && ntx < n&&nty >= 0 && nty < n&&!used[ntx][nty] && map[ntx][nty] == '.')
//		//	{
//		//		dfs(ntx, nty, num);
//		//	}
//		//}
//	}
//	else
//	{
//		int ntx, nty;
//		for (int k = 0; k < 4; ++k)
//		{
//			ntx = i + dir[k][0];
//			nty = j + dir[k][1];
//			if (ntx >= 0 && ntx < n&&nty >= 0 && nty < n&&!used[ntx][nty] && map[ntx][nty] == '.')
//			{
//				dfs(ntx, nty, num);
//			}
//		}
//	}
//}
void dfs(int i, int j, int num)
{
	if (i >= n)
	{
		if (num > re)
			re = num;
		return;
	}
	else
	{
		int k;
		for (k = j; k < n; ++k)
		{
			if (isConfig(i, k))
			{
				map[i][k] = '1';
				dfs(i, k + 1, num + 1);
				map[i][k] = '.';
				dfs(i, k + 1, num);
			}
		}
		if (k >= n)
			dfs(i + 1, 0, num);
	}
}
int main()
{
	while (cin >> n&&n)
	{
		int wall = 0;
		re = 0;
		/*bemax = false;*/
		memset(map, 0, sizeof(map));
	/*	int stx, sty, flag = 0;*/
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> map[i][j];
				if (map[i][j] == 'X')
					++wall;
				//else if (map[i][j] != 'X'&&!flag)
				//{
				//	stx = i;
				//	sty = j;
				//	flag = 1;
				//}
			}
		}
		if (n == 1)
		{
			cout << 1 - wall << endl;
			continue;
		}
		if (wall == 0)
		{
			cout << n << endl;
		}
		else
		{
			dfs(0, 0, 0);
			cout << re << endl;
		}
	}
}