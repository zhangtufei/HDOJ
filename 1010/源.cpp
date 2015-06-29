#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
struct tPoint
{
	char character;
	int i;
	int j;
};
int N, M, T,num;
bool success;
int stx, sty, endx, endy;
tPoint point[10][10];
void findway(int i,int j,int num)
{
	if (i < 0 || i >= N || j < 0 || j >= M)
	{
		return;
	}
	if (point[i][j].i == endx&&point[i][j].j==endy&&num == T)
	{
		success = true;
	}
	if (success)
		return;
	int temp = (T - num) - abs(endx - i) - abs(endy - j);
	if (temp < 0||temp&1)//ÆæÅ¼¼ôÖ¦£¿£¿
		return;
	if (point[i][j + 1].character != 'X')
	{
		point[i][j+1].character = 'X';
		findway(i, j + 1, num + 1);
		point[i][j+1].character = '.';
	}
	if (point[i + 1][j].character != 'X')
	{
		point[i+1][j].character = 'X';
		findway(i + 1, j, num + 1);
		point[i+1][j].character = '.';
	}
	if (point[i][j - 1].character != 'X')
	{
		point[i][j-1].character = 'X';
		findway(i, j - 1, num + 1);
		point[i][j-1].character = '.';
	}
	if (point[i -1][j].character != 'X')
	{
		point[i-1][j].character = 'X';
		findway( i - 1, j,num+1);
		point[i-1][j].character = '.';
	}
	return;
}
int main()
{
	string re;
	vector<string> vec;
	int wall;
	while (cin >> N >> M >> T&&N > 0 && M > 0 && T != 0)
	{
		num = 0;
		wall = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				cin >> point[i][j].character;
				point[i][j].i = i;
				point[i][j].j = j;
				if (point[i][j].character == 'S')
				{
					stx = i;
					sty = j;
				}
				else if (point[i][j].character == 'D')
				{
					endx = i;
					endy = j;
				}
				else if (point[i][j].character == 'X')
					++wall;
			}
		success = false;
		point[stx][sty].character = 'X';
		if (N*M - wall <= T)
			re = "NO";
		else
		{
			findway(stx, sty, num);
			if (success)
				re = "YES";
			else
				re = "NO";
		}
		vec.push_back(re);
	}
	vector<string>::iterator iter = vec.begin();
	for (; iter != vec.end(); ++iter)
		cout << *iter << endl;
	system("pause");
	return 0;
}