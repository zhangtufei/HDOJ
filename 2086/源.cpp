#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		double an, a0;
		cin >> a0 >> an;
		double sum=0;
		double ci;
		for (int i = 1; i <= n; ++i)
		{
			cin >> ci;
			sum += 2*(n+1 - i)*ci;
		}
		cout.precision(2);
		cout <<fixed <<(n*a0 + an - sum) / (n + 1) << endl;
	}
	return 0;
}