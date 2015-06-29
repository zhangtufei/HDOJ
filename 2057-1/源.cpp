#include <iostream>
#include <iomanip>
using namespace std;
//这个就是真相我卧槽
int main()
{
	long long a, b;
	while (cin >> hex >> a >> hex >> b)
	{
		a = a + b;
		if (a < 0)
		{
			a *= -1;
			cout << '-';
		}
		cout << hex << setiosflags(ios::uppercase) << a << endl;
	}
	return 0;
}