#include <iostream>
using namespace std;
//int sum = 2;
//for (int i = 2; i <= 12; ++i)
//{
//	sum = sum * 3 + 2;
//	cout << sum << endl;
//}
int main()
{
	int n;
	while (cin>>n)
	{
		long long sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			sum = sum * 3 + 2;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}