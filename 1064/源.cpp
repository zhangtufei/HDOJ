#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a=0.0,b;
	for (int i = 0; i < 12; ++i)
	{
		cin >> b;
		a += b;
	}
	cout << "$" << setprecision(2) << fixed << a / 12.0 << endl;
	system("pause");
	return 0;
}