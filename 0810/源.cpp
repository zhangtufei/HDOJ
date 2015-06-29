#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
void solve(string s_in)
{
	string sot;
	for (int i = 0; i < s_in.size(); ++i)
	{
		if ((s_in[i] >= 'A'&&s_in[i] <= 'Z') || s_in[i] == ' ')
		{
			sot += s_in[i];
		}
	}
	if (sot != "")
		cout << sot << endl;
}
int main()
{
	string s_in;
	getline(cin, s_in);
	solve(s_in);
	//string sot;
	//for (int i = 0; i < s_in.size(); ++i)
	//{
	//	if ((s_in[i] >= 'A'&&s_in[i] <= 'Z') || s_in[i] == ' ')
	//	{
	//		sot += s_in[i];
	//	}
	//}
	//if (sot!="")
	//	cout << sot << endl;
	system("pause");
	return 0;
}