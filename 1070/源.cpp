#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct milk
{
	string name;
	double p;
	int ml;
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		milk re;
		string name;
		int price, ml;
		re.p = 10000000.0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> name >> price >> ml;
			if (ml < 200)
				continue;
			int days = ml / 200;
			if (days > 5)
				days = 5;
			if (re.p> (price*1.0 / days))
			{
				re.p = price*1.0 / days;
				re.name = name;
				re.ml = ml;
			}
			else if (re.p == (price*1.0 / days))
			{
				if ( ml>re.ml )
				{
					re.name = name;
					re.ml = ml;
				}
			}
		}
		cout << re.name << endl;
	}
	return 0;
}