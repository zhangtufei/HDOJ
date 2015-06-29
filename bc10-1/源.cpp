#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//int main()
//{
//	int T;
//	cin >> T;
//	while (T--)
//	{
//		long long a, b,c;
//		cin >> a >> b >> c;
//		if ((c - a) % b == 0)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (c == a || c == b)
		{
			cout << "Yes" << endl;
			continue;
		}
		long long temp = a + b;
		while (temp < c)
		{
			a = b;
			b = temp;
			temp = a + b;
		}
		if (temp == c)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}