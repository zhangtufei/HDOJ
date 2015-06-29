#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
//直线：y=a1x+a2
//抛物线:y=c1(x-c2)^2+c3
//面积：1/3*c1*(x-c2)^3+c3*x - 1/2*a1*x^2 - a2*x（积分）
//
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		double x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		double c1, c2, c3, a1, a2;
		c2 = x1; c3 = y1;
		c1 = (y2 - c3) / ((x2 - c2)*(x2 - c2));
		if (x2 > x3)
		{
			int temp = x2;
			x2 = x3;
			x3 = temp;
			temp = y2;
			y2 = y3;
			y3 = temp;
		}
		a1 = (y3 - y2) / (x3 - x2);
		a2 = y2 - a1*x2;
		//判断是否对称
		double bg, ed;
		bool flag = false;
		if (y3 == y2)
		{
			bg = x2;
			ed = x1;
			flag = true;
		}
		else
		{
			bg = x2;
			ed = x3;
		}
		double area;
		//应该写成子函数。。。。
		area = (c1*(ed - c2)*(ed - c2)*(ed - c2) / 3.0 + c3*ed - a1*ed*ed / 2.0 - a2*ed) - (c1*(bg - c2)*(bg - c2)*(bg - c2) / 3.0 + c3*bg - a1*bg*bg / 2.0 - a2*bg);
		if (area < 0)
			area *= -1;
		if (flag)
			area *= 2;
		cout << setprecision(2) << fixed << area << endl;
	}
	return 0;
}