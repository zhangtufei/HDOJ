#include <iostream>
using namespace std;
//´íÅÅ¹«Ê½£¬fn=(n-1)*(f(n-1)+f(n-2)),f0=0,f1=0,f2=1
long long C(int n,int i)
{
	long long sum = 1;
	for (int j = 0; j < i; ++j)
		sum =sum* (n - j) / (j + 1);
	return sum;
}
int main()
{
	int wr[13];
	wr[0] = 0; wr[1] = 0; wr[2] = 1;
	for (int i = 3; i <= 12; ++i)
	{
		wr[i] = (i - 1)*(wr[i - 1] + wr[i - 2]);
	}
	int n;
	while (cin >> n&&n)
	{
		long long sum = 1;
		int wm = n / 2;
		for (int i = 2; i <= wm; ++i)
			sum += C(n, i)*wr[i];
		cout << sum << endl;
	}
	return 0;
}