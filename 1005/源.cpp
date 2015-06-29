#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int f[50];
	vector<int>::iterator iter;
	f[0] = 1;
	f[1] = 1;
	vector<int> vec;
	int a, b,i;
	long long n;
	int T;
	while (cin >> a >> b >> n)
	{
		if (n == 0)
		{
			break;
		}
		T = 0;
		int flag = 0;
		for (int i = 2; i < 50; ++i)
		{
			f[i] = (a*f[i - 1] + b*f[i - 2]) % 7;
			if (f[i] == 1 && f[i - 1] == 1&&flag==0)
			{
				T = i - 1;
				flag = 1;
			}
		}
		if (a%7 == 0 || b%7 == 0)
		{
			if (n <=2||(a+b)%7==1)
			{
				vec.push_back(1);
				continue;
			}
			if ((a + b)%7 == 0)
			{
				vec.push_back(0);
				continue;
			}
			else
			{
				if ((n - 1) % 12 == 0)
					vec.push_back(f[12]);
				else
					vec.push_back(f[(n - 1) % 12]);
			}
		}
		else
		{
			if (T == 0)
				vec.push_back(n - 1);
			else if (n%T == 0)
				vec.push_back(f[T - 1]);
			else
				vec.push_back(f[n%T - 1]);
		}

	}
	iter = vec.begin();
	for (; iter != vec.end(); ++iter)
		cout << *iter << endl;
	system("pause");
	return 0;
}