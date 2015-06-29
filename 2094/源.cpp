#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n)
	{
		map<string, int> m;
		set<string> s;
		string temp1,temp2;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp1>>temp2;
			s.insert(temp1);
			s.insert(temp2);
			++m[temp2];
		}
		if (m.size() == s.size()-1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}