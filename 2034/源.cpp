#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct pp
{
	int i;
	bool flag;
};
int main()
{
	int n, m;
	while (cin >> n >> m&&!(n==0&&m==0))
	{
		pp a[110];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i].i;
			a[i].flag = true;
		}
		int temp;
		int flag = 0;
		for (int i = 0; i < m; ++i)
		{
			cin >> temp;
			for (int j = 0; j < n; ++j)
			{
				if (a[j].i == temp)
				{
					a[j].flag = false;
					++flag;
					break;
				}
			}
		}
		if (flag == n)
		{
			cout << "NULL" << endl;
			continue;
		}
		else
		{
			vector<int> vec;
			for (int i = 0; i < n; ++i)
			{
				if (a[i].flag)
					vec.push_back(a[i].i);
			}
			sort(vec.begin(), vec.end());
			vector<int>::iterator iter = vec.begin();
			for (; iter != vec.end(); ++iter)
			{
				cout << *iter << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}