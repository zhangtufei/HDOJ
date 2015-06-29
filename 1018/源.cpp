#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	long long num;
	cin >> n;
	while (n--)
	{
		cin >> num;
		double re = 0;
		for (int i = 1; i <= num; ++i)
		{
			re += log10((double)i);
		}
		cout << (int)(re + 1) << endl;
	}
	system("pause");
	return 0;
}