#include <iostream>
#include <iomanip>
using namespace std;
const double PI = 3.1415927;
int main()
{
	double dia,time;
	int rev;
	int flag = 1;
	while (cin >> dia >> rev >> time&&rev)
	{
		double distance = (dia*PI*rev ) / (12.0*5280.0);
		cout.precision(2);
		cout << "Trip #" << flag++ << ": " << fixed << distance << ' '<<fixed << (distance / time) * 3600 << endl;
	}
	return 0;
}