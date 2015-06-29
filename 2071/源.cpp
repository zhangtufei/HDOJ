#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;
		double temp, max = 0.0;
		while (num--)
		{
			cin >> temp;
			if (temp > max)
				max = temp;
		}
		cout.precision(2);
		cout << fixed << max << endl;
	}
	return 0;
}