#include <iostream>
#include <vector>

using namespace std;
struct rooms
{
	int bugs;
	int brains;
	int m;
	int num;
	int x, y;
}room[110];
int rpoint[100][100];
int max(int *a, int n)
{
	int temp = 0;
	for (int i = 0; i<n; ++i)
		if (a[i]>temp)
			temp = a[i];
	return temp;
}
int capture(int x,int y,int m)
{
	if ( y > rpoint[x][0]||y<=0)
		return 0;
	int p = rpoint[x][y];
	if ((m-=room[p].m)<0)
		return 0;
	int cap = room[p].brains;
	//int *next = new int[rpoint[p+1][0]+rpoint[x][0]];
	vector<int> vec;
	int *next = new int[rpoint[p + 1][0] + rpoint[x][0]];
	for (int i = 0; i < rpoint[p+1][0]; ++i)
	{
		vec.push_back(capture(p+1, i + 1,m);
		for (int i = 0; i + y < rpoint[x][0]; ++i)
			next[rpoint[p + 1][0] + i] = capture(x, i + y + 1, m);
	}
	//next[rpoint[p+1][0]] = capture(x, y -1, m);

	cap += max(next, rpoint[p + 1][0] + rpoint[x][0]-y);
	delete[] next;
	return cap;
}
int main()
{
	int N, M;
	vector<int> vec;
	while (cin >> N >> M&&N != -1 && M != -1)
	{	
		for (int i = 0; i < N; ++i)
		{
			cin >> room[i].bugs >>room[i].brains;
			if (room[i].bugs%20!=0)
				room[i].m = room[i].bugs / 20 + 1;
			else
				room[i].m = room[i].bugs / 20;

		}
		int room1,room2;
		for (int i = 1; i < 100; ++i)
			rpoint[i][0] = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			cin >> room1 >> room2;
			rpoint[room1][0] += 1;
			rpoint[room1][rpoint[room1][0]]=room2-1;
		}
		rpoint[0][0] = 1;
		rpoint[0][1] = 0;
		int max = capture(0, 1, M);
		vec.push_back(max);
	}
	vector<int>::iterator iter = vec.begin();
	for (; iter != vec.end(); ++iter)
		cout << *iter << endl;
	system("pause");
	return 0;
}