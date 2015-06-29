#include <iostream>
#include <vector>
using namespace std;
int main()
{
	double e[10];
	double factorial[10];
	e[0] = 1;
	factorial[0] = 1;
	cout << 'n' << ' ' << 'e' << endl;
	cout << '-' << ' ' << "-----------" << endl;
	cout << 0 << ' ' << 1 << endl;
	for (int i = 1; i < 10; ++i)
	{
		int temp = 1;
		factorial[i] = i*factorial[i - 1];
		e[i] = 1.0 / factorial[i]+e[i-1];
		if (i<=2)
			cout << i << ' ' << e[i] << endl;
		else
		{
			cout.precision(9);
			cout <<fixed<< i << ' ' << e[i] << endl;
		}
	}
	system("pause");
	return 0;
}