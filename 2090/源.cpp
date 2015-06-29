#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	string name;
	double count, price, sum=0;
	while (cin >> name >> count >> price)
	{
		sum += count*price;
	}
	cout.precision(1);
	cout << fixed << sum << endl;
	system("pause");
	return 0;
}