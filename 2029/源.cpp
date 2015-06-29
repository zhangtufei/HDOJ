#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		int temp = s.size();
		bool flag = true;
		for (int i = 0; i <temp / 2; ++i)
		{
			if (s[i] != s[temp - 1 - i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}