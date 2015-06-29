#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int m;
		cin >> m;
		long long sum = 0;
		int temp;
		for (int i = 0; i < m; ++i)
		{
			cin >> temp;
			sum += temp;
		}
		cout << sum << endl;
		if (T)
			cout << endl;
	}
	return 0;
}