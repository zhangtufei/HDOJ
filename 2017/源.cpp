#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
bool isNum(char c)
{
	return c >= '0'&&c <= '9';
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		string::iterator iter = s.begin();
		int sum = 0;
		while ((iter = find_if(iter, s.end(), isNum)) != s.end())
		{
			++sum;
			++iter;
		}
		cout << sum << endl;
	}
	return 0;
}