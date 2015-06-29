#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		char cmax;
		cmax = s[0];
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i]>cmax)
				cmax = s[i];
		}
		for (int i = 0; i < s.size(); ++i)
		{
			cout << s[i];
			if (s[i] == cmax)
				cout << "(max)" ;
		}
		cout << endl;
	}
	return 0;
}