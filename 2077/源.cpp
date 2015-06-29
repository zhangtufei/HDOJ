#include <iostream>
using namespace std;
//int sum = 0;
//for (int i = 1; i <= 9; ++i)
//{
//	sum = sum * 3 + 2;
//}
//cout << sum + 2 << endl;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		long long sum=0;
		for (int i = 1; i <= n - 1; ++i)
			sum = sum * 3 + 2;
		cout << sum + 2 << endl;
	}
	system("pause");
	return 0;
}