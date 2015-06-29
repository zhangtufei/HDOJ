#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Node
{
	char c;
	int x;
	int y;
	int n;
	int w;
	int s;
};
int S, W, E;
int map[14][14];
int calf(Node n)
{
	double d = (n.s + 10) / 100.0;
	switch (n.c)
	{
	case 'S':d = d*(0.5*n.n + 0.5*n.w); break;
	case 'W':d = d*(0.8*n.n + 0.2*n.w); break;
	case 'E':d = d*(0.2*n.n + 0.8*n.w); break;
	}
	return (int)d;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		S = W = E = 0;
		//long a = 1;
		//S = 1;
		//double b = 1.0;
		//(a + S) % (int)b;
		//double x = 1.0;
		//S = x == b;
		//S = W + E = E++;
		memset(map, 0, sizeof(map));
		char c;
		vector<Node> vs, vw, ve;
		while (cin >> c&&c != '0')
		{
			Node temp;
			temp.c = c;
			if (c == 'S')
			{
				++S;
				cin >> temp.x >> temp.y >> temp.n >> temp.w >> temp.s;
				map[temp.x][temp.y]++;
			}
			else if (c == 'W')
			{

			}
			else
			{

			}
		}
	}
}