#include <iostream>
#include <string>
using namespace std;
int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		int a[4] = { 0, 0, 0, 0 };
		string s;
		cin >> s;
		if (s.size() < 8 || s.size() > 16)
		{
			cout << "NO" << endl;
			continue;
		}
		int sum = 0;
		for (int i = 0; s[i] != '\0'; ++i)
		{
			if (!a[0] && s[i] >= 'A'&&s[i] <= 'Z')
			{
				++a[0];
				++sum;
			}
			else if (!a[1] && s[i] >= 'a'&&s[i] <= 'z')
			{
				++a[1];
				++sum;
			}
			else if (!a[2] && s[i] >= '0'&&s[i] <= '9')
			{
				++a[2];
				++sum;
			}
			else if (!a[3] && (s[i] == '~' || s[i] == '^' || s[i] == '@' || s[i] == '#' || s[i] == '!' || s[i] == '$' || s[i] == '%'))
			{
				++a[3];
				++sum;
			}
			if (sum >= 3)
				break;
		}
		cout <<( (sum >= 3) ? "YES" : "NO" )<< endl;
	}
	return 0;
}