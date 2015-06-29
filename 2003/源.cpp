#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double n;
	while (cin >> n)
	{
		double n1 = (n >= 0) ? n : -n;
		cout.precision(2);
		cout << fixed << n1 << endl;
	}
	return 0;
}