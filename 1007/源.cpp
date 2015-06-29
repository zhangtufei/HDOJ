#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
struct Pointx
{
	double x;
	double y;
};
bool CompX(Pointx a,Pointx b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
bool CompY(struct Pointx a, struct Pointx b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}
double caldistance(struct Pointx a, struct Pointx b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
double mindistance(struct Pointx arr[], int len)
{
	//if (len == 2)
	//{
	//	return caldistance(arr[0], arr[1]);
	//}
	//if (len == 3)
	//{
	//	double l1 = caldistance(arr[0], arr[1]);
	//	double l2 = caldistance(arr[1], arr[2]);
	//	return l1 < l2 ? l1 : l2;
	//}
	//int len1 = len / 2;
	//double d1 = mindistance(arr, len1);
	//double d2 = mindistance(arr + len1, len - len1);
	//return d1 < d2 ? d1 : d2;
	double min = caldistance(arr[0], arr[1]);
	double temp;
	for (int i = 1; i < len - 1; ++i)
	{
		temp = caldistance(arr[i], arr[i + 1]);
		if (min > temp)
			min = temp;
	}
	return min;

}
int main()
{
	Pointx * arr = new Pointx[100000];
	int lines;
	double miny,minx,min;
	cout.precision(2);
	vector<double> re;
	while (cin >> lines&&lines > 0)
	{
		for (int i = 0; i < lines; ++i)
		{
			cin >> arr[i].x >> arr[i].y;
		}
		sort(arr, arr + lines, CompY);
		miny = mindistance(arr, lines);
		sort(arr, arr + lines, CompX);
		minx = mindistance(arr, lines);
		min = minx < miny ? minx : miny;
		re.push_back(sqrt(min) / 2.0);
	}
	delete[] arr;
	vector<double>::iterator iter = re.begin();
	for (; iter != re.end(); ++iter)
		cout << fixed << *iter << endl;
	system("pause");
	return 0;
}