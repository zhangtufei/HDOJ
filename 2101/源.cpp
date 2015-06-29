#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	long long a, b;
	while (cin >> a >> b)
	{
		long long c = a + b;
		if (c % 86 == 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}