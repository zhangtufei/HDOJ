#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	vector<double> vec[1000];
	int a[1000];
	string s;
	int p = 0;
	while (cin >> s)
	{
		bool flag=true;
		int i;
		double temp=0.0;
		for (i = 0; i < s.size(); ++i)
		{
			if (s[i] == '.')
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			int num = 0;
			for (int i = s.size() - 1; i >= 0; --i)
			{
				int t = s[i] - 0x30;
				for (int k = 0; k < s.size() - i - 1; ++k)
				{
					t *= 10;
				}
				num += t;
			}
			a[p++] = num;
			continue;
		}
		else
		{
			for (int j = i - 1; j >= 0; --j)
			{
				double t = s[j] - 0x30;
				for (int k = 1; k <= i - j - 1; ++k)
				{
					t *= 10;
				}
				temp = temp + t;
			}
			for (int j = i + 1; j < s.size(); ++j)
			{
				double t = s[j] - 0x30;
				for (int k = 0; k <= j - i - 1; ++k)
				{
					t = t*0.1;
				}
				temp += t;
			}
			vec[p].push_back(temp);
		}
	}
	double ma = 0, mi = 1000, avr = 0;

	for (int i = 0; i < p; ++i)
	{
		double sum=1;
		for (int j = 0; j < vec[i].size()&&j+a[i]<=vec[i].size(); ++j)
		{
			for (int k = 0; k < a[i];++k)
				sum *= (1 + vec[i][j+k] / 10000.0);
			sum =pow(sum,365);
			sum = pow(sum, 1.0 / a[i]);
			sum = (sum - 1) * 100;
			if (sum > ma)
				ma = sum;
			if (sum<mi)
				mi = sum;
			avr += sum;
			sum = 1;
		}
		int n = vec[i].size() - a[i] + 1;
		for (int j = 0; j< vec[i].size(); ++j)
		{
			
			cout <<resetiosflags() <<fixed<<vec[i][j] << ' ';
		}
		
		cout << a[i] << ' ';
		cout<< fixed <<setprecision(3)<< mi << "0% " << ma << "0% " << avr / n << "0%" << endl;
		ma = 0; mi = 10000; avr = 0;
	/*	vec[i].push_back(ma);
		vec[i].push_back(mi);
		vec[i].push_back(avr/n);*/
	}
}