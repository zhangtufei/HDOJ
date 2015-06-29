#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int MAX=110;
class node
{
public:
	int x;
	int y;
	int x_n;
	int y_n;
	int time;
	friend bool operator<(node a, node b){ return a.time>b.time; }
};
node path[MAX][MAX];
char map[MAX][MAX];
int used[MAX][MAX],N,M;
priority_queue<node> q;
node d;
stack<node> s;
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
int bfs()
{
	node temp, pre;
	while (!q.empty())
	{
		pre = q.top();
		if (pre.x == N - 1 && pre.y == M - 1)
		{
			d.x = pre.x;
			d.y = pre.y;
			d.x_n = 0;
			d.y_n = 0;
			return pre.time;
		}
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			temp.x = pre.x + dir[i][0];
			temp.y = pre.y + dir[i][1];
			if (temp.x >= 0 && temp.x < N&&temp.y >= 0 && temp.y < M&&!used[temp.x][temp.y] && map[temp.x][temp.y] != 'X')
			{
				if (map[temp.x][temp.y] == '.')
				{
					temp.time = pre.time + 1;
				}
				else if (map[temp.x][temp.y] >= '0'&&map[temp.x][temp.y] <= '9')
				{
					temp.time = pre.time + (map[temp.x][temp.y] - 0x30)+1;
				}
				used[temp.x][temp.y] = true;
				q.push(temp);
				pre.x_n = temp.x;
				pre.y_n = temp.y;
				path[temp.x][temp.y] = pre;
			}
		}
	}
	return 0;
}
int main()
{
	while (cin >> N >> M)
	{
		int wall = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> map[i][j];
				if (map[i][j] == 'X')
					++wall;
			}
		}
		if (N*M - wall < N + M - 1)
		{
			cout << "God please help our poor hero." << endl;
		}
		else
		{
			memset(used, 0, sizeof(used));
			while (!q.empty())
				q.pop();
			node st;
			st.x = st.y = st.time = 0;
			used[0][0] = 1;
			q.push(st);
			int flag = bfs();
			if (flag)
			{
				cout << "It takes " <<flag
					<<" seconds to reach the target position, let me show you the way." << endl;
				s.push(d);
				node temp = path[d.x][d.y];
				while (temp.x || temp.y)
				{
					s.push(temp);
					temp = path[temp.x][temp.y];
				}
				s.push(temp);
				int num = 1;
				while (!s.empty())
				{
					temp = s.top();
					s.pop();
					if (map[temp.x][temp.y]=='.'&&!(temp.x_n==0&&temp.y_n==0))
						cout << num++ << "s:(" <<temp.x << ','
							<< temp.y<< ")->(" << temp.x_n << ',' << temp.y_n << ")" << endl;
					else if (map[temp.x][temp.y] >= '0'&&map[temp.x][temp.y] <= '9')
					{
						int t = map[temp.x][temp.y] - 0x30;
						while (t--)
						{
							cout << num++ << "s:FIGHT AT (" << temp.x << ',' << temp.y << ")" << endl;
						}
						if (!(temp.x_n == 0 && temp.y_n == 0))
						{
							cout << num++ << "s:(" << temp.x << ','
								<< temp.y << ")->(" << temp.x_n << ',' << temp.y_n << ")" << endl;
						}
					}
				}
			}
			else
			{
				cout << "God please help our poor hero." << endl;
			}
		}
		cout << "FINISH" << endl;
	}
	return 0;
}