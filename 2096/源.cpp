#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a, b;
	while (n--)
	{
		cin >> a >> b;
		a %= 100;
		b %= 100;
		cout << (a + b) % 100 << endl;
	}
	return 0;
}