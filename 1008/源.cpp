#include <iostream>
#include <vector>
using namespace std;

int time1(int num)
{
	return num * 6 + 5;
}
int time2(int num)
{
	return num * 4 + 5;
}
int main()
{
	int num;
	vector<int> vec;
	vector<int> re;
	while (cin >> num&&num != 0)
	{
		int lastFloor = 0;
		int temp;
		int time = 0;
		for (int i = 0; i < num; ++i)
		{
			cin >> temp;
			vec.push_back(temp);
		}
		vector<int>::iterator iter = vec.begin();
		for (; iter != vec.end(); ++iter)
		{
			int floors = *iter - lastFloor;
			if (floors > 0)
				time += time1(floors);
			else
				time += time2(-floors);
			lastFloor = *iter;
		}
		re.push_back(time);
		vec.clear();
	}
	vector<int>::iterator iter = re.begin();
	for (; iter != re.end(); ++iter)
		cout << *iter << endl;
	system("pause");
	return 0;
}