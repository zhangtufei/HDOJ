#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T;
	cin >> T;
	getchar();
	while (T--)
	{
		string s_in;
		getline(cin, s_in);
		string sot;
		for (int i = 0; i < s_in.size(); ++i)
		{
			if (s_in[i] == ' ' || i == s_in.size() - 1)
			{
				if (i == s_in.size() - 1 && s_in[i] != ' ')
					sot += s_in[i];
				for (int j = sot.size() - 1; j >= 0; --j)
					cout << sot[j];
				if (i != s_in.size() - 1)
					cout << ' ';
				else
				{
					if (s_in[i] == ' ')
						cout << ' ' << endl;
					else
						cout << endl;
				}
				sot = "";
			}
			else
				sot += s_in[i];
		}
	}
	return 0;
}