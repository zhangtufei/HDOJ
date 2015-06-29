#include <iostream>
#include <math.h>
using namespace std;
//长度:i*(i+1)/2=m的到i<sqrt(2m)
int main()
{
	long long N, M;
	while (cin >> N >> M&&N&&M)
	{
		for (int len = (int)sqrt(double(2 * M)); len >= 1; --len)
		{
			//起点为beg，长度为len的数列和为M，求得beg
			//数学差成这样，想哭怎么办5555555555555555
			long long beg = (2 * M / len + 1 - len) / 2;
			long long end = beg + len - 1;
			if ((beg + end)*len == 2 * M)
				cout << '[' << beg << ',' << end << ']' << endl;
		}
		cout << endl;
	}
	return 0;
}
//long long sum = 0;
//for (int i = 1; i <= M / 2; ++i)
//{
//	for (int j = i; j <= M; ++j)
//	{
//		sum += j;
//		if (sum == M)
//		{
//			cout << '[' << i << ',' << j << ']' << endl;
//			sum = 0;
//			break;
//		}
//		else if (sum > M)
//		{
//			sum = 0;
//			break; 
//		}
//	}
//}
//cout << '[' << M << ',' << M<< ']' << endl;