////WA!!!!!!!!!!我哭了！！！！！我哭给你看！！！！！！！！！！
//#include <iostream>
//#include <vector>
//using namespace std;
//struct tPoint
//{
//	char character;
//	int i;
//	int j;
//}p[110][110];
//struct tmx
//{
//	int i;
//	int j;
//};
//tmx a[100000];
//int N, M, dp[110][110],lstime,mintime;
//bool success;
//bool findway(int i, int j)
//{
//	if (i < 0 || i >= N || j < 0 || j >= M)
//		return false;
//	if (dp[i][j] + N - 1 - i + M - 1 - j > mintime)
//	{
//		return false;
//	}
//	if (i == N - 1 && j == M - 1)
//	{
//		if (!success)
//		{
//			success = true;
//			if (p[i][j].character >= '0'&&p[i][j].character <= '9')
//				lstime = (p[i][j].character - 0x30);
//			mintime = dp[N - 1][M - 1];
//			a[mintime].i = i;
//			a[mintime].j = j;
//			return true;
//		}
//		else
//		{
//			if (dp[N - 1][M - 1] < mintime)
//			{
//				mintime = dp[N - 1][M - 1];
//				a[mintime].i = i;
//				a[mintime].j = j;
//				return true;
//			}
//			else
//				return false;
//		}
//	}
//	//if (success)
//	//	return false;
//	int temp=dp[i][j]+1;
//	if (p[i][j].character >= '0'&&p[i][j].character <= '9')
//		temp += (p[i][j].character - 0x30);
//	bool flag = false;
//	if (j<M-1&&p[i][j + 1].character != 'X')
//	{
//		if (!dp[i][j + 1] || temp<= dp[i][j + 1])
//		{
//			dp[i][j + 1] = temp;
//			if (findway(i, j + 1))
//			{
//				flag = true;
//				a[dp[i][j]].i = i;
//				a[dp[i][j]].j = j;
//			}
//		}
//	}
//	if (i<N-1&&p[i + 1][j].character != 'X')
//	{
//		if (!dp[i+1][j] || temp<dp[i+1][j])
//		{
//			dp[i + 1][j] = temp;
//			if (findway(i+1, j))
//			{
//				flag = true;
//				a[dp[i][j]].i = i;
//				a[dp[i][j]].j = j;
//			}
//		}
//	}
//	if (j>0&&p[i][j - 1].character != 'X')
//	{
//		if ((!dp[i][j - 1]&&!(i==0&&j==1)) || temp < dp[i][j - 1])
//		{
//			dp[i][j - 1] = temp;
//			if (findway(i, j - 1))
//			{
//				flag = true;
//				a[dp[i][j]].i = i;
//				a[dp[i][j]].j = j;
//			}
//		}
//	}
//	if (i>0&&p[i - 1][j].character != 'X')
//	{
//		if ((!dp[i - 1][j]&&!(i==1&&j==0)) || temp < dp[i - 1][j])
//		{
//			dp[i - 1][j] = temp;
//			if (findway(i - 1, j))
//			{
//				flag = true;
//				a[dp[i][j]].i = i;
//				a[dp[i][j]].j = j;
//			}
//		}
//	}
//	if (flag)
//		return true;
//	return false;
//}
//int main()
//{
//	while (cin >> N >> M)
//	{
//		lstime = 0;
//		mintime =INT_MAX;
//		int wall = 0;
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < M; ++j)
//			{
//				cin >> p[i][j].character;
//				p[i][j].i = i;
//				p[i][j].j = j;
//				if (p[i][j].character == 'X')
//				{
//					++wall;
//				}
//				else
//				{
//					dp[i][j] = 0;
//				}
//			}
//		}
//		success =false;
//		a[0].i = 1;
//		a[1].j = 2;
//		if (N*M-wall<N + M - 1)
//		{
//			cout << "God please help our poor hero." << endl;
//		}
//		else
//		{
//			memset(dp, 0, sizeof(dp));
//			memset(a, 0, sizeof(a));
//			//p[0][0].character = 'X';
//			if (findway(0, 0))
//			{
//				cout << "It takes " << mintime+lstime
//					 << " seconds to reach the target position, let me show you the way." << endl;
//				for (int i = 1; i <= mintime; ++i)
//				{
//					int x = a[i].i, y = a[i].j;
//					if (x == 0 && y == 0)
//					{
//						
//						x=a[i].i= a[i - 1].i;
//						y=a[i].j= a[i - 1].j;
//						cout <<i<< "s:FIGHT AT (" <<x<< ',' << y<< ")" << endl;
//					}
//					else
//					{
//						cout << i << "s:(" << a[i - 1].i << ','
//							<< a[i - 1].j << ")->(" << x << ',' << y << ")" << endl;
//					}
//				}
//				if (lstime)
//				{
//					for (int i = 1; i <= lstime; ++i)
//					{
//						cout << mintime + i << "s:FIGHT AT (" << N - 1 << ',' << M - 1 << ")" << endl;
//					}
//				}
//				//vector<tPoint>::iterator iter = vec.end() - 1;
//				//for (; iter != vec.begin(); --iter)
//				//{
//				//	if (p[iter->i][iter->j].character >= '0'&&p[iter->i][iter->j].character <= '9')
//				//	{
//				//		int temp = p[iter->i][iter->j].character - 0x30;
//				//		for (int i = 1; i <= temp; ++i)
//				//		{
//				//			cout << dp[iter->i][iter->j] + i << "s:FIGHT AT (" << iter->i << ',' << iter->j << ")" << endl;
//				//		}
//				//	}
//				//	cout << dp[(iter - 1)->i][(iter - 1)->j] << "s:(" << iter->i << ',' << iter->j << ")->(" << (iter - 1)->i << ',' << (iter - 1)->j << ")" << endl;
//				//}
//				//if (lstime)
//				//{
//				//	for (int i = 1; i <= lstime; ++i)
//				//	{
//				//		cout << dp[N - 1][M - 1] + i << "s:FIGHT AT (" <<N-1<< ',' << M-1<< ")" << endl;
//				//	}
//				//}
//			}
//			else
//			{
//				cout << "God please help our poor hero." << endl;
//			}
//
//		}
//		cout << "FINISH" << endl;
//	}
//	return 0;
//}
//BFS:宽度优先搜索
#include <iostream>  

