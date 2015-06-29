#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n)
	{
		int a,b,c,sum=0,sum1=0;
		int temp = n;
		a = temp / 1000; temp %= 1000; sum += a;
		b = temp / 100; temp %= 100; sum += b;
		c = temp / 10; temp %= 10; sum += c+temp;
		temp = n;
		a = temp / 4096; temp %= 4096; sum1 += a;
		b = temp / 256; temp %= 256; sum1 += b;
		c = temp / 16; temp %= 16; sum1 += c; sum1 += temp;
		if (sum1 != sum)
		{
			cout << n << " is not a Sky Number." << endl;
			continue;
		}
		temp = n;
		sum1 = 0;
		a = temp / 1728; temp %= 1728; sum1 += a;
		b = temp / 144; temp %= 144; sum1 += b;
		c = temp / 12; temp %= 12; sum1 += c; sum1 += temp;
		if (sum1 != sum)
		{
			cout << n << " is not a Sky Number." << endl;
		}
		else
			cout << n << " is a Sky Number." << endl;
	}
	return 0;
}