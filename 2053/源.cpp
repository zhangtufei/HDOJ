#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int i = 1;
		int sum = 0;
		for (; i < sqrt((double)n); ++i)
		{
			if (n%i == 0)
				++sum;
		}
		sum *= 2;
		if ( i*i==n)
			sum += 1;
		cout << sum % 2 << endl;
	}
	return 0;
}