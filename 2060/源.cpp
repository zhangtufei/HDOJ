#include <iostream>
using namespace std;
int a[7] = { 0,7, 6, 5, 4, 3, 2 };
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int ball, p, o;
		cin >> ball >> p >> o;
		if (p >= o)
		{
			cout << "Yes" << endl;
			continue;
		}
		bool flag = false;
		if (ball <= 6)
		{
			for (int i = 1; i <= ball; ++i)
			{
				p += a[i];
				if (p >= o)
				{
					flag = true;
					break;
				}
			}
			if (flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
		{
			while (ball-- > 6)
			{
				p += 8;
				if (p >= o)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				cout << "Yes" << endl;
			}
			else
			{
				p += 27;
				if (p >= o)
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
		}
	}
	return 0;
}