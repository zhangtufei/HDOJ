#include <iostream>
using namespace std;
int main()
{
	long long N, M;
	while (cin >> N >> M)
	{
		if (M ==-1&&N==-1)
			break;
		long long a = N, b = M;
		long long c = a%b;
		while (c)
		{
			a = b;
			b = c;
			c = a%b;
		}
		if (b == 1)
		{
			cout << "YES" << endl;
		}
		else
			cout << "POOR Haha" << endl;
	}
	return 0;
}