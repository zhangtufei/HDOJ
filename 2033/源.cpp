#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int ah, am, as, bh, bm, bs;
		cin >> ah >> am >> as >> bh >> bm >> bs;
		int flag = 0;
		if ((as += bs) > 59)
		{
			as -= 60;
			flag = 1;
		}
		if ((am = am + bm + flag) > 59)
		{
			am -= 60;
			flag = 1;
		}
		else
			flag = 0;
		ah += bh + flag;
		cout << ah << ' ' << am << ' ' << as << endl;
	}
	return 0;
}