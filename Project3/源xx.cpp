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
bool CompA(struct leaf la,struct leaf lb)
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