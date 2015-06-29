#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
	long double sec, min, hour,sub1,sub2,sub3;
	long double degrees;
	long double times;
	int re;
	int flag;
	vector<int> vec;
	while (cin >> degrees)
	{
		if (degrees == -1)
			break;
		sec = 0; 
		min = 0;
		hour = 0;
		times = 0;
		re = 0;
		flag = 1;
		while(flag==1)
		{
			if (sec >= 360)
				sec = 0;
			if (min >= 360)
			{
				min = 0;
			}
			if (hour >= 180)
			{
				hour = 0;
				flag = 0;
			}
			long double temp=hour;
			for (int i = 0; i < 2; ++i)
			{

				sub1 = fabs(sec - temp);
				sub2 = fabs(sec - min);
				sub3 = fabs(min - temp);
				if (sub1 > 180)
					sub1 = 360 - sub1;
				if (sub2 > 180)
					sub2 = 360 - sub2;
				if (sub3 > 180)
					sub3 = 360 - sub3;
				if (sub1 >= degrees && sub2 >= degrees&& sub3 >= degrees)
				{
					++times;
				}
				temp += 180;
			}
			sec += 0.1;
			min += 1 / 600.0;
			hour += 1 / 7200.0;

		}
		cout << (times / 25920.0) << endl;
		re = (int)((times /25920.0 + 0.0005) * 1000);
		vec.push_back(re);
	
	}
	vector<int>::iterator iter = vec.begin();
	for (; iter != vec.end(); ++iter)
	{
		int t = *iter;
		int i1 = t / 100000;
		int i2 = t / 10000;
		int i3 = t / 1000;
		int i4 = t / 100;
		int i5 = t / 10;
		if (i1 != 0)
			cout << i1 << i2 - i1 * 10 << i3 - i2 * 10 << '.' << i4 - i3 * 10 << i5 - i4 * 10 << t - i5 * 10 << endl;
		else if(i2!=0)
			cout << i2 << i3 - i2 * 10 << '.' << i4 - i3 * 10 << i5 - i4 * 10 << t - i5 * 10<<endl;
		else
			cout << i3 << '.' << i4 - i3 * 10 << i5 - i4 * 10 << t - i5 * 10<<endl;
	}
	system("pause");
	return 0;
}