#include <iostream>
#include <string>
using namespace std;
struct square
{
	int num;
	int k;
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int days;
		cin >> days;
		int d[16];
		for (int i = 0; i < 16; ++i)
			cin >> d[i];
		square dish[22][22];
		memset(dish, 0, sizeof(dish));
		for (int i = 1; i <= 20; ++i)
		{
			for (int j = 1; j <= 20; ++j)
				cin >> dish[i][j].num;
		}
		while (days--)
		{
			for (int i = 1; i <= 20; ++i)
			{
				for (int j = 1; j <= 20; ++j)
				{
					dish[i][j].k = dish[i][j].num + dish[i + 1][j].num + dish[i - 1][j].num + dish[i][j + 1].num + dish[i][j - 1].num;
				}
			}
			for (int i = 1; i <= 20; ++i)
			{
				for (int j = 1; j <= 20; ++j)
				{
					dish[i][j].num += d[dish[i][j].k];
					if (dish[i][j].num > 3)
						dish[i][j].num = 3;
					else if (dish[i][j].num < 0)
						dish[i][j].num = 0;
				}
			}
		}
		for (int i = 1; i <= 20; ++i)
		{
			for (int j = 1; j <= 20; ++j)
			{
				switch (dish[i][j].num)
				{
				case 0:cout << '.'; break;
				case 1:cout << '!'; break;
				case 2:cout << 'X'; break;
				case 3:cout << '#'; break;
				default:break;
				}
			}
			cout << endl;
		}
		if (T)
			cout << endl;
	}
	return 0;
}
