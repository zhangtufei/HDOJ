#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 + y1 > x2 + y2)
		{
			int temp = x2;
			x2 = x1;
			x1 = temp;
			temp = y2;
			y2 = y1;
			y1 = temp;
		}
		double sum=0.0;
		if (x2 + y2 == x1 + y1)
		{
			sum = (x2 - x1) *sqrt(2.0);
			if (sum < 0)
				sum = -sum;
		}
		else
		{
			int temp = x2 + y2;
			sum += sqrt((double)(temp*temp + (temp - 1)*(temp - 1))) + x2*sqrt((double)2.0);
			temp -= 1;
			while (temp > x1 + y1)
			{
				sum += sqrt((double)(temp*temp + (temp - 1)*(temp - 1))) + temp*sqrt((double)2.0);
				temp -= 1;
			}
			sum += (temp - x1)*sqrt(2.0);
			cout.precision(3);		
		}
		cout << fixed << sum << endl;
	}
	return 0;
}