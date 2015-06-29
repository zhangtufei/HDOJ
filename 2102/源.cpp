#include <iostream>
#include <string>
#include <streambuf>
#include <fstream>
using namespace std;
char map[2][20][20];
int N, M, T;
int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int dp[2][20][20];
bool suc;
void dfs(int z, int x, int y,int step)
{
	if (step > T||map[z][x][y]=='*'||suc)
		return;
	if (map[z][x][y] == 'P')
	{
		suc = true;
		return;
	}
	if (map[z][x][y] == '#')
	{
		int nz = !z;
		if (map[nz][x][y] == '#' || map[nz][x][y] == '*')
		{
			map[z][x][y] = '*';
			map[nz][x][y] = '*';
			return;
		}
		if (!dp[nz][x][y])
		{
			dp[nz][x][y] = 1;
			dfs(nz, x, y, step);
			dp[nz][x][y] = 0;
		}
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			int nx, ny;
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (map[z][nx][ny] == '*')
				continue;
			if (nx>=0 && nx < N&&ny >=0 && ny < M&&!dp[z][nx][ny])
			{
				dp[z][nx][ny] = 1;
				dfs(z, nx, ny, step + 1);
				dp[z][nx][ny] = 0;
				if (suc)
					return;
			}
		}
	}
	return;
}
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("data.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int c;
	cin >> c;
	while (c--)
	{
		cin >> N >> M >> T;
		int sz, sx, sy;
		for (int z = 0; z <= 1; ++z)
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j <M; ++j)
				{
					cin >> map[z][i][j];
					if (map[z][i][j] == 'S')
					{
						sz = z;
						sx = i;
						sy = j;
					}
				}
			}
		}
		suc = false;
		memset(dp, 0, sizeof(dp));
		dp[sz][sx][sy] = 1;
		dfs(sz, sx, sy, 0);
		if (suc)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	//cin.rdbuf(bk);
	return 0;
}