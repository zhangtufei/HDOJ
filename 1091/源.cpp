#include <iostream>
using namespace std;
int main()
{
	long long a, b;
	while (cin >> a >> b&&!(a == 0 && b == 0))
		cout << a + b << endl;
	return 0;
}