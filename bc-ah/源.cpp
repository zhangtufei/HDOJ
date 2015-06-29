#include <iostream>
#include <streambuf>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
long long  s[10010];
map<long long, int> ma;
bool Comp(long long a, long long b)
{
	return a < b;
}
int  main()
{
	//streambuf *bk;
	//bk = cin.rdbuf();
	//fstream fin;
	//fin.open("data1.txt");
	//cin.rdbuf(fin.rdbuf());
	int T;
	cin >> T;
	int flag = 1;
	while (T--)
	{
		
		long long n, m, k;
		cin >> n >> m >> k;
		long long temp;
		memset(s, 0, sizeof(s));
		//memset(l, 0, sizeof(l));
		int nums = 0;
		long long mx=0;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			
			if (temp <= m)
			{
				s[nums++] = temp;
			}
			else
			{
				if (temp >= mx)
					mx = temp;
			}
			ma[temp] = 1;
		}
		cout << "Case #" << flag++ << ":" << endl;
		if (mx == 0)
		{
			cout << "why am I so diao?" << endl;
			continue;
		}
		else if (nums == 0)
		{
			cout << "madan!" << endl;
			continue;
		}
		temp = k*(k + 1) / 2;
		sort(s, s + nums,Comp);
		bool suc = false;
		for (int i = nums - 1; i >= 0; --i)
		{
			if (s[i] + temp < mx)
			{
				break;
			}
			long long key = k;
			m = s[i] + key--;
			while (ma[m])
			{
				m += key--;
			}
			if (m >= mx)
			{
				suc = true;
				break;
			}
		}
		if (suc)
			cout << "why am I so diao?" << endl;
		else
			cout << "madan!" << endl;
	}

	//cin.rdbuf(bk);
	return 0;
}
