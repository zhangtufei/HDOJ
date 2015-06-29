#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdio.h>
using namespace std;
//使用向量积原理
int main()
{
	int n;
	while (cin >> n&&n)
	{
		int x[110], y[110];
		for (int i = 0; i < n; ++i)
			scanf("%d %d", &x[i], &y[i]);
		double sum = 0.0;
		for (int i = 1; i < n - 1; ++i)
		{
			sum += 0.5*((x[i] - x[0])*(y[i + 1] - y[0]) - (x[i + 1] - x[0])*(y[i] - y[0]));
		}
		cout.precision(1);
		cout << fixed << sum << endl;
	}
	return 0;
}

//考虑凸凹多边形
//double dd(int x, int y)
//{
//	return (double)(x - y)*(x - y);
//}
//double areatr(int x1, int y1, int x2, int y2, int x3, int y3)
//{
//	double a = sqrt(dd(x1, x2) + dd(y1, y2));
//	double b = sqrt(dd(x1, x3) + dd(y1, y3));
//	double c = sqrt(dd(x2, x3) + dd(y2, y3));
//	double s = (a + b + c)/2.0;
//	return sqrt(s*(s - a)*(s - b)*(s - c));
//
//}
//int main()
//{
//	int n;
//	while (cin >> n&&n)
//	{
//		int x1, y1;
//		cin >> x1 >> y1;
//		int p[4];
//		double sum = 0;
//		cin >> p[0] >> p[1] >> p[2] >> p[3];
//		sum += areatr(x1, y1, p[0], p[1], p[2], p[3]);
//		int flag = 0;
//		for (int i = 1; i <= n - 3; ++i)
//		{
//			if (flag)
//			{
//				--flag;
//				cin >> p[2] >> p[3];
//
//			}
//			else
//			{
//				++flag;
//				cin >> p[0] >> p[1];
//			}
//			sum += areatr(x1, y1, p[0], p[1], p[2], p[3]);
//		}
//		cout.precision(1);
//		cout <<fixed <<sum<<endl;
//	}
//	return 0;
//}