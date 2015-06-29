#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.1415927
int main()
{
	double r;
	while (cin >> r)
	{
		cout.precision(3);
		cout << fixed<<(r*r*r * 4 * PI) / 3.0 << endl;
	}
	return 0;
}