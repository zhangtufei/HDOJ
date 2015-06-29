#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int num = 0, re[256];
	for (int i = a; i <= b; ++i)
	{
		bool flag = true;
		for (int j = 2; j*j <= i; ++j)
		{
			if (i%j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			re[num++] = i;
		}
	}
	if (num == 0)
		cout << num << endl;
	else
	{
		cout << num << ',';
		for (int i = 0; i < num; ++i)
		{
			if (i == num - 1)
				cout << re[i] << endl;
			else
				cout << re[i] << ',';
		}	
	}
	system("pause");
	return 0;
}