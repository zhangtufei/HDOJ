#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int k;
		cin >> k;
		string name;
		double c,s;
		double sumc=0;
		double sums = 0;
		bool flag = true;
		for (int i = 0; i < k; ++i)
		{
			cin >> name >> c >> s;
			if (s >= 60)
			{
				sums = sums + c*s;
				sumc += c;
			}
			else
				flag = false;
		}
		if (!flag)
		{
			cout << "Sorry!" << endl;
			if (n)
				cout << endl;
			continue;
		}
		cout.precision(2);
		cout << fixed << sums / sumc << endl;
		if (n)
			cout << endl;
	}
	return 0;
}