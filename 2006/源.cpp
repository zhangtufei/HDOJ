#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int temp;
		long long re=0;
		bool first = true;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			if (temp % 2 != 0)
			{
				if (first == true)
				{
					re = temp;
					first = false;
				}
				else
					re *= temp;
			}
		}
		cout << re << endl;
	}
	return 0;
}