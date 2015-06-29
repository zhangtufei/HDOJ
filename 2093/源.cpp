#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct man
{
	string name;
	int ac;
	int time;
};
bool Comp(man a, man b)
{
	if (a.ac == b.ac)
	{
		if (a.time == b.time)
			return a.name < b.name;
		return a.time < b.time;
	}
	return a.ac > b.ac;
}
int main()
{
	int n, score;
	cin >> n >> score;
	vector<man> vec;
	string name;
	while (cin >> name)
	{
		man m;
		m.name = name;
		m.ac = 0;
		m.time = 0;
		string temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			if (temp[0] == '-' || temp[0] == '0')
				continue;
			else
			{
				m.ac++;
				string::size_type pos = temp.find("(");
				if (pos == string::npos)
				{
					int len = temp.size() - 1;
					for (int i = len; i >= 0; --i)
					{
						int x = temp[i]-0x30;
						for (int j = 0; j < len-i; ++j)
							x *= 10;
						m.time += x;
					}
				}
				else
				{
					for (int i = pos - 1; i >= 0; --i)
					{
						int x = temp[i] - 0x30;
						for (int j = 0; j < pos - 1 - i; ++j)
							x *= 10;
						m.time += x;
					}
					string::size_type pos1 = temp.find(")");
					for (int i = pos1 - 1; i > pos; --i)
					{
						int x = temp[i] - 0x30;
						for (int j = 0; j < pos1 - 1 - i; ++j)
							x *= 10;
						m.time += x * score;
					}
				}
				
			}
		}
		vec.push_back(m);
	}
	sort(vec.begin(), vec.end(), Comp);
	vector<man>::iterator iter = vec.begin();
	cout << setiosflags(ios::left);
	for (; iter != vec.end(); ++iter)
	{
		cout <<setw(10)<<resetiosflags(ios::right) << iter->name << ' ';
		cout.width(2);
		cout <<setiosflags(ios::right) <<iter->ac << ' ';
		cout.width(4);
		cout <<iter->time << endl;
	}
	system("pause");
	return 0;
}