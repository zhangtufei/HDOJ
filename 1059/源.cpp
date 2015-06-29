//Ä¸º¯Êý³¬Ê±£¬²»ÄÜÓÃ£¬ºÇºÇÄãÃÃË¼ÃÜ´ï£¡£¡£¡£¡£¡£¡£¡£¡
#include <iostream>
#include <string>
using namespace std;
int a[60010], b[60010];
int main()
{
	int n[7];
	int flag = 1;
	while (cin >> n[1] >> n[2] >> n[3] >> n[4] >> n[5] >> n[6])
	{
		if (n[1] ==0&& n[2] ==0&& n[3] ==0&& n[4] ==0&& n[5] == 0&&n[6] == 0)
			break;
		if (n[1] % 2 == 0 && n[2] % 2 == 0 && n[3] % 2 == 0 && n[4] % 2 == 0 && n[5] % 2 == 0 && n[6] % 2 == 0)
		{
			cout << "Collection #" << flag++ << ":" << endl << "Can be divided." << endl << endl;
			continue;
		}
		int tol = 0;
		for (int i = 1; i <= 6; ++i)
			tol += (i*n[i]);
		if (tol % 2 != 0)
		{
			cout << "Collection #" << flag++ << ":" << endl << "Can't be divided." << endl << endl;
			continue;
		}
		tol /= 2;
		memset(a, 0, sizeof(a));
		for (int i = 0; i <= n[1]&&i<=tol; ++i)
			a[i] = 1;
		memset(b, 0, sizeof(b));
		for (int i = 2; i <= 6; ++i)
		{
			for (int j = 0; j <=tol ; ++j)
			{
				for (int k = 0,t=n[i]; k + j <= tol&&t>=0; k += i,--t)
				{
					b[j + k]+=a[j];
				}
			}
			for (int j = 0; j <= tol; ++j)
				a[j] = b[j];
			memset(b, 0, sizeof(b));
			if (a[tol]!=0)
				break;
		}
		cout << "Collection #" << flag++ << ":" << endl;
		if (a[tol]!=0)
		{
			cout << "Can be divided." << endl;
		}
		else
		{
			cout << "Can't be divided." << endl;
		}
		cout << endl;
	}
	return 0;
}