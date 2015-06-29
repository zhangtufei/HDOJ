#include <iostream>
#include <string>
using namespace std;
string str_add(string a, string b)
{
	int j = a.size() - 1;
	int temp = 0;//进位标志
	for (int i = b.size() - 1; i >= 0; --i, --j)
	{
		int x = a[j] - 0x30 + b[i] - 0x30 + temp;
		a[j] = x % 10 + 0x30;
		temp = x / 10;
	}
	while (temp&&j >= 0)
	{
		int x = a[j] - 0x30 + temp;
		a[j] = x % 10 + 0x30;
		temp = x / 10;
		--j;
	}
	if (temp)
	{
		char c = temp + 0x30;
		a = c + a;
	}
	return a;
}
int main()
{
	string h[2010];//打表保存斐波那契数列数列
	h[1] = "1";
	h[2] = "2";
	for (int i = 3; i <= 2000; ++i)
	{
		h[i] = str_add(h[i - 1], h[i - 2]);//字符串相加子函数
	}
	string s1, s2,s3="0";
	while (cin>>s1>>s2)
	{
		if (s1 == s3&&s2 == s3)//如果都为“0”，退出程序
			break;
		if (s1.size() > s2.size() || (s1.size() == s2.size() && s1 > s2))
		{
			string temp = s1;
			s1 = s2;
			s2 = temp;
		}
		int i = 1;
		while (h[i].size() < s1.size() || (h[i].size() == s1.size() && h[i] < s1))//找到第一个>=s1的字符串
			++i;
		int sum = 0;
		while (h[i].size() < s2.size() || (h[i].size()==s2.size()&&h[i] <=s2))//找出所有<=s2的字符串
		{
			++i;
			++sum;
		}
		cout << sum << endl;
	}
	return 0;
}