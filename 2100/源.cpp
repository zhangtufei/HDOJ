#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	//streambuf *bk;
	//bk = cin.rdbuf();
	//fstream fin;
	//fin.open("data.txt");
	//cin.rdbuf(fin.rdbuf());
	string a, b;
	while (cin >> a >> b)
	{
		int t1, t2,t3;
		int i = a.size() - 1, j = b.size() - 1;
		string re = "";
		int flag = 0;
		for (; i >= 0 && j >= 0; --i, --j)
		{
			t1 = a[i] - 'A';
			t2 = b[j] - 'A';
			t3 = (t1 + t2 + flag) % 26;
			flag = (t1 + t2 + flag) / 26;
			char c = t3 + 'A';
			re = c+ re;
		}
		while (i >= 0)
		{
			t1 = a[i--] - 'A';
			t3 = (t1 +  flag) % 26;
			char c = t3 + 'A';
			flag = (t1 + flag) / 26;
			re = c+ re;
		}
		while (j >= 0)
		{
			t2 = b[j--] - 'A';
			t3 = (t2 + flag) % 26;
			flag = (t2 + flag) / 26;
			char c = t3 + 'A';
			re = c+ re;
		}
		if (flag)
			re = 'B' + re;
		string re1 = "";
		i = 0;
		while (re[i] == 'A')
			++i;
		for (; i < re.size(); ++i)
		{
			re1 += re[i];
		}
		if (re1 == "")
			re1 = "A";
		cout << re1 << endl;
	}
	//cin.rdbuf(bk);
	return 0;
}