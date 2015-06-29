#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		char c; int a;
		cin >> c >> a;
		if (c >= 'a'&&c <= 'z')
			a = a - (c - 'a' + 1);
		else if (c >= 'A'&&c <= 'Z')
			a += (c - 'A' + 1);
		cout << a << endl;
	}
	return 0;
}