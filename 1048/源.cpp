#include <iostream>
#include <string>
#include <ctype.h>
using namespace std; 
int main()
{
	string ssta = "START",send="END", sendin = "ENDOFINPUT";
	string pl = "VWXYZABCDEFGHIJKLMNOPQRSTU";
	string s;
	while (cin>>s)
	{
		if (s == ssta)
		{
			string cip;
			getchar();
			getline(cin, cip);
			string sot;
			for (int i = 0; i < cip.size(); ++i)
			{
				if (isalpha(cip[i]))
				{
					sot += pl[cip[i] - 'A'];
				}
				else
				{
					sot += cip[i];
				}
			}
			cin >> cip;
			if (cip == send)
			{
				cout << sot << endl;
			}
		}
		else if (s == sendin)
			break;
	}
	return 0;
}