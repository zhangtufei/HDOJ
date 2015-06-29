#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool Comp(int a, int b)
{
	return a > b;
}
int xxx(int num, int i)
{
	for (int j = 0; j < i; ++j)
	{
		num *= 10;
	}
	return num;
}
int main()
{
	string s;
	vector<int> vec1, vec2;
	getline(cin, s);
	int x = 0,flag=0;
	//bool isNum ;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		//isNum = false;
		if (s[i] != ' ')
		{
			x += xxx(s[i] - 0x30, flag);
			++flag;
			//isNum = true;
		}
		if (s[i]==' '||i==0)
		{
		/*	if (x == 0 && !isNum)
			{
				x = 0;
				flag = 0;
				continue;
			}*/
			if (x % 2 == 0)
				vec2.push_back(x);
			else
				vec1.push_back(x);
			x = 0;
			flag = 0;
		}
	}
	sort(vec1.begin(), vec1.end(),Comp);
	sort(vec2.begin(), vec2.end());
	vector<int>::iterator iter1 = vec1.begin();
	vector<int>::iterator iter2 = vec2.begin();
	for (; iter1 != vec1.end(); ++iter1)
	{
		if (vec2.size())
		{
			cout << *iter1 << ' ';
		}
		else
		{
			if (iter1 == vec1.end() - 1)
			{
				cout << *iter1 << endl;
			}
			else
				cout << *iter1 << ' ';
		}
	}
	for (; iter2 != vec2.end(); ++iter2)
	{
		if (iter2 == vec2.end() - 1)
		{
			cout << *iter2 << endl;
		}
		else
			cout << *iter2 << ' ';
	}
	system("pause");
	return 0;
}