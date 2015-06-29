//这一题的题目绝逼有问题
#include <iostream>
using namespace std;
int main()
{
	long long h[60];
	h[0] = 1;
	long long s = 1;
	for (int i =1; i <= 55; ++i)
	{
		h[i] = s;
		if (i >= 4)
		{
			s += h[i - 2];
		}
	}
	int n;
	while (cin >> n&&n)
	{
		long long sum=0;
		for (int i = 1; i <= n; ++i)
			sum += h[i];
		cout << sum << endl;
	}
	return 0;
}