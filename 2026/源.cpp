#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		bool flag = true;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')
				flag = true;
			else if (islower(s[i]) && flag)
			{
				s[i] = toupper(s[i]);
				flag = false;
			}
		}
		cout << s << endl;
	}
	return 0;
}