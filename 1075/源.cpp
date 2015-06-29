#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	string s,s1="START",s2="END";
	map<string, string> dic;
	while (cin>>s)
	{
		if (s == s1)
			continue;
		if (s == s2)
			break;
		string st;
		cin >> st;
		dic[st] = s;
	}
	getchar();
	while (getline(cin, s))
	{
		if (s == s1)
			continue;
		if (s == s2)
			break;
		string stt;
		for (int i = 0; i < s.size(); ++i)
		{
			if (!islower(s[i]))
			{
				if (stt != "")
				{
					if (dic[stt] != "")
					{
						cout << dic[stt];
					}
					else
						cout << stt;
				}
				stt = "";
				cout << s[i];
				continue;
			}
			stt += s[i];
		}
		cout << endl;
	}
	return 0;
}