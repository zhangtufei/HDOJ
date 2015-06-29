#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		string s;
		getline(cin, s);
		bool flag = true;
		if ((s[0] >= 'a'&&s[0] <= 'z') || (s[0] >= 'A'&&s[0] <= 'Z')||s[0]=='_')
		{
			for (int i = 1; i < s.size(); ++i)
			{
				if (!((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z') || (s[i] >= '0'&&s[i] <= '9') || s[i] == '_'))
				{
					cout << "no" << endl;
					flag = false;
					break;
				}
			}
			if (flag)
				cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}