using namespace std;

#define MAX 101  

#include <queue>  
#include <stack>  

typedef struct _node
{
	int x;
	int y;
	int x_next;
	int y_next;
	int seconds;
	friend bool operator<(_node a, _node b){ return a.seconds > b.seconds; }
}node;

node path[MAX][MAX];

char map[MAX][MAX];

bool used[MAX][MAX];

int n, m;

priority_queue<node > q;
node end1;
stack<node > S;

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

int bfs()
{
	int i;
	node tmp, no_pre;
	while (!q.empty()){
		no_pre = q.top();
		if (no_pre.x == n - 1 && no_pre.y == m - 1){
			end1.x = no_pre.x;
			end1.y = no_pre.y;
			end1.x_next = 0;
			end1.y_next = 0;
			return no_pre.seconds;
		}
		q.pop();
		for (i = 0; i < 4; i++){
			tmp.x = no_pre.x + dir[i][0];
			tmp.y = no_pre.y + dir[i][1];
			if (tmp.x >= 0 && tmp.x < n && tmp.y >= 0 && tmp.y < m &&!used[tmp.x][tmp.y] && map[tmp.x][tmp.y] != 'X'){
				if (map[tmp.x][tmp.y] == '.'){
					tmp.seconds = no_pre.seconds + 1;
				}
				else if (map[tmp.x][tmp.y] >= '0' && map[tmp.x][tmp.y] <= '9'){
					tmp.seconds = no_pre.seconds + 1 + (int)(map[tmp.x][tmp.y] - '0');
				}
				used[tmp.x][tmp.y] = true;
				q.push(tmp);
				no_pre.x_next = tmp.x;
				no_pre.y_next = tmp.y;
				path[tmp.x][tmp.y] = no_pre;
			}//if  
		}//for  
	}//while  
	return -1;
}

int main()
{
	//  freopen("input.txt", "r", stdin);  
	int i, j;
	while (scanf("%d%d", &n, &m) != EOF){
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				scanf(" %c", &map[i][j]);
			}
		}
		memset(used, false, sizeof(used));
		while (!q.empty())q.pop();
		node no_start;
		no_start.x = no_start.y = no_start.seconds = 0;
		used[0][0] = true;
		q.push(no_start);
		int flag = bfs();
		if (flag == -1)printf("God please help our poor hero.\n");
		else {
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", flag);
			S.push(end1);
			node temp = path[end1.x][end1.y];
			while (temp.x || temp.y){
				S.push(temp);
				temp = path[temp.x][temp.y];
			}
			S.push(temp);
			int num = 1;
			while (!S.empty()){
				temp = S.top();
				S.pop();
				if (map[temp.x][temp.y] == '.' && !(temp.x_next == 0 && temp.y_next == 0)){
					printf("%ds:(%d,%d)->(%d,%d)\n", num++, temp.x, temp.y, temp.x_next, temp.y_next);
				}
				else if (map[temp.x][temp.y] >= '0' && map[temp.x][temp.y] <= '9'){
					int t = map[temp.x][temp.y] - '0';
					while (t--){
						printf("%ds:FIGHT AT (%d,%d)\n", num++, temp.x, temp.y);
					}
					if (!(temp.x_next == 0 && temp.y_next == 0)){
						printf("%ds:(%d,%d)->(%d,%d)\n", num++, temp.x, temp.y, temp.x_next, temp.y_next);
					}
				}
			}
		}
		printf("FINISH\n");
	}
	return 0;
}