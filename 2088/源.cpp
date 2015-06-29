#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	bool first = true;
	while (cin >> n&&n)
	{
		if (!first)
			cout << endl;
		first = false;
		vector<int> vec;
		int height=0;
		int sum=0;
		int temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			height += temp;
			vec.push_back(temp);
		}
		height /= n;
		vector<int>::iterator iter = vec.begin();
		for (; iter != vec.end(); ++iter)
		{
			if (*iter <= height)
				continue;
			sum += *iter - height;
		}
		cout << sum << endl;
	}
	return 0;
}