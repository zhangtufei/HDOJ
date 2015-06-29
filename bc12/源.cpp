#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <limits>
#include <iosfwd>
using namespace std;
void swap(int *p1, int *p2)
{
	int *p = p1;
	p1 = p2;
	p2 = p;
}
int main()
{
	int a, b;
	int *p1=&a, *p2=&b;
	while (cin >> a >> b)
	{
		if (a < b)
			swap(p1, p2);
		cout << *p1 << *p2 << endl;
	}
}
//bc12-2 5059
//int main()
//{
//	string s;
//	while (getline(cin,s))
//	{
//		long long a, b;
//		cin >> a >> b;
//		getchar();//把getchar()放在这里就好了！！！！！！！！！！！！！！！！FUCK！！！！！！！！！
//		if (s.size() > 11)
//		{
//			cout << "NO" << endl;
//			continue;
//		}
//		string t = "0";
//		if (s==t)
//		{
//			cout << "YES" << endl;
//			continue;
//		}
//		if ((s[0] == '-' && ('1' <= s[1] && s[1] <= '9')) || ('1' <= s[0] && s[0] <= '9'))
//		{
//			bool flag = true;
//			for (int i = 1; i < s.size(); ++i)
//			{
//				if (!('0' <= s[i] && s[i] <= '9'))
//				{
//					flag = false;
//					break;
//				}
//			}
//			if (flag)
//			{
//				long long si = 0, temp = 1;
//				for (int i = s.size() - 1; i >= 1; --i)
//				{
//					si += (s[i] - 0x30)*temp;
//					temp *= 10;
//				}
//				if (s[0] == '-')
//					si *= -1;
//				else
//					si += (s[0] - 0x30)*temp;
//				if (si >= a&&si <= b)
//					cout << "YES" << endl;
//				else
//					cout << "NO" << endl;
//			}
//			else
//			{
//				cout << "NO" << endl;
//			}
//		}
//		else if (!((s[0] == '-' && ('1' <= s[1] && s[1] <= '9')) || ('1' <= s[0] && s[0] <= '9')))
//			cout << "NO" << endl;
//	}
//	return 0;
//}
//bc12-1 5058
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		map<long long, int> m;
//		long long temp;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> temp;
//			m[temp] = 1;
//		}
//		bool flag = true;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> temp;
//			if (flag)
//			{
//				++m[temp];
//				if (m[temp] == 1)
//					flag = false;
//			}
//		}
//		if (flag)
//		{
//			map<long long, int>::iterator iter = m.begin();
//			for (; iter != m.end(); ++iter)
//			{
//				if (iter->second <= 1)
//				{
//					flag = false;
//					break;
//				}
//			}
//		}
//		if (flag)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}