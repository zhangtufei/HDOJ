#include <iostream>
#include <string>
using namespace std;
string s;
char vow[5] = { 'a', 'e', 'i', 'o', 'u' };

int isvowel(char c)
{
	for (int i = 0; i < 5; ++i)
	{
		if (c == vow[i])
			return 1;
	}
	return 0;
}
bool rule1()
{
	bool flag = false;
	for (int i = 0; i < s.size(); ++i)
	{
		if (isvowel(s[i]))
		{
			flag = true;
			break;
		}
	}
	return flag;
}
bool rule2()
{
	int num, flag;
	flag = isvowel(s[0]); num = 1;
	for (int i = 1; i < s.size(); ++i)
	{
		if (flag == isvowel(s[i]))
		{
			++num;
			if (num == 3)
				return false;
		}
		else
		{
			flag = 1 - flag;
			num = 1;
		}
	}
	return true;
}
bool rule3()
{
	int c = s[0];
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] == c&&c != 'e'&&c != 'o')
		{
			return false;
		}
		c = s[i];
	}
	return true;
}
int main()
{
	string ed = "end";
	while (cin >> s&&s != ed)
	{
		if (rule1()&&rule2() && rule3())
		{
			cout << '<' << s << "> is acceptable." << endl;
		}
		else
		{
			cout << '<' << s << "> is not acceptable." << endl;
		}
	}
	return 0;
}