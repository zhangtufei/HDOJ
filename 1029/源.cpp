#include <iostream>
#include <map>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int times = (n + 1) / 2;
		map<int, int> m;
		int temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			++m[temp];
			if (m[temp] >= times)
			{
				int t;
				for (int j = i + 1; j < n; ++j)
				{
					cin >> t;
				}
				break;
			}
		}
		cout << temp << endl;
	}
	return 0;
}