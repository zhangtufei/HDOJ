#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double h, m, s;
		cin >> h >> m >> s;
		m += s / 60.0;
		if (h >= 12)
			h -= 12;
		h += m / 60.0;
		m *= 6;
		h *= 30;
		double temp = m - h;
		if (temp < 0)
			temp = -temp;
		if (temp>180)
			temp = 360 - temp;
		cout <<(int)temp<< endl;
	}
	return 0;
}