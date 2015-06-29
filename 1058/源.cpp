#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const long long maxn=2000000000;
//2^31>maxn
//3^20>maxn
//5^14>maxn
//7^12>maxn
int main()
{
	vector<long long> vec;
	for (int i = 0; i < 31; ++i)
	{
		for (int j = 0; j < 20 && pow(2, i)*pow(3, j) <= maxn; ++j)
		{
			for (int k = 0; k < 14 && pow(2, i)*pow(3, j)*pow(5, k) <= maxn; ++k)
			{
				for (int z = 0; z < 12 && pow(2, i)*pow(3, j)*pow(5, k)*pow(7, z) <= maxn; ++z)
				{
					vec.push_back(pow(2, i)*pow(3, j)*pow(5, k)*pow(7, z));
				}
			}
		}
	}
	sort(vec.begin(), vec.end());
	int n;
	while (cin >> n&&n)
	{
		if (n % 10 == 1 && n% 100 != 11)
			cout << "The " << n << "st humble number is " << vec[n - 1] << "." << endl;
		else if (n% 10 == 2 && n % 100 != 12)
			cout << "The " << n << "nd humble number is " << vec[n - 1] << "." << endl;
		else if (n % 10 == 3 && n% 100 != 13)
			cout << "The " << n << "rd humble number is " << vec[n - 1] << "." << endl;
		else
			cout << "The " << n << "th humble number is " << vec[n - 1] << "." << endl;
	}
	return 0;
}


//这样搜索不靠谱，时间炒鸡长
//long long hum[5843] = { 0, 1, 2, 3, 4, 5, 6, 7 };
//bool ishum(long long x)
//{
//	while (x % 10 == 0)
//		x /= 10;
//	while (x % 2 == 0)
//		x /= 2;
//	while (x % 3 == 0)
//		x /= 3;
//	while (x % 5 == 0)
//		x /= 5;
//	while (x % 7 == 0)
//		x /= 7;
//	if (x == 1)
//		return true;
//	else
//		return false;
//	//if (x % 2 == 0 )
//	//{
//	//	if (x % 3 != 0 && x % 5 != 0 && x % 7 != 0)
//	//		return true;
//	//	else
//	//		return false;
//	//}
//	//else if ( x % 3 == 0 )
//	//{
//	//	if (x % 2 != 0 && x % 5 != 0 && x % 7 != 0)
//	//		return true;
//	//	else
//	//		return false;
//	//}
//	//else if (x % 5 == 0 )
//	//{
//	//	if (x % 2 != 0 && x % 3 != 0 && x % 7 != 0)
//	//		return true;
//	//	else
//	//		return false;
//	//}
//	//else if ( x % 7 == 0)
//	//{
//	//	if (x % 2 != 0 && x % 3 != 0 && x % 5 != 0)
//	//		return true;
//	//	else
//	//		return false;
//	//}
//	//else
//	//	return false;
//}
//int main()
//{
//	int flag = 7;
//	while (flag <= 5000)
//	{
//		long long temp = hum[flag] + 1;
//		while (!ishum(temp))
//		{
//			++temp;
//		}
//		hum[++flag] = temp;
//	}
//	int n, x = 0;
//	while (cin >> n&&n)
//	{
//		//if (ishum(n))
//
//	}
//}