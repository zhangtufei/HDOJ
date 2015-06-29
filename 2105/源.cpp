#include <iostream>
#include <math.h>
#include <streambuf>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	//streambuf *bk;
	//bk = cin.rdbuf();
	//fstream fin;
	//fin.open("data.txt");
	//cin.rdbuf(fin.rdbuf());
	int n;
	while (cin >> n&&n)
	{
		while (n--)
		{
			double x1, x2, x3, y1, y2, y3;
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			x2 = (x2 + x3) / 2;
			y2 = (y2 + y3) / 2;
			double x = (x1 - x2) / 3 + x2;
			double y = (y1 - y2) / 3 + y2;
	/*		double k = (y1 - y2) / (x1 - x2);
			double b = y1 - x1*k;
			double x = (x1 + y1 + (2 * sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) )) / 3 - b) / (k + 1);
			double y = k*x + b;*/
			cout.precision(1);
			cout <<fixed <<x << ' ' << y << endl;
		}
	}
	//cin.rdbuf(bk);
	return 0;
}