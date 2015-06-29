#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> vec;
		int temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end());
		cout << (100 - vec[0])*(100 - vec[0]) << endl;
	}
	return 0;
}