#include <iostream>
using namespace std;
int main()
{
	int blocks;
	cin >> blocks;
	for (int i = 1; i <= blocks;++i)
	{
		int n, m;
		int flag = 1;
		while (cin >> n >> m)
		{
			if (n == 0 && m == 0)
			{
				if (i != blocks)
					cout << endl;
				break;
			}
			int a, b;
			int count = 0;
			for (a = 1; a < n-1; ++a)
				for (b = a+1; b < n; ++b)
					if ((a*a + b*b + m) % (a*b) == 0)
						++count;
			cout << "Case " << flag << ": " << count << endl;
			++flag;
		}
	}
	system("pause");
	return 0;
}