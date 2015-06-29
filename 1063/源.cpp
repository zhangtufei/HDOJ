//叔这算是绞尽脑汁了，一次AC思密达哈哈
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string addstring(string s1,string s2)
{
	if (s1.size() > s2.size())
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}
	int flag = s2.size() - 1,up=0;
	for (int i = s1.size() - 1; i >= 0; --i,--flag)
	{
		int temp = s2[flag] - 0x30 + s1[i] - 0x30 + up;
		s2[flag] = temp % 10 + 0x30;
		up = temp / 10;
	}
	while (up)
	{
		if (flag < 0)
		{
			char c = up + 0x30;
			s2 = c + s2;
			break;
		}
		else
		{
			int temp = s2[flag] - 0x30 + up;
			s2[flag] = temp % 10 + 0x30;
			up = temp / 10;
			--flag;
		}
	}
	return s2;
}
string multistring(string s2,string si)
{
	string st = si;
	vector<string> vec;
	for (int i = st.size() - 1; i >= 0; --i)
	{
		string st1 = s2;
		//这里注释掉应对整数部分为0的情况
		//if (st[i] == '0')
		//	continue;
		int up = 0;
		for (int j = st1.size() - 1; j >= 0; --j)
		{
			int temp = (st1[j] - 0x30)*(st[i] - 0x30) + up;
			st1[j] = temp % 10 + 0x30;
			up = temp / 10;
		}
		if (up)
		{
			char c = up + 0x30;
			st1 = c + st1;
		}
		for (int j = st.size() - 1 - i; j > 0; --j)
			st1 += '0';
		vec.push_back(st1);
	}
	string s = vec[0];
	for (int i = 1; i < vec.size(); ++i)
	{
		s = addstring(s, vec[i]);
	}
	return s;
}
int main()
{
	string s;
	int num;
	while (cin >> s >> num)
	{
		int i = 0,pt=0;
		string st;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '.')
			{
				pt = s.size() - 1 - i;
			}
			else
				st += s[i];
		}
		s = st;
		if (num == 0)//0次方，这里可以不做考虑，题目中给出0<n<=25
		{
			bool flag = false;
			//是否全0
			for (int i = 0; i < s.size(); ++i)
			{
				if (s[i] != '0')
				{
					flag = true;
					break;
				}
			}
			if (flag)//如果输入不为全0则输出1
				cout << '1' << endl;
			else
				cout << '0' << endl;
			continue;
		}
		pt*=num;
		for (int i = 1; i < num; ++i)
		{
			s = multistring(s, st);
		}
		if (pt == 0)//输入无小数点
		{
			int k = 0;
			while (s[k] == '0')//去掉开始的0
				++k;
			for (int i = k; i < s.size(); ++i)
				cout << s[i];
		}
		else
		{
			pt = s.size() - pt;
			if (s[0] == '0'&&pt==1)//如果第二位为小数点且第一位为0，按题目要求去掉该0，如输入0.4321
			{
				//暂时不输出，考虑到输入为XX.0
				//cout << '.';
			}
			else
			{
				int k = 0;
				while (s[k] == '0')//去掉开始的0，如输入01.4321及00.4321
					++k;
				for (int i = k; i < pt; ++i)
					cout << s[i];
				//暂时不输出，考虑到输入为XX.0
				//cout << '.';
			}
			int k = s.size() - 1;
			while (s[k] == '0')//去掉尾0
			{
				--k;
			}
			if (k >= pt)//如果输入为XX.0，则K<pt，不用输出小数点，否则输出
				cout << '.';
			for (int i = pt; i <= k; ++i)
			{
				cout << s[i];
			}
		}
		cout << endl;
	}
	return 0;
}