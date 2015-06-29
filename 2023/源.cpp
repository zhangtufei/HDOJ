#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		long long st[60][10];
		double cavr[10];
		double savr[60];
		memset(st, 0, sizeof(st));
		memset(cavr, 0, sizeof(cavr));
		memset(savr, 0, sizeof(savr));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> st[i][j];
				//先加完再除，否则可能精度不够
				//cavr[j] += (st[i][j]*1.0/n);
				//savr[i] += (st[i][j]*1.0/n);
				cavr[j] += st[i][j];
				savr[i] += st[i][j];
			}
		}
		int count = 0;
		bool flag;
		for (int i = 1; i <= n; ++i)
		{
			savr[i] /= m;
		}
		for (int i = 1; i <= m; ++i)
		{
			cavr[i] /= n;
		}
		if (n == 0)
		{
			cout << "0.00" << endl;
		}
		for (int i = 1; i <= n; ++i)
		{
			cout.precision(2);
			if (i == n)
				cout << fixed << savr[i] << endl;
			else
				cout << fixed << savr[i] << ' ';
			flag = true;
			for (int j = 1; j <= m; ++j)
			{
				if (st[i][j] < cavr[j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
				++count;
		}
		if (m == 0)
		{
			cout << "0.00" << endl;
		}
		for (int i = 1; i <= m; ++i)
		{
			cout.precision(2);
			if (i == m)
				cout << fixed << cavr[i] << endl;
			else
				cout << fixed << cavr[i] << ' ';
		}
		cout << count << endl << endl;
	}
	return 0;
}