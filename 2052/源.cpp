#include <iostream>
#include <string>
using namespace std;
int main()
{
	int w, len;
	while (cin >> w >> len)
	{
		string s,s1;
		s1 += '|';
		s += '+';
		for (int i = 0; i < w; ++i)
		{
			s += '-';
			s1 += ' ';
		}
		s += '+';
		s1 += '|';
		cout << s << endl;
		for (int i = 0; i < len; ++i)
			cout << s1 << endl;
		cout << s << endl << endl;
	}
	return 0;
}