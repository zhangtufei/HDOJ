#include <iostream>
using namespace std;
int aaa(int a,int b)
{
	int a1, b1;
	if (a < b)
	{
		a1 = b;
		b1 = a;
	}
	else
	{
		a1 = a;
		b1 = b;
	}
	//求最大公约数，结果是b1
	int temp = a1%b1;
	while (temp)
	{
		a1 = b1;
		b1 = temp;
		temp = a1%b1;
	}
	//这里开始手贱给a*b加了一个括号，a*b可能会超出32位的范围
	return a*(b/b1);
}
int main()
{
	int n;
	while (cin >> n)
	{
		int a, b;
		cin >> a;
		for (int i = 1; i < n; ++i)
		{
			cin >> b;
			a = aaa(a, b);
		}
		cout << a << endl;
	}
	return 0;
}