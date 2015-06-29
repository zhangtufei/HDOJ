#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Comp(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	return a>b;
}
int main()
{
	int n;
	while (cin >> n&&n)
	{
		vector<int> vec;
		int temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end(), Comp);
		vector<int>::iterator iter = vec.begin();
		for (; iter != vec.end(); ++iter)
		{
			if (iter == vec.end() - 1)
				cout << *iter << endl;
			else
				cout << *iter << ' ';
		}
	}
	return 0;
}