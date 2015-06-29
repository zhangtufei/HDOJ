#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
const double PI = 3.1415926;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		double t1, t2;
		if (y1*y2 >0)
		{
			t1 = (x1 != 0) ? (atan(y1 / x1) / PI * 180) : (90.0);
			t1 = t1 < 0 ? t1 + 180 : t1;
			t2 = (x2 != 0) ? (atan(y2 / x2) / PI * 180) : (90.0);
			t2 = t2 < 0 ? t2 + 180 : t2;
			t1 = (t1 - t2 >= 0) ? (t1 - t2) : (t2 - t1);
		}
		else if (y1*y2 < 0)
		{
			t1 = (x1 != 0) ? (atan(y1 / x1) / PI * 180) : (90.0);
			t1 = t1 < 0 ? t1 + 180 : t1;
			t2 = (x2 != 0) ? (atan(y2 / x2) / PI * 180) : (90.0);
			t2 = t2 < 0 ? t2 + 180 : t2;
			t1 = (t1 > t2) ? (180 - t1 + t2) : (180 - t2 + t1);
		}
		else if (y1*y2 == 0)
		{
			double ty1, tx1, ty2, tx2;
			if (y1 == y2)
				t1 = (x1*x2 > 0) ? 0 : 180;
			else
			{
				if (y1 == 0)
				{
					ty1 = y1; tx1 = x1; ty2 = y2; tx2 = x2;
				}
				else if (y2 == 0)
				{
					ty1 = y2; tx1 = x2; ty2 = y1; tx2 = x1;
				}
				if (tx1 > 0)
				{
					if (ty2 > 0)
						t1 = 0.0;
					else
						t1 = 180.0;
				}
				else
				{
					if (ty2 > 0)
						t1 = 180.0;
					else
						t1 = 0.0;
				}
				t2 = (tx2 != 0) ? (atan(ty2 / tx2) / PI * 180) : (90.0);
				t2 = t2 < 0 ? t2 + 180 : t2;
				t1 = (t1 - t2 >= 0) ? (t1 - t2) : (t2 - t1);
			}
		}
		cout.precision(2);
		cout << fixed << t1 << endl;
	}
	return 0;
}