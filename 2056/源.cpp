#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
struct rectp
{
	double ax, ay;
	double bx, by;
	double cx, cy;
	double dx, dy;
};
void sortxy(struct rectp &re1,double &x1,double &y1,double &x2,double &y2)
{
	if (x1 > x2)
	{
		double temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	if (y1 < y2)
	{
		re1.cx = x1; re1.cy = y1; re1.bx = x2; re1.by = y2;
		re1.ax = x1; re1.ay = y2; re1.dx = x2; re1.dy = y1;
	}
	else
	{
		re1.ax = x1; re1.ay = y1; re1.dx = x2; re1.dy = y2;
		re1.cx = x1; re1.cy = y2; re1.bx = x2; re1.by = y1;
	}
}
int main()
{
	double x1, y1, x2, y2, x3, y3, x4, y4;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
	{
		rectp re1, re2;
		sortxy(re1, x1, y1, x2, y2);
		sortxy(re2, x3, y3, x4, y4);
		if (re1.bx<re2.ax || re1.ax>re2.bx || re1.cy > re2.ay || re1.ay < re2.cy)
		{
			cout << "0.00" << endl;
			continue;
		}
		if (re1.ax > re2.ax)//re1为左边的矩形
		{
			rectp temp = re1;
			re1 = re2;
			re2 = temp;
		}
		double area1 = (re1.by - re1.dy)*(re1.dx - re1.cx);
		double area2 = (re2.by - re2.dy)*(re2.dx - re2.cx);
		cout.precision(2);
		if (re1.ay >= re2.ay)//re1在左上角(包括平行)
		{
			if (re2.dx <= re1.dx)
			{
				if (re2.dy >= re1.dy)
				{
					cout << fixed << area2 << endl;
					continue;
				}
				else
				{
					cout << fixed << (re2.dx - re2.cx)*(re2.ay - re1.cy) << endl;
					continue;
				}
			}
			else
			{
				if (re2.dy >= re1.dy)
				{
					cout << fixed << (re2.by - re2.dy)*(re1.dx - re2.cx) << endl;
					continue;
				}
				else
				{
					cout << fixed << (re2.ay - re1.dy)*(re1.dx - re2.ax) << endl;
					continue;
				}
			}
		}
		else
		{
			if (re2.dy >= re1.dy)
			{
				if (re1.bx >= re2.bx)
				{
					cout << fixed << (re2.dx - re2.cx)*(re1.ay - re2.dy) << endl;
					continue;
				}
				else
				{
					cout << fixed << (re1.ay - re2.dy)*(re1.dx - re2.cx) << endl;
					continue;
				}
			}
			else
			{
				if (re1.bx >= re2.bx)
				{
					cout << fixed << (re2.dx - re2.cx)*(re1.ay - re1.dy) << endl;
					continue;
				}
				else
				{
					cout << fixed << (re1.ay - re1.dy)*(re1.dx - re2.cx) << endl;
					continue;
				}
			}
		}
	}
	return 0;
}
//#include <stdio.h>
//#include <math.h>
//#include <algorithm>
//using namespace std;
//#include <stdlib.h>
//double max(double a, double b){
//	return a > b ? a : b;
//
//}
//
//double min(double a, double b){
//	return a > b ? b : a;
//
//}
//int compare(const void * a, const void * b)
//{
//	return (*(double*)a - *(double*)b);
//}
//int main(){
//	double x1, y1, x2, y2, x3, y3, x4, y4;
//	while (~scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4)){
//		double s = 0;
//
//		if (max(x1, x2)<min(x3, x4) || max(y1, y2) < min(y3, y4) || min(x1, x2) > max(x3, x4) || min(y1, y2) > max(y3, y4)){
//			printf("%0.2lf\n", s);
//		}
//		else{
//			double sx[] = { x1, x2, x3, x4 };
//			double sy[] = { y1, y2, y3, y4 };
//			//	sort(sx,sx+4);
//			qsort(sx, 4, sizeof(double), compare);
//			qsort(sy, 4, sizeof(double), compare);
//			s = (sx[2] - sx[1])*(sy[2] - sy[1]);
//
//			printf("%0.2lf\n", s);
//		}
//	}
//	return 0;
//}