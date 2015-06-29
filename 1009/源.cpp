#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Rooms
{
	int J;
	int F;
};
bool compRoom(Rooms a, Rooms b)
{
	return (double)a.J / (double)a.F > (double)b.J / (double)b.F;
}
int main()
{
	int M, N;
	Rooms rooms[1000];
	vector<double> re;
	while (cin >> M >> N&&M != -1 && N != -1)
	{
		double ob=0.0;
		for (int i = 0; i < N; ++i)
			cin >> rooms[i].J >> rooms[i].F;
		sort(rooms, rooms + N, compRoom);
		for (int i = 0; i < N; ++i)
		{
			if (M <= rooms[i].F)
			{
				ob += rooms[i].J*M / (double)rooms[i].F;
				break;
			}
			ob += rooms[i].J;
			M -= rooms[i].F;
		}
		re.push_back(ob);
	}
	vector<double>::iterator iter = re.begin();
	cout.precision(3);
	for (; iter != re.end(); ++iter)
		cout << fixed << *iter << endl;
	system("pause");
	return 0;
}