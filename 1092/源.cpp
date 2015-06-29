#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n)
	{
		long long temp, sum=0;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			sum += temp;
		}
		cout << sum << endl;
	}
	return 0;
}