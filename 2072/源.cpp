#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s) && s != "#")
	{
		set<string> re;
		string temp="";
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == ' ')
			{
				if (temp!="")
					re.insert(temp);
				temp = "";
				continue;
			}
			else
				temp += s[i];
			if (i == s.length() - 1)
				re.insert(temp);
		}
		cout << re.size() << endl;
	}
	return 0;
}