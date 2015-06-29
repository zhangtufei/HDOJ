#include <iostream>
#include <vector>
using namespace std;
//A(H)=30H+6M+S/120;
//A(M)=6M+S/10;
//A(S)=6S;
/*
 D <= | A(H) - A(M) | <= 360-D; (1)
 D <= | A(H) - A(S) | <= 360-D; (2)
 D <= | A(M) - A(S) | <= 360-D; (3)
 用结果表示S的区间，绝对值号内的正负值用两个函数分别去解
 D<=bS-a<=360-D;
 D<=a-bS<=360-D;-->D-360+a<bS<a-D
*/
class Range
{
public:
	double left;
	double right;
	//Range operator*(const Range & r1,const Range & r2);
};
double D;//角度
Range operator *(const Range & r1,const Range & r2)
{
	Range r;
	r.left = r1.left > r2.left ? r1.left : r2.left;
	r.right = r1.right < r2.right ? r1.right : r2.right;
	if (r.left >= r.right)
		r.left = r.right = 0.0;
	return r;
}
Range calRange1(double a, double b)
{
	Range r;
	r.left = (D + a) / b;
	r.right = (360.0 - D + a) / b;
	if (r.left < 0.0)
		r.left = 0.0;
	if (r.right > 60.0)
		r.right = 60.0;
	if (r.left >= r.right)
		r.left = r.right = 0.0;
	return r;
}
Range calRange2(double a, double b)
{
	Range r;
	r.left = (D + a-360.0) / b;
	r.right = (a - D ) / b;
	if (r.left < 0)
		r.left = 0.0;
	if (r.right > 60.0)
		r.right = 60.0;
	if (r.left >= r.right)
		r.left = r.right = 0.0;
	return r;
}
int main()
{
	vector<double> vec;
	while (cin >> D&&D!=-1)
	{
		double times=0.0;
		for (int H = 0; H < 12; ++H)
		{
			for (int M = 0; M < 60; ++M)
			{
				Range range[3][2];
				double a, b;
				a = 30.0 * H - 5.5*M; b = 11.0 / 120.0;
				range[0][0] = calRange1(a, b); range[0][1] = calRange2(a, b);
				a = 30.0 * H + 0.5*M; b = 719.0 / 120.0;
				range[1][0] = calRange1(a, b); range[1][1] = calRange2(a, b);
				a = 6.0 * M; b = 5.9;
				range[2][0] = calRange1(a, b); range[2][1] = calRange2(a, b);
				for (int i = 0; i < 2;++i)
					for (int j = 0; j < 2; ++j)
						for (int k = 0; k < 2; ++k)
						{
							Range rtemp = range[0][i] * range[1][j] * range[2][k];
							times += rtemp.right - rtemp.left;
						}
			}
		}
		cout.precision(3);
		cout <<fixed <<times / 432.0 << endl;
	}
	return 0;
}