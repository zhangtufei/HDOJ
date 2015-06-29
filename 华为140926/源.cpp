#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct leaf
{
	int num;
	int ang;
};
bool CompA(struct leaf la, struct leaf lb)
{
	return la.ang < lb.ang;
}
int main()
{
	string s, s1 = "init:", s2 = "leaf:", s3 = "end";
	leaf le[1000];
	char c;
	int h, v;
	int flag = 0;
	while (cin >> c)
	{
		s += c;
		if (s == s1)
		{
			s = "";
			cin >> h >> c >> v;
			continue;
		}
		else if (s == s2)
		{
			s = "";
			cin >> le[flag].num >> c >> le[flag].ang;
			if (le[flag].ang > 90)
				le[flag].ang -= 90;
			else
				le[flag].ang = 90 - le[flag].ang;
			++flag;
			continue;
		}
		else if (s == s3)
		{
			break;
		}
	}
	if (!h)
	{
		//sort(le, le + flag,CompN);
		for (int i = 0; i < flag - 1; ++i)
			cout << le[i].num << ',';
		cout << le[flag - 1].num << endl;
	}
	else
	{
		sort(le, le + flag, CompA);
		for (int i = 0; i < flag - 1; ++i)
			cout << le[i].num << ',';
		cout << le[flag - 1].num << endl;
	}
	system("pause");
	return 0;
}
//int main()
//{
//	int n;
//	cin >> n;
//	int a[110];
//	int flag = 0;
//	for (int i = 2; i <= n; ++i)
//	{
//		int sum = 1;
//		int sq = sqrt((double)i);
//		int j = 2;
//		for (; j <sq; ++j)
//		{
//			if (i%j == 0)
//			{
//				sum = sum + j + i / j;
//			}
//		}
//		if (j*j == i)
//		{
//			sum += j;
//		}
//		else if (i%j==0)
//			sum = sum + j + i / j;
//		if (sum == i)
//			a[flag++] = i;
//	}
//	for (int i = 0; i < flag-1; ++i)
//	{
//		cout << a[i] << ' ';
//	}
//	cout << a[flag - 1] << endl;
//	system("pause");
//	return 0;
//}