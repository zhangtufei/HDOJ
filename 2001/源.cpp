#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	double x1, y1, x2, y2, len;
	while (cin >> x1 >> y1 >> x2 >> y2)
	{
		len = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
		cout.precision(2);
		cout <<fixed<< sqrt(len) << endl;
	}
	return 0;
}