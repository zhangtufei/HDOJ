#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 &&s1!="#")
	{
		cin >> s2;
		int num = 0;
		int len = s2.length();
		for (int i = 0; i < s1.length(); ++i)
		{
			if (s1[i] == s2[0])
			{
				bool flag = true;
				for (int j = 1; j < len; ++j)
				{
					if (s1[i + j] != s2[j])
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					++num;
					i += len - 1;
				}
			}
			else
				continue;
		}
		cout << num << endl;
	}
	return 0;
}