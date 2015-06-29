#include <iostream>
#include <map>
using namespace std;
long long a[110];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		map<long long, long long> m;
		long long temp;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				temp = a[i] + a[j];
				m[temp]++;
			}
		}
		map<long long, long long>::iterator iter = m.begin();
		long long sum = 0;
		for (; iter != m.end(); ++iter)
		{
			sum += iter->first;
		}
		cout << sum << endl;
	}
	return 0;
}