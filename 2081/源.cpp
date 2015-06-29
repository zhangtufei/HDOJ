#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s = "6";
		string temp;
		cin >> temp;
		for (int i = 6; i <= 10; ++i)
			s += temp[i];
		cout << s << endl;
	}
	return 0;
}