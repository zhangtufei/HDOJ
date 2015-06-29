#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int n1;
		cin >> n1;
		long long temp, sum = 0;
		for (int i = 0; i < n1; ++i)
		{
			cin >> temp;
			sum += temp;
		}
		cout << sum << endl;
	}
	return 0;
}