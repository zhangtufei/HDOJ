#include <iostream>
using namespace std;
int main()
{
	int beg, end;
	while (cin >> beg >> end)
	{
		if (beg > end)
		{
			int temp = beg;
			beg = end;
			end = temp;
		}
		int square=0, cubic=0;
		for (int i = beg; i <= end; ++i)
		{
			if (i % 2 == 0)
			{
				square += i*i;
			}
			else
			{
				cubic += i*i*i;
			}
		}
		cout << square << ' ' << cubic << endl;
	}
	return 0;
}