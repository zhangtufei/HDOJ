#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
bool Comp(long long x,long long y)
{
	return x > y;
}
int main()
{
	long long n, m;
	while (cin >> n >> m&&n&&m)
	{
		vector<long long> vec;
		long long i =1;
		//int flag = 0;
		//if (m % 2 == 0)
		//{

		//}
		//有问题，解决没法
		long long temp = m;
		if (m % 2 == 0&&m>=2)
		{
			int flag = 2;
			while ((temp / flag) % 2 == 0)
			{
				flag *= 2;
			}
			vec.push_back(flag);
		}
		else 
			vec.push_back(2);
		while (i*i<=m)
		{
			if (i % 2 == 0)
			{
				++i;
				continue;
			}
			if (m%i == 0)
				vec.push_back(i);
			++i;
		}
		sort(vec.begin(), vec.end(), Comp);
		vector<long long>::iterator iter = vec.begin();
		for (; iter != vec.end(); ++iter)
		{
			if (*iter % 2 == 0)
			{
				if ((m / (*iter) - (*iter - 1) / 2) > 0)
					cout << '[' << (m / (*iter) - (*iter - 1) / 2) << ',' << (m / (*iter) + (*iter) / 2) << ']' << endl;
					//temp = temp + '[' + (char)((m / (*iter) - (*iter - 1) / 2) + 0x30) + ',' + (char)(m / (*iter) + (*iter) / 2 + 0x30) + ']';
				else
					cout << '[' << 1 << ',' << (m / (*iter) + (*iter) / 2) << ']' << endl;
			}
			else
				if ((m / (*iter) - (*iter - 1) / 2) > 0)
					//temp = temp + '[' + (char)(m / (*iter) - (*iter - 1) / 2 + 0x30) + ',' + (char)(m / (*iter) + (*iter - 1) / 2 + 0x30) + ']';
					cout << '[' << (m / (*iter) - (*iter - 1) / 2) << ',' << (m / (*iter) + (*iter - 1) / 2) << ']' << endl;
		}
		cout << endl;
	}
	return 0;
}